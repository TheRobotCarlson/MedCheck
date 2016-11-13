'use strict';

var constants = require('./constants');
var https     = require('https');
var firebase = require("firebase");
var database = null;



exports.handler = function(event, context, callback){

 try {
        console.log("event.session.application.applicationId=" + event.session.application.applicationId);


if(database === null){
        var config = {
	apiKey: constants.apiKey,
	authDomain: constants.authDomain,
	databaseURL: constants.databaseURL,
	storageBucket: constants.storageBucket,
};
firebase.initializeApp(config);
    database = firebase.database();
}
        /**
         * Uncomment this if statement and populate with your skill's application ID to
         * prevent someone else from configuring a skill that sends requests to this function.
         */
		 
//     if (event.session.application.applicationId !== "amzn1.echo-sdk-ams.app.05aecccb3-1461-48fb-a008-822ddrt6b516") {
//         context.fail("Invalid Application ID");
//      }

        if (event.session.new) {
            onSessionStarted({requestId: event.request.requestId}, event.session);
        }

        if (event.request.type === "LaunchRequest") {
            onLaunch(event.request,
                event.session,
                function callback(sessionAttributes, speechletResponse) {
                    context.succeed(buildResponse(sessionAttributes, speechletResponse));
                });
        } else if (event.request.type === "IntentRequest") {
            onIntent(event.request,
                event.session,
                function callback(sessionAttributes, speechletResponse) {
                    context.succeed(buildResponse(sessionAttributes, speechletResponse));
                });
                console.log("made it");
			
        } else if (event.request.type === "SessionEndedRequest") {
            onSessionEnded(event.request, event.session);
            context.succeed();
        }else{
			var message = 'Sorry, I could not understand. You can ask about medications.';
            this.response.speak(message).listen(message);
            this.emit(':responseReady');
		}
    } catch (e) {
        context.fail("Exception: " + e);
    }
    
	
};

/**
 * Called when the session starts.
 */
function onSessionStarted(sessionStartedRequest, session) {
    console.log("onSessionStarted requestId=" + sessionStartedRequest.requestId
        + ", sessionId=" + session.sessionId);


if(database === null){
        var config = {
	apiKey: constants.apiKey,
	authDomain: constants.authDomain,
	databaseURL: constants.databaseURL,
	storageBucket: constants.storageBucket,
};
firebase.initializeApp(config);
    database = firebase.database();
}

    // add any session init logic here
}

/**
 * Called when the user invokes the skill without specifying what they want.
 */
function onLaunch(launchRequest, session, callback) {
    console.log("onLaunch requestId=" + launchRequest.requestId
        + ", sessionId=" + session.sessionId);

    var cardTitle = "MedBot";
    var speechOutput = "You can ask MedCheck to check or update medications";
    callback(session.attributes,
        buildSpeechletResponse(cardTitle, speechOutput, "", true));
}

/**
 * Called when the user specifies an intent for this skill.
 */
function onIntent(intentRequest, session, callback) {
    console.log("onIntent requestId=" + intentRequest.requestId
        + ", sessionId=" + session.sessionId);

    var intent = intentRequest.intent,
        intentName = intentRequest.intent.name;
		
	// dispatch custom intents to handlers here
    if (intentName == 'CheckPrescriptionIntent') {
        handleCheckRequest(intent, session, callback);
    }
	else if(intentName == 'SetPrescriptionIntent'){
		handleSetRequest(intent, session, callback);
	}
    else {
        buildSpeechletResponseWithoutCard("That's not an option", "", "true");
    }
	
	console.log("intent: ",intent.name);
//    handleTestRequest(intent, session, callback);
}

/**
 * Called when the user ends the session.
 * Is not called when the skill returns shouldEndSession=true.
 */
function onSessionEnded(sessionEndedRequest, session) {
    console.log("onSessionEnded requestId=" + sessionEndedRequest.requestId
        + ", sessionId=" + session.sessionId);

    // Add any cleanup logic here
}

function handleSetRequest(intent, session, callback) {
var starCountRef = database.ref('drugs/' + intent.slots.medication.value + '/');

starCountRef.on('value', function(snapshot) {
	callback(session.attributes,buildSpeechletResponseWithoutCard("you have "+ snapshot.val() +" "+intent.slots.medication.value+" remaining", "", "true"));
});
}

function handleCheckRequest(intent, session, callback) {
	
	if(intent.slots.checkOption.value == 'how many'){
		var starCountRef = database.ref('drugs/' + intent.slots.medication.value + '/');

	starCountRef.on('value', function(snapshot) {
		callback(session.attributes,buildSpeechletResponseWithoutCard("you have "+ snapshot.val() +" "+intent.slots.medication.value+" remaining", "", "true"));
	});
	}

}

// ------- Helper functions to build responses -------

function buildSpeechletResponse(title, output, repromptText, shouldEndSession) {
    return {
        outputSpeech: {
            type: "PlainText",
            text: output
        },
        card: {
            type: "Simple",
            title: title,
            content: output
        },
        reprompt: {
            outputSpeech: {
                type: "PlainText",
                text: repromptText
            }
        },
        shouldEndSession: shouldEndSession
    };
}

function buildSpeechletResponseWithoutCard(output, repromptText, shouldEndSession) {
    return {
        outputSpeech: {
            type: "PlainText",
            text: output
        },
        reprompt: {
            outputSpeech: {
                type: "PlainText",
                text: repromptText
            }
        },
        shouldEndSession: shouldEndSession
    };
}

function buildResponse(sessionAttributes, speechletResponse) {
    return {
        version: "1.0",
        sessionAttributes: sessionAttributes,
        response: speechletResponse
    };
}

