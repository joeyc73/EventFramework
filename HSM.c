/* HSM.c
 * Hierarchal State Machine
 * Underwater ROV/Drone
 */

 #include "EventFramework.h"

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

Event RunHSM(Event ThisEvent){

	switch(CurrentState){
		case InitState:
			if(ThisEvent->EventType == Init_Event){
				//do initializations
			}
			break;

		case SearchingForSignal:
			if(ThisEvent->EventType == Ultrasonic_Event){
				
			}
			else if(ThisEvent->EventType == Depth_Event){
				
			}
			else if(ThisEvent->EventType == Humidity_Event){
				nextState = Panic;
			}
			break;

		case TrackingSignal:
			if(ThisEvent->EventType == Ultrasonic_Event){
				
			}
			else if(ThisEvent->EventType == Depth_Event){
				
			}
			else if(ThisEvent->EventType == Humidity_Event){
				nextState = Panic;
			}
			break;

		case GoingUp:
			if(ThisEvent->EventType == Ultrasonic_Event){
				
			}
			else if(ThisEvent->EventType == Depth_Event){
				
			}
			else if(ThisEvent->EventType == Humidity_Event){
				nextState = Panic;
			}
			break;

		case GoingDown:
			if(ThisEvent->EventType == Ultrasonic_Event){
				
			}
			else if(ThisEvent->EventType == Depth_Event){
				
			}
			else if(ThisEvent->EventType == Humidity_Event){
				nextState = Panic;
			}
			break;

		case Panic:
			if(ThisEvent->EventType == Ultrasonic_Event){
				
			}
			else if(ThisEvent->EventType == Depth_Event){
				
			}
			else if(ThisEvent->EventType == Humidity_Event){
				nextState = Panic;
			}
			break;
	}
	return ThisEvent;
}
