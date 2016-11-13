'use strict';

var Alexa = require('alexa-sdk');

var stateHandlers = {
    startModeIntentHandlers : Alexa.CreateStateHandler(constants.states.START_MODE, {
	'LaunchRequest' : function () {
            // Initialize Attributes
           
            //  Change state to START_MODE
            this.handler.state = constants.states.START_MODE;

            var message = 'Welcome to UK MedCheck. You can set prescriptions or check medications.';
            var reprompt = 'You can say, have I taken my medicine yet? for example';

            this.response.speak(message).listen(reprompt);
            this.emit(':responseReady');
        },

        'AMAZON.HelpIntent' : function () {
            var message = 'Come again?';
            this.response.speak(message).listen(message);
            this.emit(':responseReady');
        },
        'AMAZON.StopIntent' : function () {
            var message = 'Good bye.';
            this.response.speak(message);
            this.emit(':responseReady');
        },
        'AMAZON.CancelIntent' : function () {
            var message = 'Good bye.';
            this.response.speak(message);
            this.emit(':responseReady');
        },
        'SessionEndedRequest' : function () {
            // No session ended logic
        },
        'Unhandled' : function () {
            var message = 'Sorry, I could not understand. You can ask about medications.';
            this.response.speak(message).listen(message);
            this.emit(':responseReady');
        }
    })
}