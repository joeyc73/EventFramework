/* SubUltrasonicEvent.c
 * Substate Machine for Ultrasonic Events
 * Underwater ROV/Drone
 */

#include <stdio.h>
#include <stdlib.h>
#include "EventFramework.h"
#include "HSM.h"
#include "eventQueue.h"
#include "SubUltrasonicEvent.h"
#include "autoMotorFunctions.h"

typedef enum {
    Init,
    Tracking,
} SubUltrasonicEventHSMState;

static SubUltrasonicEventHSMState CurrentState;
int right, left, up, down, tracking, moving;

int pivotToSignal(uint8_t param);

uint8_t InitSubUltrasonicState(){
    Event returnEvent;
    CurrentState = Init;
    Event initEvent = {Init_Event, 0};
    returnEvent = RunSubUltrasonicEventHSM(initEvent);
    if (returnEvent.Type == No_Event) {
        return TRUE;
    }
    return FALSE;
}

Event RunSubUltrasonicEventHSM(Event ThisEvent) {
    uint8_t changeStates = FALSE; // use to flag transition
    SubUltrasonicEventHSMState NextState;
    
    switch (CurrentState) {
        case Init:
            if(ThisEvent.Type == Init_Event){
                //do initializations
                
                NextState = Tracking;
                changeStates = TRUE;
            }
            break;

        case Tracking:
            if (ThisEvent.Type == Ultrasonic_Event){
                if (ThisEvent.Param == 0){
                    //Lost the signal
                    return ThisEvent;
                }
                pivotToSignal(ThisEvent.Param);
                ThisEvent.Type = No_Event;
            }

        

        default://NOT SURE WHAT THIS IS?
            break;

    }
    if (changeStates == TRUE) { // making a state transition, send EXIT and ENTRY
 		// recursively call the current state with an exit event
        Event exitEvent = {Exit_Event, 0};
        Event entryEvent = {Entry_Event, 0};
        RunSubUltrasonicEventHSM(exitEvent);
        CurrentState = NextState;
        RunSubUltrasonicEventHSM(entryEvent);
    }
    return ThisEvent;
}


/*Adjusts the direction the drone is facing/moving depending on the 
state of the ultrasonic sensors. Param is in the following order: LRTB
Returns 1 for ok, and 0 for a problem */
int pivotToSignal(uint8_t param){
    //Move drone depending on ultrasonic parameter
    int moving = 0;
    switch (param){
        
        case TOP_ON:
        case (TOP_ON | LEFT_ON | RIGHT_ON): //0b1110
            //Go up
            //dive(10);  
            break;

        case BOTTOM_ON:
        case (BOTTOM_ON | LEFT_ON | RIGHT_ON):
            //Go down
            //dive(10);
            break;

        case LEFT_ON:
        case (LEFT_ON | TOP_ON | BOTTOM_ON):
            //Go left
	    //turnLeft(10);
            break;

        case RIGHT_ON:
        case (RIGHT_ON | TOP_ON | BOTTOM_ON):
            //Go right
	    //turnRight(10);
            break;

        case (TOP_ON | LEFT_ON):
            //Go up and to the left
	    //dive(10);
	    //turnLeft(10);
            break;

        case (TOP_ON | RIGHT_ON):
            //Go up and to the right
	    //dive(10);
	    //turnRight(10);
            break;

        case (BOTTOM_ON | LEFT_ON):
            //Go down and to the left
	    //dive(10);
	    //turnLeft(10);
            break;

        case (BOTTOM_ON | RIGHT_ON):
            //Go down and to the right
	    //dive(10);
	    //turnRight(10);
            break;

        default:
            // ALL_ON || LEFT_ON | RIGHT_ON || TOP_ON | BOTTOM_ON
            //Go forward
	    //goForward(10);
            break;
    }

    return 1;
}
