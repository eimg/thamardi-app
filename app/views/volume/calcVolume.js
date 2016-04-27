var appSettings = require("application-settings");

var Observable = require("data/observable").Observable;
var data = new Observable();

var frameModule = require("ui/frame");
var convert = require('convert-units/lib');

var l10n = require('../l10n');

var page;

var inputUnitSet;
var resultUnitSet;
var realUnits;

// Setting up initial value to converter
data.inputValue = 1;
data.inputUnit = 12;
data.resultValue = 3.78541;
data.resultUnit = 14;

exports.reloadMain = function (args) {
	page = args.object;

	// Setting up font based on user setting
	if(appSettings.getString("font") == "zawgyi") {
		data.lang = l10n.zawgyi;
		inputUnitSet = l10n.volumeUnitSetZg;
		resultUnitSet = l10n.volumeUnitSetZg;
		realUnits = l10n.realVolumeZg;
	} else {
		data.lang = l10n.unicode;
		inputUnitSet = l10n.volumeUnitSetUni;
		resultUnitSet = l10n.volumeUnitSetUni;
		realUnits = l10n.realVolumeUni;
	}

	data.inputUnitSet = inputUnitSet;
	data.resultUnitSet = resultUnitSet;

	page.bindingContext = data;
	convertUnit();
};

var convertUnit = function(args) {
	var inputValue = page.getViewById("inputValue").text;

	var inputUnit = page.getViewById("inputUnit").selectedIndex;
	var resultUnit = page.getViewById("resultUnit").selectedIndex;

	if(inputValue === 0) return false;
	if(inputUnit === undefined || resultUnit === undefined) return false;

	inputUnit = realUnits[ inputUnitSet[ inputUnit ] ];
	resultUnit = realUnits[ resultUnitSet[ resultUnit ] ];

	page.getViewById("resultValue").text = convert(inputValue).from(inputUnit).to(resultUnit);
};

exports.convertUnit = convertUnit;
