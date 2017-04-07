/* Framework_Main.c
This file checks for events in the HSM queue, handles them if any.
When the queue is empty, the file will poll each event checker functions 
and add the events to the queue. */

#include <stdio.h>

#include "EventFramework.h"
#include "queue.h"


int main(int argc, char* argv[]) {
	printf("Hello World");
}