#import "RNXtremepushReact.h"
//#import <XPush/XPush.h>

@implementation RNXtremepushReact

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}



RCT_EXPORT_METHOD(hitEvent : (NSString *)event)
{
    NSLog(@"------------------------------------HERE IN LIB---------------");
//    [XPush hitEvent : event];
}

RCT_EXPORT_MODULE()
@end
  
