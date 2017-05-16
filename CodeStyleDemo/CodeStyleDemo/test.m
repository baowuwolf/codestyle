

// oc/block_in_method.m


@implementation NSArray (WWDC)
- (NSArray*)map:(id (^)(id))xform {
    id result = [NSMutableArray array];
    for (id elem in self) {
        [result addObject:xform(elem)];
    }

    return result;
}

- (NSArray*)collect:(BOOL (^)(id))predicate {
    id result = [NSMutableArray array];
    for (id elem in self) {
        if (predicate(elem)) {
            [result addObject:elem];
        }
    }

    return result;
}

- (void)each:(void (^)(id object))block {
    [self enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop){
        block(obj);
    }];
}

// corner case: block literal in use with return type
id longLines = [allLines collect:^BOOL (id item){
    return [item length] > 20;
}];

// corner case: block literal in use with return type
id longLines = [allLines collect:^BOOL* (id item){
    return [item length] > 20;
}];

@end

// 1. block literal: ^{ ... };
// 2. block declaration: return_t (^name) (int arg1, int arg2, ...) NB: return_t is optional and name is also optional
// 3. block inline call ^ return_t (int arg) { ... }; NB: return_t is optional


// oc/blocks.m
int* (^ blkReturningPointer)(int) = ^int* (int a){
    return a + 1;
};

void (^ blk2)(int*) = ^(int *b){
    *b = 1;
};


int (^ oneFrom)(int) = ^(int anInt){
    return anInt - 1;
};

// this should not be flagged as OC_BLOCK_CARET
int x = 12 ^ 23;

// oc/blocks_align.m
[[HRNewsService sharedInstance] unregisterPushToken:data
 success:^{
    self.notificationsEnabled = NO;
    if (data.param) {
        self.loudNotifications = YES;
    }
}
 fail:^{
    self.notificationsEnabled = NO;
    if (data.param) {
        self.loudNotifications = YES;
    }
}
];


// oc/box.m
NSArray      *test = @[];
NSNumber     *test = @(42 * 2);
NSNumber     *test = @4.0;
NSDictionary *test = @{@"foo":@"bar"};

@implementation UrlTemplateTest
- (void)test {
    NSString *test   = @"";
    NSString *string = [[NSMutableString alloc] initWithString:@""];
    STAssertEqualObjects(string, @"", nil);
}

@end


// oc/bug_340.m
#import <Cocoa/Cocoa.h>

@implementation MyDocument
- (void)locationManager:(CLLocationManager*)manager didFailWithError:(NSError*)error {
    [UIAlertView showError:error
     withTitle:NSLocalizedString(@"Your location cannot be determined",
                                 @"The location of the user cannot be guessed")
     message:NSLocalizedString(@"You can try again by pressing the refresh button",
                               @"Recovery suggestion when the location cannot be found")];
}

@end


// oc/bug_497.m
NSArray *array = @[@1,
                   @2,
                   @3,
                   @4];

NSArray *array = @{ @1:@1,
                    @2:@2,
                    @3:@3,
                    @4:@4 };

int i = 1
        + 1
        + 2;


// oc/bug_i_125-412.m
[[NSFileManager defaultManager] createFileAtPath:path contents:data attributes:nil]

[self.myProperty setObject: obj forKey: key];

NSString *newValue = [@"my string" stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceCharacterSet];

NSString *newValue = [myStrings[0] stringByTrimmingCharactersInSet:NSCharacterSet.whitespaceCharacterSet];


// oc/bug_i_408.m
CGFloat fontSize = floorf([font pointSize]* [self tileContentScale] + 0.5);


// oc/bug_i_477.m
[dataArray enumerateObjectsUsingBlock:^(dataType *data, NSUInteger idx, BOOL *stop){
    // Do stuff!
}];


// oc/cmt_insert.m
@protocol spacingProtocol

@property NSInteger spacing;

@end

@interface cmt_insert

+ (cmt_insert*)shareInstance;

