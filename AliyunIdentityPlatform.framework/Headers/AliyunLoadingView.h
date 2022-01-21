//
//  AliyunLoadingView.h
//  AliyunIdentityPlatform
//
//  Created by nansong.zxc on 2020/7/25.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AliyunLoadingView : UIView

/**
 * 调整Loading位置
 */
- (void)initUI:(UIColor *)backgroundColor withTextColor:(UIColor *) textColor withRoundUIMode:(BOOL) isRoundFace;

/**
 * 设置加载文案
 */
- (void)setLoadingText:(NSString *)loadingText;

/**
 * 开启Loading动画
 */
- (void)startLoading;

/**
 * 关闭Loading动画
 */
- (void)stopLoading;
@end

NS_ASSUME_NONNULL_END
