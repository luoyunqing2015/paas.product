//
//  paas.h
//  paas
//
//  Created by Zhu Zeng on 2/25/13.
//  Copyright (c) 2013 AVOS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVConstants.h"
#import "AVGeoPoint.h"
#import "AVObject.h"
#import "AVQuery.h"
#import "AVUser.h"
#import "AVFile.h"
#import "AVAnonymousUtils.h"
#import "AVACL.h"

@interface AVPaas : NSObject

/** @name Connecting to Parse */

/*!
 Sets the applicationId and clientKey of your application.
 @param applicationId The applicaiton id for your Parse application.
 @param applicationId The client key for your Parse application.
 */
+ (void)setApplicationId:(NSString *)applicationId clientKey:(NSString *)clientKey;
+ (NSString *)getApplicationId;
+ (NSString *)getClientKey;

#if PAAS_IOS_ONLY
/** @name Configuring Facebook Settings */

/*!
 Sets the Facebook application id that you are using with your Parse application. You must set this in
 order to use the Facebook functionality in Parse.
 @param applicationId The Facebook application id that you are using with your Parse application.
 */
+ (void)setFacebookApplicationId:(NSString *)applicationId __attribute__ ((deprecated));

/*!
 Whether the Facebook application id has been set.
 */
+ (BOOL)hasFacebookApplicationId __attribute__ ((deprecated));

/** @name Configuring UI Settings */

/*!
 Set whether to show offline messages when using a Parse view or view controller related classes.
 @param enabled Whether a UIAlert should be shown when the device is offline and network access is required
 from a view or view controller.
 */
+ (void)offlineMessagesEnabled:(BOOL)enabled;

/*!
 Set whether to show an error message when using a Parse view or view controller related classes
 and a Parse error was generated via a query.
 @param enabled Whether a UIAlert should be shown when a Parse error occurs.
 */
+ (void)errorMessagesEnabled:(BOOL)enabled;
+ (NSString *)getFacebookApplicationId __attribute__ ((deprecated));
#endif


@end
