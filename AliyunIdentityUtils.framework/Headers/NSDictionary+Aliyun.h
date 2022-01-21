//
//  NSDictionary+Aliyun.h
//  AliyunIdentityUtils
//
//  Created by nansong.zxc on 2020/7/24.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#ifndef NSDictionary_Aliyun_h
#define NSDictionary_Aliyun_h

#import <Foundation/Foundation.h>


@interface NSDictionary (Aliyun)
/**
 *  转换成JSON串字符串（没有可读性）
 *
 *  @return JSON字符串
 */
- (NSString *)toJSONString;
 
/**
 *  转换成JSON串字符串（有可读性）
 *
 *  @return JSON字符串
 */
- (NSString *)toStyledJSONString;

/**
 * JSON字符串转字典
 */
+ (NSDictionary *)dictionaryWithJSONString:(NSString *)jsonString;

/**
 * 把字典的Key的首字母从大写改成小写
 */
- (NSDictionary *)tanslateKeyU2LCase;

/**
 * 把字典的Key的首字母从小写改成大写
 */
- (NSDictionary *)tanslateKeyL2UCase;
@end

#endif
