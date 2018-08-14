//
//  XPMessageResponse.h
//  XPush
//
//  Created by Vlad Soroka on 9/7/17.
//  Copyright © 2017 XPush. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "XPMessage.h"
#import "XPAction.h"

@interface XPMessageResponse : NSObject

@property (nonatomic, nonnull, readonly) XPMessage* message;
@property (nonatomic, nonnull, readonly) XPAction* action;

- (NSDictionary * _Nonnull ) dictionaryRepresentation;

@end
