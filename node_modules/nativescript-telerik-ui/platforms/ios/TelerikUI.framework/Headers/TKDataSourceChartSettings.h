//
//  TKDataSourceChartSettings.h
//  TestDataSource
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKChartData.h"

@class TKChartSeries;
@class TKDataSourceGroup;

/**
 Defines a block function that is used when creating a new series in TKChart when using it with TKDataSource.
 
 @param group The group associated with the series. It can be nil if there is no grouping applied in TKDataSource.
 */
typedef TKChartSeries* __nullable (^TKDataSourceChartSettings_CreateSeriesBlock)(TKDataSourceGroup * __nullable group);

/**
 Defines a block function that is used when creating a new point in TKChart when using it with TKDataSource.
 
 @param seriesIndex The series index (or group index).
 @param dataIndex The point index within the series.
 @param item The item associated with this point.
 */
typedef id<TKChartData> __nullable (^TKDataSourceChartSettings_CreatePointBlock)(NSInteger seriesIndex, NSInteger dataIndex, id __nonnull item);

/**
 The settings that can be customized when using TKDataSource with TKChart.
 */
@interface TKDataSourceChartSettings : NSObject

/**
 Defines a block function that is called when creating a new series in TKChart.
 
 @param createSeries The block function that will be called when creating a new series.
 */
- (void)createSeries:(TKDataSourceChartSettings_CreateSeriesBlock __nonnull)createSeries;

/**
 Defines a block function that is called when creating a new point in TKChart.
 
 @param createPoint The block function that will be when creating a new point.
 */
- (void)createPoint:(TKDataSourceChartSettings_CreatePointBlock __nonnull)createPoint;

@end
