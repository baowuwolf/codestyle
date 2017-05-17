
/// 换行的宏
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

/// 宏对齐
// *INDENT-OFF*
#if __has_include(<CocoaLumberjack/DDLog.h>)
// *INDENT-ON*
#import <CocoaLumberjack/DDLog.h>
#import <CocoaLumberjack/DDFileLogger.h>
#import <CocoaLumberjack/DDTTYLogger.h>
#import <CocoaLumberjack/DDASLLogger.h>
#define LOG_COLOR(R,G,B)  [UIColor colorWithRed: (R / 255.0) green: (G / 255.0) blue: (B / 255.0) alpha: 1.0]

#if DEBUG
static const int ddLogLevel = LOG_LEVEL_VERBOSE;
#else /* if DEBUG */
static const int ddLogLevel = LOG_LEVEL_INFO;
#endif /* if DEBUG */

#define NSLogSetup() \
do { \
[[DDTTYLogger sharedInstance] setForegroundColor:LOG_COLOR(187,187,187) backgroundColor:nil forFlag:LOG_FLAG_INFO]; \
[[DDTTYLogger sharedInstance] setForegroundColor:LOG_COLOR(255,255,0) backgroundColor:nil forFlag:LOG_FLAG_WARN]; \
[[DDTTYLogger sharedInstance] setForegroundColor:LOG_COLOR(255,0,0) backgroundColor:nil forFlag:LOG_FLAG_ERROR]; \
[DDTTYLogger sharedInstance].logFormatter = [SARRSLogCustomFormatter new]; \
[[DDTTYLogger sharedInstance] setColorsEnabled:YES]; \
[DDLog addLogger:[DDTTYLogger sharedInstance]]; \
[DDLog addLogger:[DDASLLogger sharedInstance]]; \
} while (0)

#define NSLogInfo   DDLogInfo
#define NSLogWarn DDLogWarn
#define NSLogError  DDLogError

#define NSLogCInfo    DDLogCInfo
#define NSLogCWarn DDLogCWarn
#define NSLogCError  DDLogCError

#ifdef NSLog
#undef NSLog
#endif // ifdef NSLog

#define NSLog NSLogInfo

@interface SARRSLogCustomFormatter : NSObject <DDLogFormatter> {
int              atomicLoggerCount;
NSDateFormatter *threadUnsafeDateFormatter;
}
@end


#else // if __has_include(<CocoaLumberjack / DDLog.h>)
/// LOG
#define __FILENAME__ ({ char*ptr = strrchr(__FILE__, '/'); if (ptr) { ptr++; } else { ptr = __FILE__; } ptr; })

/// LOG
#define XCODE_COLORS_FG(color) @"\033[fg" color @";"
#define XCODE_COLORS_END @"\033[;"

#define NSLogBase(color, level, fmt, ...) do { NSLog(XCODE_COLORS_FG(color) level " %s:%d %s> " fmt XCODE_COLORS_END, __FILENAME__, __LINE__, __FUNCTION__, ## __VA_ARGS__); } while (0)

#define NSLogSetup()        do {} while (0)
#define NSLogInfo(fmt, ...) NSLogBase(@"187,187,187",@"Info", fmt,    ## __VA_ARGS__)
#define NSLogWarn(fmt, ...) NSLogBase(@"255,255,0",@"Warning", fmt, ## __VA_ARGS__)
#define NSLogError(fmt, ...) NSLogBase(@"255,0,0",@"Error", fmt,   ## __VA_ARGS__)

#define NSLogCInfo   NSLogInfo
#define NSLogCWarn  NSLogWarn
#define NSLogCError  NSLogError
#endif // if __has_include(<CocoaLumberjack / DDLog.h>)

#define DQLogDebug  NSLogInfo
#define DQLogInfo   NSLogInfo
#define DQLogWarn NSLogWarn
#define DQLogError  NSLogError

#define DQLogDownload DQLogDebug
#define DQLog                NSLogInfo

/// 测试括号
void func(){
}

