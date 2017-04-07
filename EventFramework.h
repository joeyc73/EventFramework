/* EventFramework.h
Contains declarations of structs and data-types used in the EventFramework */

#ifndef EVENT_FRAMEWORK_H
#define EVENT_FRAMEWORK_H

#include <stdint.h>

typedef enum {
	Init_Event,
	Entry_Event,
	Exit_Event,
	Ultrasonic_Event,
	Depth_Event,
	Humidity_Event,
} EventType;


typedef struct {
	EventType Type;
	uint8_t Param;
} Event;

#endif //EVENT_FRAMEWORK_H