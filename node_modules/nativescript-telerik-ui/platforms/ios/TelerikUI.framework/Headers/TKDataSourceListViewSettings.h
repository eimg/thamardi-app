//
//  TKDataSourceListViewSettings.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKListView;
@class TKListViewCell;
@class TKDataSource;
@class TKDataSourceGroup;
@class TKListViewReusableCell;
@class TKListViewHeaderCell;
@class TKListViewFooterCell;

/**
 Defines a block function that is used when creating a new cell in TKListView when using it with TKDataSource.
 
 @param listView The list view.
 @param indexPath The index path for the cell.
 @param item The item associated with this cell.
 */
typedef TKListViewCell*  __nullable (^TKDataSourceListViewSettings_CreateCellItemBlock)(TKListView * __nonnull listView, NSIndexPath * __nonnull indexPath, id  __nonnull item);

/**
 Defines a block function that is used when initializing cell properties in TKListView when using it with TKDataSource.
 
 @param listView The list view.
 @param indexPath The index path for the cell.
 @param cell The cell.
 @param item The item associated with this cell.
 */
typedef void (^TKDataSourceListViewSettings_InitCellWithItemBlock)(TKListView * __nonnull listView, NSIndexPath *  __nonnull indexPath, TKListViewCell *  __nonnull cell, id  __nonnull item);

/**
 Defines a block function that is used when creating a supplementaty view cell in TKListView when using it with TKDataSource.
 
 @param listView The list view.
 @param indexPath The index path for the cell.
 @param kind The cell kind.
 @param group The group associated with this cell.
 */
typedef TKListViewReusableCell* __nullable (^TKDataSourceListViewSettings_CreateViewBlock)(TKListView * __nonnull listView,
                                                                                           NSIndexPath *  __nonnull indexPath,
                                                                                           NSString *  __nonnull kind,
                                                                                           TKDataSourceGroup* __nullable group);

/**
 Defines a block function that is used when initializing a header cell in TKListView when using it with TKDataSource.
 
 @param listView The list view.
 @param indexPath The index path for the cell.
 @param headerCell The cell.
 @param group The group associated with this cell.
 */
typedef void (^TKDataSourceListViewSettings_InitHeaderCellWithItemBlock)(TKListView * __nonnull listView,
                                                                         NSIndexPath * __nonnull indexPath,
                                                                         TKListViewHeaderCell * __nonnull headerCell,
                                                                         TKDataSourceGroup * __nullable group);

/**
 Defines a block function that is used when initializing a footer cell in TKListView when using it with TKDataSource.
 
 @param listView The list view.
 @param indexPath The index path for the cell.
 @param footerCell The cell.
 @param group The group associated with this cell.
 */
typedef void (^TKDataSourceListViewSettings_InitFooterCellWithItemBlock)(TKListView *  __nonnull listView,
                                                                         NSIndexPath *  __nonnull indexPath,
                                                                         TKListViewFooterCell * __nonnull footerCell,
                                                                         TKDataSourceGroup * __nullable group);

/**
 The settings that can be customized when using TKDataSource with TKListView.
 */
@interface TKDataSourceListViewSettings : NSObject

/**
 The default cell identifier that will be used when calling dequeueReusableCellWithReuseIdentifier if no block is specified for creating cells.
 */
@property (nonatomic, strong, nonnull) NSString *defaultCellID;

/**
 The default cell class that will be registered in TKListView.
 */
@property (nonatomic, strong, nonnull) Class defaultCellClass;

/**
 A block function that is called when creating a new cell in TKListView.
 
 @param createCellBlock The block method that will be called.
 */
- (void)createCell:(TKDataSourceListViewSettings_CreateCellItemBlock __nonnull)createCellBlock;

/**
 A block function that is called when initializing the cell properties.
 @param initCellBlock The block method that will be called.
 */
- (void)initCell:(TKDataSourceListViewSettings_InitCellWithItemBlock __nonnull)initCellBlock;

/**
 A block function that is called when creating a supplementary view in TKListView.

 @param createViewBlock The block method that will be called.
 */
- (void)createSupplementaryView:(TKDataSourceListViewSettings_CreateViewBlock __nonnull)createViewBlock;

/**
 A block function that is called when initializing a header cell in TKListView.
 
 @param initHeaderBlock The block method that will be called.
 */
- (void)initHeader:(TKDataSourceListViewSettings_InitHeaderCellWithItemBlock __nonnull)initHeaderBlock;

/**
 A block function that is called when initializing a footer cell in TKListView.
 
 @param initFooterBlock The block method that will be called.
 */
- (void)initFooter:(TKDataSourceListViewSettings_InitFooterCellWithItemBlock __nonnull)initFooterBlock;

@end
