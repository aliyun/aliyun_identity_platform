//
//  XMediaClassifyResult.h
//  XMedia
//
//  Created by Cloud on 2017/9/6.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XMediaResult.h"

@interface XMediaClassifyResultItem : NSObject

@property (nonatomic, copy) NSString *label;
@property (nonatomic, assign) float confidence;

- (instancetype)initWithResult:(NSDictionary *)result;

@end

@interface XMediaClassifyResult : XMediaResult 

@property (nonatomic, strong) NSArray <XMediaClassifyResultItem *>*items;

- (instancetype)initWithArray:(NSArray <NSDictionary *>*)array;

- (void)updateJsonDictionary:(NSDictionary *)jsonDict;

@end