@property(readonly) BOOL            isAvailable;

@property(copy) NSArray<NSString*> *contents;

- (void)updateContents:(NSArray<NSString*>*)inContents andRefresh:(BOOL)inRefresh;

@end

@implementation cmt_insert

+ (cmt_insert*)sharedInstance {
    return nil;
}

- (BOOL)isAvailable {
    return YES;
}

- (NSArray<NSString*>*)contents {
    return @[];
}

- (void)setContents:(NSArray<NSString*>*)inContents {
}

- (void)updateContents:(NSArray<NSString*>*)inContents andRefresh:(BOOL)inRefresh {
}

@end

@interface cmt_insert_with_protocol (spacingProtocol)
@end

@implementation cmt_insert_with_protocol (spacingProtocol)

- (NSInteger)spacing {
    return 0;
}

- (void)setSpacing:(NSInteger)inSpacing {
}

@end


// oc/code_placeholder.m
double          delayInSeconds = 2.0;
dispatch_time_t popTime        = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayInSeconds * NSEC_PER_SEC));
dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
    <#code to be executed on the main queue after delay#>
});


// oc/complex_method.m
// Turn the document contents into a single savable lump of data
- (NSData*)dataOfType:(NSString*)typeName error:(NSError**)outError {
    #pragma unused(typeName)

    // Produce the data lump:
    NSData *retval = [NSKeyedArchiver archivedDataWithRootObject:model];

    // If the lump is nil something went wrong
    // fill out the error object to explain what wrent wrong
    if (outError != NULL) {
        // The sender wanted an error reported. If there
        // was a problem, fill in an NSError object
        if (retval == nil) {
            // The error object should include an (unhelpful)
            // explanation of what happened
            NSDictionary *userInfoDict = [NSDictionary dictionaryWithObjectsAndKeys:
                                          @"Internal error formatting data", NSLocalizedDescriptionKey,
                                          @"Archiving of data failed. Probably a bug.", NSLocalizedFailureReasonErrorKey,
                                          @"There's nothing you can do.", NSLocalizedRecoverySuggestionErrorKey, nil];

            *outError = [NSError errorWithDomain:LinearInternalErrorDomain
                         code:linErrCantFormatDocumentData
                         userInfo:userInfoDict];
        } else {
            // No problem. Don't supply an error object.
            *outError = nil;
        }
    }

    return retval;
}

// oc/Declarations.h

@interface EmptyClass : NSObject
- (void)aMessage:(id)arg;
@end

@interface EmptyClass : NSObject {}
- (void)aMessage:(id)arg;
@end

@interface NSObject (ObjectAdditions)
- (void)aMessage:(id)arg;
@end

@protocol TestProtocol
- (void)aMessage:(id)arg;
@end

@interface TestClass : NSObject <TestProtocol> {
}
- (void)aMessage:(id)arg;
@end


// oc/exceptions.m

int main(int argc, const char *argv[]){
    @try {
        [NSException raise:NSInternalInconsistency
         format:@"An internal inconsistency was raised"];
    }@catch (NSException *e) {
        NSLog(@"Catch");
    }@finally {
        NSLog(@"Finally");
    }

    @throw [NSException exceptionWithName:@"foo" reason:@"bar" userInfo:nil];

    NSException *exception = [NSException exceptionWithName:@"HotTeaException"
                              reason:@"The tea is too hot"
                              userInfo:nil];

    @throw exception;

    return 0;
}

// oc/for.m
[[HRNewsService sharedInstance] fetchBreakingNewsItemWithId:self.breakingNewsId success:^(id responseObject){
    NSDictionary *thing;
    for (NSArray *dictionary in photos) {
    }
} failure:^(NSError *error){
    // Failure?
}];

// We also need to consider cases where a non-pointer type (or, a pointer without the star) is declared in ObjC.
for (id obj in someDictionary) {
    NSLog(@"This could be anything! Objective-C really needs parametrized collections.");
}


