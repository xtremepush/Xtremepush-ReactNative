#import "RNXtremepushReact.h"
#import XPush

@implementation RNXtremepushReact

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}



RCT_EXPORT_METHOD(hitEvent : (NSString *)event)
{
    [XPush hitEvent : userId];
}

RCT_EXPORT_MODULE()
ß@end
  