class flx{
char*name;
int age;
LOGGXXXXXXX l;
public:
void test(){
int i = 0;
}

private:
};
class flxa:flx{
char*name;
int age;
LOGGXXXXXXX l;
public:
void test(){
int i = 0;
}
};
stuct sx{

char*name;
int age;
LOGGXXXXXXX l;
};
enum x{
 Red =  -1;
 Green          = 2111;
 Blue=31;
};
/// 宏内部代码和注释对齐
#ifndef ALShortVideo_ALShortVideoConfig_h
#define ALShortVideo_ALShortVideoConfig_h

// Video file time length limitation (Maximum Seconds)
#define VIDEO_MAX_TIME 30.0
// Video file time length limitation (Minimum Seconds)
#define VIDEO_VALID_MINTIME 0.8
// Video filename
#define VIDEO_DEFAULTNAME @"videoReadyToUpload.mov"
// Video filepath
#define VIDEO_OUTPUTFILE [NSURL fileURLWithPath:[PATH_OF_DOCUMENT stringByAppendingPathComponent:VIDEO_DEFAULTNAME]]

// Tip Strings pressed on the record area
#define OPERATE_RECORD_TIP @"↑上移取消"
// Tip Strings pressed on the cancel area
#define OPERATE_CANCEL_TIP @"松手取消"

// Save btn title
#define SAVE_BTN_TITLE @"确定"
// Retake btn title
#define RETAKE_BTN_TITLE @"重录"
// Record btn title
#define RECORD_BTN_TITLE @"按住拍"

#define NAVBAR_LEFT_BTN_TITLE @"取消"

// Tip color normal
#define NORMAL_TIPCOLOR WeALColor(0, 192, 130)
// Tip color warning
#define WARNING_TIPCOLOR WeALColor(216, 0, 40)

