/**
 * \file
 * \brief Application entry point and core functionality.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * In this module the application logic is implemented.
 */

#include "Platform.h"
#include "Application.h"
#include "LED.h"
//#include "LEDcpp.h"
#include "WAIT1.h"
#include "Event.h"

/*!
 * \brief Application event handler
 * \param event Event to be handled
 */
static void APP_HandleEvents(EVNT_Handle event) {
  switch(event) {
    case EVNT_STARTUP:
      LED1_On();
      WAIT1_Waitms(50);
      LED1_Off();
      break;
    case EVENT_LED_HEARTBEAT:
      LED1_Neg();
      break;
    default:
      break;
  }
}

/*!
 * \brief Application main 'task'.
 */
static void APP_Task(void) {
  EVNT_SetEvent(EVNT_STARTUP); /* set startup event */
  for(;;) {
    EVNT_HandleEvent(APP_HandleEvents);
    WAIT1_Waitms(100); /* wait some time */
  }
}

void APP_Run(void) {
  PL_Init();
  APP_Task(); /* does not return */
#if 0
  LED1_On();
  LED2_On();
  LED3_On();

  LED1_Off();
  LED2_Off();
  LED3_Off();

  LEDcpp_Test();
#endif
#if 0
  j = *p;
  f();
  *p = 5;
#endif
#if 0
  for(;;) {
    WAIT1_Waitms(200);
    LedBit1_ClrVal();
    WAIT1_Waitms(200);
    LedBit2_ClrVal();
    WAIT1_Waitms(200);
    LedBit3_ClrVal();
    WAIT1_Waitms(200);

    WAIT1_Waitms(200);
    LedBit1_SetVal();
    WAIT1_Waitms(200);
    LedBit2_SetVal();
    WAIT1_Waitms(200);
    LedBit3_SetVal();
    WAIT1_Waitms(200);
  }
#endif
}
