//
//  UIImage+APMResize.h
//  APMUtils
//
//  Created by feihu on 2020/12/2.
//  Copyright © 2020 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (APMResize)

- (UIImage *)apm_resize:(CGSize)targetSize;

@end

NS_ASSUME_NONNULL_END
