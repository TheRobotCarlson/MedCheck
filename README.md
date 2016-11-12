# MedCheck

## Main Components
- [ ] raspberry pi server
  - [ ] logs pill taken status every minute
  - [ ] records when pill container is opened
  - [ ] records when reset button is pressed
  - [ ] makes post requests to api
- [ ] Amazon web services
  - [ ] API gateway
    - [ ] Create API to accept get and post requests
    - [ ] Trigger lambda functions
  - [ ] Lambda
    - [ ] Respond to Alexa queries
    - [ ] Edit database through api call
    - [ ] Create CloudWatch events from api calls
  - [ ] DynamoDB
    - [ ] Store pill scheduling
    - [ ] Store user settings
  - [ ] CloudWatch
    - [ ] Setup initial events
  - [ ] Alexa
    - [ ] Alexa Voice Service for "push notifications"
- [ ] Telegram bot
  - [ ] accepts notifications from post requests
  - [ ] queries api gateway 
  - [ ] change account settings
- [ ] website
  - [ ] scheduling of when pills are to be taken
  - [ ] Change account settings
  - [ ] queries api gateway
  - [ ] allows changing of settings

## Stretch Goals 
- [ ] Twilio for prescription refills