// oc/Fraction.h
#import <Foundation/NSObject.h>

@interface Fraction : NSObject {
    int numerator;
    int denominator;
}

- (void)print;
- (void)setNumerator:(int)d;
- (void)setDenominator:(int)d;
- (int)numerator;
- (int)denominator;
- (void)setNumDen:(int)n:(int)d;
@end


// oc/Fraction.m
#import "Fraction.h"
#import <stdio.h>

@implementation Fraction
- (void)print {
    printf("%i/%i", numerator, denominator);
}

- (void)setNumerator:(int)n {
    numerator = n;
}

- (void)setDenominator:(int)d {
    denominator = d;
}

- (int)denominator {
    return denominator;
}

- (int)numerator {
    return numerator;
}

@end


// oc/gh137.m
[UIView animateWithDuration:0.2f delay:0.f options:UIViewAnimationCurveEaseInOut animations:^{
    self.transform = CGAffineTransformMakeScale(1.05f, 1.05f);
} completion:^(BOOL finished){
    [UIView animateWithDuration:0.08f delay:0.f options:UIViewAnimationOptionCurveEaseInOut animations:^{
        self.transform = CGAffineTransformIdentity;
        [UIView animateWithDuration:1 delay:0 options:0 animations:^{
            // blah
        } completion:nil];
    }];
}];

dispatch_async(foo, ^{
    dispatch_async(bar, ^{
        dispatch_async(qux, ^{
            quz();
        });
    });
})


// oc/gh293.m
self.someErrorView = ({
    UIView *view = [[UIView alloc] init];
    view.backgroundColor = [UIColor redColor];
    [view addSubview:({
        self.someErrorLabel = ({
            UILabel *label = [[UILabel alloc] init];
            label.textAlignment = NSTextAlignmentCenter;
            label.backgroundColor = [UIColor clearColor];
            label;
        });
    })];
    view;
});
[self.view addSubview:self.someErrorView];


// oc/gh511.m
BOOL          valid = YES;
NSDictionary *p1    = @{@"Test":@"Example"};
NSDictionary *p = valid?p1:nil;


// oc/kw.m
#include <stdio.h>
#include <objc/Object.h>

@protocol Job
- do;
@end

@interface MyJob : Object<Job>
- do;
@end
@implementation MyJob
- do
{
    printf("Doing Job\n");

    return self;
}
@end

@interface JobExecutor : Object
- doWith:(id<Job>) job for:(int)count;
@end

@implementation JobExecutor
- doWith:(id<Job>)job for:(int)count
{
    for (int i = 0; i < count; ++i) {
        [job do];
    }

    return self;
}
@end


// oc/literals.m

NSDictionary *dictionary = @{@0:@"red", @1:@"green", @2:@"blue"};

NSArray      *array = @[@0, @1, @2, @YES, @'Z', @42U];

NSArray      *multilineArray = @[
    @0, @1, @2, @YES,
    @'Z', @42U
];

void main(int argc, const char *argv[]){
    // character literals.
    NSNumber *theLetterZ = @'Z';        // equivalent to [NSNumber numberWithChar:'Z']

    // integral literals.
    NSNumber *fortyTwo         = @42;   // equivalent to [NSNumber numberWithInt:42]
    NSNumber *fortyTwoUnsigned = @42U;  // equivalent to [NSNumber numberWithUnsignedInt:42U]
    NSNumber *fortyTwoLong     = @42L;  // equivalent to [NSNumber numberWithLong:42L]
    NSNumber *fortyTwoLongLong = @42LL; // equivalent to [NSNumber numberWithLongLong:42LL]

    // floating point literals.
    NSNumber *piFloat  = @3.141592654F; // equivalent to [NSNumber numberWithFloat:3.141592654F]
    NSNumber *piDouble = @3.1415926535; // equivalent to [NSNumber numberWithDouble:3.1415926535]

    // BOOL literals.
    NSNumber *yesNumber = @YES;         // equivalent to [NSNumber numberWithBool:YES]
    NSNumber *noNumber  = @NO;          // equivalent to [NSNumber numberWithBool:NO]

    #ifdef __cplusplus
    NSNumber *trueNumber  = @true;      // equivalent to [NSNumber numberWithBool:(BOOL)true]
    NSNumber *falseNumber = @false;     // equivalent to [NSNumber numberWithBool:(BOOL)false]
    #endif /* ifdef __cplusplus */
}

