//
//  AliyunIdentityVerifyMode.h
//  AliyunIdentityPlatform
//
//  Created by nansong.zxc on 2020/7/24.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#ifndef AliyunIdentityVerifyMode_h
#define AliyunIdentityVerifyMode_h

/* 识别类型 */
typedef  NS_ENUM(NSInteger,AliyunIdentityMode){
    /** 身份证OCR识别模式  */
    AliyunIdentityModeIdCardOCR = 0,
    
    /**银行卡OCR识别模式*/
    AliyunIdentityModeBankCardOCR = 1
};

#endif /* AliyunIdentityVerifyMode_h */
