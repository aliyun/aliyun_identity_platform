//
//  AliyunIdentityCenter.h
//  AliyunIdentityPlatform
//
//  Created by nansong.zxc on 2020/7/24.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#ifndef AliyunIdentityCenter_h
#define AliyunIdentityCenter_h

#import "AliyunIdentityCom.h"
#import <UIKit/UIKit.h>
#import "AliyunIdentityVerifyMode.h"
#import "AliyunIdentityOcrInfo.h"

typedef NS_ENUM(NSInteger, AliyunIdentityOSSFileIdx){
    IOF_INVALID,
    IOF_IDCARD_FRONT,
    IOF_IDCARD_BACK,
    IOF_BANK,
    IOF_FACE_IMAGE
};

@interface AliyunIdentityCenter : NSObject

//保存本次操作的CertifyId
@property(nonatomic, copy) NSString *certifyId;
//客户传入的回调block
@property(nonatomic, strong) AliyunIdentityVerifyBlock completionCallback;
//客户传入的ExtParams
@property(nonatomic, strong) NSDictionary *extParams;
//客户传入的UIViewController
@property(nonatomic, strong) UIViewController *currentViewController;
//客户传入的认证模式
@property(nonatomic, assign) AliyunIdentityMode verifyMode;
//服务端初始化结果
@property(nonatomic, strong) NSDictionary *deviceConfig;
//MetaInfo
@property(nonatomic, copy) NSString *metaInfo;
//最大超时保护
@property(nonatomic, strong) NSTimer *sdkMaxTimeOutTimer;
//人脸活体算法需要的参数
@property(atomic, strong) NSDictionary *toygerUploadParams;
//人脸活体算法需要的桉树
@property(atomic, strong) NSDictionary *toygerAlgorithmParams;
//业务内部工作流
@property(atomic, strong) NSMutableArray *verifyActionFlow;

//---------------------OCR数据中心--------------------
//Ocr识别的结果
@property(nonatomic, strong) AliyunIdentityOcrInfo *ocrInfo;
//修改过的身份证姓名
@property(nonatomic, copy) NSString *certNameConfirm;
//修改过的身份证号码
@property(nonatomic, copy) NSString *certNoConfirm;
//修改过的银行卡号
@property(nonatomic, copy) NSString *bankConfirm;
//身份证正面照片
@property(nonatomic, strong) UIImage *idcardFrontImage;
//身份证正面裁剪图片
@property(nonatomic, strong) UIImage *idcardFrontCropImage;
//身份证正面OSS地址
@property(nonatomic, copy) NSString *idcardFrontOss;
//身份证反面照片
@property(nonatomic, strong) UIImage *idcardBackImage;
//身份证反面裁剪图片
@property(nonatomic, strong) UIImage *idcardBackCropImage;
//身份证反面OSS地址
@property(nonatomic, copy) NSString *idcardBackOss;
//银行卡
@property(nonatomic, strong) UIImage *bankImage;
//银行卡裁剪图片
@property(nonatomic, strong) UIImage *bankCropImage;
//银行卡Oss
@property(nonatomic, copy) NSString *bankOss;
//---------------------活体数据中心--------------------
//刷脸SDK返回的高清图片
@property(nonatomic, strong) UIImage *faceHighQualityImage;
//图片Hash
@property(nonatomic, strong) NSData *faceHighQualityHash;
//人脸高清图片oss
@property(nonatomic, strong) NSString *faceImageOss;
//是否通过图片选择
@property(nonatomic, assign) BOOL isSelectedPhoto;

//--------------------单流程保护---------------------
@property(atomic, assign) BOOL isBusy;

@property(nonatomic, assign) long verifyStartTime;

//单例，这个类主要就是作为调度模块的数据存储中心
+ (AliyunIdentityCenter *) sharedInstance;

//回调给客户SDK
- (void)sendResWithCode:(int)code withMessage:(NSString *)message withOcrInfo:(AliyunIdentityOcrInfo *)ocrInfo;

//清理老数据
- (void)clear;

//删除已经运行过的模块
- (void)removeIdentityMode:(NSString *)identityMode;

//判断是否是圆脸UI
- (BOOL)isRoundFaceUI;

//是否打开Crash搜集开关
- (BOOL)isCrashDetectEnable;

@end
#endif /* AliyunIdentityCenter_h */
