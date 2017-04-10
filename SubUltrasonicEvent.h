/* SubUltrasonicEvent.c
 * Substate Machine for Ultrasonic Events
 * Underwater ROV/Drone
 */

#include <stdio.h>
#include <stdlib.h>
#include "EventFramework.h"
#include "HSM.h"
#include "eventQueue.h"

#define LEFT_ON		3
#define RIGHT_ON	2
#define TOP_ON 		1
#define BOTTOM_ON	0

uint8_t InitSubUltrasonicState(void);
Event RunSubUltrasonicEventHSM(Event ThisEvent);