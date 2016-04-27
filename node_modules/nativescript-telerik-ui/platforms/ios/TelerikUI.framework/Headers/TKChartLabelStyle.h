//
//  TKAxisLabelStyle.h
//  TelerikUI
//
//  Copyright (c) 2013 Telerik. All rights reserved.
//

#import "TKStyleNode.h"

/**
 * @discussion A class that represents a label's style.
 */
@interface TKChartLabelStyle : TKStyleNode

/**
 The label's font.
 */
@property (nonatomic, strong) UIFont * __nullable font;

/**
 The label's text color.
 */
@property (nonatomic, strong) UIColor * __nullable textColor;

/**
 The labels' text shadow color.
 */
@property  (nonatomic, strong) UIColor * __nullable shadowColor;

/**
 The labels' text shadow offset.
 */
@property  (nonatomic, assign) CGSize  shadowOffset;

/**
 Determines whether the label is hidden.
 */
@property (nonatomic, assign) BOOL textHidden;

@end

