/// = 对齐

- (UIView*)setupADBottomView {
    UIView      *adbottomView = [[UIView alloc] initWithFrame:CGRectMake(0, self.window.frame.size.height - 90, self.window.frame.size.width, 90)];
    adbottomView.backgroundColor = [UIColor whiteColor];
    UIImageView *ImgView = [[UIImageView alloc] initWithFrame:CGRectMake(self.window.frame.size.width / 2 - 90, 20, 43, 43)];
    [ImgView setImage:[UIImage imageNamed:@"iPhone图标120"]];
    [adbottomView addSubview:ImgView];
    UILabel *titLab = [[UILabel alloc] initWithFrame:CGRectMake(self.window.frame.size.width / 2 - 40, 22, 200, 30)];
    titLab.text      = @"影视大全";
    titLab.font      = [UIFont systemFontOfSize:27];
    titLab.textColor = UIColorFromRGB(0x222222);
    [adbottomView addSubview:titLab];

    UILabel *sloganLab = [[UILabel alloc] initWithFrame:CGRectMake(self.window.frame.size.width / 2 - 40, 43, 200, 30)];
    sloganLab.text      = @"没钱买会员 用影视大全";
    sloganLab.font      = [UIFont systemFontOfSize:11];
    sloganLab.textColor = UIColorFromRGB(0x666666);
    [adbottomView addSubview:sloganLab];
    #if TARGET_VALUE == TARGET_SDSP
    titLab.text    = @"影视大全";
    sloganLab.text = @"没钱买会员 用影视大全";
    #else // if TARGET_VALUE == TARGET_SARRS
    titLab.text    = @"快看影视";
    sloganLab.text = @"大片来袭，快看不能停";
    #endif // if TARGET_VALUE == TARGET_SARRS

    return adbottomView;
}


/// Block
typedef void (^adImgCompletion)(ADInfo *adInfo, NSError *err);
typedef void (^adHomeCompletion)(ADInfo *focusAdInfo, ADInfo *bannerAdInfo, ADInfo *floatAdInfo, NSError *err);

@interface DQADRequest : DQRequestBase
@property(nonatomic, copy) NSString *ip;
@property(nonatomic, copy) NSString *model;
@property(nonatomic, copy) NSString *whichpage;

- (void)startRequestWithAdPlace:(NSString*)adPlace andSize:(NSString*)adSize finishBlock:(adImgCompletion)block;
- (void)startRequestHomeWithAdPlace:(NSString*)adPlace andSize:(NSString*)adSize finishBlock:(adHomeCompletion)block;

@end

// typedef void (^baiduNativeBlock)(BaiduMobAdNativeAdObject *object);
typedef void (^baiduNativeBlock)(BaiduMobAdNativeAdView *view);
typedef void (^adRequestFailedBlock)(NSError *error);

@interface DQAdView : UIView<BaiduMobAdViewDelegate, BaiduMobAdNativeAdDelegate>

// @property (nonatomic, retain) GADBannerView *bannerView;
@property(nonatomic, retain) BaiduMobAdView         *baiduAdView;
@property(nonatomic, retain) BaiduMobAdNative       *native;
@property(nonatomic, retain) BaiduMobAdNativeAdView *baiduNativeAdView;
@property(nonatomic, retain) NSMutableArray         *mainArray;
@property(nonatomic, copy) NSString                 *adUntiTag;
@property(nonatomic, copy) NSString                 *adActionUrl;
@property(nonatomic, copy) NSString                 *posKey;
@property(nonatomic, copy) NSString                 *adImgUrl;
@property(nonatomic, retain) UIImageView            *adImgView;
@property(copy) baiduNativeBlock                     natvieBlock;
@property(copy) void (^ finishBlock)(BaiduMobAdNativeAdObject *data, BaiduMobAdNativeAdView *view);
@property(copy) adRequestFailedBlock                 adFailedBlock;

@property(nonatomic, strong) ADView                 *commonView;
@property(nonatomic, strong) ADModel                *adModel;

// 广告点击block
@property(copy) void (^ tapBlock)();


typedef void (^AdEventBlock)(GDTNativeAdData*, DQAdEvent);

// long.add.20161228
@property(nonatomic, strong) GDTNativeAdData *adData;
@property(nonatomic, strong) UIImageView     *imgvBack;
@property(nonatomic, strong) UIImageView     *imgvShow;
@property(nonatomic, strong) UIImageView     *imgvBottomBar;
@property(nonatomic, strong) UIButton        *btnMark;
@property(nonatomic, strong) UILabel         *labelDesc;
@property(nonatomic, strong) UILabel         *labelTitle;
@property(nonatomic, strong) UILabel         *labelRating;
@property(nonatomic, assign) DQAdType         adType;

@property(nonatomic, retain) NSTimer         *cntTimer;
@property(nonatomic, retain) NSTimer         *dismissTimer;
@property(nonatomic, retain) UIButton        *dismissBtn;
@property(nonatomic, retain) UIImageView     *cntView;
@property(nonatomic, assign) int              cnt;


- (id)initWithFrame:(CGRect)frame AdData:(GDTNativeAdData*)adData withEvent:(void (^)(GDTNativeAdData*adData, DQAdEvent event))eventBlock;
- (id)initWithFrame:(CGRect)frame AdData:(GDTNativeAdData*)adData;
- (id)initWithFrame:(CGRect)frame adData:(GDTNativeAdData*)adData type:(DQAdType)adType;
- (instancetype)initWithAdData:(GDTNativeAdData*)adData type:(DQAdType)adType withEvent:(void (^)(GDTNativeAdData*adData, DQAdEvent event))eventBlock;
@end

