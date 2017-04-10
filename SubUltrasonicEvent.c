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
    Init,
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

static SubUltrasonicEventHSMState CurrentState;

#define LEFT_ON		3
#define RIGHT_ON	2
#define TOP_ON 		1
#define BOTTOM_ON	0

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
    SubUltrasonicEventHSMState nextState;
    
    switch (CurrentState) {
        case Init:

            break;
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
            break;

        case TopOn: // If Top sensor goes high
            /* Once TopPin goes low
                nextState = Idle;
                break;
                */
            break;

        case BottomOn: // If bottom sensor goes high
            /* Once BottomPin goes low
                nextState = Idle;
                break;
                */
            break;

        case LeftOn: // If left sensor goes high
            /* Once LeftPin goes low
                nextState = Idle;
                break;
                */
            break;

        case RightOn: // If right sensor goes high
            /* Once RightPin goes low
                nextState = Idle;
                break;
                */
            break;

        default:
            break;

    }
    if (changeStates == TRUE) { // making a state transition, send EXIT and ENTRY
 		// recursively call the current state with an exit event
        Event exitEvent = {Exit_Event, 0};
        Event entryEvent = {Entry_Event, 0};
        RunSubUltrasonicEventHSM(exitEvent);
        CurrentState = nextState;
        RunSubUltrasonicEventHSM(entryEvent);
    }
    return ThisEvent;
}
