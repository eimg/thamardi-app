//
//  TKAlertViewContentView.h
//  AlertView
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import "TKStyleNode.h"

/**
 @enum TKAlertAppearAnimation
 @discussion Defines the animation by which TKAlery shows up.
 */
typedef NS_ENUM(NSInteger, TKAlertAnimation)
{
    /**
     Scale in.
     */
    TKAlertAnimationScale,
    
    /**
     Fade in.
     */
    TKAlertAnimationFade,
    
    /**
     Slide in from left.
     */
    TKAlertAnimationSlideFromLeft,
    
    /**
     Slide in from top.
     */
    TKAlertAnimationSlideFromTop,
    
    /**
     Slide in from right.
     */
    TKAlertAnimationSlideFromRight,
    
    /**
     Slide in from bottom.
     */
    TKAlertAnimationSlideFromBottom,
};

/**
 @enum TKAlertBackgroundStyle
 @discussion Defines the type of the TKAlert background.
 */
typedef NS_ENUM(NSInteger, TKAlertBackgroundStyle)
{
    /**
     Blurred background.
     */
    TKAlertBackgroundStyleBlur,
    
    /**
     Dimmed background.
     */
    TKAlertBackgroundStyleDim,
    
    /**
     No background
     */
    TKAlertBackgroundStyleNone,
};

/**
 Reprsents the alert message style when using TKAlert.
 */
@interface TKAlertStyle : TKStyleNode

/**
 The height of header view.
 */
@property (nonatomic) CGFloat headerHeight;

/**
 The height of content view.
 */
@property (nonatomic) CGFloat contentHeight;

/**
 The corner radius of the view.
 */
@property (nonatomic) CGFloat cornerRadius;

/**
 The width of the gap between the headerView and the contentView.
*/
@property (nonatomic) CGFloat titleSeparatorWidth;

/**
 The width of the gap between the contentView and the buttonsView.
 */
@property (nonatomic) CGFloat contentSeparatorWidth;

/**
 The maximum possible width of TKAlert.
 */
@property (nonatomic) CGFloat maxWidth;

/**
 The animation by which TKAlert appears and hides.
 -TKAlertAnimationScale,
 -TKAlertAnimationFade,
 -TKAlertAnimationSlideFromLeft,
 -TKAlertAnimationSlideFromTop,
 -TKAlertAnimationSlideFromRight,
 -TKAlertAnimationSlideFromBottom,
 */
@property (nonatomic) TKAlertAnimation showAnimation;

/**
 The animation by which TKAlert appears and hides.
 -TKAlertAnimationScale,
 -TKAlertAnimationFade,
 -TKAlertAnimationSlideFromLeft,
 -TKAlertAnimationSlideFromTop,
 -TKAlertAnimationSlideFromRight,
 -TKAlertAnimationSlideFromBottom,
 */
@property (nonatomic) TKAlertAnimation dismissAnimation;

/**
 The style of TKAlert's background.
 -TKAlertViewBackgroundStyleDim,
 -TKAlertBackgroundStyleBlur,
 -TKAlertBackgroundStyleClear
 */
@property (nonatomic) TKAlertBackgroundStyle backgroundStyle;

/**
 The background color of TKAlert.
 */
@property (nonatomic, strong, nullable) UIColor* backgroundColor;

/**
 The tint color of TKAlert's background.
 */
@property (nonatomic, strong, nullable) UIColor* backgroundTintColor;

/**
 The value of TKAlert's dim background opacity.
 */
@property (nonatomic) CGFloat backgroundDimAlpha;

/**
 The spacing between every two action buttons.
 */
@property (nonatomic) CGFloat buttonSpacing;

/**
 The height the action buttons.
 */
@property (nonatomic) CGFloat buttonHeight;

/**
 The title color.
 */
@property (nonatomic, strong, nullable) UIColor* titleColor;

/**
 The message color.
 */
@property (nonatomic, strong, nullable) UIColor* messageColor;

 /**
 The content insets relative to its view size.
 */
@property (nonatomic) UIEdgeInsets contentInset;

/**
 The buttons insets.
 */
@property (nonatomic) UIEdgeInsets buttonsInset;

/**
 Determines whether the custom frame will be centered in screen.
 */
@property (nonatomic) BOOL centerFrame;

@end
