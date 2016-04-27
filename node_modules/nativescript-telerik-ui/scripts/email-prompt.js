var inquirerModule = require('inquirer');
var emailValidatorModule = require('email-validator');
var fileSystemModule = require('fs');
var markerFileName = './.done';
var emailQuestion = {
    'name': 'email',
    'type': 'input',
    'message': 'Leave your e-mail address here to subscribe for NativeScript newsletter and UI for NativeScript product updates, tips and tricks (press Enter for blank): ',
    'default': undefined,
    'validate': function(input) {
        if (input === "") {
            return true;
        }

        if (emailValidatorModule.validate(input) === true) {
            return true;
        }

        return "Please provide a valid e-mail or simply leave it blank."
    }
};

function promptForEmail() {
    var markerExists = false;
    try {
        fileSystemModule.statSync(markerFileName)
        markerExists = true;
    } catch (e) {
        // Marker file doesn't exist
    }
    if (markerExists === false) {
        inquirerModule.prompt([emailQuestion],
            function(answers) {
                sendEmailInfo(answers['email'])
            });
    }
}

function sendEmailInfo(email) {
    if (email) {
        console.log('Email sent: ' + email);
        fileSystemModule.writeFileSync(markerFileName, "", "utf8");
    }
}

promptForEmail();