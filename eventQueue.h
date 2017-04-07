
/* A queue implementation used to keep track of events posted to the HSM */

#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include "EventFramework.h"

#define MAX_VAL 5

void insertEvent(Event event);

void removeEvent();

int queue_size();



#endif //EVENT_QUEUE_H