//
//  AliyunIdentityVerifyRes.h
//  AliyunIdentityPlatform
//
//  Created by nansong.zxc on 2020/7/24.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#ifndef AliyunIdentityVerifyRes_h
#define AliyunIdentityVerifyRes_h

#import "AliyunIdentityOcrInfo.h"
#import <UIKit/UIKit.h>

@interface AliyunIdentityVerifyRes : NSObject
//错误码
@property (nonatomic, assign) int code;
//错误码描述
@property (nonatomic, copy) NSString *message;
//OCR信息
@property (nonatomic, strong) AliyunIdentityOcrInfo *ocrInfo;
//身份证正面裁剪照片
@property (nonatomic, strong) UIImage *idCardFrontCropImage;
//身份证反面裁剪照片
@property (nonatomic, strong) UIImage *idCardBackCropImage;
//银行卡裁剪照片
@property (nonatomic, strong) UIImage *bankCardCropImage;
//设备指纹的deviceToken
@property (nonatomic, copy) NSString *deviceToken;
//刷脸的照片
@property (nonatomic, strong) UIImage *faceImage;
@end
#endif /* AliyunIdentityVerifyRes_h */
