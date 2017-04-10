/* EventFramework.h
Contains declarations of structs and data-types used in the EventFramework */

#ifndef EVENT_FRAMEWORK_H
#define EVENT_FRAMEWORK_H

//Uncomment this to simulate the Framework from keyboard
#define USE_KEYBOARD_INPUT 

#include <stdint.h>

#define ANSI_COLOR_RED		"\x1b[31m"
#define ANSI_COLOR_GREEN	"\x1b[32m"
#define ANSI_COLOR_BLUE		"\x1b[34m"
#define ANSI_COLOR_RESET	"\x1b[0m"

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