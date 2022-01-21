//
//  UIViewController+Aliyun.h
//  AliyunIdentityUtils
//
//  Created by nansong.zxc on 2020/7/27.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^AliyunDismissBlock)(void);
@interface UIViewController ()
/**
 * 只有一个确定按钮的Alert提示框
 */
- (void)aliyunAlertWithTitle:(NSString *)title
               message:(NSString *)message
          confirmTitle:(NSString *)confirmTitle
               handler:(void(^)(void))handler;

/**
 * 左边取消 右边确定的Alert提示框
 */
- (void)aliyunAlertWithTitle:(NSString *)title
               message:(NSString *)message
           cancelTitle:(NSString *)cancelTitle
          confirmTitle:(NSString *)confirmTitle
                cancel:(void(^)(void))cancel confirm:(void(^)(void))confirm;

/**
 * 返回到顶层页面
 */
- (void)aliyunDismissToController:(UIViewController *) dstViewController completion:(AliyunDismissBlock) complete;
//- (void)aliyunDismissToController:(UIViewController *) dstViewController;

@end

NS_ASSUME_NONNULL_END
