
/* A queue implementation used to keep track of events posted to the HSM */

#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include "EventFramework.h"

#define MAX_VAL 5
//Queue
typedef struct QueueObj* Queue;

//Constructor
Queue newQueue(void);
//Destructor
void freeQueue(Queue* Q);

void insertEvent(Event event, Queue Q);

void removeEvent(Queue Q);

int queue_size(Queue Q);



#endif //EVENT_QUEUE_H
