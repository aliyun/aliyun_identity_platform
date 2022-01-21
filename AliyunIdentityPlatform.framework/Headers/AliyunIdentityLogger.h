/*
 日志组件，统计用户行为
 */
//  AliyunLogService.h
//  AliyunIdentityDemo
//
//  Created by 胡锦涛 on 2020/6/3.
//  Copyright © 2020 胡锦涛. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSInteger {
    // 信息日志
    AliyunLogLevelInfo = 0,
    // 警告日志
    AliyunLogLevelWarning,
    // 调试日志
    AliyunLogLevelDebug,
    // 错误日志
    AliyunLogLevelError,
    // 详细日志
    AliyunLogLevelVerbose,
} AliyunLogLevel;

@interface AliyunIdentityLogger : NSObject
@property(nonatomic, copy) NSString *certifyId;

//单例
+ (AliyunIdentityLogger *)sharedInstance;

//日志打点
- (void)logEvent:(NSString*)actionName bizParams:(NSDictionary *)bizParam;

//上传本地所有日志
- (void)flushLog;
@end

NS_ASSUME_NONNULL_END
