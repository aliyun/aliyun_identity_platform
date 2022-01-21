//
//  AliyunIdentityUtils.h
//  AliyunIdentityUtils
//
//  Created by nansong.zxc on 2020/7/24.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#ifndef AliyunIdentityUtils_h
#define AliyunIdentityUtils_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UIView+Aliyun.h"
#import "NSArray+Aliyun.h"
#import "UIColor+Aliyun.h"
#import "NSDictionary+Aliyun.h"
#import "UIViewController+Aliyun.h"
#import "UIButton+Aliyun.h"

//! Project version number for AliyunIdentityUtils.
FOUNDATION_EXPORT double AliyunIdentityUtilsVersionNumber;

//! Project version string for AliyunIdentityUtils.
FOUNDATION_EXPORT const unsigned char AliyunIdentityUtilsVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <AliyunIdentityUtils/PublicHeader.h>

@interface AliyunIdentityUtils : NSObject
//获取当前App名称
+ (NSString *)appName;

//获取当前App版本号
+ (NSString *)appVersion;

//获取当前系统版本号
+ (NSString *)osVersion;

//获取设备版本号
+ (NSString*)deviceVersion;

//判断服务端返回数据是否有效
+ (BOOL)isNetworkResValid:(NSDictionary *)dic;

/**
 * json转dictionary
 */
+ (NSDictionary *)json2Dictionary:(NSString *)json;

/**
 * 旋转图像，让图像正立
 */
+ (UIImage *)fixTakenPhoto:(UIImage *)aImage;

/**
 * 对图片进行裁剪
 */
+ (UIImage *)cropImage:(UIImage *)srcImage withSrcRect:(CGRect) srcRect withDstRect:(CGRect) dstRect;

/**
 * 身份证日期校验
 */
+ (BOOL)isIdCardOutOfDate:(NSString *)endDate withNow:(NSString *)nowDate;

/**
 * 生成Oss上传需要的文件名
 */
+ (NSString *)genOssFileName:(NSString *) prefix withType:(NSString *)type whithExt:(NSString *)fileExt;

/**
 * 把图像压缩到指定大小, 可指定压缩质量
 */
+ (NSData *)scaleImage:(UIImage *)srcImage withMaxWidth:(CGFloat) maxWidth withQuality:(CGFloat) quality;
+ (UIImage *)scaleImage:(UIImage *)srcImage withMaxWidth:(CGFloat) maxWidth;

/**
 * 获取当时时间戳
 */
+ (long)systemCurrentMiliSeconds;
+ (long)systemCurrentSeconds;
@end

#endif
