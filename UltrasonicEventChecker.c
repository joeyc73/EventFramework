/* UltrasonicEventChecker.c
 * Underwater Drone/ROV
 * Checks for changes in readings of the sensors
 */

#include <stdio.h>
#include <stdlib.h>
#include "EventFramework.h"
#include "HSM.h"
#include "eventQueue.h"
#include "SubUltrasonicEvent.h"
#include "autoMotorFunctions.h"
#include "UltrasonicEventChecker.h"

uint8_t lastState = 0;

Event checkUltrasonicSensors(){
	uint8_t currentState = lastState;
	left = digitalRead(leftPin);
	right = digitalRead(rightPin);
	top = digitalRead(topPin);
	bottom = digitalRead(bottomPin);
	currentState = left << right << top << bottom;
	if(currentState != lastState) return Ultrasonic_Event;
	lastState = currentState;
	return No_Event;
}