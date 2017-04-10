/* EventFramework.h
Contains declarations of structs and data-types used in the EventFramework */

#ifndef EVENT_FRAMEWORK_H
#define EVENT_FRAMEWORK_H

#include <stdint.h>

typedef enum {
	No_Event,
	Init_Event,
	Entry_Event,
	Exit_Event,
	Ultrasonic_Event,
	Depth_Event,
	Humidity_Event,
} EventType;

extern const char* EventStr[]; //Defined in Framework_Main.c

typedef struct Event{
	EventType Type;
	uint8_t Param;
} Event;

typedef enum {
	FALSE,
	TRUE
} bools;

#endif //EVENT_FRAMEWORK_H