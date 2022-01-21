//
//  XMediaOptions.h
//  XMedia
//
//  Created by Cloud on 2017/9/6.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 输入可选参数中ROI的key，value为CGRect，存于NSValue对象中
extern NSString *const kXMediaOptionsROIKey;
/// 输入可选参数中算法所需model的key，value为字符串
extern NSString *const kXMediaOptionsModelPathKey;
/// 输入可选参数中算法所需model文件对应Id的key，value为字符串
extern NSString *const kXMediaOptionsModelIdKey;
/// 输入可选参数中算法结果过滤的key，value为字典，字典的key为对应的算法，value为对应的filter
extern NSString *const kXMediaOptionsFilterKey;
/// 输入可选参数中模型类型key，value为XMediaMode值，
extern NSString *const kXMediaOptionsModeKey;
/// 输入可选参数中模型类型key，value为XMediaMode值，
extern NSString *const kXMediaOptionsModeTypeKey;
///输入可选参数中额外增加的modelPath数组的key
extern NSString *const kXMediaOptionsExtraModelPathsKey;
///输入可选参数中额外增加的model类型数组的key
extern NSString *const kXMediaOptionsExtraModeTypesKey;

///输入可选参数中额外增加的算法是否降级的key
extern NSString *const kXMediaOptionsOptionDegradeKey;
///输入可选参数中 算法配置信息 key
extern NSString *const kXMediaOptionsAlgoConfigKey;
//算法处理中抖动检测阈值：0表示不做抖动检测，＞0 表示检测阈值
extern NSString *const kXMediaShakingThreshold;
//算法处理流程步长控制，单位秒
extern NSString *const kXMediaProcessTimeInterval;
//算法处理结果中是否输出处理成功当前帧图片
extern NSString *const kXMediaProcessFullPictureOutput;
//算法处理结果中是否输出处理成功当前帧目标区域的图片
extern NSString *const kXMediaProcessResultPictureOutput;
//算法处理结果中是否输出处理成功当前帧ROI区域的图片
extern NSString *const kXMediaProcessROIPictureOutput;
//log采样上报功能，主要在biz层做Functor串联逻辑时，可能不需要Functor内部的log上传数据了
extern NSString *const kXMediaRemoteLogSampling;
//算法处理置信度阈值[0~1],值越大，检测为微笑条件越严格
extern NSString *const kXMediaAlgoConfThreshold;
//xNN初始化config
extern NSString *const kXMediaXNNConfig;
//图像旋转角度
extern NSString *const kXMediaImageRotation;
//自适应控制-CPU
extern NSString *const kXMediaAdaptiveCpu;
//自适应控制-算法执行最小时间间隔
extern NSString *const kXMediaAdaptiveMinInterval;
//自适应控制-算法执行最大时间间隔
extern NSString *const kXMediaAdaptiveMaxInterval;
//算法档数：0/1/2
extern NSString *const kXMediaAlgoMode;
//通用检测目标数组
extern NSString *const kXMediaDetectTargets;
//支持最大人脸检测个数
extern NSString *const kXMediaMaxFaceDetectNum;
//人脸识别性别阈值
extern NSString *const kXMediaZFaceGenderThreshold;
//前置摄像头
extern NSString *const kXMediaFrontCamera;
//人脸检测类型：FaceDetectTypeDefault:-1;FaceDetectTypeMouth:0;FaceDetectTypeEye:1
extern NSString *const kXMediaFaceDetectType;
//最大人脸识别个数
extern NSString *const kXMediaFaceDetectMaxNum;
//是否检测相关3D维度信息
extern NSString *const kXMediaFaceDetectFix3D;

/// 数据源
typedef NS_ENUM(NSUInteger, XMediaSource) {
    XMediaSourceImage     = 0,  /// 单帧图像
    XMediaSourceFrame     = 1,  /// 摄像头采集帧
    XMediaSourceData      = 2,  /// 数据
};

/// 算法模式，可以使用组合的方式，先detect再track
typedef NS_OPTIONS(NSUInteger, XMediaMode) {
    XMediaModeDetect            = 1 << 0,  /// 检测算法
    XMediaModeClassify          = 1 << 1,  /// 分类算法
    XMediaModePredict           = 1 << 2,  /// 通用预测算法
    XMediaModeTrack             = 1 << 3,  /// 跟踪算法
//    XMediaModeOCR               = 1 << 4,  /// OCR算法
//    XMeidaModeOCREast           = 1 << 5,  /// OCR价签/VIN码/车牌
    XMediaModeBorderDetect      = 1 << 6,  /// 边框检测
//    XMediaModeCarDamageDetect   = 1 << 7,  /// 汽车定损
    XMeidaModeOCRNew            = 1 << 8,  /// OCR C++ 流程
};

/// 模型类型，caffe/TfLite
typedef NS_ENUM(NSUInteger, XMediaModeType) {
    XMediaModeTypeCaffe     = 0,    ///caffe
    XMediaModeTypeTfLite    = 1,    ///TesorflowLite
};

typedef NS_ENUM(NSUInteger, XMediaFacialExpressionType) {
    XMediaFacialExpressionSmile,            //微笑
    XMediaFacialExpressionOpenMouth,        //张嘴
    XMediaFacialExpressionCloseEyes,        //闭眼
    XMediaFacialExpressionEyeball,          //眼球
    XMediaFacialExpressionFaceKeyPoints     //人脸关键点
};

#define   XMedia_Error_Param               (10001)        //输入参数有误
#define   XMedia_Error_UNSUPPORT           (10002)        //暂不支持该算法
#define   XMedia_Error_ENGINE              (10003)        //引擎内部错误
#define   XMedia_Error_BUSYING             (10005)        //算法处理忙
