#import "RNXtremepushReact.h"
#import "XPush.h"

@implementation RNXtremepushReact

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}



RCT_EXPORT_METHOD(hitEvent : (NSString *)event)
{
    [XPush hitEvent : event];
}


RCT_EXPORT_METHOD(hitTag : (NSString *)tag)
{
    [XPush hitTag : tag];
}

RCT_EXPORT_METHOD(hitTag : (NSString *)tag withValue: (NSString *)value)
{
    [XPush hitTag : tag withValue:value];
}

RCT_EXPORT_METHOD(setUser : (NSString *)user)
{
    [XPush setUser : user];
}

RCT_EXPORT_METHOD(setExternalId : (NSString *)id)
{
    [XPush setExternalId : id];
}

RCT_EXPORT_METHOD(openInbox)
{
    [XPush openInbox];
}

RCT_EXPORT_MODULE(Xtremepush)
@end
  
