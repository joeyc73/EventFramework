/* HSM.c
 * Hierarchal State Machine
 * Underwater ROV/Drone
 */

 #include "EventFramework.h"

typedef enum {
    InitState,
    SearchingForSignal,
    TrackingSignal,
    GoingUp,
    GoingDown,
    Panic,
} HSMState;

static const char *StateNames[] = {
	"InitState",
    "SearchingForSignal",
    "TrackingSignal",
    "GoingUp",
    "GoingDown",
    "Panic",
};

static HSMState CurrentState = InitState;
static HSMState nextState;

Event RunHSM(Event ThisEvent){

	switch(CurrentState){
		case InitState:

		case SearchingForSignal:

		case TrackingSignal:

		case GoingUp:

		case GoingDown:

		case Panic:
	}
	return ThisEvent;
}