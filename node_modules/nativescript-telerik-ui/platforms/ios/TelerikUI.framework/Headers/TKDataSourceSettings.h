//
//  TKDataSourceSettings.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKDataSourceChartSettings;
@class TKDataSourceCollectionViewSettings;
@class TKDataSourceTableViewSettings;
@class TKDataSourceCalendarSettings;
@class TKDataSourceListViewSettings;
@class TKDataSourceAutoCompleteSettings;

/**
 Contains various settings allowing appearance customizations of TKDataSource consumers. e.g. TKChart, TKCalendar, UITableView, etc.
 */
@interface TKDataSourceSettings : NSObject

/**
 Settings specific to TKChart.
 */
@property (nonatomic, strong, readonly, nonnull) TKDataSourceChartSettings *chart;

/**
 Settings specific to UICollectionView.
 */
@property (nonatomic, strong, readonly, nonnull) TKDataSourceCollectionViewSettings *collectionView;

/**
 Settings specific to UITableView.
 */
@property (nonatomic, strong, readonly, nonnull) TKDataSourceTableViewSettings *tableView;

/**
 Settings specific to TKCalendar.
 */
@property (nonatomic, strong, readonly, nonnull) TKDataSourceCalendarSettings *calendar;

/**
 Settings specific to TKListView.
 */
@property (nonatomic, strong, readonly, nonnull) TKDataSourceListViewSettings *listView;

/**
 Settings specific to TKAutoComplete.
 */
@property (nonatomic, strong, readonly, nonnull) TKDataSourceAutoCompleteSettings *autocomplete;

@end
