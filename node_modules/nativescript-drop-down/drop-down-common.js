/*! *****************************************************************************
Copyright (c) 2015 Tangra Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
***************************************************************************** */
var __extends = (this && this.__extends) || function (d, b) {
    for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p];
    function __() { this.constructor = d; }
    d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
};
var proxy = require("ui/core/proxy");
var dependencyObservable = require("ui/core/dependency-observable");
var view = require("ui/core/view");
var types = require("utils/types");
var DROPDOWN = "DropDown";
function onSelectedIndexPropertyChanged(data) {
    var picker = data.object;
    picker._onSelectedIndexPropertyChanged(data);
}
function onItemsPropertyChanged(data) {
    var picker = data.object;
    picker._onItemsPropertyChanged(data);
}
var DropDown = (function (_super) {
    __extends(DropDown, _super);
    function DropDown() {
        _super.call(this);
    }
    Object.defineProperty(DropDown.prototype, "items", {
        get: function () {
            return this._getValue(DropDown.itemsProperty);
        },
        set: function (value) {
            this._setValue(DropDown.itemsProperty, value);
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(DropDown.prototype, "selectedIndex", {
        get: function () {
            return this._getValue(DropDown.selectedIndexProperty);
        },
        set: function (value) {
            this._setValue(DropDown.selectedIndexProperty, value);
        },
        enumerable: true,
        configurable: true
    });
    DropDown.prototype._onSelectedIndexPropertyChanged = function (data) {
        var index = this.selectedIndex;
        if (types.isUndefined(index)) {
            return;
        }
        if (types.isDefined(this.items)) {
            if (index < 0
                || index >= this.items.length) {
                this.selectedIndex = undefined;
                throw new Error("selectedIndex should be between [0, items.length - 1]");
            }
        }
    };
    DropDown.itemsProperty = new dependencyObservable.Property("items", DROPDOWN, new proxy.PropertyMetadata(undefined, dependencyObservable.PropertyMetadataSettings.AffectsLayout, onItemsPropertyChanged));
    DropDown.selectedIndexProperty = new dependencyObservable.Property("selectedIndex", DROPDOWN, new proxy.PropertyMetadata(undefined, dependencyObservable.PropertyMetadataSettings.AffectsLayout, onSelectedIndexPropertyChanged));
    return DropDown;
})(view.View);
exports.DropDown = DropDown;
