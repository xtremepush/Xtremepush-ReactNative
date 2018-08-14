//
//  XPInternalMessage.h
//  XPush
//
//  Created by Vlad Soroka on 8/23/17.
//  Copyright © 2017 XPush. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "XPAction.h"

@interface XPMessage : NSObject

///unique identifier for this particular message
@property (nonatomic, readonly, nonnull) NSString* identifier;

///unique identifier for campaign this message belongs
@property (nonatomic, readonly, nullable) NSString* campaignIdentifier;

///key-value pairs defined when you created campaign
@property (nonatomic, readonly, nullable) NSDictionary* data;

///push, inbox, inapp
@property (nonatomic, readonly) XPMessageType type;

@property (nonatomic, readonly, nullable) NSString* title;
@property (nonatomic, readonly, nullable) NSString* text;

///raw representation of the message for custom message processing
@property (nonatomic, readonly, nonnull) NSDictionary *payload;

@end
