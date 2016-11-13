"use strict";

module.exports = Object.freeze({
    
    // App-ID. TODO: set to your own Skill App ID from the developer portal.
    appId : 'amzn1.ask.skill.6fabd97e-f0ca-416d-b57f-da364549b5aa',
	avsId : 'amzn1.application.96fe405c3a9a47d3bf09ab29aad0c2f8',
	clientId : 'amzn1.application-oa2-client.15dde1feb98a45e2a925e7aec6602292',
	clientSecret : '23ecb51df435e1d3f579f8e64fded797a95e23d492246d14de200e82694fb3c1'
    
    //  DynamoDB Table name
    dynamoDBTableName : 'LongFormAudioSample',
    
    /*
     *  States:
     *  START_MODE : Welcome state when the audio list has not begun.
     *  PLAY_MODE :  When a playlist is being played. Does not imply only active play.
     *               It remains in the state as long as the playlist is not finished.
     *  RESUME_DECISION_MODE : When a user invokes the skill in PLAY_MODE with a LaunchRequest,
     *                         the skill provides an option to resume from last position, or to start over the playlist.
     */
    states : {
        START_MODE : '',
        PLAY_MODE : '_PLAY_MODE',
        RESUME_DECISION_MODE : '_RESUME_DECISION_MODE'
    }
});
