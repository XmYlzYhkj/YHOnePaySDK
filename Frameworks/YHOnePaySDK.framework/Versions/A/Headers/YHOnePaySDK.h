//
//  YHOnePaySDK.h
//  YHOnePaySDK
//
//  Created by Jagtu on 2018/4/27.
//  Copyright © 2018年 yh. All rights reserved.
//
//  Version 2.0.8  by Jagtu  2018/8/12
//  Version 2.1.9  by Jagtu  2018/9/5
//
// In this header, you should import all the public headers of your framework using statements like
// #import <YHOnePaySDK/YHOnePaySDK.h>


#import <UIKit/UIKit.h>
//config
#import <YHOnePaySDK/YHOnePayConfig.h>
#import <YHOnePaySDK/YHOnePayTheme.h>


@interface YHOnePaySDK : NSObject


/**
 *  创建统一支付单例服务
 *
 *  @return 返回单例对象
 */
+ (YHOnePaySDK *)defaultService;

/**
 *  统一支付，将调起SDK内置收银台页面，让用户选择支付渠道
 *
 *  @param chargeNo        订单号（【统一支付服务端】返回的订单号chargeNo）
 *  @param completionBlock 支付结果回调Block，获得支付结果。
 *                         支付成功后，用户服务器也会收到易联众服务器发送的异步通知。 最终支付成功请根据服务端异步通知为准。(特别是微信支付，这里返回成功不代表支付成功，需服务端再次查询确定)
 
 */
-(void)paymentWithChargeNo:(NSString *)chargeNo
                  callback:(YHOPayCompletionBlock)completionBlock;

/**
 *  统一支付
 *
 *  @param orderParam      订单信息（【统一支付服务端】返回的订单信息）
 *  @param completionBlock 支付结果回调Block，获得支付结果。
 *                         支付成功后，用户服务器也会收到易联众服务器发送的异步通知。 最终支付成功请根据服务端异步通知为准。(特别是微信支付，这里返回成功不代表支付成功，需服务端再次查询确定)
 
 */
- (void)paymentWithParam:(id)orderParam
                callback:(YHOPayCompletionBlock)completionBlock;



/**
 *  查询订单支付信息(获取发起第三方支付的入参信息)
 *
 *  @param chargeNo        订单号（【统一支付服务端】返回的订单号chargeNo）
 *  @param channelId       渠道编码（【统一支付服务端】返回的channelId）
 *  @param completionBlock 查询结果回调Block
 */
-(void)queryPayInfo:(NSString *)chargeNo
          channelId:(NSString *)channelId
           callback:(YHOPayCompletionBlock)completionBlock;

/**
 *  查询订单详情
 *
 *  @param chargeNo       订单号
 *  @param completionBlock 回调Block
 */
- (void)queryOrderInfo:(NSString *)chargeNo
              callback:(YHOPayCompletionBlock)completionBlock;


/**
 *  查询支付结果接口
 *
 *  @param chargeNo       订单号
 *  @param completionBlock 支付结果回调Block
 
 */
- (void)queryPayResult:(NSString *)chargeNo
              callback:(YHOPayCompletionBlock)completionBlock;


/**
 *  处理第三方app支付完成后跳回商户app携带的支付结果Url
 *
 *  @param resultUrl        支付结果url
 *  @param completionBlock  支付结果回调Block
 *  【由于在跳转第三方支付的过程中，商户app在后台很可能被系统kill了，所以之前调起支付接口设置的callback就会失效，请商户对standbyCallback返回的回调结果进行处理,就是在这个方法里面处理跟callback一样的逻辑】
 *  注：如果商户app并未被系统kill掉，且之前调起支付接口时设置的callback有效，则不会调用completionBlock
 */
- (void)processOrderWithPaymentResult:(NSURL *)resultUrl
                      standbyCallback:(YHOPayCompletionBlock)completionBlock;

@end