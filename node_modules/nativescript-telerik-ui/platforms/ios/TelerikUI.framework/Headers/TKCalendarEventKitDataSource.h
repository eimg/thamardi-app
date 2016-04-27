//
//  TKCalendarPhoneDataSource.h
//  Telerik UI
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

#import "TKCalendar.h"
#import <EventKit/EventKit.h>

/**
 @discussion The methods declared by the TKCalendarEventKitDataSourceDelegate protocol allow customizing the process of importing events from EventKit.
 */
@protocol TKCalendarEventKitDataSourceDelegate<NSObject>

@optional

/**
 Defines whether events from the specified EKCalendar should be imported.
 
 @param calendar The calendar to import.
 
 @return Returns YES if events should be imported.
 */
- (BOOL)shouldImportEventsFromCalendar:(EKCalendar* __nonnull)calendar;

/**
 Determines whether the specified EKEvent should be imported.
 
 @param event The event to import.
 
 @return Returns YES if the event should be imported.
 */
- (BOOL)shouldImportEvent:(EKEvent* __nonnull)event;

@end

/**
 @discussion A data source that can be used with TKCalendar component to read dates stored on the device by using the EventKit API.
 Import EventKit and EventKitUI frameworks when using this class.
 */
@interface TKCalendarEventKitDataSource : NSObject <TKCalendarDataSource>

/**
 A delegate for customizing the import process when reading events from EventKit.
 */
@property (nonatomic, weak) id<TKCalendarEventKitDataSourceDelegate> delegate;

/**
 Returns a list with calendars available when using EventKit.

 @return An array with instances of EKCalendar class.
 */
@property (nonatomic, strong, readonly) NSArray* __nullable calendars;

/**
 Gets a list with calendars available when using EventKit asyncronously.
 @param callbackBlock A callback that will be executed after calendars are fetched.
 */
- (void)getCalendarsWithBlock:(void (^ __nullable)(NSArray * __nullable))callbackBlock;

/**
 Creates a new object adopting the TKCalendarEventProtocol protocol.
 
 @param event    The corresponding EKEvent class.
 @param calendar The corresponding EKCalendar class.
 
 @return An instance of an object implementing the TKCalendarEventProtocol protocol.
 */
- (id<TKCalendarEventProtocol> __nullable)createCalendarEvent:(EKEvent* __nullable)event inCalendar:(EKCalendar* __nullable)calendar;

@end