// oc/main.m
#import <stdio.h>
#import "Fraction.h"

int main(int argc, const char *argv[]){
    // create a new instance
    Fraction *frac = [[Fraction alloc] init];

    // set the values
    [frac setNumerator:1];
    [frac setDenominator:3];

    // print it
    printf("The fraction is: ");
    [frac print];
    printf("\n");

    // free memory
    [frac release];

    return 0;
}

// oc/misc.m
- (id)init {
    GLfloat wc[3][3] = {{ 0.6, 0.6, 0.0 }, { 1.0, 0.7, 0.1 }, { 0.5, 0.7, 0.2}, };
    GLfloat cc[3][3] = {{ 0.0, 0.0, 0.6 }, { 0.3, 0.1, 0.5 }, { 0.0, 0.0, 0.5}, };
    GLfloat sc[3] = {0.75, 0.75, 0.75};

    return [self initWithWarmColors:(float*)&wc coolColors:(float*)&cc
            surfaceColor:sc enableTexturing:NO enableSpecular:YES
            enableQuakeDisruptor:NO];

    [NSException raise:NSInternalInconsistency
     format:@"An internal inconsistency was raised"];

    for (i = 0; i <[a count]; i++) {
        [thePerson setAmount:(1.5 * 17) forKey:@"overtime"];
        [screen showtext:x:y:@"Message"];
    }
}

*outError = [NSError errorWithDomain:NSCocoaErrorDomain
             code:0
             userInfo:[NSDictionary
                       dictionaryWithObject:@"Some Description"
                       forKey:NSLocalizedDescriptionKey]];


// oc/more_blocks.m
int (^ myBlock)(int) = ^(int num){ return num * multiplier; };
// for comparison
int (*fcnptr)(int);

int d = i % 10;
repeat(10, ^{ putc('0' + d); });


void (^ block)(void);
typedef void (^vstr_t)(char*);
typedef void (^workBlk_t)(void);

void AllLinesInFile(char *f, vstr_t block){
    FILE *fp = fopen(f, "r");
    if (!fp) {
        return;
    }
    char line[1024];
    while (fgets(line, 1024, fp)) {
        block(line);
    }
    fclose(fp);
}

@implementation NSArray (WWDC)
- (NSArray*)map:(id (^)(id))xform {
    id result = [NSMutableArray array];
    for (id elem in self) {
        [result addObject:xform(elem)];
    }

    return result;
}

- (NSArray*)collect:(BOOL (^)(id))predicate {
    id result = [NSMutableArray array];
    for (id elem in self) {
        if (predicate(elem)) {
            [result addObject:elem];
        }
    }

    return result;
}

// corner case: block literal in use with return type
id longLines = [allLines collect:^BOOL (id item){
    return [item length] > 20;
}];

// corner case: block literal in use with return type
id longLines = [allLines collect:^BOOL* (id item){
    return [item length] > 20;
}];

@end

// 1. block literal: ^{ ... };
// 2. block declaration: return_t (^name) (int arg1, int arg2, ...) NB: return_t is optional and name is also optional
// 3. block inline call ^ return_t (int arg) { ... }; NB: return_t is optional


// oc/more_blocks_2.m
// Test a case where blocks wrapped by parentheses were causing the parser to crash
int (^ myBlock)(int) = (^(int num){
    return num * multiplier;
});

dispatch_async(thread, (^{
    dispatch_async(thread, ^{
        dispatch_async(thread, ^{
            NSLog(@"Hooray for dispatch_async!");
        });
    });
}));

