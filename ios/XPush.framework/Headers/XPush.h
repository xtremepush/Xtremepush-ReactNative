//
//  XPush.h
//  XtremePush
//  Copyright (c) 2017 Xtremepush. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>

#import "XPPublicConstants.h"
#import "XPMessageResponseNotification.h"
#import "XPMessageResponse.h"

@interface XPush : NSObject

/**
 * Call this method in your AppDelegate's 
 * [applicationDidFinishLaunchingWithOptions:]
 * Make sure to configure SDK options before calling it
 */
+ (void)applicationDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions;



/** SDK CONFIGURATION **/

/**
 * Set application key retrieved from the platform
 */
+ (void)setAppKey:(NSString *)appKey;

/**
 * Should be turned on for development builds
 */
+ (void)setSandboxModeEnabled:(BOOL)sandboxModeEnabled;

/**
 * Turn on to show debug logs in console
 */
+ (void)setShouldShowDebugLogs:(BOOL)log;

/**
 * Turn on to run SDK in debug code
 */
+ (void)setDebugModeEnabled:(BOOL)debugModeEnabled;

/**
 * Turn on to enable IDFA collecting
 */
+ (void)setAttributionsEnabled:(BOOL)attributionsEnabled;

/**
 * Turn off to prevent device name collecting
 */
+ (void)setNameCollectingEnabled:(BOOL)nameCollectingEnabled;

/**
 * Turn on to enable in-app messages being shown on session start event
 */
+ (void)setInAppMessageEnabled:(BOOL)enabled;



/** LOCATIONS CONFIGURATION **/

/**
 * Turn on to enable geofence and ibeacon monitoring in the app
 */
+ (void)setLocationEnabled:(BOOL)locationEnabled;

/**
 * Turn off to prevent SDK to request location persmissions automatically
 */
+ (void)setAsksForLocationPermissions:(BOOL)asksForLocationPermissions;

/**
 * Request locations permissions manually
 */
+ (void)askForLocationPermissions;

/**
 * Set user location radius in meters
 */
+ (void)setLocationUpdateRadius:(CGFloat) radius;



/** DELEGATE BRIDGES **/

/**
 * Call this method in your AppDelegate's 
 * [application:didRegisterForRemoteNotificationsWithDeviceToken:]
 */
+ (void)applicationDidRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

/**
 * Call this method in your AppDelegate's 
 * [application:didFailToRegisterForRemoteNotificationsWithError:]
 */
+ (void)applicationDidFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

/**
 * Call this method in your AppDelegate's 
 * [application:didReceiveRemoteNotification:fetchCompletionHandler:]
 */
+ (void)applicationDidReceiveRemoteNotification:(NSDictionary *)userInfo
                         fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

/**
 * You should never call this method.
 * Use applicationDidReceiveRemoteNotification:fetchCompletionHandler:
 */
+ (void)applicationColdLaunchRemoteNotification:(NSDictionary *)userInfo;

/**
 * Call this method in your AppDelegate's 
 * [application:didReceiveLocalNotification:]
 */
+ (void)applicationDidReceiveLocalNotification:(UILocalNotification *)notification;

/**
 * Call this method in your AppDelegate's 
 * [application:handleActionWithIdentifier:forRemoteNotification:completionHandler:]
 */
+ (void)         application:(UIApplication *)application
  handleActionWithIdentifier:(NSString *)identifier
       forRemoteNotification:(NSDictionary *)userInfo
           completionHandler:(XPSimpleCompletionBlock)completionHandler;

/**
 * Call this method in your AppDelegate's
 * [application:handleActionWithIdentifier:forLocalNotification:completionHandler:]
 */
+ (void)         application:(UIApplication *)application
  handleActionWithIdentifier:(NSString *)identifier
        forLocalNotification:(UILocalNotification *)localNotification
           completionHandler:(XPSimpleCompletionBlock)completionHandler;

/**
 * Call this method in your custom UNNotificationCenterDelegate's
 * [userNotificationCenter:willPresentNotification:withCompletionHandler:]
 */
