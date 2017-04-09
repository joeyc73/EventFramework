/* Framework_Main.c
This file checks for events in the HSM queue, handles them if any.
When the queue is empty, the file will poll each event checker functions 
and add the events to the queue. */

#include <stdio.h>

#include "EventFramework.h"
#include "eventQueue.h"


int main(int argc, char* argv[]) {
	Queue hsmQueue = newQueue();
	Event e1 = {Init_Event, 1};
	insertEvent(e1, hsmQueue);
	printf ("Size: %d\n", queue_size(hsmQueue));
	removeEvent(hsmQueue);
	printf ("Size: %d\n", queue_size(hsmQueue));
	freeQueue(&hsmQueue);
}