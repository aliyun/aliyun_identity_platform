//
//  AliyunIdentityCom.h
//  AliyunIdentityPlatform
//
//  Created by nansong.zxc on 2020/7/24.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#ifndef AliyunIdentityCom_h
#define AliyunIdentityCom_h

#pragma mark ----------日志定义--------------------
#define AliyunLog(...) \
    NSLog(__VA_ARGS__);

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#pragma mark ---------客户回调Block格式--------------
@class AliyunIdentityVerifyRes;
typedef void (^AliyunIdentityVerifyBlock)(AliyunIdentityVerifyRes *response);

#pragma mark ---------内部业务模块名称定义------------
#define IDENTITY_MODULE_OCR @"IDENTITY_MODULE_OCR"
#define IDENTITY_MODULE_FACE @"IDENTITY_MODULE_FACE"
#define IDENTITY_MODULE_VERIFY @"IDENTITY_MODULE_VERIFY"

#pragma mark ----------屏幕适配相关------------------
//以IPhone6为基准
#define ALIYUN_WIDTH 750.0
#define ALIYUN_HEIGHT 1334.0

#define ALIYUN_SCREEN_BOUNDS ([UIScreen mainScreen].bounds)
#define ALIYUN_SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define ALIYUN_SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)


#define ALIYUN_IPHONEX ([UIScreen mainScreen].bounds.size.height == 812 || [UIScreen mainScreen].bounds.size.height == 896)

#define ALIYUN_NO_NAV_HEIGHT  (ALIYUN_IPHONEX ? 24 : 0)
//#define ALIYUN_STATUSBAR_HEIGHT (ALIYUN_IPHONEX ? 44.f:20.f)
#define ALIYUN_STATUSBAR_HEIGHT (ALIYUN_IPHONEX ? 54.f:30.f)
#define ALIYUN_NAVBAR_HEIGHT (ALIYUN_IPHONEX ? 88.f : 64.f)
#define ALIYUN_TABBAR_HEIGHT (ALIYUN_IPHONEX ? 49.f+34.f : 49.f)

#pragma mark ----------资源Bundle相关----------------
//Platform
#define ALIYUN_PlatformBundlePath [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"AliyunIdentityPlatform.bundle"]
#define ALIYUN_PlatformImagePath [ALIYUN_PlatformBundlePath stringByAppendingPathComponent:@"images"]
#define ALIYUN_PLATFORM_IMAGE(imageName) [UIImage imageNamed:[ALIYUN_PlatformImagePath stringByAppendingPathComponent:[NSString stringWithFormat:@"%@",imageName]]]


//OCR
#define ALIYUN_OCRBundlePath [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"AliyunIdentityOCR.bundle"]
#define ALIYUN_OCRImagePath [ALIYUN_OCRBundlePath stringByAppendingPathComponent:@"images"]
#define ALIYUN_OCR_IMAGE(imageName) [UIImage imageNamed:[ALIYUN_OCRImagePath stringByAppendingPathComponent:[NSString stringWithFormat:@"%@",imageName]]]

//活体
#define ALIYUN_FaceBundlePath [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"AliyunIdentityFace.bundle"]
#define ALIYUN_FaceImagePath [ALIYUN_FaceBundlePath stringByAppendingPathComponent:@"images"]
#define ALIYUN_FACE_IMAGE(imageName) [UIImage imageNamed:[ALIYUN_FaceImagePath stringByAppendingPathComponent:[NSString stringWithFormat:@"%@",imageName]]]

#endif /* AliyunIdentityCom_h */
