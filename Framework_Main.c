/* Framework_Main.c
This file checks for events in the HSM queue, handles them if any.
When the queue is empty, the file will poll each event checker functions 
and add the events to the queue. */

#include <stdio.h>

#include "EventFramework.h"
#include "UltrasonicEventChecker.h"
#include "eventQueue.h"
#include "HSM.h"

const char* EventStr[] = {
	"No_Event",
	"Init_Event",
	"Entry_Event",
	"Exit_Event",
	"Ultrasonic_Event",
	"Depth_Event",
	"Humidity_Event"
};

//Private function declarations
void printEventOptions(void);



int main(int argc, char* argv[]) {

	//Initialize everything..
	Queue hsmQueue = InitHSM();

	//Start main loop
	int loop = TRUE;
	while (loop){

#ifndef USE_KEYBOARD_INPUT

		//Check for new events
		Event event = checkUltrasonicSensors();
		if (event.Type != No_Event){
			PostHSM(event);
			loop = FALSE;
		}
		printf("Ultrasonic result: %s\n", EventStr[event.Type]);
#endif


#ifdef USE_KEYBOARD_INPUT
		//Use user input to simulate state machine
		char in[] = {0};
		Event e1 = {No_Event, 0};

		printEventOptions();
		while ((in[0] - '0') > 7 || (in[0] - '0') < 1){
			printf(ANSI_COLOR_GREEN"Enter an Event Type (1 - 7): ");
			scanf("%s", in);
		}
		e1.Type = (EventType) (in[0] - '0' - 1);

		do {
			printf("Enter a Parameter (0 - 9): "ANSI_COLOR_RESET);
			scanf("%s", in);
		} while ((in[0] - '0') > 9 || (in[0] - '0') < 0);

		e1.Param = (uint8_t) in[0] - '0';
		printf("passing: %s\n", EventStr[e1.Type]);
		PostHSM(e1);
#endif //USE_KEYBOARD_INPUT 

		while (queueSize(hsmQueue) > 0){
			//Remove event from queue, and pass it to the HSM
			Event retEvent = RunHSM(removeEvent(hsmQueue));

			if (retEvent.Type != No_Event){
				printf(ANSI_COLOR_RED"Error: Event was not handled in HSM - %s" ANSI_COLOR_RESET "\n", EventStr[retEvent.Type]);
				loop = FALSE;
			}
		}
	}

	// TODO: Need a way to exit while loop
	freeQueue(&hsmQueue);
	return 0;
}

//Private function definitions

void printEventOptions(void){
	printf(ANSI_COLOR_BLUE"\n1) No_Event    2) Init_Event    3) Entry_Event    4) Exit_Event\n");
	printf("5) Ultrasonic_Event    6) Depth_Event    7) Humidity_Event\n\n" ANSI_COLOR_RESET);
}

