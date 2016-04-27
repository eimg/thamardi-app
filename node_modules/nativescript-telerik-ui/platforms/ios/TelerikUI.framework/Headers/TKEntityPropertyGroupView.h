//
//  TKEntityPropertyGroupView.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TKLayout.h"

@class TKEntityPropertyGroup;
@class TKEntityPropertyGroupEditorsView;
@class TKEntityPropertyGroupTitleView;

/**
 @discussion Represents a view that displays TKEntityGroup.
 */
@interface TKEntityPropertyGroupView : UIView

/**
 Title view for the group.
 */
@property (nonatomic, strong) TKEntityPropertyGroupTitleView *titleView;

/**
 View that contains editors for the properties in the group.
 */
@property (nonatomic, strong, readonly) TKEntityPropertyGroupEditorsView *editorsContainer;

/**
 A bool that determines if the group is collapsable.
 */
@property (nonatomic) BOOL collapsible;

/**
 The TKEntityPropertyGroup that this view represents.
 */
@property (nonatomic, strong, readonly) TKEntityPropertyGroup *group;

@end
