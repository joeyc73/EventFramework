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

typedef enum {
    Idle,
    TopOn,
    BottomOn,
    LeftOn,
    RightOn,
} SubUltrasonicEventHSMState;

/* #define LeftPin
   #define RightPin
   #define TopPin
   #define BottomPin
   */

#define LEFT_ON		3
#define RIGHT_ON	2
#define TOP_ON 		1
#define BOTTOM_ON	0

uint8_t InitSubUltrasonicState(void){
    Event returnEvent;
    CurrentState = Idle;
    returnEvent = RunSubUltrasonicEventHSM(Init_Event);
    if (returnEvent.EventType == No_Event) {
        return TRUE;
    }
    return FALSE;
}

Event RunSubUltrasonicEventHSM(Event ThisEvent) {
    uint8_t changeStates = FALSE; // use to flag transition
    SubUltrasonicEventHSMState nextState;
    
    switch (CurrentState) {
        case Idle: // If current state is initial State
            /* if TopPin goes high 
                    nextState = TopOn;
                    break;
               else if BottomPin goes high 
                    nextState = BottomOn;
                    break;
               else if RightPin goes high
                    nextState = RightOn;
                    break;
               else if LeftPin goes high
                    nextState = LeftOn;
                    break;
                    */

        case TopOn: // If Top sensor goes high
            /* Once TopPin goes low
                nextState = Idle;
                break;
                */

        case BottomOn: // If bottom sensor goes high
            /* Once BottomPin goes low
                nextState = Idle;
                break;
                */

        case LeftOn: // If left sensor goes high
            /* Once LeftPin goes low
                nextState = Idle;
                break;
                */

        case RightOn: // If right sensor goes high
            /* Once RightPin goes low
                nextState = Idle;
                break;
                */

    }
    if (changeStates == TRUE) { // making a state transition, send EXIT and ENTRY
 		// recursively call the current state with an exit event
        RunSubUltrasonicEventHSM(Exit_Event);
        CurrentState = nextState;
        RunSubUltrasonicEventHSM(Entry_Event);
    }
    return ThisEvent;
}
