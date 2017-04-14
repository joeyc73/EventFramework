/* UltrasonicEventChecker.h
 * Underwater Drone/ROV
 */

#ifndef ULTRASONIC_EVENT_CHECKER_H
#define ULTRASONIC_EVENT_CHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include "EventFramework.h"
#include "HSM.h"
#include "eventQueue.h"
#include "SubUltrasonicEvent.h"
#include "autoMotorFunctions.h"
#include "UltrasonicEventChecker.h"

Event checkUltrasonicSensors();

#endif //ULTRASONIC_EVENT_CHECKER_H