//
//  XPMessageResponseNotification.h
//  XPush
//
//  Created by Vlad Soroka on 7/18/17.
//  Copyright © 2017 XPush. All rights reserved.
//

#import <Foundation/Foundation.h>

#if RELEASE
__deprecated_msg("Consider switching to block based notification and XPMessage that are safer to use. ")
#endif
@interface XPMessageResponseNotification : NSObject

@property (nonatomic, readonly) NSDictionary      *messagePayload;

@property (nonatomic, readonly) NSString* responseType;
@property (nonatomic, readonly) NSString* messageType;

@property (nonatomic, readonly) NSString* button;

@end
