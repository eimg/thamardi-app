//
//  TKChartScatterSeries.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKChartSeries.h"

/**
 Represents scatter series. Check this [Guide](chart-series-scatter) for more information.
 
 <img src="../docs/images/chart-series-scatter001.png">
 
 @see [Working with TKChartScatterSeries](chart-series-scatter)
 
 */
@interface TKChartScatterSeries : TKChartSeries

/**
 If the distance between hit point is bigger, selection is cleared. By default, it is 8 pixels.
 */
@property (nonatomic, assign) CGFloat marginForHitDetection;

@end