+ (void)userNotificationCenter:(UNUserNotificationCenter *)center
       willPresentNotification:(UNNotification *)notification
         withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler;

/**
 * Call this method in your custom UNNotificationCenterDelegate's
 * [userNotificationCenter:didReceiveNotificationResponse:withCompletionHandler:]
 */
+ (void)userNotificationCenter:(UNUserNotificationCenter *)center
didReceiveNotificationResponse:(UNNotificationResponse *)response
         withCompletionHandler:(XPSimpleCompletionBlock)completionHandler;



/** PUSH MESSAGING */

/**
 * Register current application and this lib to receive notifications
 */
+ (void)registerForRemoteNotificationTypes:(XPNotificationType)types;

/**
 * Unregister current application and this lib to receive notifications
 */
+ (void)unregisterForRemoteNotifications;

/**
 * Customise foreground notification behaviours
 */
+ (void)registerForegroundNotificationOptions:(XPForegroundNotificationOptions)options;

/**
 * Should or not application reset a badge icon
 */
+ (void)setShouldWipeBadgeNumber:(BOOL)shouldWipeBadgeNumber;

/**
 * Should or not application be processing notifications from the launch options
 */
+ (void)setShouldProcessNotificationsFromLaunchOptions:(BOOL)shouldProcess;



/** MESSAGE HANDLING */

/**
 * Register custom message response handler
 */
+ (void)registerMessageResponseHandler:(XPMessageInteractionCallback)callback;

/**
 * Register custom message response handler
 * Use this version if you want to support background handling (such as notification buttons in background mode)
 */
+ (void)registerMessageResponseHandlerWithCompletion:(XPContinousMessageInteractionCallback)callback;

/**
 * Register standard deeplinks handler
 */
+ (void)registerDeeplinkHandler: (XPDeeplinkCallback)callback;

/**
 * Progamatically process message click event after showing custom dialog
 */
+ (void)clickMessage:(XPMessage *)message;

/**
 * Progamatically process message click with certain action identifier event after showing custom dialog
 */
+ (void)clickMessage:(XPMessage *)message actionIdentifier:(NSString*)actionIdentifier;

/**
 * Report message being clicked after showing custom dialog
 */
+ (void)reportMessageClicked:(XPMessage *)message;

/**
 * Report message being clicked with certain action identifier after showing custom dialog
 */
+ (void)reportMessageClicked:(XPMessage *)message actionIdentifier:(NSString*)actionIdentifier;

/**
 * Report message being closed after showing custom dialog
 */
+ (void)reportMessageDismissed:(XPMessage *)message;



/** INBOX **/

/**
 * Turn on to enable Inbox
 */
+ (void)setInboxEnabled:(BOOL)inboxEnabled;

/**
 * Open inbox
 */
+ (void)openInbox;

/**
 * Get current inbox badge
 */
+ (NSInteger)getInboxBadge;

+ (void) registerInboxChangeCallback:(void(^)(NSInteger)) callback;

/** INAPP BEHAVIOR */

/**
 * Record in-app event hit
 */
+ (void)hitEvent:(NSString *)event;

/**
 * Calls "eventHit" with value.
 */
+ (void)hitEvent:(NSString *)event withValue:(NSString *)value;

/**
 *	Calls "eventHit" with multiple values.
 */
+ (void)hitEvent:(NSString *)event withValues:(NSDictionary *)values;

/**
 * Record tag hit
 */
+ (void)hitTag:(NSString *)tag;

/**
 * Record tag with value or attribute
 */
+ (void)hitTag:(NSString *)tag withValue:(NSString *)value;

/**
 * Record impression hit
 */
+ (void)hitImpression:(NSString *)impression;



/** DEVICE INFORMATION **/

/**
 * Set external id of a device which can be used then on platform to target devices
 */
+ (void)setExternalId:(NSString *)externalId;

/**
 * Switch device's push subscription on/off
 */
+ (void)setSubscription:(BOOL)subscription;

