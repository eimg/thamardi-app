//
//  TKAlertViewContentView.h
//  AlertView
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKAlert;
@class TKAlertStyle;
@class TKAlertAction;
@class TKAlertView;
@class TKAlertContentView;
@class TKAlertButtonsView;
@class TKAView;

/**
 @enum TKAlertSwipeDismissDirection
 @discussion Defines the orientations(s) at which TKAlert can be panned.
 */
typedef NS_ENUM(NSInteger, TKAlertSwipeDismissDirection)
{
    /**
     Left or Right.
     */
    TKAlertSwipeDismissDirectionHorizontal,

    /**
     Up or Down (default).
     */
    TKAlertSwipeDismissDirectionVertical
};

/**
 @enum TKAlertActionsLayout
 @discussion Defines the possible button actions alignments.
 */
typedef NS_ENUM(NSInteger, TKAlertActionsLayout)
{
    /**
     Horizontal layout.
     */
   TKAlertActionsLayoutHorizontal,

    /**
    Vertical layout.
     */
   TKAlertActionsLayoutVertical,
};

/**
 @enum TKAlertDismisMode
 @discussion Defines the gesture by which TKAlery can be dismissed.
 */
typedef NS_ENUM(NSInteger, TKAlertDismissMode)
{
    /**
     The alert can not be dismissed by using a gesture.
     */
    TKAlertDismissModeNone,

    /**
     The alert can be dismissed by using a tap gesture.
     */
    TKAlertDismissModeTap,
    
    /**
     The alert can be dismissed by using a pan gesture.
     */
    TKAlertDismissModeSwipe,
};

/**
 The delegate of a TKAlert object must adopt the TKAlertDelegate protocol.
 */
@protocol TKAlertDelegate <NSObject>
@optional

/** 
Returns the UIButton object for the specified TKAlertAction.
 @param alert The TKAlert object.
 @param action The concrete action.
 */
-(UIButton * __nonnull)alert:(TKAlert * __nonnull)alert buttonForAction:(TKAlertAction * __nonnull)action;

/**
 This method is called after TKAlert has been dismissed.
 @param alert The TKAlert object.
 @param action The action that dismissed the alert.
 */
-(void) alert:(TKAlert * __nonnull)alert didDismissWithAction:(TKAlertAction * __nonnull)action;

/**
 Called before TKAlert is shown.
 @param alert The TKAlert object.
 */
-(void) alertWillShow:(TKAlert * __nonnull)alert;

/**
 Called after TKAlert has been shown.
 @param alert The TKAlert object.
 */
-(void) alertDidShow:(TKAlert * __nonnull)alert;

/**
 Called before TKAlert is dismissed.
 @param alert The TKAlert object.
 */
-(void) alertWillDismiss:(TKAlert * __nonnull)alert;

/**
 This method is called after TKAlert was dismissed.
 @param alert The TKAlert object.
 */
-(void) alertDidDismiss:(TKAlert * __nonnull)alert;

@end

/**
 A TKAlert object displays an alert message to the user. It is highly customizable and you can place your own view in it. It supports three predefined show/dismiss animations: scale, slide, fade. You can also dim or blur the background as the TKAlert appears.
 */
@interface TKAlert : NSObject <UIGestureRecognizerDelegate>

/**
 TKAlert's delegate.
 */
@property (nonatomic, weak) id <TKAlertDelegate> delegate;

/**
 The title used by the header view.
 */
@property (nonatomic, strong, nullable) NSString *title;

/**
 The attributed title used by the header view.
 */
@property (nonatomic, strong, nullable) NSAttributedString * attributedTitle;

/**
 The message used by the custom view.
 */
@property (nonatomic, strong, nullable) NSString *message;

/**
 The attributed message used by the custom view.
 */
@property (nonatomic, strong, nullable) NSAttributedString * attributedMessage;

/**
 Determines if TKAlert's view is displayed on screen.
 */
@property (nonatomic, getter=isVisible) BOOL visible;

