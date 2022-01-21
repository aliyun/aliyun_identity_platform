//
//  AliyunIdentityVerifyCode.h
//  AliyunIdentityPlatform
//
//  Created by nansong.zxc on 2020/7/24.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#ifndef AliyunIdentityVerifyCode_h
#define AliyunIdentityVerifyCode_h

/** 客户端对外错误码 */
typedef NS_ENUM(NSUInteger, AliyunIdentityBizCode) {
    AliyunBizCodeVerifySuccess = 1000,//认证成功
    AliyunBizCodeVerifyFailed = 1001,//认证失败
    AliyunBizCodeSystemException = 1002,//系统错误❌
    AliyunBizCodeInitFailed = 1003,//初始化失败
    AliyunBizCodeCameraFailed = 1004,//摄像头异常
    AliyunBizCodeNoneNetwork = 1005,//网络错误
    AliyunBizCodeQuitByUser = 1006,//用户操作中断
    AliyunBizCodeCertifyIdInvalid = 1007,//CertifyID无效或已过期
    AliyunBizCodeIDCardExpired = 1008,//身份证已过期
//    AliyunBizCodeNoCameraAuth = 1009,//无相机授权
//    AliyunBizCodeFailedOverLimit = 10010,//识别失败次数超限
//    AliyunBizCodeUploadFaild = 10011,//图片上传失败
//    AliyunBizCodeIDCardNumberIllegal = 10012,//身份证号码不合法
    AliyunBizCodeDateException = 1009,//客户端系统时间异常
};
/** SDK内部错误码 */
#define CODE_SYSTEM_BUSY @"CODE_SYSTEM_BUSY"
#define CODE_CERTIFY_ID_INVALID @"CODE_CERTIFY_ID_INVALID"
#define CODE_SYSTEM_EXC @"CODE_SYSTEM_EXC" //内部异常
#define CODE_INIT_ERROR @"CODE_INIT_ERROR"//SDK初始化失败
#define CODE_USER_BACK @"CODE_USER_BACK"//用户主动中断流程
#define CODE_OVER_TIME @"CODE_OVER_TIME"//用户操作超时
#define CODE_ERROR_CAMERA_NO_FOUND @"CODE_ERROR_CAMERA_NO_FOUND"//无法发现摄像头
#define CODE_ERROR_CAMERA_OPEN_ERROR @"CODE_ERROR_CAMERA_OPEN_ERROR"//无法打开摄像头
#define CODE_UNSUPPORTED_DEVICE @"CODE_UNSUPPORTED_DEVICE"//当前设备不支持
#define CODE_OS_VERSION_LOW @"CODE_OS_VERSION_LOW"//当前系统不支持刷脸
#define CODE_NETWORK_TIMEOUT @"CODE_NETWORK_TIMEOUT"//网络超时
#define CODE_NETWORK_ERROR @"CODE_NETWORK_ERROR"//网络异常
#define CODE_NO_CAMERA_PERMISSION @"CODE_NO_CAMERA_PERMISSION"//无摄像头权限
#define CODE_OVER_AUTH_TIME @"CODE_OVER_AUTH_TIME"//身份证已过期
#define CODE_FRONT_OCR_FAILED @"CODE_FRONT_OCR_FAILED"//身份证人像面识别失败
#define CODE_BACK_OCR_FAILED @"CODE_BACK_OCR_FAILED"//身份证国徽面面识别失败
#define CODE_OCR_SUCCESS @"CODE_OCR_SUCCESS"//身份证OCR成功
#define CODE_LIVENESS_SUCCESS @"CODE_LIVENESS_SUCCESS"//活体检测成功
#define CODE_VERIFY_SUCCESS @"CODE_VERIFY_SUCCESS"//认证成功
#define CODE_VERIFY_FAIL @"CODE_VERIFY_FAIL"//认证失败
#define CODE_OSS_UPLOAD_ERROR @"CODE_OSS_UPLOAD_ERROR"//oss文件上传失败
#define CODE_SDK_MAX_TIMEOUT @"CODE_SDK_MAX_TIMEOUT"//全局超时15分钟
#define CODE_FRONT_BANK_FAILED @"CODE_FRONT_BANK_FAILED"//银行卡识别失败
#define CODE_HTTP_RES_INVALID @"CODE_HTTP_RES_INVALID" //服务端数据返回异常
#define CODE_CLIENT_TIME_INVALID @"CODE_CLIENT_TIME_INVALID" //客户端时间戳异常

#endif /* AliyunIdentityVerifyCode_h */
