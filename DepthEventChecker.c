/* Event Checker for Depth Sensor
 * Underwater ROV/Drone
 * /

#include <stdlib.h>
#include <stdio.h>
#include "EventFramework.h"
#include "HSM.h"
#include "eventQueue.h"
#include "MS5803_Collection.h"

int pressure = 0;
static uint8_t lastEvent = DEPTH_OK;
Event checkDepthSensor(){
    Event thisEvent = {No_Event, 0};
    pressure = psArgs->pres;
    if(pressure<1.001 && lastEvent!=TOO_SHALLOW){
         thisEvent.Type = Depth_Event;
	 thisEvent.Param = TOO_SHALLOW;
	 lastEvent = TOO_SHALLOW;
    }
    else if(pressure>10 && lastEvent!=TOO_DEEP){
         thisEvent.Type = Depth_Event;
	 this_Event.Param = TOO_DEEP;
	 lastEvent = TOO_DEEP;
    }
    else if(10<pressure<1.001 && lastEvent!=DEPTH_OK){
         thisEvent.Type = Depth_Event;
	 thisEvent.Param = DEPTH_OK;
    }
    return thisEvent;
}