@implementation DQAdView {
    AdEventBlock _eventBlock;
}
- (void)refreshDisplay {
    if (self.adData) {
        [self reSizeUIItems];

        NSString                  *desc             = [self.adData.properties objectForKey:@"desc"];
        NSMutableAttributedString *attributedString = [[NSMutableAttributedString alloc] initWithString:desc];
        NSMutableParagraphStyle   *paragraphStyle   = [[NSMutableParagraphStyle alloc] init];
        [paragraphStyle setLineSpacing:1];// 调整行间距

        [attributedString addAttribute:NSParagraphStyleAttributeName value:paragraphStyle range:NSMakeRange(0, [desc length])];
        self.labelTitle.attributedText = attributedString;
        [self.labelTitle sizeToFit];

        NSString *iconUrl = [self.adData.properties objectForKey:@"icon"]; // 小图
        NSString *imgvUrl = [self.adData.properties objectForKey:@"img"];// 大图

        if (self.adType == DQAdTypeTencentSplash) {
            if (!self.cntTimer) {
                self.cntTimer = [NSTimer timerWithTimeInterval:1.0 target:self selector:@selector(timerJump:)userInfo:nil repeats:YES];
                [[NSRunLoop currentRunLoop] addTimer:_cntTimer forMode:NSRunLoopCommonModes];
                [self.cntTimer setFireDate:[NSDate distantFuture]];
            }
            __weak typeof(self) weakSelf = self;
            [self.imgvShow setImageWithURL:[NSURL URLWithString:imgvUrl] placeholder:nil options:YYWebImageOptionSetImageWithFadeAnimation completion:^(UIImage*_Nullable image, NSURL*_Nonnull url, YYWebImageFromType from, YYWebImageStage stage, NSError*_Nullable error){
                __strong typeof(weakSelf) strongSelf = weakSelf;

                if (!strongSelf) {
                    return;
                }
                if (error) {
                    [strongSelf loadImageFailed];
                }
                [strongSelf setSecontCountView];
                [strongSelf.btnMark setHidden:NO];
            }];
        } else {
            __weak typeof(self) weakSelf = self;
            NSString *imgURL = self.adType == DQAdTypeTencentImgBig?imgvUrl:iconUrl;
            [self.imgvShow setImageWithURL:[NSURL URLWithString:imgURL] placeholder:nil options:YYWebImageOptionProgressiveBlur | YYWebImageOptionSetImageWithFadeAnimation completion:^(UIImage*_Nullable image, NSURL*_Nonnull url, YYWebImageFromType from, YYWebImageStage stage, NSError*_Nullable error){
                __strong typeof(weakSelf) strongSelf = weakSelf;
                if (image) {
                    [strongSelf.imgvBack setHidden:strongSelf.adType != DQAdTypeTencentImgBig];
                    [strongSelf.btnMark setHidden:NO];
                    strongSelf.imgvBack.image = image;
                }
            }];
        }
    }
} /* refreshDisplay */

/// oc函数对齐
- (id)initWithFrame:(CGRect)frame
    posKey:(NSString *)aPosKey
    adImgUrl:(NSString *)adImgUrl
    adActionUrl:(NSString *)adActionUrl {
    self = [super initWithFrame:frame];
    if (self) {
        _posKey = aPosKey;

        UIImageView *imgView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, self.frame.size.width, self.frame.size.height)];
        [imgView setImageWithURL:[NSURL URLWithString:adImgUrl]
         options:YYWebImageOptionProgressiveBlur | YYWebImageOptionSetImageWithFadeAnimation];
        if (adActionUrl.length > 0) {
            _adActionUrl                   = adActionUrl;
            imgView.userInteractionEnabled = true;
            UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(jumpAd)];
            [imgView addGestureRecognizer:tap];
        }

        [self addSubview:imgView];
    }

    return self;
}

/// 注释对齐
- (void)loadBAIDU:(ADModel*)model {
    self.commonView = [[[NSBundle mainBundle] loadNibNamed:@"ADView" owner:self options:nil] objectAtIndex:0];
    [self addSubview:self.commonView];

    //CGRect imgFrame = CGRectMake(10, 25, 126, 84);
    if (model.module == BusinessModule_DOWNLOADMANAGER) {
        //imgFrame = CGRectMake(10, 10, 112, 75);
        [self.commonView updateDLConstraints];
    }

    [self requestBaiduNativeAd];

//    @weakify(self);
//    self.finishBlock = ^(BaiduMobAdNativeAdObject *object, BaiduMobAdNativeAdView*view) {
//        @strongify(self);
//        dispatch_async(dispatch_get_main_queue(), ^{
//            [self addSubview:view];
//            view.frame = CGRectMake(0, 0, self.frame.size.width, self.frame.size.height);
//            view.brandLabel.text = @"广告";
//
//            [self updateBaiduUI:object];
//            [self bringSubviewToFront:view];
//        });
//    };


//    self.baiduAdView           = [[BaiduMobAdView alloc] init];
//    self.baiduAdView.AdUnitTag = adID;//adId;
//    //            self.baiduAdView.AdType    = BaiduMobAdViewTypeBanner;
//    self.baiduAdView.frame    = imgFrame;
//    self.baiduAdView.delegate = self;
//    [self addSubview:self.baiduAdView];
//    [self.baiduAdView start];
} // loadBAIDU
@end

/// 宏
#define SFAssert(condition, ...) \
    if (!(condition)) { SFLogError(__VA_ARGS__); } \
    NSAssert(condition, __VA_ARGS__);

#ifdef NSLogError
    #define SFLogError NSLogError
#else // ifdef NSLogError
    #define SFLogError(fmt, ...) \
    NSLog(@"\033[fg255,0,0;%s:%d %s> " fmt @"\033[;", \
          __FILENAME__, __LINE__, __FUNCTION__,##__VA_ARGS__)


#endif // ifdef NSLogError