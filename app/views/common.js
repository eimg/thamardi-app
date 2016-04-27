var application = require('application');
var appSettings = require("application-settings");
var webViewModule = require("ui/web-view");

var Observable = require("data/observable").Observable;
var data = new Observable();

var frameModule = require("ui/frame");

var l10n = require("./l10n");

var page;
var navTarget = "";

exports.reloadMain = function (args) {
	page = args.object;

	// Setting UI font based on user setting
	if(appSettings.getString("font") == "zawgyi") {
		data.lang = l10n.zawgyi;
	} else {
		data.lang = l10n.unicode;
	}

    page.bindingContext = data;

	// Hide activity indicator
	var indicator = page.getViewById("spinner");
	if(indicator) indicator.busy = false;
};

// Disabling zoom controls in WebView
exports.disableZoom = function (args) {
	var $this = args.object;
	if($this.android) {
		$this.android.getSettings().setBuiltInZoomControls(false);
	}
};

exports.toggleDrawer = function (args) {
	var sideDrawer = page.getViewById("sideDrawer");
	sideDrawer.toggleDrawerState();
};

exports.navigateTo = function (args) {
	if(navTarget) {
		frameModule.topmost().navigate({
			moduleName: navTarget,
			animated: false
		});

		navTarget = "";
	}
};

exports.showLength = function (args) {
	var sideDrawer = page.getViewById("sideDrawer");
	sideDrawer.toggleDrawerState();

	showIndicator();
	navTarget = "views/length/length";
};

exports.showMass = function (args) {
	var sideDrawer = page.getViewById("sideDrawer");
	sideDrawer.toggleDrawerState();

	showIndicator();
	navTarget = "views/mass/mass";
};

exports.showVolume = function (args) {
	var sideDrawer = page.getViewById("sideDrawer");
	sideDrawer.toggleDrawerState();

	showIndicator();
	navTarget = "views/volume/volume";
};

exports.showTime = function (args) {
	var sideDrawer = page.getViewById("sideDrawer");
	sideDrawer.toggleDrawerState();

	showIndicator();
	navTarget = "views/time/time";
};

exports.showAbout = function (args) {
	var sideDrawer = page.getViewById("sideDrawer");
	sideDrawer.toggleDrawerState();

	showIndicator();
	navTarget = "views/about/about";
};

exports.calcLengthModal = function (args) {
	page.showModal("./views/length/calcLength", {}, function () {
        //
    }, false);
};

exports.calcMassModal = function (args) {
	page.showModal("./views/mass/calcMass", {}, function () {
        //
    }, false);
};

exports.calcVolumeModal = function (args) {
	page.showModal("./views/volume/calcVolume", {}, function () {
        //
    }, false);
};

exports.calcTimeModal = function (args) {
	page.showModal("./views/time/calcTime", {}, function () {
        //
    }, false);
};

// Showing activity indicator on Page Switch
function showIndicator() {
	var indicator = page.getViewById("spinner");
	indicator.width = 100;
	indicator.height = 100;
	indicator.busy = true;
};

exports.switchToUnicode = function(args) {
	appSettings.setString("font", "unicode");

	frameModule.topmost().navigate({
		moduleName: "views/length/length",
		animated: false
	});
};

exports.switchToZawgyi = function(args) {
	appSettings.setString("font", "zawgyi");

	frameModule.topmost().navigate({
		moduleName: "views/length/length",
		animated: false
	});
};
