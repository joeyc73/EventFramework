/* Framework_Main.c
This file checks for events in the HSM queue, handles them if any.
When the queue is empty, the file will poll each event checker functions 
and add the events to the queue. */

#include <stdio.h>

#include "EventFramework.h"
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



int main(int argc, char* argv[]) {

	//Initialize everything..
	Queue hsmQueue = InitHSM();



	//Start main loop
	int loop = 1;
	while (loop){

		//Check for new events
		//Ex: if (event = checkUltrasonic()) insertEvent(event)

		Event e1 = {Humidity_Event, 51};
		PostHSM(e1);

		if (queueSize(hsmQueue) > 0){
			//Remove event from queue, and pass it to the HSM
			Event retEvent = RunHSM(removeEvent(hsmQueue));

			if (retEvent.Type != No_Event){
				printf("Error: Event was not handled in HSM - %s\n", EventStr[retEvent.Type]);
				loop = 0;
			}
			loop = 0;
		}
		
	}

	// TODO: Need a way to exit while loop
	freeQueue(&hsmQueue);
	return 0;
}