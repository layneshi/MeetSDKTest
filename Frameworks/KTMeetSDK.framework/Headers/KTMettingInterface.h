//
//  KTMettingInterface.h
//  SDKDemo
//
//  Created by layne on 2019/12/19.
//  Copyright © 2019 layne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, KTEndMeetType) {
    KTEndMeetTypeOutMeeting = 6,   //被踢出会议
    KTEndMeetTypeEndMeeting = 7,   //会议结束
    KTEndMeetTypeExitMeeting = 9,   //自己退出会议
    KTEndMeetTypeNetMeeting = 10  //网络断开
};


@protocol KTMettingInterfaceDelegate <NSObject>

@optional

/**
 自定义邀请，可以自己操作
 */
- (void)KTMettingInterfaceInviteUser:(NSString *)meetingKey;

/**
 区分退出会议的类型
 @param leaveType 退出会议类型
 */
- (void)KTLeaveMeeing:(KTEndMeetType)leaveType;


@end


@interface KTMettingInterface : NSObject

/**
 初始化会议
 */
+ (void)initMetting;

/**
  登录
 * @param appId 分配的唯一标识
 * @param appToken 分配的标识token
 * @param userName 用户姓名
 * @param password 用户密码
 */
+ (void)loginWithAppId:(NSString *)appId
              appToken:(NSString *)appToken
              userName:(NSString *)userName
              password:(NSString *)password
           completion:(void (^)(NSInteger))block;

/**创建会议
 * @param roomName 会议名称
 */
+ (void)createConference:(NSString *)roomName
              completion:(void (^)(NSString *, NSInteger))block;

/**
 创建者加入会议
*/
+ (void)createrJoinConferenceCompletion:(void (^)(NSInteger, BOOL))block;

/**参会者加入会议
 *  @param meetingKey 会议号
 *  @param userName 用户姓名
*/
+ (void)joinConferenceWithmeetingKey:(NSString *)meetingKey
                            userName:(NSString *)userName
                          completion:(void (^)(NSInteger,BOOL))block;

/**离开会议挂断*/
+ (void)leaveConferenceCompletion:(void (^)(NSInteger))block;

/**
 弹出会议界面
 @param isCreater  是否为创建者
 */
+ (void)pushMeetingViewFromController:(UIViewController *)controller
                            isCreater:(BOOL)isCreater
                             Animated:(BOOL)animated
                           completion:(void(^)(void))completion;

/**获取会中参会人列表*/
+ (void)getAttendListInConferenceCompletion:(void(^)(NSArray *,NSString *))completion;

/**
 弹出预约会议界面
 */
+ (void)pushOrderViewController:(UIViewController *)controller
                       Animated:(BOOL)animated
                     completion:(void(^)(void))completion;

/**
 弹出会议列表界面
 */
+ (void)pushConferenceListController:(UIViewController *)controller
                            Animated:(BOOL)animated
                          completion:(void(^)(void))completion;

/**
 添加代理获取监听各种事件，可添加多个代理

 @param delegate delegate
 */
+ (void)addDelegate:(id<KTMettingInterfaceDelegate>)delegate;
@end

NS_ASSUME_NONNULL_END
