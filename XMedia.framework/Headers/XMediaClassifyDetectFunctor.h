//
//  XMediaClassifyDetectFunctor.h
//  XMedia
//
//  Created by tao zeng on 2019/3/26.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import "XMediaBaseFunctor.h"
#import "XMediaClassifyResult.h"
#import "XMediaDetectResult.h"

//边框检测
extern NSString *const kXMediaBorderDetect;

@interface XMediaClassifyDetectFunctor : XMediaBaseFunctor

@property (nonatomic, assign) int processImageWidth;     //模型内部算法处理的图像宽度,process接口处理后才有有效值
@property (nonatomic, assign) int processImageHeight;    //模型内部算法处理的图像高度,process接口处理后才有有效值

/**
 *  创建实例之前先调用当前机型是否支持此功能接口，isSupported(继承基类的类方法)
 */

/**
 *  XMediaClassifyDetectFunctor初始化
 *
 *  @param bizId 业务标识
 *  @param modelId 模型文件id
 *  @param modelPath 模型路径
 *  @param options 扩展字段,@{kXMediaRemoteLogSampling:@(0)}
 */
- (instancetype)initWithBizId:(NSString *)bizId
                      modelId:(NSString *)modelId
                    modelPath:(NSString *)modelPath
                      options:(NSDictionary *)options;

/**
 *  对相机帧进行分类
 *  @param options 扩展字段：@{kXMediaOptionsROIKey:@[@(0.1),@(0.25),@(0.8),@(0.5)]} // 归一化roi:[x,y,w,h]
 *
 *  @return 分类的结果
 */
- (XMediaClassifyResult *)classifyWithVideoFrame:(CVPixelBufferRef)cameraFrame
                                        options:(NSDictionary *)options;

/**
 *  对图像帧数据进行分类
 *
 *  @param baseBuffer   输入视频帧数据,如果是yuv格式，则为y数据buffer
 *  @param uvBuffer     输入视频帧,如果是yuv格式，则为uv数据buffer，否则填NULL
 *  @param width        输入视频帧宽度
 *  @param height       输入视频帧高度
 *  @param srcFormat    输入视频帧格式：0:nv12; 1:RGB; 2:RGBA; 3:BGRA; 4:BGR; 5:nv21; 6:gray
 *  @param clsFormat    进行分类的帧格式(模型训练时用的图像格式)：0:nv12; 1:RGB; 2:RGBA; 3:BGRA; 4:BGR; 5:nv21; 6:gray
 *  @param options 可选参数，支持的key为kXMediaOptionsROIKey
 *
 *  @return 分类的结果
 */
- (XMediaClassifyResult *)classifyWithBuffer:(unsigned char *)baseBuffer
                                   uvBuffer:(unsigned char *)uvBuffer
                                      width:(int)width
                                     height:(int)height
                                  srcFormat:(int)srcFormat
                                  clsFormat:(int)clsFormat
                                    options:(NSDictionary *)options;

/**
 *  对输入图片中的内容进行分类
 *
 *  @param image   输入图片
 *  @param options 扩展字段：@{kXMediaOptionsROIKey:@[@(0.1),@(0.25),@(0.8),@(0.5)]} // 归一化roi:[x,y,w,h]
 *
 *  @return 分类的结果
 */
- (XMediaClassifyResult *)classifyWithImage:(UIImage *)image options:(NSDictionary *)options;


/**
 *  对相机帧进行检测
 *  @param options 扩展字段：@{kXMediaOptionsROIKey:@[@(0.1),@(0.25),@(0.8),@(0.5)]} // 归一化roi:[x,y,w,h]
 *
 *  @return 分类的结果
 */
- (XMediaDetectResult *)detectWithVideoFrame:(CVPixelBufferRef)cameraFrame
                                     options:(NSDictionary *)options;

/**
 *  对图像帧数据进行检测
 *
 *  @param baseBuffer   输入视频帧数据,如果是yuv格式，则为y数据buffer
 *  @param uvBuffer     输入视频帧,如果是yuv格式，则为uv数据buffer，否则填NULL
 *  @param width        输入视频帧宽度
 *  @param height       输入视频帧高度
 *  @param srcFormat    输入视频帧格式：0:nv12; 1:RGB; 2:RGBA; 3:BGRA; 4:BGR; 5:nv21; 6:gray
 *  @param dtcFormat    进行检测的帧格式(模型训练时用的图像格式)：0:nv12; 1:RGB; 2:RGBA; 3:BGRA; 4:BGR; 5:nv21; 6:gray
 *  @param options 可选参数，支持的key为kXMediaOptionsROIKey
 *
 *  @return 检测的结果
 */
- (XMediaDetectResult *)detectWithBuffer:(unsigned char *)baseBuffer
                                uvBuffer:(unsigned char *)uvBuffer
                                   width:(int)width
                                  height:(int)height
                               srcFormat:(int)srcFormat
                               dtcFormat:(int)dtcFormat
                                 options:(NSDictionary *)options;

/**
 *  对输入图片中的内容进行检测
 *
 *  @param image   输入图片
 *  @param options 扩展字段：@{kXMediaOptionsROIKey:@[@(0.1),@(0.25),@(0.8),@(0.5)]} // 归一化roi:[x,y,w,h]
 *
 *  @return 检测的结果
 */
- (XMediaDetectResult *)detectWithImage:(UIImage *)image options:(NSDictionary *)options;

@end

