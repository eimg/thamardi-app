//
//  TKListViewCellBackgroundView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKView.h"

@class TKCheckView;

@interface TKListViewCellBackgroundView : TKView

@property (nonatomic, strong, readonly, nonnull) TKCheckView *checkView;

@property (nonatomic) BOOL allowsMultipleSelection;

@property (nonatomic) BOOL isSelectedBackground;

@property (nonatomic) BOOL isVertical;

@property (nonatomic) CGFloat checkInset;

- (void)updateStyle;

@end