// Example of a unit test using Kiwi
beforeAll(^{
    NSString *serviceURL = [NSURL URLWithString:@"http://TEST_URL"];
    NSLog(serviceURL);
});


// oc/msg.m
[obj doSomething:0 withArgs:@""];
[@"" doSomething:0 withArgs:@""];
NSString *result = (id)[obj arg:param value:3];


// oc/msg_align.m

BOOL immediatlyReady = [self ensureResource:mutableResources[0]
                        existsInDirectoryAtPath:mutablePaths[0]
                        queueMode:mode
                        completionHandler:completionHandler
                        errorHandler:errorHandler];

[myObject doFooWith1:arg1 name1:arg2  // some lines with >1 arg
 error1:arg3];

[myObject doFooWith2:arg4
 name2:arg5 error2:arg6];

[myObject doFooWith3:arg7
 name3:arg8           // aligning keywords instead of colons
 error3:arg9];

[myObject doithereguysA:argA
 reallylongargname:argB another:argC];

int foo(){
    [UIView transitionWithView:self.window
     duration:0.3
     options:UIViewAnimationOptionTransitionCrossDissolve
     animations:^{
        BOOL oldState = [UIView areAnimationsEnabled];
        [UIView setAnimationsEnabled:NO];
        self.window.rootViewController = self.viewController;
        [UIView setAnimationsEnabled:oldState];
    }
     completion:^(BOOL finished){
        BOOL foo;
    }];
}

int foo2(){
    [UIView transitionWithView:self.window duration:0.3 options:UIViewAnimationOptionTransitionCrossDissolve animations:^{
        BOOL oldState = [UIView areAnimationsEnabled];
        [UIView setAnimationsEnabled:NO];
        self.window.rootViewController = self.viewController;
        [UIView setAnimationsEnabled:oldState];
    }
     completion:^(BOOL finished){
        BOOL foo;
    }];

    [[HRNewsService sharedInstance] registerPushToken:deviceToken success:^{
        DLog(@"Finished Registering Push Token!");
        self.notificationsEnabled = YES;
    } fail:nil];
}

// oc/ns_enum.m
// The semicolons at the end of these declarations are not superfluous.
typedef NS_ENUM (NSUInteger, MyEnum){MyValue1, MyValue2, MyValue3};
typedef NS_OPTIONS (NSUInteger, MyBitmask){MyBit1, MyBit2, MyBit3};

// NS_ENUM specifies the type and name of the enum.
typedef enum {
    MyValue1,
    MyValue2,
    MyValue3
} MyEnum;
typedef NS_ENUM (NSUInteger, MyEnum){
    MyValue1,
    MyValue2,
    MyValue3
};

// NS_OPTIONS is equivalent to NS_ENUM, but semantically used for bitmask enums.
typedef enum {
    MyBit1                              = (1u << 0),
    MyBit2Longer                        = (1u << 1),
    MyBit3ThatIsConsiderablyMoreVerbose = (1u << 2)
} MyBitmask;
typedef NS_OPTIONS (NSUInteger, MyBitmask){
    MyBit1                              = (1u << 0),
    MyBit2Longer                        = (1u << 1),
    MyBit3ThatIsConsiderablyMoreVerbose = (1u << 2)
};


// oc/oc-split.m
[self findstart:&startBarcode end:&endBarcode forLine:greenScalePixels derivative:greenDerivative centerAt:xAxisCenterPoint min:&minValue max:&maxValue];

[self findstart:&startBarcode
 end:&endBarcode
 forLine:greenScalePixels
 derivative:greenDerivative
 centerAt:xAxisCenterPoint
 min:&minValue
 max:&maxValue];


// oc/oc_cond_colon.m
[self.vendorID_TextField setStringValue:string?string:@""];

x = [NSString str:path];
x = [NSString strFormat:@"Data/%s", path];
x = path[0] == '/'?path:"abc";
x = path[0] == '/'?[NSString str:path]:[NSString strFormat:@"Data/%s", path];

