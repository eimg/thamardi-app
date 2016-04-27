//
//  TKAlertViewContentView.h
//  AlertView
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKView.h"

@class TKAlert;

/**
 The message body of an alert defined in a TKAlert object.
 */
@interface TKAlertContentView : TKView

/**
 The image view contained in TKAlert's content view.
 */
@property (nonatomic, strong, readonly, nonnull) UIImageView* imageView;

/**
 The text label contained in TKAalert's content view.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel* textLabel;

/**
 The alert instance owner of this content view.
 */
@property (nonatomic, weak) TKAlert *alert;

@end
