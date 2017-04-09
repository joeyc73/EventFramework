/* HSM.c
 * Hierarchal State Machine
 * Underwater ROV/Drone
 */

#include <stdio.h>
#include <stdlib.h>

#include "EventFramework.h"
#include "HSM.h"
#include "eventQueue.h"

typedef enum {
    InitState,
    SearchingForSignal,
    TrackingSignal,
    GoingUp,
    GoingDown,
    Panic,
} HSMState;

static HSMState CurrentState = InitState;
static HSMState nextState;

static Queue hsmQueue;


/* Sets up hsmQueue, initializes states
Returns 0 for Fail and 1 for Success */
Queue InitHSM(void){
	hsmQueue = newQueue();
	return hsmQueue;
}

/* Posts a new event to the hsmQueue
Returns 0 for Fail and 1 for Success */
uint8_t PostHSM(Event ThisEvent){
	insertEvent(ThisEvent, hsmQueue);
	printf("Queue Size: %d\n", queueSize(hsmQueue));
	return 1;
}

/* Runs the HSM on the next event in its queue
Will return No_Event if the event is handled,
otherwise the event was not handled and program should exit */
Event RunHSM(Event ThisEvent){

	printf("Event is: %d,  %d\n", ThisEvent.Type, ThisEvent.Param);

	switch(CurrentState){
		case InitState:
			if(ThisEvent.Type == Init_Event){
				//do initializations
			}
			break;

		case SearchingForSignal:
			if(ThisEvent.Type == Ultrasonic_Event){
				
			}
			else if(ThisEvent.Type == Depth_Event){
				
			}
			else if(ThisEvent.Type == Humidity_Event){
				nextState = Panic;
			}
			break;

		case TrackingSignal:
			if(ThisEvent.Type == Ultrasonic_Event){
				
			}
			else if(ThisEvent.Type == Depth_Event){
				
			}
			else if(ThisEvent.Type == Humidity_Event){
				nextState = Panic;
			}
			break;

		case GoingUp:
			if(ThisEvent.Type == Ultrasonic_Event){
				
			}
			else if(ThisEvent.Type == Depth_Event){
				
			}
			else if(ThisEvent.Type == Humidity_Event){
				nextState = Panic;
			}
			break;

		case GoingDown:
			if(ThisEvent.Type == Ultrasonic_Event){
				
			}
			else if(ThisEvent.Type == Depth_Event){
				
			}
			else if(ThisEvent.Type == Humidity_Event){
				nextState = Panic;
			}
			break;

		case Panic:
			if(ThisEvent.Type == Ultrasonic_Event){
				
			}
			else if(ThisEvent.Type == Depth_Event){
				
			}
			else if(ThisEvent.Type == Humidity_Event){
				nextState = Panic;
			}
			break;
	}
	return ThisEvent;
}
