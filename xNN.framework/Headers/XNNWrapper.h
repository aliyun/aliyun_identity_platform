//
//  ARAIEngineWrapper.h
//  FalconARKit
//
//  Created by taoyuan on 2017/5/2.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

typedef struct {
    int imageFormat;//0:YUV,1:RGB,2:RGBA,3:BGRA
    unsigned char *baseData;
    unsigned char *otherData;
    int width;
    int height;
    int * roi;
} XNNInputImage;

typedef struct{
    char *table;
    char *column;
    int offset;
    int train_steps;
    int batch_size;
} xTrainContext;

@protocol XNNTargetDelegate <NSObject>
@optional

-(void)onAIEngineError:(int)errorCode message:(NSString *)msg;
@end

@interface XNNWrapper : NSObject

@property(nonatomic,weak) id<XNNTargetDelegate> delegate;


/**
 初始化XNN
 
 @param path model dtat path,use path[0]
 @param configString default pass nil
 @return self
 */
-(instancetype)initWithModelPath:(NSArray *)path biztype:(NSString *)biztype config:(NSString*)configString;

-(instancetype)initWithModelPath:(NSArray *)path patchPath:(NSArray *)patchPath biztype:(NSString *)biztype config:(NSString*)configString;
/**
 分类
 
 @param img 图片
 @return 分类结果
 [
   {"label":"plant","conf":0.782},
   {"label":"vehicle","conf":0.551}
 ]
 */
-(NSArray *)classify:(XNNInputImage *)img;

/**
 检测
 
 @param img 图片
 @return 检测结果
 [
   {"label":"tire","conf":0.782,"bbox":[0.572,0.333,0.584,0.410]},
   {"label":"tire","conf":0.513,"bbox":[0.630,0.483,0.698,0.610]},
   {"label":"plate","conf":0.527,"bbox":[0.730,0.283,0.788,0.312]}
 ]
 */
-(NSArray *)detect:(XNNInputImage *)img;


-(BOOL)fillInput:(NSString *)channel data:(NSArray *)data;
-(BOOL)fillInputData:(NSString *)channel data:(NSData *)data;
-(NSArray *)getShape:(NSString *)channel;
-(NSArray *)getOutputShape:(NSString *)channel;

-(BOOL)forward;
-(NSArray *)getOutput:(NSString *)channel;
-(NSData *)getOutputData:(NSString *)channel;


//train
-(BOOL)trainWithDb:(NSString *)dbPath trainCtx:(xTrainContext*)ctx;
-(BOOL)exportUpdates:(NSString *)exportPath;

-(void)releaseEngine;

@end
