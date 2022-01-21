//
//  AliyunIdentityOcr.h
//  AliyunIdentityOcr
//
//  Created by nansong.zxc on 2020/7/24.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//! Project version number for AliyunIdentityOcr.
FOUNDATION_EXPORT double AliyunIdentityOcrVersionNumber;

//! Project version string for AliyunIdentityOcr.
FOUNDATION_EXPORT const unsigned char AliyunIdentityOcrVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <AliyunIdentityOcr/PublicHeader.h>

@interface AliyunIdentityOcr : NSObject

/**
 * 启动OCR识别
 */
+ (void)startOCRWithController:(UIViewController *)currentViewController;

@end
