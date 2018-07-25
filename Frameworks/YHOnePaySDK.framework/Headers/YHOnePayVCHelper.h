//
//  YHOnePayVCHelper.h
//  YHBaseSDK
//
//  Created by Jagtu on 2018/4/25.
//  Copyright © 2018年 YH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface YHOnePayVCHelper : NSObject

/**
 *  打开下一个页面
 *  present YHBaseNavController,其rootViewController为vc
 */
+(void)gotoNextVC:(UIViewController *)vc;

/**
 *  当前显示的vc
 */
+(UIViewController *)getCurrentVc;

@end
