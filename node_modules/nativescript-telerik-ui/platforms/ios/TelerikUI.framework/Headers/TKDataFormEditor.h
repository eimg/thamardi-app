//
//  TKDataFormCell.h
//  TelerikUI
//
//  Copyright (c) 2015 Telerik. All rights reserved.
//

@class TKEntityProperty;
@class TKDataFormEditorStyle;
@class TKDataForm;
@class TKGridLayout;
@class TKView;
@class TKLabel;
@class TKImageView;
/**
 The base editor class used in TKDataForm.
 */
@interface TKDataFormEditor : UIView

/**
 The TKDataForm which owns the editor.
 */
@property (nonatomic, weak) TKDataForm *owner;

/**
 The grid layout used to layout the editor.
 */
@property (nonatomic, strong, readonly, nonnull) TKGridLayout *gridLayout;

/**
 The view shown when the editor is selected.
 */
@property (nonatomic, strong, nullable) TKView *selectedView;

/**
 The selected state of the editor.
 */
@property (nonatomic, readonly) BOOL selected;

/**
 *  Determines if the editor is enabled.
 */
@property (nonatomic) BOOL enabled;

/**
 The text label of the editor (read-only).
 */
@property (nonatomic, strong, readonly, nonnull) TKLabel *textLabel;

/**
 The image view of the editor (read-only).
 */
@property (nonatomic, strong, readonly, nonnull) TKImageView *imageView;

/**
 The validation image view in TKDataFormEditor (read-only).
 */
@property (nonatomic, strong, readonly, nonnull) TKImageView *feedbackImageView;

/**
 The validation text label in TKDataFormEditor.
 */
@property (nonatomic, strong, readonly, nonnull) UILabel *feedbackLabel;

/**
 @return The control used to edit a property.
 */
@property (nonatomic, strong, readonly, nonnull) UIView *editor;

/**
 The object responsible for TKDataFormEditor's styling and customization.
 */
@property (nonatomic, strong, readonly, nonnull) TKDataFormEditorStyle *style;

/**
 The property that is edited by this editor.
 */
@property (nonatomic, strong, nonnull) TKEntityProperty *property;

/**
 The TKDataFormEditor's value.
 */
@property (nonatomic, nullable) id value;

/**
 *  Determines if this editor will edit text.
 */
@property (nonatomic, readonly) BOOL isTextEditor;

/**
 Initializes a TKDataFormEditor with an entity property.
 @param property The entity property used for creating TKDataFormEditor.
 */
- (instancetype __nonnull)initWithProperty:(TKEntityProperty * __nonnull)property;

/**
 *  Initializes a TKDataFormEditor with an entity property.
 *
 *  @param property The entity property used for creating TKDataFormEditor.
 *  @param owner    TKDataForm that will show this editor.
 *
 *  @return TKDataFormEditor instance.
 */
- (instancetype __nonnull)initWithProperty:(TKEntityProperty * __nonnull)property owner:(TKDataForm * __nonnull)owner;

/**
 Updates the value of the editor when the property value candidate is changed.
 */
- (void)updateControlValue;

/**
 Updates the visuals of editor.
 */
- (void)update;

@end
