//
//  AliyunCrashHandler9.h
//  为了防止跟阿里云其他的类似功能组件重名，后面加个9，飞天9部
//  Created by nansong.zxc on 2021/2/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//定义OC方法开始进行异常保护的宏
#define DECLARE_OC_START_EXCEPTION_GUARD(classname) \
- (void)classname##_oc_start_exception_guard {}

//定义OC方法结束进行异常保护的宏
#define DECLARE_OC_END_EXCEPTION_GUARD(classname) \
- (void)classname##_oc_end_exception_guard {}

//定义C方法开始进行异常保护的宏
#define DECLARE_C_START_EXCEPTION_GUARD(classname) \
void classname##_c_start_exception_guard() {}

//定义C方法结束进行异常保护的宏
#define DECLARE_C_END_EXCEPTION_GUARD(classname) \
void classname##_c_end_exception_guard() {} \
void classname##_c_register_exception_guard() { \
    [[AliyunCrashHandler9 sharedInstance] addFilterStartAddr:(NSUInteger)classname##_c_start_exception_guard withEndAddr:(NSUInteger)classname##_c_end_exception_guard]; \
}

//定义注册Crash捕捉
#define DECLARE_REGISTER_OC_EXCEPTION_GUARD(classname) \
[[AliyunCrashHandler9 sharedInstance] addFilter:@""#classname""];

//定义注册Crash捕捉
//#define DECLARE_REGISTER_C_EXCEPTION_GUARD(startAddr, endAddr) \
//[[AliyunCrashHandler9 sharedInstance] addFilterStartAddr:startAddr withEndAddr:endAddr];

#define DECLARE_REGISTER_C_EXCEPTION_GUARD(classname) \
    classname##_c_register_exception_guard();
//[[AliyunCrashHandler9 sharedInstance] addFilterStartAddr:(NSUInteger)classname##_c_start_exception_guard withEndAddr:(NSUInteger)classname##_c_end_exception_guard];

typedef void (^AliyunCrashBlock9)(NSString *deviceInfo, NSString *crashContent);
@interface AliyunCrashHandler9 : NSObject

/**
 * 单例
 */
+ (instancetype)sharedInstance;

/**
 * 启动Crash搜集组件
 */
- (void)initWithBlock:(AliyunCrashBlock9) crashBlock;

/**
 * 添加过滤字符串
 */
- (void)addFilter:(NSString *) filterClassName;

/**
 * 按照地址范围来操作，主要用于C函数的地址捕获
 */
- (void)addFilterStartAddr:(NSUInteger) startAddr withEndAddr:(NSUInteger) endAddr;

/**
 * 清理过滤器
 */
- (void)clearFilter;

/**
 * 恢复Signal
 */
- (void)restoreExceptionHandlers;
@end

NS_ASSUME_NONNULL_END
