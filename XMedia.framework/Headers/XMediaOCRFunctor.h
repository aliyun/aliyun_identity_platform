//
//  XMediaOCRFunctor.h
//  XMedia
//
//  Created by tao zeng on 2019/1/8.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import "XMediaBaseFunctor.h"
#import "XMediaOCRResult.h"

@interface XMediaOCRFunctor : XMediaBaseFunctor

/**
 *  创建实例之前先调用当前机型是否支持此功能接口，isSupported(继承基类的类方法)
 */

/**
 *  XMediaOCRFunctor初始化
 *
 *  @param bizId 业务标识
 *  @param modelId 模型文件id
 *  @param dtcModelPath 检测模型路径
 *  @param recModelPath 识别模型路径
 *  @param lexionPath 数据字典文件路径
 *  @param configPath ocr参数配置文件路径
 *  @param algoConfig ocr子算法串流程配置字段[可选参数，设nil，走默认配置参数]
 *  @param options 扩展字段，例如：@{kXMediaShakingThreshold:@(40),kXMediaProcessTimeInterval:@(0.5),kXMediaProcessFullPictureOutput:@(1),kXMediaRemoteLogSampling:@(0.2)}
 */
- (instancetype)initWithBizId:(NSString *)bizId
                      modelId:(NSString *)modelId
              detectModelPath:(NSString *)dtcModelPath
           recognizeModelPath:(NSString *)recModelPath
                   lexionPath:(NSString *)lexionPath
                   configPath:(NSString *)configPath
                   algoConfig:(NSDictionary *)algoConfig
                      options:(NSDictionary *)options;

/**
 *  视频帧实时ocr处理,内部独立线程完成整个识别流程，并异步回调返回结果
 *
 *  @param pixelBuffer 视频帧
 *  @param options 扩展字段：@{kXMediaOptionsROIKey:@[@(0.1),@(0.25),@(0.8),@(0.5)]} // 归一化roi:[x,y,w,h]
 *
 *  @return ocr处理结果
 */
- (XMediaOCRResult *)processWithVideoFrame:(CVPixelBufferRef)pixelBuffer options:(NSDictionary *)options;

/**
 *  视频帧实时ocr处理,同步处理并返回结果
 *
 *  @param baseBuffer   输入视频帧数据,如果是yuv格式，则为y数据buffer
 *  @param uvBuffer     输入视频帧,如果是yuv格式，则为uv数据buffer
 *  @param width        输入视频帧宽度
 *  @param height       输入视频帧高度
 *  @param format       输入视频帧格式：0:nv12; 1:RGB; 2:RGBA; 3:BGRA; 4:BGR; 5:nv21; 6:gray
 *  @param options      扩展字段：@{kXMediaOptionsROIKey:@[@(0.1),@(0.25),@(0.8),@(0.5)]} // 归一化roi:[x,y,w,h]
 *
 *  @return ocr处理结果
 */
- (XMediaOCRResult *)processWithBuffer:(unsigned char *)baseBuffer
                              uvBuffer:(unsigned char *)uvBuffer
                                 width:(int)width
                                height:(int)height
                                format:(int)format
                               options:(NSDictionary *)options;

/**
 *  图片ocr处理
 *
 *  @param image 待处理图片
 *  @param options 扩展字段：@{kXMediaOptionsROIKey:@[@(0.1),@(0.25),@(0.8),@(0.5)]} // 归一化roi:[x,y,w,h]
 *
 *  @return ocr处理结果
 */
- (XMediaOCRResult *)processWithImage:(UIImage *)image options:(NSDictionary *)options;

@end

