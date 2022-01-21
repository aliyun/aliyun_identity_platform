//
//  AliyunIdentityPlatform.h
//  AliyunIdentityPlatform
//
//  Created by nansong.zxc on 2020/7/24.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#ifndef AliyunIdentityPlatform_header_
#define AliyunIdentityPlatform_header_

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AliyunIdentityVerifyRes.h"
#import "AliyunIdentityVerifyMode.h"
#import "AliyunIdentityVerifyCode.h"
#import "AliyunIdentityCom.h"
#import "AliyunNetEnv.h"
#import "AliyunNetwork.h"
#import "AliyunLoadingView.h"
#import "AliyunIdentityLogger.h"
#import "AliyunIdentityCenter.h"
#import "AliyunIdentityVerifyController.h"

//! Project version number for AliyunIdentityPlatform.
FOUNDATION_EXPORT double AliyunIdentityPlatformVersionNumber;

//! Project version string for AliyunIdentityPlatform.
FOUNDATION_EXPORT const unsigned char AliyunIdentityPlatformVersionString[];

//取值YES/NO
#define kIdentityParamKeyVideo @"kIdentityParamKeyVideo"
//取值为字符串
#define kIdentityParamKeyWaterMark @"kIdentityParamKeyWaterMark"
//取值YES/NO
#define kIdentityParamKeyShowResult @"kIdentityParamKeyShowResult"
//取值为字符串，如 #FF0000
#define kIdentityParamKeyNextButtonColor @"kIdentityParamKeyNextButtonColor"
//取值为整形，单位为秒，如30
#define kIdentityParamKeyScanMaxTime @"kIdentityParamKeyScanMaxTime"
//取值YES/NO
#define kIdentityParamKeyValidIdCardDate @"kIdentityParamKeyValidIdCardDate"
//取值YES/NO
#define kIdentityParamKeyIdCardFaceOnly @"kIdentityParamKeyIdCardFaceOnly"
//取值 SCAN/PHOTO
#define kIdentityParamKeyOcrMode @"kIdentityParamKeyOcrMode"
//取值YES/NO
#define kIdentityParamKeyOcrSelectPhoto @"kIdentityParamKeyOcrSelectPhoto"
//取值RectMode/RoundMode
#define kIdentityParamKeyUIMode @"kIdentityParamKeyUIMode"
//圆脸模式下，进度条颜色，如 #0xFF6A00 阿里橙
#define kIdentityParamKeyRoundProgressColor @"kIdentityParamKeyRoundProgressColor"
//主界面关闭按钮的位置参数
#define kIdentityParamKeyCloseButtonLayout @"kIdentityParamKeyCloseButtonLayout"

@interface AliyunIdentityPlatform : NSObject

#pragma mark - 客户对接API
/**
 * 单例模式，获取IdentityPlatform实例
 */
+ (AliyunIdentityPlatform *)sharedInstance;

/**
 * IdentityPlatform初始化，需要第一个被调用的函数
 */
- (void)install;

/**
 * IPv6版本install
 */
- (void)installIPv6;

/**
 * 获取服务端初始化需要的MetaInfo
 */
- (NSString*) getMetaInfo;

/**
 * 卡证核身启动认证流程
 * @param certifyId - 从服务端获取到的CertifyId
 * @param viewController - 用来展示SDK页面用的，会在这个Controller上present页面
 * @param extParams - 自定义扩展参数
 * @param verifyMode - 认证模式(身份证或者银行卡)
 * @param completeBlock - 认证完成回调
 */
- (void)verifyWithCertifyId:(NSString *)certifyId
  withCurrentViewController:(UIViewController *)viewController
              withExtParams:(NSDictionary *)extParams
             withVerifyMode:(AliyunIdentityMode) verifyMode
                   complete:(AliyunIdentityVerifyBlock)completeBlock;

/**
 * 增强版活体检测
 * @param certifyId - 从服务端获取到的CertifyId
 * @param viewController - 用来展示SDK页面用的，会在这个Controller上present页面
 * @param extParams - 自定义扩展参数
 * @param completeBlock - 完成回调
 */
- (void)faceDetectWithCertifyId:(NSString *)certifyId
      withCurrentViewController:(UIViewController *)viewController
                  withExtParams:(NSDictionary *)extParams
                       complete:(AliyunIdentityVerifyBlock)completeBlock;

/**
 * 增强版活体验证
 * @param certifyId - 从服务端获取到的CertifyId
 * @param viewController - 用来展示SDK页面用的，会在这个Controller上present页面
 * @param extParams - 自定义扩展参数
 * @param completeBlock - 完成回调
 */
- (void)faceCompareWithCertifyId:(NSString *)certifyId
       withCurrentViewController:(UIViewController *)viewController
                   withExtParams:(NSDictionary *)extParams
                        complete:(AliyunIdentityVerifyBlock)completeBlock;

/**
 * 增强版实人认证
 * @param certifyId - 从服务端获取到的CertifyId
 * @param viewController - 用来展示SDK页面用的，会在这个Controller上present页面
 * @param extParams - 自定义扩展参数
 * @param completeBlock - 完成回调
 */
- (void)faceVerifyWithCertifyId:(NSString *)certifyId
      withCurrentViewController:(UIViewController *)viewController
                   withExtParams:(NSDictionary *)extParams
                       complete:(AliyunIdentityVerifyBlock)completeBlock;
@end

#endif
