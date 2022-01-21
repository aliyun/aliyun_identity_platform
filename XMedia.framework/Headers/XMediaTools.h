//
//  XMediaTools.h
//  XMedia
//
//  Created by tao zeng on 2018/12/17.
//  Copyright © 2018 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

typedef NS_ENUM(NSUInteger, PixelFomat) {
    PixelFomat_Gray,
    PixelFomat_RGB,
    PixelFomat_RGBA,
    PixelFomat_BGRA,
    PixelFomat_BGR
};

@interface XMediaTools : NSObject

/**
 *  释放支持ARM64机型(iphone5s及以上机型)
 */
+ (BOOL)isARM64CpuSupported;

/**
 *  图像数据处理，resize/rotation/crop
 *
 *  @param baseBuffer      输入的图像数据
 *  @param uvBuffer        输入的图像数据
 *  @param srcFormat       输入的图像数据格式
 *  @param srcImgWidth     输入的图像宽度
 *  @param srcImgHeight    输入的图像高度
 *  @param roiRect         待处理视频帧区域
 *  @param rotation         图片旋转, support 0,90,180,270
 *  @param padValue         if roi area out of the image, use valuePad to pad
 *  @param dstFormat        处理后的图片格式: 0:nv12; 1:RGB; 2:RGBA; 3:BGRA; 4:BGR; 5:nv21; 6:gray
 *  @param dstImgWidth      处理后的图片宽度
 *  @param dstImgHeight     处理后的图片高度
 *
 *  @return 处理后帧数据
 */
+ (unsigned char *)imageProcessWithBufferData:(unsigned char *)baseBuffer
                                     uvBuffer:(unsigned char *)uvBuffer
                                    srcFormat:(int)srcFormat
                                  srcImgWidth:(int)srcImgWidth
                                 srcImgHeight:(int)srcImgHeight
                                          roi:(CGRect)roiRect
                                     rotation:(int)rotation
                                     padValue:(int)padValue
                                    dstFormat:(int)dstFormat
                                  dstImgWidth:(int)dstImgWidth
                                 dstImgHeight:(int)dstImgHeight;

/**
 *  视频帧数据处理，resize/rotation/crop
 *
 *  @param pixelBuffer      输入的视频帧数据
 *  @param roiRect          待处理视频帧区域
 *  @param rotation         图片旋转, support 0,90,180,270
 *  @param padValue         if roi area out of the image, use valuePad to pad
 *  @param dstFormat        处理后的图片格式: 0:nv12; 1:RGB; 2:RGBA; 3:BGRA; 4:BGR; 5:nv21; 6:gray
 *  @param dstImgWidth      处理后的图片宽度
 *  @param dstImgHeight     处理后的图片高度
 *
 *  @return 处理后帧数据
 */
+ (unsigned char *)imageProcessWithPixelBuffer:(CVPixelBufferRef)pixelBuffer
                                           roi:(CGRect)roiRect
                                      rotation:(int)rotation
                                      padValue:(int)padValue
                                     dstFormat:(int)dstFormat
                                   dstImgWidth:(int)dstImgWidth
                                  dstImgHeight:(int)dstImgHeight;

/**
 *  将视频帧数据转换成UIImage
 *
 *  @param data   pixel 数据
 *  @param format pixelData 格式，@PixelFomat
 *  @param width  pixelData 宽度
 *  @param height pixelData 高度
 *
 *  @return 结果UIImage对象
 */
+ (UIImage *)convertToImageWithPixelData:(unsigned char*)data
                                  format:(PixelFomat)format
                                   width:(int)width
                                  height:(int)height;

/**
 *  获取UIImage灰度图buffer
 *
 *  @param image   彩色图片
 *
 *  @return 灰度图指针,用完记得free
 */
+ (unsigned char *)getGrayWithImage:(UIImage *)image;

/**
 *  获取UIImage图像buffer
 *
 *  @param image  图片
 *  @param roi  roi
 *
 *  @return 图像数据指针,用完记得free
 */
+ (unsigned char *)getBaseDataWithImage:(UIImage *)image roi:(CGRect)roi;

// 根据bizId和modelPath生成processId
+ (NSString *)processIdWithBizId:(NSString *)bizId modelPath:(NSString *)modelPath;

// yuv pixelBuffer --> NSData
+ (NSData *)dataWithYUVPixelBuffer:(CVPixelBufferRef)pixelBuffer;

+ (CGRect)getRoiRectWithOptions:(NSDictionary *)options;

+ (int)rotationWithCameraOrientation:(AVCaptureVideoOrientation)cameraOrientation
                         frontCamera:(BOOL)frontCamera;

@end
