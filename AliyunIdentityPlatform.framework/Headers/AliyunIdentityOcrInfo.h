//
//  AliyunIdentityOcrInfo.h
//  AliyunIdentityPlatform
//
//  Created by nansong.zxc on 2020/7/24.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#ifndef AliyunIdentityOcrInfo_h
#define AliyunIdentityOcrInfo_h

/**
 * OCR识别结果信息
 */
@interface AliyunIdentityOcrInfo : NSObject
//身份证姓名
@property(nonatomic, copy) NSString *CertName;
//身份证号
@property(nonatomic, copy) NSString *CertNo;
//性别
@property(nonatomic, copy) NSString *Sex;
//民族
@property(nonatomic, copy) NSString *Nationality;
//出生日期
@property(nonatomic, copy) NSString *BirthDate;
//家庭地址
@property(nonatomic, copy) NSString *Address;
//发证机关
@property(nonatomic, copy) NSString *Authority;
//有效期开始时间
@property(nonatomic, copy) NSString *StartDate;
//有效期结束时间
@property(nonatomic, copy) NSString *EndDate;
//银行卡号
@property(nonatomic, copy) NSString *BankCardNo;
@end
#endif /* AliyunIdentityOcrInfo_h */
