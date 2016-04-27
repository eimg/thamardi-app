"use strict";
var __extends = (this && this.__extends) || function (d, b) {
    for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p];
    function __() { this.constructor = d; }
    d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
};
var dependencyObservable = require("ui/core/dependency-observable");
var proxy = require("ui/core/proxy");
var view = require("ui/core/view");
var SideDrawerLocation;
(function (SideDrawerLocation) {
    SideDrawerLocation.Left = "Left";
    SideDrawerLocation.Right = "Right";
    SideDrawerLocation.Top = "Top";
    SideDrawerLocation.Bottom = "Bottom";
})(SideDrawerLocation = exports.SideDrawerLocation || (exports.SideDrawerLocation = {}));
var DrawerTransitionBase = (function () {
    function DrawerTransitionBase() {
    }
    DrawerTransitionBase.prototype.getNativeContent = function () {
        return undefined;
    };
    ;
    return DrawerTransitionBase;
}());
exports.DrawerTransitionBase = DrawerTransitionBase;
var DrawerStateChangingEventArgs = (function () {
    function DrawerStateChangingEventArgs() {
    }
    return DrawerStateChangingEventArgs;
}());
exports.DrawerStateChangingEventArgs = DrawerStateChangingEventArgs;
var DrawerStateChangedEventArgs = (function () {
    function DrawerStateChangedEventArgs() {
    }
    return DrawerStateChangedEventArgs;
}());
exports.DrawerStateChangedEventArgs = DrawerStateChangedEventArgs;
var RadSideDrawer = (function (_super) {
    __extends(RadSideDrawer, _super);
    function RadSideDrawer() {
        _super.call(this);
        this._isOpen = false;
    }
    RadSideDrawer.onGesturesEnabledPropertyChanged = function (eventData) {
        var classInstance = eventData.object;
        classInstance._onGesturesEnabledChanged(eventData);
    };
    RadSideDrawer.onDrawerTransitionChanged = function (eventData) {
        var classInstance = eventData.object;
        classInstance._onDrawerTransitionChanged(eventData);
    };
    RadSideDrawer.onDrawerContentSizeChanged = function (eventData) {
        var classInstance = eventData.object;
        classInstance._onDrawerContentSizeChanged(eventData);
    };
    RadSideDrawer.onDrawerLocationPropertyChanged = function (eventData) {
        var classInstance = eventData.object;
        classInstance._onDrawerLocationChanged(eventData);
    };
    RadSideDrawer._onMainContentPropertyChanged = function (eventData) {
        var classInstance = eventData.object;
        classInstance._onMainContentChanged(eventData);
    };
    RadSideDrawer._onDrawerContentPropertyChanged = function (eventData) {
        var classInstance = eventData.object;
        classInstance._onDrawerContentChanged(eventData);
    };
    RadSideDrawer.prototype._onMainContentChanged = function (eventData) { };
    ;
    RadSideDrawer.prototype._onDrawerContentChanged = function (eventData) { };
    ;
    RadSideDrawer.prototype._onDrawerLocationChanged = function (eventData) { };
    ;
    RadSideDrawer.prototype._onDrawerTransitionChanged = function (eventData) { };
    ;
    RadSideDrawer.prototype._onDrawerContentSizeChanged = function (eventData) { };
    ;
    RadSideDrawer.prototype._onGesturesEnabledChanged = function (eventData) { };
    ;
    Object.defineProperty(RadSideDrawer.prototype, "drawerTransition", {
        get: function () {
            return this._getValue(RadSideDrawer.drawerTransitionProperty);
        },
        set: function (value) {
            this._setValue(RadSideDrawer.drawerTransitionProperty, value);
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadSideDrawer.prototype, "drawerContentSize", {
        get: function () {
            return this._getValue(RadSideDrawer.drawerContentSizeProperty);
        },
        set: function (value) {
            this._setValue(RadSideDrawer.drawerContentSizeProperty, value);
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadSideDrawer.prototype, "drawerLocation", {
        get: function () {
            return this._getValue(RadSideDrawer.drawerLocationProperty);
        },
        set: function (value) {
            this._setValue(RadSideDrawer.drawerLocationProperty, value);
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadSideDrawer.prototype, "drawerContent", {
        get: function () {
            return this._getValue(RadSideDrawer.drawerContentProperty);
        },
        set: function (value) {
            this._setValue(RadSideDrawer.drawerContentProperty, value);
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadSideDrawer.prototype, "mainContent", {
        get: function () {
            return this._getValue(RadSideDrawer.mainContentProperty);
        },
        set: function (value) {
            this._setValue(RadSideDrawer.mainContentProperty, value);
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadSideDrawer.prototype, "gesturesEnabled", {
        get: function () {
            return this._getValue(RadSideDrawer.gesturesEnabledProperty);
        },
        set: function (value) {
            this._setValue(RadSideDrawer.gesturesEnabledProperty, value);
        },
        enumerable: true,
        configurable: true
    });
    RadSideDrawer.prototype.showDrawer = function () {
    };
    RadSideDrawer.prototype.closeDrawer = function () {
    };
    RadSideDrawer.prototype.getIsOpen = function () {
        var androidIsOpen = false;
        var iosIsOpen = false;
        if (this.android) {
            androidIsOpen = this.android.getIsOpen();
        }
        if (this.ios) {
            iosIsOpen = this.ios.defaultSideDrawer.isVisible;
        }
        var result = androidIsOpen || iosIsOpen;
        if (result) {
            return result;
        }
        return false;
    };
    RadSideDrawer.prototype.toggleDrawerState = function () {
        if (this.getIsOpen()) {
            this.closeDrawer();
        }
        else {
            this.showDrawer();
        }
    };
    Object.defineProperty(RadSideDrawer.prototype, "_childrenCount", {
        get: function () {
            var count = 0;
            if (this.drawerContent) {
                count++;
            }
            if (this.mainContent) {
                count++;
            }
            return count;
        },
        enumerable: true,
        configurable: true
    });
    RadSideDrawer.prototype._eachChildView = function (callback) {
        if (this.mainContent) {
            callback(this.mainContent);
        }
        if (this.drawerContent) {
            callback(this.drawerContent);
        }
    };
    Object.defineProperty(RadSideDrawer.prototype, "android", {
        get: function () {
            return undefined;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(RadSideDrawer.prototype, "ios", {
        get: function () {
            return undefined;
        },
        enumerable: true,
        configurable: true
    });
    RadSideDrawer.drawerOpeningEvent = "drawerOpening";
    RadSideDrawer.drawerOpenedEvent = "drawerOpened";
    RadSideDrawer.drawerClosingEvent = "drawerClosing";
    RadSideDrawer.drawerClosedEvent = "drawerClosed";
    RadSideDrawer.gesturesEnabledProperty = new dependencyObservable.Property("gesturesEnabled", "RadSideDrawer", new proxy.PropertyMetadata(true, dependencyObservable.PropertyMetadataSettings.None, RadSideDrawer.onGesturesEnabledPropertyChanged));
    RadSideDrawer.drawerTransitionProperty = new dependencyObservable.Property("drawerTransition", "RadSideDrawer", new proxy.PropertyMetadata(undefined, dependencyObservable.PropertyMetadataSettings.AffectsLayout, RadSideDrawer.onDrawerTransitionChanged));
    RadSideDrawer.drawerContentSizeProperty = new dependencyObservable.Property("drawerContentSize", "RadSideDrawer", new proxy.PropertyMetadata(280, dependencyObservable.PropertyMetadataSettings.AffectsLayout, RadSideDrawer.onDrawerContentSizeChanged));
    RadSideDrawer.drawerLocationProperty = new dependencyObservable.Property("drawerLocation", "RadSideDrawer", new proxy.PropertyMetadata(SideDrawerLocation.Left, dependencyObservable.PropertyMetadataSettings.AffectsLayout, RadSideDrawer.onDrawerLocationPropertyChanged));
    RadSideDrawer.mainContentProperty = new dependencyObservable.Property("mainContent", "RadSideDrawer", new proxy.PropertyMetadata(undefined, dependencyObservable.PropertyMetadataSettings.AffectsLayout, RadSideDrawer._onMainContentPropertyChanged));
    RadSideDrawer.drawerContentProperty = new dependencyObservable.Property("drawerContent", "RadSideDrawer", new proxy.PropertyMetadata(undefined, dependencyObservable.PropertyMetadataSettings.AffectsLayout, RadSideDrawer._onDrawerContentPropertyChanged));
    return RadSideDrawer;
}(view.View));
exports.RadSideDrawer = RadSideDrawer;