id<MTLBuffer> buf = data?[metal::g_Device newBufferWithBytes:data length:len options:MTLResourceOptionCPUCacheModeDefault]
                    :[metal::g_Device newBufferWithLength:len options:MTLResourceOptionCPUCacheModeDefault];


// oc/properties.m
@interface UCTestClass ()

@property(nonatomic, strong, null_unspecified, readonly) NSString                                              *test1;
@property(strong, readonly, nonatomic, nullable) NSString                                                      *test2;
@property(strong, readonly, getter = test2Getter, nonatomic, nonnull) NSString                                 *test3;
@property(strong, readonly, getter = test2Getter, nonatomic, setter = test2Setter :, null_resettable) NSString *test4;

@end


// oc/protocol.m

NSAssert([self.delegate conformsToProtocol:@protocol(UISearchBarDelegate)], @"Some Error.");

Protocol *counter = @protocol(ReferenceCounting);

@protocol ReferenceCounting

- setRefCount:(int)count;

- (int)refCount;

- incrementCount;

- decrementCount;

@end

@interface Formatter : NSObject < Formatting, Prettifying >

@end

if ([receiver conformsTo:@protocol(ReferenceCounting)]) {
    [receiver incrementCount];
}

@protocol B;

@protocol A
- Foo:(id <B>)anObject;
@end


// oc/real_world_file.m
/*
   File: ATColorTableController.m
   Abstract: A controller used by the ATImageTextCell to edit the color property. It is implemented in an abstract enough way to be used by a class other than the cell.

   Version: 1.0

   Disclaimer: IMPORTANT:  This Apple software is supplied to you by Apple
   Inc. ("Apple") in consideration of your agreement to the following
   terms, and your use, installation, modification or redistribution of
   this Apple software constitutes acceptance of these terms.  If you do
   not agree with these terms, please do not use, install, modify or
   redistribute this Apple software.

   In consideration of your agreement to abide by the following terms, and
   subject to these terms, Apple grants you a personal, non-exclusive
   license, under Apple's copyrights in this original Apple software (the
   "Apple Software"), to use, reproduce, modify and redistribute the Apple
   Software, with or without modifications, in source and/or binary forms;
   provided that if you redistribute the Apple Software in its entirety and
   without modifications, you must retain this notice and the following
   text and disclaimers in all such redistributions of the Apple Software.
   Neither the name, trademarks, service marks or logos of Apple Inc. may
   be used to endorse or promote products derived from the Apple Software
   without specific prior written permission from Apple.  Except as
   expressly stated in this notice, no other rights or licenses, express or
   implied, are granted by Apple herein, including but not limited to any
   patent rights that may be infringed by your derivative works or by other
   works in which the Apple Software may be incorporated.

   The Apple Software is provided by Apple on an "AS IS" basis.  APPLE
   MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION
   THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS
   FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND
   OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS.

   IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL
   OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION,
   MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED
   AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE),
   STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.

   Copyright (C) 2009 Apple Inc. All Rights Reserved.

 */

#import "ATColorTableController.h"
#import "ATPopupWindow.h"

@implementation ATColorTableController

+ (ATColorTableController*)sharedColorTableController {
    static ATColorTableController *gSharedColorTableController = nil;
    if (gSharedColorTableController == nil) {
        gSharedColorTableController = [[[self class] alloc] initWithNibName:@"ColorTable" bundle:[NSBundle bundleForClass:[self class]]];
    }

    return gSharedColorTableController;
}

@synthesize delegate = _delegate;
@dynamic selectedColor, selectedColorName;

- (void)dealloc {
    [_colorList release];
    [_colorNames release];
    [_window release];
    [super dealloc];
}

- (void)loadView {
    [super loadView];
    _colorList  = [[NSColorList colorListNamed:@"Crayons"] retain];
    _colorNames = [[_colorList allKeys] retain];
    [_tableColorList setIntercellSpacing:NSMakeSize(3, 3)];
    [_tableColorList setTarget:self];
    [_tableColorList setAction:@selector(_tableViewAction:)];
}

