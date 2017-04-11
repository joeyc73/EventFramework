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

static SubUltrasonicEventHSMState CurrentState;
int right, left, up, down, tracking, moving;

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
            right  = digitalRead(rightPin);
            left = digitalRead(leftPin);
            up = digitalRead(upPin);
            down = digitalRead(downPin);
           
            if(up){ // if Top Pin goes high
                nextState = TopOn;
                break;
            }else if(down) //if Bottom Pin goes high 
                nextState = BottomOn;
                break;
            }else if(right) // if Right Pin goes high
                nextState = RightOn;
                break;
            }else if(left) // if LeftPin goes high
                nextState = LeftOn;
                break;
            }  
            break;
        
        case TopOn: // If Top sensor goes high
            moving = 1;
            while(moving)
                up = digitalRead(upPin);
                if(up) dive(-10); //rise by moving motors 10 percent
                if(!up){
                    dive(0); //stop motors from rising
                    moving = 0;
                }
            }
            // Once TopPin goes low
            nextState = Idle;
              
            break;

        case BottomOn: // If bottom sensor goes high
            moving = 1;
            while(moving)
                down = digitalRead(downPin);
                if(down) dive(10); //dive by moving motors 10 percent
                if(!down){
                    dive(0); //stop motors from diving
                    moving = 0;
                }
            }
            // Once BottomPin goes low
            nextState = Idle;
            break;

        case LeftOn: // If left sensor goes high
            moving = 1;
            while(moving)
                left = digitalRead(leftPin);
                if(left) turnLeft(10); //turn left by moving motors 10 percent
                if(!left){
                    turnLeft(0); //stop motors from turning
                    moving = 0;
                }
            }
            // Once LeftPin goes low
            nextState = Idle;
            break;

        case RightOn: // If right sensor goes high
            moving = 1;
            while(moving)
                right = digitalRead(rightPin);
                if(right) turnRight(10); //turn right by moving motors 10 percent
                if(!right){
                    turnRight(0); //stop motors from turning
                    moving = 0;
                }
            }
            // Once RightPin goes low
            nextState = Idle;
            break;

        default://NOT SURE WHAT THIS IS?
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
