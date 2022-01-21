//
//  XMediaOCRResult.h
//  XMedia
//
//  Created by tao zeng on 2018/2/23.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import "XMediaResult.h"
#import "XMediaClassifyResult.h"

@interface XMediaOCRResultItem : XMediaClassifyResultItem
@property (nonatomic, strong) NSArray *boxCoord;
@property (nonatomic, assign) int isKVPair;
@property (nonatomic, strong) NSString *key;
@end

@interface XMediaOCRResult : XMediaResult

@property (nonatomic, strong) NSArray <XMediaOCRResultItem*> *items;
@property (nonatomic, strong) UIImage *fullImage;
@property (nonatomic, strong) UIImage *roiImage;
@property (nonatomic, strong) UIImage *resultImage;
@property (nonatomic, assign) BOOL runRecognize;      //有走recognize算法处理

- (void)updateJsonDictonary:(NSDictionary *)jsonDict;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
