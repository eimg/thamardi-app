//
//  TKAlertView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKView.h"

@class TKAlert;
@class TKAlertContentView;
@class TKAlertButtonsView;

/**
 The TKAlertView class is used to show the message defined by TKAlert object.
 */
@interface TKAlertView : TKView

/**
 The alert object containing TKAlertView.
 */
@property (nonatomic, weak) TKAlert *alert;

/**
 TKAlert's header view.
 */
@property (nonatomic, strong, readonly, nonnull) TKAlertContentView *headerView;

/**
 TKAlert's content view.
 */
@property (nonatomic, strong, readonly, nonnull) TKAlertContentView *contentView;

/**
 TKAlert's buttons view.
 */
@property (nonatomic, strong, readonly, nonnull) TKAlertButtonsView *buttonsView;

@end
