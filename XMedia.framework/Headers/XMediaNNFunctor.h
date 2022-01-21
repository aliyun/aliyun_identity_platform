//
//  XMediaCommonNNFunctor.h
//  XMedia
//
//  Created by tao zeng on 2020/9/29.
//  Copyright © 2020 Alipay. All rights reserved.
//

#import "XMediaBaseFunctor.h"

NS_ASSUME_NONNULL_BEGIN

/*支持所有通用NN处理(分类、检测、预测、OCR)*/

@interface XMediaNNFunctor : XMediaBaseFunctor

/**
 *  创建实例之前先调用当前机型是否支持此功能接口，isSupported(继承基类的类方法)
 */

/**
 *  XMediaCommonNNFunctor初始化
 *
 *  @param bizId 业务标识
 *  @param modelId 模型文件id
 *  @param modelPath 模型路径数组
 *  @param options 扩展字段,@{kXMediaRemoteLogSampling:@(0)}
 */
- (instancetype)initWithBizId:(NSString *)bizId
                      modelId:(NSString *)modelId
                    modelPath:(NSString *)modelPath
                      options:(NSDictionary *)options;

/**
 *  对相机帧进行NN处理
 *  @param cameraFrame 输入视频帧数据
 *  @param cameraOrientation 相机流方向
 *  @param frontCamera 是否前置摄像头
 *  @param options 扩展字段：@{kXMediaOptionsROIKey:@[@(0.1),@(0.25),@(0.8),@(0.5)]} // 归一化roi:[x,y,w,h]
 *
 *  @return 处理的结果
 */
- (XMediaResult *)processWithVideoFrame:(CVPixelBufferRef)cameraFrame
                      cameraOrientation:(AVCaptureVideoOrientation)cameraOrientation
                          isFrontCamera:(BOOL)frontCamera
                                options:(NSDictionary *)options;

/**
 *  对输入图片中的内容进行NN处理
 *
 *  @param image   输入图片
 *  @param options 扩展字段：@{kXMediaOptionsROIKey:@[@(0.1),@(0.25),@(0.8),@(0.5)]} // 归一化roi:[x,y,w,h]
 *
 *  @return 处理的结果
 */
- (XMediaResult *)processWithImage:(UIImage *)image options:(NSDictionary *)options;


@end

NS_ASSUME_NONNULL_END
