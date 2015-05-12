/*
 * line_detection.c
 *
 *  Created on: May 12, 2015
 *      Author: Kiefer
 */
#include "Platform.h"
#include "LED.h"
#include "Event.h"
#include "Timer.h"
#include "Mealy.h"
#include "Keys.h"
#include "Trigger.h"
#include "Buzzer.h"
#include "Debounce.h"
#include "RTOS.h"
#include "Shell.h"
#include "ShellQueue.h"
#include "Sem.h"
#include "Reflectance.h"
#include "Motor.h"
#include "Tacho.h"
#include "PID.h"
#include "Drive.h"
#include "Ultrasonic.h"
#include "Accel.h"
#include "RNet_App.h"
#include "Remote.h"
#include "Watchdog.h"


#define REF_NOF_SENSORS 6 /* number of sensors */
#define REF_SENSOR1_IS_LEFT   1 /* sensor number one is on the left side */
#define REF_MIN_LINE_VAL      0x60   /* minimum value indicating a line */
#define REF_MIN_NOISE_VAL     0x40   /* values below this are not added to the weighted sum */
#define REF_USE_WHITE_LINE    0  /* if set to 1, then the robot is using a white (on black) line, otherwise a black (on white) line */

#define REF_START_STOP_CALIB      1 /* start/stop calibration commands */
#define REF_MEASURE_TIMEOUT   		1 /* use timeout for measurement */
#define REF_STORE_CALIB_IN_FLASH  1 /* if storing calibration data in FLASH */







