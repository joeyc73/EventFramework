/* SubUltrasonicEvent.c
 * Substate Machine for Ultrasonic Events
 * Underwater ROV/Drone
 */

#ifndef SUB_ULTRASONIC_EVENT_H
#define SUB_ULTRASONIC_EVENT_H

#include <stdio.h>
#include <stdlib.h>
#include "EventFramework.h"
#include "HSM.h"
#include "eventQueue.h"
#include "autoMotorFunctions.h"

// #define LEFT_ON		3
// #define RIGHT_ON	2
// #define TOP_ON 		1
// #define BOTTOM_ON	0

uint8_t InitSubUltrasonicState(void);
Event RunSubUltrasonicEventHSM(Event ThisEvent);

#endif //SUB_ULTRASONIC_EVENT_H
