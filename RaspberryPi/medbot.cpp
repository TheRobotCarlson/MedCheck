#include <stdio.h>
#include <wiringPi.h>



int main(void) {

    // setup
    wiringPiSetupGpio();

    // set pins here
    int inputPins[] = {23, 24, 25, 12, 16}; // uses BCM pins 23, 24, 25, 12, 16
    int outputPins[] = {17, 22, 19, 13, 26};
    int resetPin = 21;
    bool tripped[] = {false, false, false, false, false};

    // initialize output and input pins
    for (int i = 0; i < 5; i++) {
	pinMode(outputPins[i], OUTPUT);
	pinMode(inputPins[i], INPUT);
	digitalWrite(outputPins[i], 0);
    }

    // loop
    while (1) {

        // alert when you haven't taken pill
        




        // handle opening pill box
        for (int i = 0; i < 5; i++) {
            // when the circuit is disconnected, do something
            if (!digitalRead(inputPins[i]) && !tripped[i]) {
                printf("pin %d tripped\n", inputPins[i]);
                // call func to alert pill box opening

                tripped[i] = true;
		digitalWrite(outputPins[i], 1);
            }
        }

        // reset button
        if (digitalRead(resetPin)) {
            for (int i = 0; i < 5; i++) {
                tripped[i] = false;
		digitalWrite(outputPins[i], 0);
            }
 	    printf("all pins reset\n");
	    
        }
    }
}
