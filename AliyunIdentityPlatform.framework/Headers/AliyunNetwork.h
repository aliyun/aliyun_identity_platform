//
//  AliyunNetwork.h
//  AliyunIdentityPlatform
//
//  Created by nansong.zxc on 2020/7/24.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^AliyunNetworkBlock)(bool success, NSDictionary *__nullable resContent, NSString *__nullable error);
typedef void(^AliyunOssBlock)(bool success, int fileIdx, NSString *fileName);

@interface AliyunNetwork : NSObject

/**
 * 单例
 */
+ (AliyunNetwork *)sharedInstance;

/**
 * 初始化网络环境
 */
- (void)initNetwork;

/**
 * 取消当前队列中所有的网络请求
 */
- (void)cancelAll;
/**
 * 调用网关接口发送业务请求
 */
- (void)sendHttpRequest:(NSString*) appKey
              appSecret:(NSString*)appSecret
               withSeed:(NSString *)appSeed
                    Url:(NSString*)url
                 action:(NSString*)action
                version:(NSString*) version
                   host:(NSString *)host
                  param:(NSDictionary*) parameters
        completionBlock:(AliyunNetworkBlock)completionBlock;

/**
 *  判断是否是开启了安全链路加密的CertifyId
 */
+ (BOOL)isSecCertifyId:(NSString *)certifyId;

/**
 * 内置URL和AppSecret，自动容灾
 */
- (void)sendHttpRequestInteli:(NSString*)action
                      version:(NSString*) version
                     withSeed:(NSString *)appSeed
                        param:(NSDictionary*) parameters
              completionBlock:(AliyunNetworkBlock)completionBlock;

/**
 * 上传OSS文件
 */
- (void)uploadOssFile:(int) fileIdx
         withFileName:(NSString *)fileName
      withFileContent:(NSData *)fileContent
        withAccessKey:(NSString *) accessKey
        withSecretKey:(NSString *) secretKey
    withSecurityToken:(NSString *) securityToken
         withEndPoint:(NSString *) endPoint
       withNamePrefix:(NSString *) namePrefix
       withBucketName:(NSString *) bucketName
            withBlock:(AliyunOssBlock) ossBlock;

/**
 * 同步上传接口
 */
- (BOOL)uploadOssFileSyn:(int) fileIdx
     withFileName:(NSString *)fileName
  withFileContent:(NSData *)fileContent
    withAccessKey:(NSString *) accessKey
    withSecretKey:(NSString *) secretKey
withSecurityToken:(NSString *) securityToken
     withEndPoint:(NSString *) endPoint
   withNamePrefix:(NSString *) namePrefix
          withBucketName:(NSString *) bucketName;
@end


NS_ASSUME_NONNULL_END
