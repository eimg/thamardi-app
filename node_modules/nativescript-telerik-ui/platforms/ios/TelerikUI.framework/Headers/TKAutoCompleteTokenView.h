//
//  TKAutoCompleteTokenView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKView.h"

@class TKAutoCompleteToken;
@class TKAutoCompleteTextView;
@class TKAutoCompleteTokenRemoveButton;

/**
 Defines the token visual object.
 */
@interface TKAutoCompleteTokenView : TKView<UIKeyInput>

/**
 The text label showing the token text.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel* textLabel;

/**
 The image view representing the token image.
 */
@property (nonatomic, strong, readonly, nonnull) UIImageView* imageView;

/**
 The token remove button.
 */
@property (nonatomic, strong, nonnull) UIButton *removeButton;

/**
 The highlighted view.
 */
@property (nonatomic, strong, nonnull) UIView *highlightedView;

/**
 Defines whether or not the token is highlighted.
 */
@property (nonatomic) BOOL isHighlighted;

/**
 Token inset.
 */
@property (nonatomic) CGFloat tokenInset;

/**
 The TKAutoCompleteView in which the token presents.
 */
@property (nonatomic, weak) TKAutoCompleteTextView *owner;

/**
 The data model object.
 */
@property (nonatomic, weak, nullable) TKAutoCompleteToken *token;

/**
 Initializes the TKAutoCompleteTokenView with token object model.
 @param token The token objec model.
 */
-(instancetype __nonnull)initWithToken:(TKAutoCompleteToken * __nonnull)token;

@end
