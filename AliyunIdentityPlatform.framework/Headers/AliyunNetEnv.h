//
//  AliyunNetEnv.h
//  AliyunIdentityPlatform
//
//  Created by nansong.zxc on 2020/7/27.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#ifndef AliyunNetEnv_h
#define AliyunNetEnv_h

typedef NS_ENUM(NSInteger, AliyunNetEnvCode){
    NEC_INVALID,
    NEC_ONLINE,
    NEC_PRE,
    NEC_DEV
};

@interface AliyunNetEnv : NSObject
@property(nonatomic, copy) NSString *safHost;
@property(nonatomic, copy) NSString *safUrl;
@property(nonatomic, copy) NSString *safBackupUrl;
@property(nonatomic, copy) NSString *deviceHost;
@property(nonatomic, copy) NSString *appKey;
@property(nonatomic, copy) NSString *appSecret;
@property(nonatomic, assign) AliyunNetEnvCode envCode;
@property(nonatomic, assign) BOOL isIPv6;

//表示当前是否已经进入容灾模式
@property(nonatomic, assign) BOOL isBackupMode;

/**
 * 单例
 */
+ (AliyunNetEnv *)sharedInstance;

/**
 * 设置网络环境
 */
- (void)setNetEnv:(AliyunNetEnvCode) envCode;

@end
#endif /* AliyunNetEnv_h */
