//
//  AVGeoPoint.h
//  Parse
//
//  Created by Henele Adams on 12/1/11.
//  Copyright (c) 2011 Parse, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/*!
 Object which may be used to embed a latitude / longitude point as the value for a key in a PFObject.
 PFObjects with a AVGeoPoint field may be queried in a geospatial manner using PFQuery's whereKey:nearGeoPoint:.
 
 This is also used as a point specifier for whereKey:nearGeoPoint: queries.
 
 Currently, object classes may only have one key associated with a GeoPoint type.
 */

@interface AVGeoPoint : NSObject<NSCopying>

/** @name Creating a AVGeoPoint */
/*!
 Create a AVGeoPoint object.  Latitude and longitude are set to 0.0.
 @result Returns a new AVGeoPoint.
 */
+ (AVGeoPoint *)geoPoint;

/*!
 Creates a new AVGeoPoint object for the given CLLocation, set to the location's
 coordinates.
 @param location CLLocation object, with set latitude and longitude.
 @result Returns a new AVGeoPoint at specified location.
 */
+ (AVGeoPoint *)geoPointWithLocation:(CLLocation *)location;

/*!
 Creates a new AVGeoPoint object with the specified latitude and longitude.
 @param latitude Latitude of point in degrees.
 @param longitude Longitude of point in degrees.
 @result New point object with specified latitude and longitude.
 */
+ (AVGeoPoint *)geoPointWithLatitude:(double)latitude longitude:(double)longitude;

/*!
 Fetches the user's current location and returns a new AVGeoPoint object via the
 provided block.
 @param geoPointHandler A block which takes the newly created AVGeoPoint as an
 argument.
 */
+ (void)geoPointForCurrentLocationInBackground:(void(^)(AVGeoPoint *geoPoint, NSError *error))geoPointHandler;

/** @name Controlling Position */

/// Latitude of point in degrees.  Valid range (-90.0, 90.0).
@property (nonatomic) double latitude;
/// Longitude of point in degrees.  Valid range (-180.0, 180.0).
@property (nonatomic) double longitude;

/** @name Calculating Distance */

/*!
 Get distance in radians from this point to specified point.
 @param point AVGeoPoint location of other point.
 @result distance in radians
 */
- (double)distanceInRadiansTo:(AVGeoPoint*)point;

/*!
 Get distance in miles from this point to specified point.
 @param point AVGeoPoint location of other point.
 @result distance in miles
 */
- (double)distanceInMilesTo:(AVGeoPoint*)point;

/*!
 Get distance in kilometers from this point to specified point.
 @param point AVGeoPoint location of other point.
 @result distance in kilometers
 */
- (double)distanceInKilometersTo:(AVGeoPoint*)point;


@end
