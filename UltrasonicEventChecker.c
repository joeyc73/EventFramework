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
Event thisEvent;

Event checkUltrasonicSensors(){
	uint8_t currentState = lastState;
	left = digitalRead(leftPin);
	right = digitalRead(rightPin);
	top = digitalRead(topPin);
	bottom = digitalRead(bottomPin);
	tracking = digitalRead(beaconPin);
	currentState = (left<<3) | (right<<2) | (top<<1) | bottom; //combine 4 digit reading
	if(currentState != lastState){ 
		thisEvent.Eventype = Ultrasonic_Event;
		thisEvent.Param = currentState;
		return thisEvent;
	}else if(!tracking){
		thisEvent.EventType = Ultrasonic_Event;
		thisEvent.Param = 0; //lost signal
		return thisEvent;
	}
	lastState = currentState;
	return No_Event;
}
