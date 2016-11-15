# MedCheck 
## A friendly reminder to take your medicine

# What it does
MedCheck Is a medication adherence utility that runs primarily through the Amazon Echo, Echo Dot, and other Alexa enabled IOT Devices. The app uses scheduled events and persistent updates through firebase to remind the user to take any daily medications as well as keep track of whether or not certain medications have been taken for the day/on schedule. Additionally, the app is linked to a daily hardware pill planner with LED indicators to designate whether or not medications for a particular day need to be taken (the current day will be highlighted blue if medication for the day has been taken). The pill planner was made using a raspberry pi, LEDs, and a store-bought pill container. Additionally, using the Telegram API, Medcheck will send a reminder to the user's web-enabled device to take medication, presenting a use case for personal reminders as well as care takers who need to keep track of what meds they are administering. The user or caretaker can ask the Echo at any time how many of a certain medicine is remaining, how many days until the next available refill, and whether or not there are any refills remaining, and whether or not you've taken a certain dosage for the day. Their is also a web component that allows the user to get, at a glance, a view of any and all medications, the ability to refill them through their preferred pharmacy, as well as a countdown-timer for the next dosage of any medications.

# Inspiration for this project
CJ had come up with the idea for a medication adherence app from having several daily medications that were at times hard to keep track of. As he put it, the only thing worse than forgetting to take your meds is forgetting whether or not you took your meds. MedCheck presents itself as having the potential not only for individual uses to better manage their medication routine, but also for caretakers needing to keep up with their dependents' medical needs effectively.

# Problems we ran into
Amazon Web Services had a big learning curve for us. None of us had ever used any of the services and didn't have tons of experience with nodejs. There was a lot of documentation to wade through to get exactly what we wanted.  The Alexa voice API in particular was lacking key built-in features that we had to come up with creative solutions to get past. 

## Goals
- [X] raspberry pi server
  - [X] records when pill container is opened
  - [X] records when reset button is pressed
  - [X] makes post requests to api
- [ ] Amazon web services
  - [X] Lambda
    - [X] Respond to Alexa queries
    - [X] Edit database through api call
    - [ ] Create CloudWatch events from api calls
    - [ ] Simulate voice control through api call
  - [X] Firebase
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
  - [X] display medicine information
  - [ ] display caretaker information
  - [X] display pharmacist information
  - [ ] scheduling of when pills are to be taken
  - [ ] Change account settings
  - [X] queries database

## Stretch Goals 
- [ ] Twilio for prescription refills
- [ ] PillPack integration