- (NSColor*)selectedColor {
    NSString *name = [self selectedColorName];
    if (name != nil) {
        return [_colorList colorWithKey:name];
    } else {
        return nil;
    }
}

- (NSString*)selectedColorName {
    if ([_tableColorList selectedRow] != -1) {
        return [_colorNames objectAtIndex:[_tableColorList selectedRow]];
    } else {
        return nil;
    }
}

- (void)_selectColor:(NSColor*)color {
    // Search for that color in our list
    NSInteger row = 0;
    for (NSString *name in _colorNames) {
        NSColor *colorInList = [_colorList colorWithKey:name];
        if ([color isEqual:colorInList]) {
            break;
        }
        row++;
    }
    _updatingSelection = YES;
    if (row != -1) {
        [_tableColorList scrollRowToVisible:row];
        [_tableColorList selectRowIndexes:[NSIndexSet indexSetWithIndex:row] byExtendingSelection:NO];
    } else {
        [_tableColorList scrollRowToVisible:0];
        [_tableColorList selectRowIndexes:[NSIndexSet indexSet] byExtendingSelection:NO];
    }
    _updatingSelection = NO;
}

- (void)_createWindowIfNeeded {
    if (_window == nil) {
        NSRect viewFrame = self.view.frame;
        // Create and setup our window
        _window = [[ATPopupWindow alloc] initWithContentRect:viewFrame styleMask:NSBorderlessWindowMask backing:NSBackingStoreBuffered defer:NO];
        [_window setReleasedWhenClosed:NO];
        [_window setLevel:NSPopUpMenuWindowLevel];
        [_window setHasShadow:YES];
        [[_window contentView] addSubview:self.view];
        [_window makeFirstResponder:_tableColorList];

        // Make the window have a clear color and be non-opaque for our pop-up animation
        [_window setBackgroundColor:[NSColor clearColor]];
        [_window setOpaque:NO];
    }
}

- (void)_windowClosed:(NSNotification*)note {
    if (_eventMonitor) {
        [NSEvent removeMonitor:_eventMonitor];
        _eventMonitor = nil;
    }
    [[NSNotificationCenter defaultCenter] removeObserver:self name:NSWindowWillCloseNotification object:_window];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:NSApplicationDidResignActiveNotification object:nil];
}

- (void)_closeAndSendAction:(BOOL)sendAction {
    [_window close];
    if (sendAction) {
        if ([self.delegate respondsToSelector:@selector(colorTableController:didChooseColor:named:)]) {
            [self.delegate colorTableController:self didChooseColor:self.selectedColor named:self.selectedColorName];
        }
    } else {
        if ([self.delegate respondsToSelector:@selector(didCancelColorTableController:)]) {
            [self.delegate didCancelColorTableController:self];
        }
    }
}

- (void)_windowShouldClose:(NSNotification*)note {
    [self _closeAndSendAction:NO];
}

