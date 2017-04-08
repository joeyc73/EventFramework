/* A queue implementation used to keep track of events posted to the HSM */

#include <stdio.h>
#include "EventFramework.h"
#include "eventQueue.h"

// structs --------------------------------------------------------------------
// private NodeObj type
typedef struct NodeObj{
   Event event;
   struct NodeObj* next;
   struct NodeObj* prev;
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private QueueObj type
typedef struct QueueObj{
   Node top;
   Node bottom;
   int numItems;
} QueueObj;

// Constructors-Destructors ---------------------------------------------------
Node newNode(Event event){
   Node N;
   N = malloc(sizeof(NodeObj));
   N->event = event;
   N->prev = N->next = NULL;
   return(N);
}
void freeNode(Node* pN){
	if(pN != NULL && *pN != NULL){
		free(*pN);
		*pN = NULL;
	}
} 
Queue newQueue(void){
   Queue Q;
   Q = malloc(sizeof(QueueObj));
   Q->top = Q->bottom = NULL;
   Q->numItems = 0;
   return(Q);
}
void freeQueue(List* pL){
	if(pL != NULL && *pL != NULL){
		free(*pL);
		*pL = NULL;
	}
}

void insertEvent(Event event, Queue Q){
	if(Q->numItems == 0){
		Node N = newNode(event);
		Q->top = Q->bottom = N;
	}
	else{
		Node P = Q->bottom;
		Node N = newNode(event);
		P->next = N;
		N->prev = P;
		Q->bottom = N;
	}
	Q->numItems++;
}

void removeEvent(Queue Q){
	if(Q->numItems == 0) printf("QueueError: calling removeEvent() on empty Queue\n");
	else{
		Node P = Q->top;
		Q->top = P->next;
		Node N = Q->top;
		N->prev = NULL;
		P->next = NULL;
		freeNode(&P);
		Q->numItems--;
	}
}

int queue_size(Queue Q){
	return Q->numItems;
}
