/* SubUltrasonicEvent.c
 * Substate Machine for Ultrasonic Events
 * Underwater ROV/Drone
 */

#include <stdio.h>
#include <stdlib.h>
#include "EventFramework.h"
#include "HSM.h"
#include "eventQueue.h"

typedef enum {
    Idle,
    TopOn,
    BottomOn,
    LeftOn,
    RightOn,
} SubUltrasonicEventHSMState;

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

        case TopOn: // If Top sensor goes high

        case BottomOn: // If bottom sensor goes high

        case LeftOn: // If left sensor goes high

        case RightOn: // If right sensor goes high

    }
    if (changeStates == TRUE) { // making a state transition, send EXIT and ENTRY
 		// recursively call the current state with an exit event
        RunSubUltrasonicEventHSM(Exit_Event);
        CurrentState = nextState;
        RunSubUltrasonicEventHSM(Entry_Event);
    }
    return ThisEvent;
}