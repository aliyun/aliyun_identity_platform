//
//  APMVideoWriter.h
//
//
//  Created by Monster on 15/8/27.
//
//

#import <Foundation/Foundation.h>

#import <CoreMedia/CMFormatDescription.h>
#import <CoreMedia/CMSampleBuffer.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@protocol APMVideoWriterDelegate;

@interface APMVideoWriter : NSObject

@property (nonatomic, strong) dispatch_queue_t callbackQueue;
@property (nonatomic, weak) id<APMVideoWriterDelegate> delegate;
@property (readwrite) BOOL renderingEnabled; // When set to false the GPU will not be used after the setRenderingEnabled: call returns.

@property (nonatomic, strong, readonly) NSURL *outputVideoURL;
@property (nonatomic, strong) UIImage *thumbnail;
@property (nonatomic, assign) BOOL captureThumbnailWhenStartRecording;
@property (nonatomic, assign) CGSize inputSize; // 视频输入尺寸，不考虑方向
@property (nonatomic, assign) CGSize outputSize; // 视频输出尺寸，方向校正之后的尺寸
@property (nonatomic, assign) int bitrate;
@property (nonatomic, assign) int fps;
@property (nonatomic, assign) BOOL needsMirrored;
// 是否是实时录制源（相机录制），默认是YES；如果是YES，则可能丢帧，并确保第一帧与最后一帧是视频帧；
// 如果是NO，则不丢弃任何帧
@property (nonatomic, assign) BOOL realtimeSource;

@property (nonatomic, assign) AVCaptureVideoOrientation orientation; // 视频目标方向，输入方向默认y为portrait
@property (nonatomic, assign, getter=isInputTextureOpenGLCoordinatesSystem) BOOL inputTextureOpenGLCoordinatesSystem; // 输入纹理方向是否是OpenGL坐标系，默认为YES

/*!
 @property shouldOptimizeForNetworkUse
 @abstract
	Specifies whether the output file should be written in way that makes it more suitable for playback over a network
 
 @discussion
	When the value of this property is YES, the output file will be written in such a way that playback can start after only a small amount of the file is downloaded.
	
	This property cannot be set after writing has started.
 */
// 默认为YES，会将MOOV的信息移到MDAT信息之前，有利于视频在线播放，但会增加一点耗时
@property (nonatomic, assign) BOOL shouldOptimizeForNetworkUse;


- (instancetype)initWithURL:(NSURL *)URL;

- (BOOL)prepareToRecord;
- (BOOL)isReadyForAppendingVideoBuffer;
- (BOOL)isReadyForAppendingAudioBuffer;
- (void)appendVideoPixelBuffer:(GLuint)texture context:(EAGLContext *)t time:(CMTime)time;
- (void)appendAudioSampleBuffer:(CMSampleBufferRef)sampleBuffer;
- (void)appendVideoSampleBuffer:(CMSampleBufferRef)sampleBuffer;

- (void)requestaAudioDataWhenReadyOnQueue:(dispatch_queue_t)queue usingBlock:(void (^)(void))block;
- (void)requestaVideoDataWhenReadyOnQueue:(dispatch_queue_t)queue usingBlock:(void (^)(void))block;
- (void)finishRecording:(BOOL)isCanceled;

@end

@protocol APMVideoWriterDelegate <NSObject>
@required
- (void)videoWriter:(APMVideoWriter *)writer didFailWithError:(NSError *)error;
- (void)videoWriterDidFinishWriting:(APMVideoWriter *)writer;
@end

