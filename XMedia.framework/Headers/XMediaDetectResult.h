//
//  XMediaDetectResult.h
//  XMedia
//
//  Created by Cloud on 2017/9/6.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "XMediaClassifyResult.h"

@interface XMediaDetectResultItem : XMediaClassifyResultItem

@property (nonatomic, assign) CGRect boundingBox;
@property (nonatomic, strong) NSArray *keyPoints;
@end

@interface XMediaDetectResult : XMediaResult

@property (nonatomic, strong) NSArray <XMediaDetectResultItem *>*items;
@property (nonatomic, strong) NSArray *boxCoord;
@property (nonatomic, strong) NSData *detectFrameData;
@property (nonatomic, assign) CGSize detectFrameSize;
@property (nonatomic, strong) NSData *roiImageOutput;

- (instancetype)initWithArray:(NSArray <NSDictionary *>*)array isBorderDetect:(BOOL)borderDetect;

- (void)updateJsonDictionary:(NSDictionary *)jsonDict;

@end
