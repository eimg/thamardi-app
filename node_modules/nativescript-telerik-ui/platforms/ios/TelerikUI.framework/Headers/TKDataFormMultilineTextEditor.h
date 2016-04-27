//
//  TKDataFormMultilineTextEditor.h
//  TelerikUI
//
//  Copyright © 2015 Telerik. All rights reserved.
//

#import "TKDataFormEditor.h"

@interface TKDataFormMultilineTextEditor : TKDataFormEditor <UITextViewDelegate>

@property (nonatomic, strong, readonly) UITextView *textView;

@end