#endif // ifndef ALShortVideo_ALShortVideoConfig_h

    @interface ALHelper:NSObject
    + (void)convertVideoFromComposition:(AVComposition *)composition
    success:(void (^)(NSURL *url)) success
    failure:(void (^)(NSError *error))failure;

    + (void)compressVideoWithSourceComposition:(AVComposition *)sourceComposition
    success:(void (^)(NSURL *url, CGFloat size)) success
    failure:(void (^)(NSError *error))failure;
    @end


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
    @property(nonatomic, retain) BaiduMobAdView *baiduAdView;
    @property(nonatomic, retain) BaiduMobAdNative *native;
    @property(nonatomic, retain) BaiduMobAdNativeAdView *baiduNativeAdView;
    @property(nonatomic, retain) NSMutableArray *mainArray;
    @property(nonatomic, copy) NSString *adUntiTag;// 是否添加单位
    @property(nonatomic, copy) NSString *adActionUrl;// 操作URL
    @property(nonatomic, copy) NSString *posKey;// 位置信息
    @property(nonatomic, copy) NSString *adImgUrl;// 封面
    @property(nonatomic, retain) UIImageView *adImgView;//封面控件
    @property(copy) baiduNativeBlock                     natvieBlock;// 导航
    @property(copy) void (     ^       finishBlock)(BaiduMobAdNativeAdObject *  data, BaiduMobAdNativeAdView  *view);
    @property(copy) adRequestFailedBlock adFailedBlock;

    @property(nonatomic, strong) ADView *     commonView;
    @property(nonatomic, strong) ADModel *   adModel;

    // 广告点击block
    @property(copy) void (^ tapBlock)();


    typedef void (^AdEventBlock)(GDTNativeAdData*, DQAdEvent);

    // long.add.20161228
    @property(nonatomic, strong) GDTNativeAdData  *     adData;
    @property(nonatomic, strong) UIImageView     *imgvBack;
    @property(nonatomic, strong) UIImageView *imgvShow;
    @property(nonatomic, strong) UIImageView *imgvBottomBar;
    @property(nonatomic, strong) UIButton        *btnMark;
    @property(nonatomic, strong) UILabel *labelDesc;
    @property(nonatomic, strong) UILabel *labelTitle;
    @property(nonatomic, strong) UILabel         *labelRating;
    @property(nonatomic, assign) DQAdType         adType;

    @property(nonatomic, retain) NSTimer         *cntTimer;
    @property(nonatomic, retain) NSTimer         *dismissTimer;
    @property(nonatomic, retain) UIButton        *dismissBtn;
    @property(nonatomic, retain) UIImageView     *cntView;
    @property(nonatomic, assign) int              cnt;


    - (id)initWithFrame:(CGRect)frame AdData:(GDTNativeAdData*)adData withEvent:(void(^)(GDTNativeAdData*adData, DQAdEvent event))eventBlock;
    - (id)initWithFrame:(CGRect)frame AdData:(GDTNativeAdData*)adData;
    - (id)initWithFrame:(CGRect)frame adData:(GDTNativeAdData*)adData type:(DQAdType)adType;
    - (instancetype)initWithAdData:(GDTNativeAdData*)adData type:(DQAdType)adType withEvent:(void (^)(GDTNativeAdData*adData, DQAdEvent event))eventBlock;
    @end

    @implementation DQAdView {
    AdEventBlock _eventBlock;
    void(^_completeBlock)(DQSubscriptionItem *item, NSError *error);
    void(^_CompleteBlock_Ablum)(DQSubscriptionModel_Album_List * item, NSError *error);
    }

    /// 赋值 = 对齐

    - (UIView*)setupADBottomView {
    UIView      *adbottomView = [[UIView alloc] initWithFrame:CGRectMake(0, self.window.frame.size.height - 90, self.window.frame.size.width, 90)];
    adbottomView.backgroundColor = [UIColor whiteColor];
    UIImageView *ImgView = [[UIImageView alloc] initWithFrame:CGRectMake(self.window.frame.size.width / 2 - 90, 20, 43, 43)];
    [ImgView setImage:[UIImage imageNamed:@"iPhone图标120"]];
    [adbottomView addSubview:ImgView];
    UILabel *titLab = [[UILabel alloc] initWithFrame:CGRectMake(self.window.frame.size.width / 2 - 40, 22, 200, 30)];
    titLab.text  = @"影视大全";
    titLab.font = [UIFont systemFontOfSize:27];
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

    /// 保持字典变量对齐
    - (NSDictionary *)reportDic {
    if (_reportDic == nil) {
    _reportDic = [NSDictionary dictionaryWithObjectsAndKeys:
    kMainRecommend,   @"DQMainRecommendViewController",
    kMainChannel,     @"DQMainChannelViewController",
    kMainTopic,       @"DQMainTopicViewController",
    kMainRanking,     @"DQMainRankViewController",
    kMainSearch,      @"DQSearchViewController",
    kMainHistory,     @"DQHistoryViewController2",
    kMainDownload,    @"DQDownloadManagementViewController",
    kMainMore,        @"DQMainMoreViewController",
    kMainCollect,     @"DQFavorViewController",
    kMainEpisodes,    @"DQChannelFilterViewController",
    kMainMovie,       @"DQChannelFilterViewController",
    kMainCartoon,     @"DQChannelFilterViewController",
    kMainVariety,     @"DQChannelFilterViewController",
    kMaindocumentary,  @"DQChannelFilterViewController",
    kMain_Subscriptionlist,     @"DQSubscriptionViewController",
    kMain_Halfscreenplaypage,   @"DQHalfScreenPlayerViewController",
    kMain_Subscriptionhome,     @"DQSubscriptionHomeViewController",
    kMainTheme,                 @"DQTopicItemListViewController",
    kMainMovie_Ranking,         @"DQMainRankViewController",
    kMainEpisodes_Ranking,      @"DQRank50ViewController",
    kMainVariety_Ranking,       @"DQRank50ViewController",
    kMainSearch_Result,         @"DQSearchResultView",
    kMain_details,              @"DQDetailViewController3",
    nil];
    }

    return _reportDic;
    }

    /// oc 方法定义按照冒号对齐
    - (NSURLSessionDownloadTask *)downloadTaskWithRequest:(NSURLRequest *)request
    progress:(void (^)(NSProgress *downloadProgress))downloadProgressBlock
    destination:(NSURL * (^)(NSURL *targetPath, NSURLResponse *response))destination
    completionHandler:(void (^)(NSURLResponse *response, NSURL *filePath, NSError *error))completionHandler {
    NSURLSessionDownloadTask *dataTask = [self.httpSessionManager downloadTaskWithRequest:request
    progress:^(NSProgress * _Nonnull downloadProgress) {
    downloadProgressBlock(downloadProgress);
    } destination:^NSURL * _Nonnull (NSURL * _Nonnull targetPath, NSURLResponse * _Nonnull response) {
    return destination(targetPath, response);
    } completionHandler:^(NSURLResponse * _Nonnull response, NSURL * _Nullable filePath, NSError * _Nullable error) {
    completionHandler(response, filePath, error);
    }];

    [dataTask resume];

    return dataTask;
    }
    - (void)refreshDisplay {
    if (self.adData) {
    [self reSizeUIItems];

    NSString                  *desc= [self.adData.properties objectForKey:@"desc"];
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

        // @weakify(self);
        // self.finishBlock = ^(BaiduMobAdNativeAdObject *object, BaiduMobAdNativeAdView*view) {
        // @strongify(self);
        // dispatch_async(dispatch_get_main_queue(), ^{
        // [self addSubview:view];
        // view.frame = CGRectMake(0, 0, self.frame.size.width, self.frame.size.height);
        // view.brandLabel.text = @"广告";
        //
        // [self updateBaiduUI:object];
        // [self bringSubviewToFront:view];
        // });
        // };


        //    self.baiduAdView           = [[BaiduMobAdView alloc] init];
        //    self.baiduAdView.AdUnitTag = adID;//adId;
        //    //            self.baiduAdView.AdType    = BaiduMobAdViewTypeBanner;
        //    self.baiduAdView.frame    = imgFrame;
        //    self.baiduAdView.delegate = self;
        //    [self addSubview:self.baiduAdView];
        //    [self.baiduAdView start];
    } // loadBAIDU

    /// block调用
    - (NSURLSessionDataTask *)GET:(NSString *)URLString
    parameters:(_Nullable id)parameters
    progress:(void (^)(NSProgress * _Nonnull progress))downloadProgressB
    success:(void (^)(NSURLSessionDataTask *task, id responseObject))success
    failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure;
    {
    NSURLSessionDataTask *dataTask = [self.httpSessionManager GET:URLString parameters:parameters progress:^(NSProgress * _Nonnull downloadProgress) {
    if (downloadProgressB) {
    downloadProgressB(downloadProgress);
    }
    } success:^(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject) {
    success(task, responseObject);
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
    failure(task, error);
    }];

    return dataTask;
    }

    - (void)playExtStreamWithMultiUrlVideoInfo:(DQMultiUrlVideoStreamInfo *)info {
        NSString     *aResolution = info.resulotation;
        [self setCurrentResulotionView:aResolution];
        NSArray      *apiList   = info.apiList;
        NSArray      *steamList = info.steamList;
        NSDictionary *rule      = info.rule;
        NSDictionary *header    = info.header;
        NSArray    *durationList = info.durationList;
        double     totalduration = info.totalduration;

        //非优酷的外网源 当apiList不为空时 调用本地js解析流地址
        if (![self.site isEqualToString:@"youku"] && apiList.count > 0 && rule.count > 0) {
        @weakify(self);
         [[LocalParseExtStreamHelper sharedInstance]  getPlayAddressWithUrl: self.currentExtOriginUrl apiUrls: apiList  header: header  uStreams: steamList
         rule: rule 
         onFinish:^(NSArray *resUrls, NSError *err) {
         }];
      
        // 本地
        [[LocalParseExtStreamHelper sharedInstance]  getPlayAddressWithUrl: self.currentExtOriginUrl apiUrls: apiList  header: header  uStreams: steamList
         rule: rule 
         onFinish:^(NSArray *resUrls, NSError *err) {
        DQLog(@"resUrls: %@", resUrls);
        @strongify(self); if (!self) {
        return;
        }
        if (err == nil && resUrls.count > 0) {
        NSMutableArray *steamListArray = [NSMutableArray arrayWithArray:resUrls];
        [self playWithUrls:steamListArray durationlist:durationList totalDuration:totalduration];

        // 本地解析成功 上报结果
        [self reportLocalStreamWith:self.extStreamInfo
        andStreamListArray:steamListArray
        andCurrentResoltion:aResolution];
        } else {
        DQLog(@"local_extract error: %@", err);
        // 本地解析失败
        if (steamList.count > 0) {
        // 远程
        [self playWithUrls:[steamList mutableCopy] durationlist:durationList totalDuration:totalduration];
        } else {
        [self _goHtmlPlay];
        }
        }
        }];
        } else if (steamList.count > 0) {
        // 远程
        [self playWithUrls:[steamList mutableCopy] durationlist:durationList totalDuration:totalduration];
        return;
        }
    } // playExtStreamWithMultiUrlVideoInfo



    - (void)start {
    if ((!self.link) || ![self.link length]) {
    return;
    }

    NSString *urlString = self.link;
    if ([self.link rangeOfString:@"%"].location == NSNotFound) {
    urlString = [self.link stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    }



    //MARK: v3.1.0   这个方法值针对UIImageView+URL中的  ，下载图片处理。
    NSString *md5FileName = [self _md5];

    _afnAccess = [[DQAFNAccess alloc] init];
    NSURLRequest *request = [[NSURLRequest alloc] initWithURL:[NSURL URLWithString:urlString]];

    //    __block unsigned long long received = 0;
    __weak id                  wself    = self;
    [_afnAccess downloadTaskWithRequest:request progress:^(NSProgress * _Nonnull downloadProgress) {
    NSLog(@"%@",downloadProgress);

    } destination:^NSURL * _Nonnull(NSURL * _Nonnull targetPath, NSURLResponse * _Nonnull response) {

    NSURL *desFileURL = [[NSFileManager defaultManager] URLForDirectory:NSCachesDirectory inDomain:NSUserDomainMask appropriateForURL:nil create:NO error:nil];
    desFileURL =  [desFileURL URLByAppendingPathComponent:kDQDownloaderPath isDirectory:YES];
    desFileURL =  [desFileURL URLByAppendingPathComponent:md5FileName];

    return desFileURL;

    } completionHandler:^(NSURLResponse * _Nonnull response, NSURL * _Nonnull filePath, NSError * _Nonnull error) {
    NSLog(@"File downloaded to: %@", filePath);
    __strong DQDownloader *sself = wself;
    if (error == nil)
    {
    if ((sself.delegate) &&
    [sself.delegate respondsToSelector:@selector(downloader:finishedWithError:)]) {
    [sself.delegate downloader:sself finishedWithError:nil];
    }
    sself.state = DQDownloaderStateFinished;
    }
    else
    {
    sself.state = DQDownloaderStateError;
    if ((sself.delegate) &&
    [sself.delegate respondsToSelector:@selector(downloader:finishedWithError:)]) {
    [sself.delegate downloader:sself finishedWithError:error];
    }
    }
    }];

    self.state = DQDownloaderStateDownloading;
    NSString* name=isLogin?:@"Unknown";
    NSString* state=isLogin?"Welecom":@"Guest";

    NSString* name=isLogin    ? :       @"Unknown";
    NSString* state=isLogin ?  "Welecom": @"Guest";
    } /* start */

    /// 测试Switch
    + (NSMutableDictionary*)downloadVideosMapFormDQDownloaders {
    NSArray             *downloadersArray = [DQGlobalSingelton sharedInstance].gDownloadManager.downloaderQueue;

    NSMutableDictionary *videosDict = [NSMutableDictionary dictionaryWithCapacity:downloadersArray.count];

    for (DQBaseDownloader *downloader in downloadersArray) {
    DQDownloadableObject *obj   = downloader.downloadableObject;
    DQVideoForDownload   *video = [[DQVideoForDownload alloc] init];
    [self setDQVideo:video withDQDownloadObject:obj];
    DQDownloadStatus      status = downloader.status;
    switch (status) {
    case DQDownloadStatusUnstart:
    video.state = DQVideoDownloadState_Waitting;
    break;

    case DQDownloadStatusPrepare:
    video.state = DQVideoDownloadState_Waitting;
    break;

    case DQDownloadStatusDownloading:{
    video.state = DQVideoDownloadState_Waitting;
    }
    break;

    case DQDownloadStatusPaused:
    {
    video.state = DQVideoDownloadState_Paused;
    break;
}
    case DQDownloadStatusFinished:
 {   video.state      = DQVideoDownloadState_Finished;
    video.isFinished = YES;
  }  break;

    case DQDownloadStatusFailed:
    video.state = DQVideoDownloadState_Waitting;
    break;

    default:
    break;
    } /* switch */


    switch (downloader.downloadableObject.type) {
    case DQDownloadableObjectTypeUnknown:
    video.type = DQVideoFileTypeUnkonwn;
    break;

    case DQDownloadableObjectTypeMP4:
    video.type = DQVideoFileTypeMP4;
    break;

    case DQDownloadableObjectTypeM3U8:
    video.type = DQVideoFileTypeM3U8;
    break;

    default:
    video.type = DQVideoFileTypeUnkonwn;
    break;
    }


    void (^cleanBlock)(DQBaseDownloader *) = ^(DQBaseDownloader *downloder) {
    NSString *oldFilePath = downloader.downloadableObject.filePath;
    NSString *oldTempPath = [downloader.downloadableObject.filePath stringByAppendingString:@".tmp"];
    [[NSFileManager defaultManager] removeItemAtPath:oldFilePath error:NULL];
    [[NSFileManager defaultManager] removeItemAtPath:oldTempPath error:NULL];
    };


    if (downloader.status == DQDownloadStatusFinished) {
    if (downloader.downloadableObject.type == DQDownloadableObjectTypeMP4) {
    video.fileSize     = downloader.totalBytes;
    video.downloadSize = downloader.receivedBytes;
    video.state        = DQVideoDownloadState_Finished;
    video.isFinished   = YES;
    video.m3u8UrlArray = @[@"0"];

    NSString *newFilePath  = [video filePathAtIndex:0];
    NSString *oldFilePath  = downloader.downloadableObject.filePath;
    BOOL      movedSuccess = [self moveFileItemAtPath:oldFilePath toPath:newFilePath];
    DQLogDownload(@"Move File %@ ! Video type: MP4 name: %@ ",movedSuccess?@"success":@"faild",video.name);
    if (!movedSuccess) {
    cleanBlock(downloader);
    continue;
    }
    } else if (downloader.downloadableObject.type == DQDownloadableObjectTypeM3U8) {
    video.type         = DQVideoFileTypeM3U8;
    video.fileSize     = downloader.totalBytes;
    video.downloadSize = downloader.receivedBytes;
    video.isFinished   = YES;

    NSString *newFolderPath = [video folderPath];
    NSString *oldFolderPath = downloader.downloadableObject.filePath;
    BOOL      movedSuccess  = [self moveFileItemAtPath:oldFolderPath toPath:newFolderPath];
    DQLogDownload(@"Move File %@ ! Video type: M3U8 name: %@ ",movedSuccess?@"success":@"faild",video.name);
    if (!movedSuccess) {
    cleanBlock(downloader);
    continue;
    }
    } else {
    DQLogError(@"Error! downloader status is Finished but type is Unkonwn");
    cleanBlock(downloader);
    continue;
    }
    } else {
    video.type       = DQVideoFileTypeUnkonwn;
    video.isFinished = NO;
    }
    cleanBlock(downloader);
    [videosDict setObject:video forKey:video.uniqueID];
    }


    [(NSMutableArray *)([DQGlobalSingelton sharedInstance].gDownloadManager.downloaderQueue)removeAllObjects];

    return videosDict;
    } /* downloadVideosMapFormDQDownloaders */

    @end

