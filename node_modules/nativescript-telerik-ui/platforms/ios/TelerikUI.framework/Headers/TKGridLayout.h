//
//  TKGridLayout.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKLayout.h"

@class TKGridLayoutCellDefinition;

/**
 @discussion A class that is able to arrange views in grid layout.
 */
@interface TKGridLayout : NSObject <TKLayout>

/**
 The rect in which the views will be arranged.
 */
@property (nonatomic) CGRect frame;

/**
 An array containt cell definitions for the views that will be layed out.
 */
@property (nonatomic, strong, readonly) NSArray *definitions;

/**
 An array containing the views that will be layed out.
 */
@property (nonatomic, strong, readonly) NSArray *arrangedViews;

/**
 Layout's orientation.
 */
@property (nonatomic) TKLayoutOrientation orientation;

/**
 Horizontal spacing between the views.
 */
@property (nonatomic) CGFloat horizontalSpacing;

/**
 Vertical spacing between the views.
 */
@property (nonatomic) CGFloat verticalSpacing;

/**
 Instantiates TKGridLayout object.
 @param frame The layout's frame.
 @return TKGridLayout instance.
 */
- (id)initWithFrame:(CGRect)frame;

/**
 Adds arranged view.
 @param view The view that will be added to the layout.
 */
- (void)addArrangedView:(UIView *)view;

/**
 Inserts arranged view.
 @param view The view that will be inserted.
 @param index The index at which the view will be inserted.
 */
- (void)insertArrangedView:(UIView *)view atIndex:(NSUInteger)index;

/**
 Removes arranged view.
 @param view The view that will be remove.
 */
- (void)removeArrangedView:(UIView *)view;

/**
 Removes all arranged views.
 */
- (void)removeAllArrangedViews;

/**
 Adds definition for the specified view.
 @param view The view for which a definition will be added.
 @param row The row at wich the view will be layed out.
 @param column The column at which the view will be layed out.
 @param rowSpan Row span.
 @param columnSpan Column span.
 */
- (TKGridLayoutCellDefinition *)addDefinitionForView:(UIView *)view atRow:(NSNumber *)row column:(NSNumber *)column rowSpan:(NSInteger)rowSpan columnSpan:(NSInteger)columnSpan;

/**
 Adds cell definition to the layout.
 @param definition The definition that will be added.
 */
- (void)addDefinition:(TKGridLayoutCellDefinition *)definition;

/**
 Removes a definition
 @param definition The definition that will be removed.
 */
- (void)removeDefinition:(TKGridLayoutCellDefinition *)definition;

/**
 Removes all cell definitions.
 */
- (void)removeAllDefinitions;

/**
 Returns definition for specified view.
 @param view The view for which a definition will be returned.
 @return Cell definition for the specified view.
 */
- (TKGridLayoutCellDefinition *)definitionForView:(UIView *)view;

/**
 Sets width for specified column.
 @param width The width to be set.
 @param col The column for which width will be set.
 */
- (void)setWidth:(CGFloat)width forColumn:(NSInteger)col;

/**
 Sets height for specified row.
 @param height The height to be set.
 @param row The row for which height will be set.
 */
- (void)setHeight:(CGFloat)height forRow:(NSInteger)row;

/**
 Measures the size of the of the arranged views to fit in the specified size.
 @param size The size that the views must fit after arrangement.
 @return The optimal size to fit the desired size.
 */
- (CGSize)measurePreferredSizeThatFitsSize:(CGSize)size;

/**
 Lays out the arranged views.
 */
- (void)layoutArrangedViews;

@end
