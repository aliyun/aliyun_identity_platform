//
//  XMediaCommonNNResult.h
//  XMedia
//
//  Created by tao zeng on 2020/9/29.
//  Copyright © 2020 Alipay. All rights reserved.
//

#import "XMediaResult.h"
#include "defs.h"

@interface XMediaNNResultItem : NSObject

@property (nonatomic, copy) NSString *label;
@property (nonatomic, assign) float confidence;
@property (nonatomic, strong) NSArray *positon;

//主要用于OCR算法结果
@property (nonatomic, assign) BOOL isKVPair;
@property (nonatomic, strong) NSString *key;

@end


@interface XMediaNNResult : XMediaResult

@property (nonatomic, strong) NSArray <XMediaNNResultItem*> *items;  //算法结果
@property (nonatomic, strong) UIImage *fullImage;           //识别成功时当前帧图片
@property (nonatomic, strong) UIImage *roiImage;            //识别成功时当前帧roi图片

@property (nonatomic, weak) id<XMediaResultTransformDelegate> transDelegate;

- (void)udpateWithResults:(Results)results jsonString:(NSString *)jsonStr;

@end

