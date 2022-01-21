//
//  XMediaBaseFunctor.h
//  XMedia
//
//  Created by tao zeng on 2019/1/7.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XMediaResult.h"

@class XNNWrapper;
@interface XMediaBaseFunctor : NSObject
@property (nonatomic, strong) NSString *bizId;              //业务id
@property (nonatomic, strong) NSString *modelId;            //模型id
@property (nonatomic, assign) CGFloat remoteLogSampling;    //log上报采样率
@property (nonatomic, assign) CFTimeInterval initCostTime;  //引擎初始化耗时
@property (nonatomic, assign) BOOL isBusy;                  //算法处理中
@property (nonatomic, assign) float procTimeInterval;       //算法处理时长
@property (nonatomic, strong) NSString *xnnConfigStr;       //xNN初始化配置
@property (nonatomic, assign) float adaptiveCpu;            //自适应控制，目标cpu
@property (nonatomic, assign) float adaptiveMinInterval;    //自适应控制，算法执行最小时间间隔
@property (nonatomic, assign) float adaptiveMaxInterval;    //自适应控制，算法执行最大时间间隔

/**
 image2view转换回调
 */
@property (nonatomic, weak) id<XMediaResultTransformDelegate> transDelegate;

/**
 *  功能是否支持
 */
+ (BOOL)isSupported;

/**
 *  功能是否支持,不支持则返回错误XMediaResult
 */
- (XMediaResult *)engineUnsupport;

/**
 *  Functor初始化，目前classify/detect/predict functor有继承此方法初始化引擎
 *
 *  @param bizId 业务标识
 *  @param modelId 模型文件id
 *  @param options 扩展字段
 */
- (instancetype)initWithBizId:(NSString *)bizId
                      modelId:(NSString *)modelId
                      options:(NSDictionary *)options;

/**
 *  根据上报采样率参数，检测是否需要上报
 */
- (BOOL)shouldRemoteLog;

/**
 *  根据业务设置的算法处理间隔，判断是否还需要等待
 */
- (BOOL)shouldWaitWithTimeInterval;

/**
 *  检查模型路径是否存在
 */
- (BOOL)checkModelPath:(NSString *)modelPath;

@end
