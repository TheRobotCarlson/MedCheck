///*
 * Copyright (c) 2015 Oleg Morozenkov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <signal.h>
#include <stdio.h>
#include <exception>
#include <string>
#include <tgbot/tgbot.h>
#include <iostream>
#include <algorithm>
#include <wiringPi.h>
//#include "../json.hpp"
 

using namespace std;
using namespace TgBot;

class MedData {
	public:
		string medName;
		string medNum;
	
} medData;

bool sigintGot = false;
string sysCommandAddtoArray;
int locationOfStuff = 0;

// set pins here
int inputPins[5] = {23, 24, 25, 12, 16}; // uses BCM pins 23, 24, 25, 12, 16
int outputPins[5] = {17, 22, 19, 13, 26};
int resetPin = 21;
bool tripped[5] = {false, false, false, false, false};

int main() {
	
	// setup
    wiringPiSetupGpio();

    // initialize output and input pins
    for (int i = 0; i < 5; i++) {
		pinMode(outputPins[i], OUTPUT);
		pinMode(inputPins[i], INPUT);
		digitalWrite(outputPins[i], 0);
    }
	
	signal(SIGINT, [](int s) {
		printf("SIGINT got");
		sigintGot = true;
	});
	
	
	//Create Bot from Server (note: we removed the key for upload to github)
	Bot bot("<insert key here>");

	//Upon Joining
	bot.getEvents().onCommand("start", [&bot](Message::Ptr message) {
		bot.getApi().sendMessage(message->chat->id, "Thank You for Choosing MedCheck(tm).");
	});
	
	//Logistics & Messy Code To the Extreme
	

	
	//Get User Message
	bot.getEvents().onAnyMessage([&bot](Message::Ptr message) {
		//printf("User wrote %s\n", message->text.c_str());
		
		//MAYBE THE LOOP IS HERE
		//	CHECK FOR DOORS turn off LEDs
		for (int i = 0; i<5; i++)
			if (digitalRead(inputPins[i])==0) {
				for (int j=0; j<5; j++)
					digitalWrite(outputPins[j], 0);
				
				bot.getApi().sendMessage(message->chat->id, "Medicine Taken.");
					//TODO: lock database and add security rules
				sysCommandAddtoArray = "curl -X PUT -d \'{\"takenMeds\":0}\' \'https://medcheck-34916.firebaseio.com/settings.json\'";

				system(sysCommandAddtoArray.c_str());
			}
		
        // reset button
        if (digitalRead(resetPin)) {
            for (int i = 0; i < 5; i++) {
                tripped[i] = false;
				digitalWrite(outputPins[i], 0);
            }
			printf("all pins reset\n");
	    }
		
		
		
		
		
		//Look for Command
		if (locationOfStuff == 0) {
		
			if (StringTools::startsWith(message->text, "/start")) {
				return;
			}
		
			//add med
			else if (StringTools::startsWith(message->text, "/addmed")) {
			
				bot.getApi().sendMessage(message->chat->id, "What is the name of the medication?");
			
				locationOfStuff = 1;
			
			}
			
			//cheat and make monday light flash without date/time
			else if (StringTools::startsWith(message->text, "/trig1")) {
			
				//FLASH CODE HERE
				//Turn monday's led on
				//activate alexa
				//until door is opened outside of event loop
				printf("triggering 1st led\n");
				digitalWrite(outputPins[0], 1);
				printf("triggered 1st led\n");
				
				bot.getApi().sendMessage(message->chat->id, "Time to take your medicine.");
					
				sysCommandAddtoArray = "curl -X PUT -d \'{\"takenMeds\":1}\' \'https://medcheck-34916.firebaseio.com/settings.json\'";

				system(sysCommandAddtoArray.c_str());
			
			}
			
			//cheat and make monday light flash without date/time
			else if (StringTools::startsWith(message->text, "/trig2")) {
			
				//FLASH CODE HERE
				//Turn monday's led on
				//activate alexa
				//until door is opened outside of event loop
				printf("triggering 1st led\n");
				digitalWrite(outputPins[1], 1);
				printf("triggered 1st led\n");
				
				bot.getApi().sendMessage(message->chat->id, "Time to take your medicine.");
					
				sysCommandAddtoArray = "curl -X PUT -d \'{\"takenMeds\":1}\' \'https://medcheck-34916.firebaseio.com/settings.json\'";

				system(sysCommandAddtoArray.c_str());
			
			}
			
			//cheat and make monday light flash without date/time
			else if (StringTools::startsWith(message->text, "/trig3")) {
			
				//FLASH CODE HERE
				//Turn monday's led on
				//activate alexa
				//until door is opened outside of event loop
				printf("triggering 1st led\n");
				digitalWrite(outputPins[2], 1);
				printf("triggered 1st led\n");
				
				bot.getApi().sendMessage(message->chat->id, "Time to take your medicine.");
					
				sysCommandAddtoArray = "curl -X PUT -d \'{\"takenMeds\":1}\' \'https://medcheck-34916.firebaseio.com/settings.json\'";

				system(sysCommandAddtoArray.c_str());
			
			}
			
			//cheat and make monday light flash without date/time
			else if (StringTools::startsWith(message->text, "/trig4")) {
			
				//FLASH CODE HERE
				//Turn monday's led on
				//activate alexa
				//until door is opened outside of event loop
				printf("triggering 1st led\n");
				digitalWrite(outputPins[3], 1);
				printf("triggered 1st led\n");
				
				bot.getApi().sendMessage(message->chat->id, "Time to take your medicine.");
					
				sysCommandAddtoArray = "curl -X PUT -d \'{\"takenMeds\":1}\' \'https://medcheck-34916.firebaseio.com/settings.json\'";

				system(sysCommandAddtoArray.c_str());
			
			}

			//cheat and make monday light flash without date/time
			else if (StringTools::startsWith(message->text, "/trig5")) {
			
				//FLASH CODE HERE
				//Turn monday's led on
				//activate alexa
				//until door is opened outside of event loop
				printf("triggering 1st led\n");
				digitalWrite(outputPins[4], 1);
				printf("triggered 1st led\n");
				
				bot.getApi().sendMessage(message->chat->id, "Time to take your medicine.");
					
				sysCommandAddtoArray = "curl -X PUT -d \'{\"takenMeds\":1}\' \'https://medcheck-34916.firebaseio.com/settings.json\'";

				system(sysCommandAddtoArray.c_str());
			
			}
			
			//Anything else display menu
			else {
				bot.getApi().sendMessage(message->chat->id, "MENU:\n /addmed - Add a new medication to schedules. \n /checkmed - Check the medication status. \n /nextMed - When is your next scheduled medication. \n /caretaker - Get status of patients medication.");
			}
			//bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
			
		}
		
		//Name for Med
		else if (locationOfStuff == 1) {
			
			medData.medName = message->text;
			
			printf("%s", medData.medName.c_str());
			
			locationOfStuff = 2;
			bot.getApi().sendMessage(message->chat->id, "How many pills/capsule are left?");
		}
		
		else if (locationOfStuff == 2) {
			
			medData.medNum = message->text;
			
			printf("%s", medData.medNum.c_str());
			
			bot.getApi().sendMessage(message->chat->id, "DONE!!!!!!!!");
			locationOfStuff = 0;
			
			string data = medData.medName; 
			transform(data.begin(), data.end(), data.begin(), ::tolower);
			
			//Submit to server fire-seomthing amazon
			sysCommandAddtoArray =
					"curl -X PUT -d \'{\"name\":\"" +
					medData.medName +
					"\",\"refill\":true,\"remaining\":" +
					medData.medNum +
					",\"time_since\":5000000,\"dosage\":{}}\' \'https://medcheck-34916.firebaseio.com/drugs/"+data+".json\'";
					
			system(sysCommandAddtoArray.c_str());
			
		}

		else {
		};
		
		//printf("%s", medData.medName.c_str());
	});
	
	try {
		printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());

		TgLongPoll longPoll(bot);
		while (!sigintGot) {
			printf("Long poll started\n");
			
			     // handle opening pill box
        /*for (int i = 0; i < 5; i++) {
            // when the circuit is disconnected, do something
            if (!digitalRead(inputPins[i]) && !tripped[i]) {
                printf("pin %d tripped\n", inputPins[i]);
                // call func to alert pill box opening

                tripped[i] = true;
				digitalWrite(outputPins[i], 1);
            }*/
        
		longPoll.start();
		
		}
		
	} catch (exception& e) {
		printf("error: %s\n", e.what());
	}

	return 0;
}
