# MedCheck

## Main Components
- [ ] raspberry pi server
  - [ ] logs pill taken status every minute
  - [X] records when pill container is opened
  - [X] records when reset button is pressed
  - [X] makes post requests to api
- [ ] Amazon web services
  - [X] Lambda
    - [X] Respond to Alexa queries
    - [X] Edit database through api call
    - [ ] Create CloudWatch events from api calls
    - [ ] Simulate voice control through api call
  - [ ] Firebase
    - [X] Store pill scheduling
    - [X] Store user settings
  - [ ] CloudWatch
    - [ ] Setup initial events
  - [ ] Alexa
    - [X] Accept main queries
    - [ ] Alexa Voice Service for "push notifications"
- [ ] Telegram bot
  - [ ] accepts notifications from post requests
  - [X] queries api 
  - [X] change account settings
- [ ] website
  - [ ] scheduling of when pills are to be taken
  - [ ] Change account settings
  - [ ] queries api gateway
  - [ ] allows changing of settings

## Stretch Goals 
- [ ] Twilio for prescription refills