/** 
Determines the dismiss mode used in TKAlert.
 - TKAlertDismissModeSwipe - allows user to dismiss the alert by a swipe gesture.
 - TKAlertDismissModeTap - allows user to dismiss the alert by a tap gesture anywhere on the screen.
 - TKAlertDismissNone - the user is allowed to dismiss the alert only by tapping one of the actions (buttons).
*/
@property (nonatomic) TKAlertDismissMode dismissMode;

/**
Determines if the dismiss direction is vertical or horizontal. This property affects TKAlert only if dismissMode = TKAlertDismissModeSwipe
*/
@property (nonatomic) TKAlertSwipeDismissDirection swipeDismissDirection;

/**
This is the amount of time the TKAlert stay on the screen before dismissing itself automatically.
 */
@property (nonatomic) NSTimeInterval dismissTimeout;

/**
 Determines if the parallax effect should be applied.
 */
@property (nonatomic) BOOL allowParallaxEffect;

/**
 The view that contains headerView, contentView, buttonsView in itself (read-only).
 */
@property (nonatomic, strong, readonly, nonnull) TKAlertView *alertView;

/**
 The header view (read-only).
 */
@property (nonatomic, strong, readonly, nonnull) TKAlertContentView *headerView;

/**
 The content view (read-only).
 */
@property (nonatomic, strong, readonly, nonnull) TKAlertContentView *contentView;

/**
The buttons view (read-only).
 */
@property (nonatomic, strong, readonly, nonnull) TKAlertButtonsView *buttonsView;

/**
 The object responsible for the style of TKAlert.
 */
@property (nonatomic, strong, readonly, nonnull) TKAlertStyle *style;

/**
 The default tint color to be used with TKAlert content.
 */
@property (nonatomic, strong, nullable) UIColor *tintColor;

/**
The custom frame used for TKAlert.
 */
@property (nonatomic) CGRect customFrame;

/**
 The layout object used to arrange buttons.
 */
@property (nonatomic) TKAlertActionsLayout actionsLayout;

/**
 All the actions in TKAlert.
 */
@property (nonatomic, strong, readonly, nonnull) NSArray <__kindof TKAlertAction* > * actions;

/**
 The animation duration of TKAlertAnimation.
 */
@property (nonatomic) CGFloat animationDuration;

/**
 Initializes a TKAlert with a title, a message, a delegate and actions.
 @param title The title.
 @param message The  message.
 @param delegate The delegate.
 @param cancelActionTitle The title of the first action.
 @param title1 Titles for the rest of the buttons. 
 @param ... Other button titles.
 */
-(instancetype __nonnull)initWithTitle:(NSString* __nullable)title
                     message:(NSString* __nullable)message
                    delegate:(id  __nullable)delegate
           cancelActionTitle:(NSString *  __nullable)cancelActionTitle
           otherActionTitles:(id  __nullable)title1, ...;

/**
 Displays TKAlertView on the screen using the chosen show animation.
 @param animated Determines if TKAlert will show with or without an animation.
 */
-(void)show:(BOOL)animated;

/**
 Hides TKAlertView using the chosen dismiss animation.
 @param animated Determines if TKAlert will show with or without an animation.
 */
-(void)dismiss:(BOOL)animated;

/**
 Shakes TKAlert.
 */
-(void)shake;

/**
 This method adds an action to TKAlert.
 @param action The action to be added.
 */
-(void)addAction:(TKAlertAction* __nonnull) action;

/**
Creates and adds an action to TKAlert.
 @param title The title.
 @param handler The block that is called after the action is tapped.
 */
-(TKAlertAction* __nonnull)addActionWithTitle:(NSString* __nullable)title handler:(BOOL (^ __nullable)(TKAlert * __nonnull alert, TKAlertAction* __nonnull action))handler;

/**
 Removes an action from TKAlert at the given index.
 @param index The index of TKAlertAction to be removed.
 */
-(void)removeActionAtIndex:(NSInteger) index;

/**
 Removes an action from TKAlert.
 @param action The TKAlertAction to be removed.
 */
-(void)removeAction:(TKAlertAction* __nonnull) action;

/**
 Returns the action at a given index.
 @param index The action index.
 */
-(TKAlertAction* __nullable)actionAtIndex:(NSInteger) index;

@end