- (void)editColor:(NSColor*)color locatedAtScreenRect:(NSRect)rect {
    [self _createWindowIfNeeded];
    [self _selectColor:color];
    NSPoint origin      = rect.origin;
    NSRect  windowFrame = [_window frame];
    // The origin is the lower left; subtract the window's height
    origin.y -= NSHeight(windowFrame);
    // Center the popup window under the rect
    origin.y += floor(NSHeight(rect) / 3.0);
    origin.x -= floor(NSWidth(windowFrame) / 2.0);
    origin.x += floor(NSWidth(rect) / 2.0);

    [_window setFrameOrigin:origin];
    [_window popup];

    // Add some watches on the window and application
    [[NSNotificationCenter defaultCenter] addObserver:self
     selector:@selector(_windowClosed:)
     name:NSWindowWillCloseNotification
     object:_window];

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(_windowShouldClose:)name:NSApplicationDidResignActiveNotification object:nil];

    // Start watching events to figure out when to close the window
    NSAssert(_eventMonitor == nil, @"_eventMonitor should not be created yet");
    _eventMonitor = [NSEvent addLocalMonitorForEventsMatchingMask:NSLeftMouseDownMask | NSRightMouseDownMask | NSOtherMouseDownMask | NSKeyDownMask handler:^(NSEvent *incomingEvent){
        NSEvent *result = incomingEvent;
        NSWindow *targetWindowForEvent = [incomingEvent window];
        if (targetWindowForEvent != _window) {
            [self _closeAndSendAction:NO];
        } else if ([incomingEvent type] == NSKeyDown) {
            if ([incomingEvent keyCode] == 53) {
                // Escape
                [self _closeAndSendAction:NO];
                result = nil; // Don't process the event
            } else if ([incomingEvent keyCode] == 36) {
                // Enter
                [self _closeAndSendAction:YES];
                result = nil;
            }
        }

        return result;
    }];
} /* editColor */

- (NSInteger)numberOfRowsInTableView:(NSTableView*)tableView {
    return _colorNames.count;
}

- (id)tableView:(NSTableView*)tableView objectValueForTableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row {
    return [_colorNames objectAtIndex:row];
}

- (void)tableView:(NSTableView*)tableView willDisplayCell:(id)cell forTableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row {
    NSColor *color = [_colorList colorWithKey:[_colorNames objectAtIndex:row]];
    [cell setColor:color];
}

- (void)_tableViewAction:(id)sender {
    [self _closeAndSendAction:YES];
}

@end


// oc/receiver.m
#import <Cocoa/Cocoa.h>

@implementation MyDocument

- (NSString*)appPath {
    [ AClass AFunc ];

    return [NSSearchPathForDirectoriesInDomains (NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
}

@end


// oc/return_type.m
#import <Foundation/NSObject.h>
#import <stdio.h>

@interface Fraction : NSObject {
    int numerator;
    int denominator;
}
- (void)print;
- (void)setNumerator:(int)d;
- (void)setDenominator:(int)d;
- (int)numerator;
- (int)denominator;
- (void)setNumDen:(int)n:(int)d;
@end

@implementation Fraction
- (void)print {
    printf("%i/%i", numerator, denominator);
}

- (void)setNumerator:(int)n {
    numerator = n;
}

- (void)setDenominator:(int)d {
    denominator = d;
}

- (int)denominator {
    return(denominator);
}

- (int)numerator {
    return(numerator);
}

@end


// oc/selector.m
@selector(methodNameWithArg:);
@selector(methodNameNoArg);
@selector(methodNameArg1:arg2:);

NSArray *sortedTZs = [ [ NSTimeZone knownTimeZoneNames ]
                       sortedArrayUsingSelector:@selector(compare:) ];


// oc/sort_import.m
// should be ddd, eee, fff
#import "ddd"
#import "fff"
#import "eee"

// should be aaa, ccc
#import "ccc"
#import "aaa"
// should be just bbb
#import "bbb"


// oc/string.m

- (void)moreScannedData:(Image*)img from:(int)start to:(int)stop;
- (void)moreScannedData:(Image*)img from:(int)start to:(int)stop;

public bool Enabled
{
    NSString *whatever = @"some lovely text, the fox and co";

    a = (enderedImage->h - toplines - bottomlines);
}


// oc/ternary.m
NSString *str  = (otherString?:@"this is the placeholder");
NSString *str2 = (str?otherString:@"this is the other placeholder");
NSString *str3 = str?[[NSString alloc] initWithString:str]:@"this is the third placeholder";
id        str4 = str?[self methodWithParameter1:@{@"bla":({[self anotherMethod:@{@"id":@1}]; })}
                      andParameter2:@{@"dict_key":@{@"nested_dict_key_1":@(1), @"nested_dict_key_2":@"colon:in:string"}}]:[self anotherMethod:str?@1:@2];
