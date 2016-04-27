//
//  TKDataSourceCalendarSettings.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

/**
 Represents the settings that can be customized when using TKDataSource with TKCalendar.
 */
@interface TKDataSourceCalendarSettings : NSObject

/**
 The property key which defines the item start date. Setting this property is required when using TKCalendar.
 */
@property (nonatomic, copy, nullable) NSString *startDateKey;

/**
 The property key which defines the item end date. Setting this property is required when using TKCalendar.
 */
@property (nonatomic, copy, nullable) NSString *endDateKey;

/**
 The property key which defines the item color. The defaultEventColor property is used when this property walue is not set.
 */
@property (nonatomic, copy, nullable) NSString *eventColorKey;

/**
 The default event color.
 */
@property (nonatomic, strong, nullable) UIColor *defaultEventColor;

@end
