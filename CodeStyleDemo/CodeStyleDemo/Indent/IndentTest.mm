//
//  IndentTest.m
//  CodeStyleDemo
//
//  Created by wangchao9 on 2017/5/15.
//  Copyright © 2017年 wangchao9. All rights reserved.
//

#import "IndentTest.h"
#import <UIKit/UIKit.h>

// # Whether to indent strings broken by '\' so that they line up
NSString* multiLineText = @"1111111111" \
                          "111111111111111111";
NSString* multiLineText2 = @"111111111111111\
11111111111111111";

NSString*xmlText = @"\
<html>\
    <head>\
    <title>Test XML</title>\
    </head>\
<body>\
    Hello\
<div id=\"some\">\
<label>1892</label>\
</div>\
</body>\
</html>\
";

#define join(a, b) join_base(a, b)
#define join_base(a, b) a ## b

#define str(...) str_base(__VA_ARGS__)
#define str_base(...) #__VA_ARGS__

#define _Q(...) @ #__VA_ARGS__
NSString*xmlText2 = _Q(
    <html>
    <head>
    <title>Test XML</title>
    </head>
    <body>
    Hello
    <div id="some">
    <label>1892</label>
    </div>
    </body>
    </html>
    );

// indent_brace
void test(){
    int i = 0;
}


// # Indent based on the size of the brace parent, i.e. 'if' => 3 spaces, 'for' => 4 spaces, etc.
void indentBasedOnTheSizeOfTheBraceParent(){
    if (0 == 0 ) {
        NSLog(@"");
    }

    for (int i = 0; i < 100; i++) {
        NSLog(@"");
    }
}

// # Indent based on the paren open instead of the brace open in '({\n', default is to indent by brace.
void indentBasedOnTheParenOpen(){
    char x[] = {1,2,3,
                4,5,6};

}



//# False=treat 'else\nif' as 'else if' for indenting purposes
//# True=indent the 'if' one level

void intentElseIf(){
    int i = 0;
    if (i == 0 ) {
        //
    }else if( i == 3) {

    }else {

    }

    if (i == 0 ) {
        //
    }else
        if( i == 3) {

        }else {

        }
}
// # Amount to indent variable declarations after a open brace. neg=relative, pos=absolute
void indent_var_def_blk(){
    int i = 0;
    double d = 0;
    char c = 0;
    char* x = NULL;
}
// # True:  indent continued function call parameters one indent level
// # False: align parameters under the open paren
void tooManyArguments1(int arg1, double arg2,
    char arg3, long arg4);
void tooManyArguments2(
    int arg1, double arg2,
    char arg3, long arg4);

void tooManyArguments1(int arg1, double arg2,
    char arg3, long arg4){

}

void tooManyArguments2(
    int arg1, double arg2,
    char arg3, long arg4){

}

void switchFunc(){
    int i = 0;
    switch (i) {
    case 1: {
        switch (i) {
        case 1:
            break;
        default:
            break;
        }
    }
    break;
    default:
        break;
    }


}

void callTooManyArgeuments(){
    tooManyArguments1(1, 2,
        3, 4);
    tooManyArguments2(
        1, 2,
        3, 4);
}

@interface TestBlockHost : NSObject

@end

typedef void (^TestBlock)(NSString* name, NSObject*from, UIView* view);
@implementation TestBlockHost

- (void)fetchWithURL:(NSString*)url progress:(TestBlock)progress completion:(TestBlock)completion {
    progress(@"progress", @"wan", nil);
    completion(@"progress", @"wan", nil);
}

@end

@implementation IndentTest
- (instancetype)init
{
    self = [super init];
    if (self) {
        NSLog(@"%@\n %@", xmlText, xmlText2);
    }
    return self;
}

- (void)test {
    NSString* url = @"";
    UIView* view = [UIView new];

    [UIView animateKeyframesWithDuration:1 delay:1 options:0 animations:^{
        int i = 0;

        [[[TestBlockHost alloc] init] fetchWithURL:url progress:^(NSString *name, NSObject *from, UIView *view) {

        } completion:^(NSString *name, NSObject *from, UIView *view) {

        }];

        switch (i) {
        case 1:
            [[[TestBlockHost alloc] init] fetchWithURL:url progress:^(NSString *name, NSObject *from, UIView *view) {

            } completion:^(NSString *name, NSObject *from, UIView *view) {

            }];
            break;
        default:
            break;
        }
    } completion:^(BOOL finished) {
        if (finished) {

        }
    }];

    [[[TestBlockHost alloc] init] fetchWithURL:url progress:^(NSString *name, NSObject *from, UIView *view) {

    } completion:^(NSString *name, NSObject *from, UIView *view) {

    }];
}
@end