/**
 *	Returns version of the lib.
 */
+ (NSString *)version;

/**
 *	Returns dictionary with device token and device id.
 *  XPushDeviceID - key for XtremePush device id.
 *  deviceToken - key for token.
 *  deviceID - key for device identifier (IDFV).
 *  externalID - key for external id.
 */
+ (NSDictionary *)deviceInfo;



/** INAPP BEHAVIOR RELEASING CONFIGURATION **/

/**
 * Turn off to send tag hits to the server in realtime
 */
+ (void)setTagsBatchingEnabled:(BOOL)tagsBatchingEnabled;

/**
 * Send stored tag hits to the server
 */
+ (void)sendTags;

/**
 * Turn off to send impression hits to the server in realtime
 */
+ (void)setImpressionsBatchingEnabled:(BOOL)impressionsBatchingEnabled;

/**
 * Send stored impression hits to the server
 */
+ (void)sendImpressions;

/**
 *  Set a limit for a maximum number of stored tags, impressions and sessions
 */
+ (void)setTagsStoreLimit:(NSUInteger *)limit;
+ (void)setImpressionsStoreLimit:(NSUInteger *)limit;
+ (void)setSessionsStoreLimit:(NSUInteger *)limit;



/** DEPRECATED PUSH MESSAGES ACCESS METHODS */

/**
 *	Used to get a list of push notifications for current device
 */
+ (void)getPushNotificationsOffset:(NSUInteger)offset limit:(NSUInteger)limit completion:(void(^)(NSArray *pushList, NSError *error))completion;

/**
 *	Used to get a list of push notifications for current device
 */
+ (void)getPushNotificationsRead:(BOOL)read offset:(NSUInteger)offset limit:(NSUInteger)limit completion:(void(^)(NSArray *pushList, NSError *error))completion;

/**
 *	Used to manually mark a push as read.
 */
+ (void)markPushAsRead:(NSString *)actionId;


/**
 *  User setting
 */
+ (void) setUser:(NSString*) userId;
+ (void) setTempUser:(NSString*) userId;


+ (void)setServerURL:(NSString *)url;
+ (void)setServerExpectedCertificate:(NSString *)certDataString;
+ (void)setServerExpectedCertificates:(NSArray *)certDataStringArray;
+ (void)setServerExpectedCertificateFromFile:(NSString *)filePath;
+ (void)setServerExpectedCertificateFromFiles:(NSArray *)filePathArray;

+ (void)setServerExpectedCertificate:(NSString *)certDataString preferedIndex:(NSNumber*)index;
+ (void)setServerExpectedCertificates:(NSArray *)certDataStringArray preferedIndex:(NSNumber*)index;
+ (void)setServerExpectedCertificateFromFile:(NSString *)filePath preferedIndex:(NSNumber*)index;
+ (void)setServerExpectedCertificateFromFiles:(NSArray *)filePathArray preferedIndex:(NSNumber*)index;

@end


/** DEPRECATED PUSH MESSAGE MODEL **/

@interface XPPushModel : NSObject
@property (nonatomic, readonly) NSDate      *createDate;
@property (nonatomic, readonly) NSString    *pushId;
@property (nonatomic, readonly) NSString    *locationId;
@property (nonatomic, readonly) NSString    *alert;
@property (nonatomic, readonly) NSInteger   badge;
@property (nonatomic, readonly) NSString    *messageId;
@property (nonatomic, readonly) NSString    *url;
@property (nonatomic, readonly) BOOL        shouldOpenInApp;
@property (nonatomic, readonly) BOOL        isRead;
@property (nonatomic, readonly) NSDictionary *customPayload;
@end


/** INBOX BUTTON **/

@interface XPInboxButton : UIButton
- (UILabel *)badge;
- (void)setBadgeSize:(NSInteger)badgeSize;
- (void)setBadgePosition:(CGPoint)badgeSize;
- (void)setBadgeColor:(UIColor *)color;
- (void)setBadgeTextColor:(UIColor *)color;
@end


