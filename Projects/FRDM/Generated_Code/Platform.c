/*
 * Platform.c
 *
 *  Created on: Mar 9, 2015
 *      Author: Kiefer
 */


 #include "Platform.h"
 #include "LED.h"
 //#include "Event.h"


 void PL_Init(void) {
 #if PL_HAS_LED
   LED_Init();
 #endif
//#if PL_HAS_EVENTS
 //  EVNT_Init();
//#endif
 }

 void PL_Deinit(void) {
 //#if PL_HAS_EVENTS
	// EVNT_Deinit();
 //#endif
 #if PL_HAS_LED
	 LED_Deinit();
 #endif
 }




