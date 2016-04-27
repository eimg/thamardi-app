//
//  TKAlertAction.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKAlert;

/**
 This object represents an action that can be executed when tapping a button in an alert.
 */
@interface TKAlertAction : NSObject

/**
 The block that will execute when TKAlertAction's button is clicked.
 */
@property (nonatomic, copy) BOOL (^ __nullable handler)(TKAlert * __nonnull alert, TKAlertAction* __nonnull action);

/**
 The title.
 */
@property (nonatomic, strong, nullable) NSString* title;

/**
 The color of the title.
 */
@property (nonatomic, strong, nullable) UIColor* titleColor;

/**
 The background color.
 */
@property (nonatomic, strong, nullable) UIColor* backgroundColor;

/**
 The font.
 */
@property (nonatomic, strong, nullable) UIFont* font;

/**
 The tag.
 */
@property (nonatomic) NSInteger tag;

/**
 The corner radius.
 */
@property (nonatomic) CGFloat cornerRadius;

/**
 Initializes a TKAlertAction with a title and a block method to be called when the button of the action is tapped.
 @param title The title.
 @param handler The block method to be called when the button of the action is tapped.
 */
-(instancetype __nonnull)initWithTitle:(NSString * __nullable)title handler:(BOOL (^ __nullable)(TKAlert * __nonnull alert, TKAlertAction* __nonnull action))handler;

/**
 Initializes a TKAlertAction with a title and a block method to be called when the button of the action is tapped.
 @param title The title.
 @param handler The block method to be called when the button of the action is clicked.
 */
+(instancetype __nonnull)actionWithTitle:(NSString* __nullable)title handler:(BOOL (^ __nullable)(TKAlert * __nonnull alert, TKAlertAction* __nonnull action))handler;

@end
