//
//  AliyunIdentityFace.h
//  AliyunIdentityFace
//
//  Created by nansong.zxc on 2020/8/6.
//  Copyright © 2020 aliyun.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//! Project version number for AliyunIdentityFace.
FOUNDATION_EXPORT double AliyunIdentityFaceVersionNumber;

//! Project version string for AliyunIdentityFace.
FOUNDATION_EXPORT const unsigned char AliyunIdentityFaceVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <AliyunIdentityFace/PublicHeader.h>

@interface AliyunIdentityFace : NSObject

/**
 * 启动人脸组件
 * @param currentViewController  - 用来在人脸组件中展示UI
 */
+ (void)startFaceWithController:(UIViewController *)currentViewController;

@end


