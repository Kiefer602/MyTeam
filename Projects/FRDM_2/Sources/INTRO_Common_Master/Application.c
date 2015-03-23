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
#include "CLS1.h"
#include "Mealy.h"
#include "Keys.h"
#include "KeyDebounce.h"
#include "Debounce.h"

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
#if PL_NOF_KEYS >= 1
    case EVNT_SW1_PRESSED:
      CLS1_SendStr("SW1\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 2
    case EVNT_SW2_PRESSED:
      CLS1_SendStr("SW2\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 3
    case EVNT_SW3_PRESSED:
      CLS1_SendStr("SW3\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 4
    case EVNT_SW4_PRESSED:
      CLS1_SendStr("SW4\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 5
    case EVNT_SW5_PRESSED:
      CLS1_SendStr("SW5\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 6
    case EVNT_SW6_PRESSED:
      CLS1_SendStr("SW6\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 7
    case EVNT_SW7_PRESSED:
      CLS1_SendStr("SW7\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
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
#if PL_HAS_KEYS && PL_NOF_KEYS>0
    KEY_Scan(); /* scan keys */
#endif
#if PL_HAS_MEALY
    MEALY_Step();
#endif
#if 0
    CLS1_SendStr("Hello!\r\n", CLS1_GetStdio()->stdOut);
#endif
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
