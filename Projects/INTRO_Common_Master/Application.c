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
#include "Buzzer.h"
#include "KeyDebounce.h"
#include "RTOS.h"
#include "FRTOS1.h"
#include "Shell.h"
#if configUSE_TRACE_HOOKS
  #include "RTOSTRC1.h"
#endif
#include "timers.h"
#if PL_HAS_REFLECTANCE
  #include "Reflectance.h"
#endif

#define USE_SW_TIMERS 0

#if USE_SW_TIMERS /* software timers */
static xTimerHandle timerHndl;
#define TIMER_PERIOD_MS 50

static void vTimerCallback(xTimerHandle pxTimer) {
  /* TIMER_PERIOD_MS ms timer */
  LED2_Neg();
}
#endif

void APP_DebugPrint(unsigned char *str) {
#if PL_HAS_SHELL
  SHELL_SendString(str);
#endif
}

/*!
 * \brief Application event handler
 * \param event Event to be handled
 */
void APP_HandleEvents(EVNT_Handle event) {
  switch(event) {
    case EVNT_STARTUP:
      LED1_On();
      WAIT1_WaitOSms(50);
      LED1_Off();
#if PL_HAS_BUZZER
      BUZ_Beep(300, 500);
#endif
     break;
    case EVENT_LED_HEARTBEAT:
      LED1_Neg();
      break;
#if PL_NOF_KEYS >= 1
    case EVNT_SW1_PRESSED:
      CLS1_SendStr("SW1\r\n", CLS1_GetStdio()->stdOut);
#if PL_HAS_BUZZER
      BUZ_Beep(300, 250);
#endif
      RTOS_ButtonSW1Press();
      break;
    case EVNT_SW1_LPRESSED:
      CLS1_SendStr("SW1 long\r\n", CLS1_GetStdio()->stdOut);
#if PL_HAS_REFLECTANCE
      REF_CalibrateStartStop();
#endif
      break;
    case EVNT_SW1_RELEASED:
      CLS1_SendStr("SW1 release\r\n", CLS1_GetStdio()->stdOut);
      break;
      break;
#endif
#if PL_NOF_KEYS >= 2
    case EVNT_SW2_PRESSED:
      CLS1_SendStr("SW2 short\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW2_LPRESSED:
      CLS1_SendStr("SW2 long\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW2_RELEASED:
      CLS1_SendStr("SW2 release\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 3
    case EVNT_SW3_PRESSED:
      CLS1_SendStr("SW3\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW3_LPRESSED:
      CLS1_SendStr("SW3 long\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW3_RELEASED:
      CLS1_SendStr("SW3 release\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 4
    case EVNT_SW4_PRESSED:
      CLS1_SendStr("SW4\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW4_LPRESSED:
      CLS1_SendStr("SW4 long\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW4_RELEASED:
      CLS1_SendStr("SW4 release\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 5
    case EVNT_SW5_PRESSED:
      CLS1_SendStr("SW5\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW5_LPRESSED:
      CLS1_SendStr("SW5 long\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW5_RELEASED:
      CLS1_SendStr("SW5 release\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 6
    case EVNT_SW6_PRESSED:
      CLS1_SendStr("SW6\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW6_LPRESSED:
      CLS1_SendStr("SW6 long\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW6_RELEASED:
      CLS1_SendStr("SW6 release\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 7
    case EVNT_SW7_PRESSED:
      CLS1_SendStr("SW7\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW7_LPRESSED:
      CLS1_SendStr("SW7 long\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW7_RELEASED:
      CLS1_SendStr("SW7 release\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
    default:
      break;
  }
}

#if !PL_HAS_RTOS
/*!
 * \brief Application main 'task'.
 */
static void APP_Task(void) {
  int cntr;

  CLS1_SendStr("INFO: Application startup!\r\n", CLS1_GetStdio()->stdOut);
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
    cntr++;
    if (cntr>40) {
      cntr = 0;
      CLS1_SendStr("Hello!\r\n", CLS1_GetStdio()->stdOut);
    }
#endif
    WAIT1_Waitms(50); /* wait some time */
  }
}
#endif

void APP_Run(void) {
#if configUSE_TRACE_HOOKS
  if (RTOSTRC1_uiTraceStart()!=1) {
    for(;;){} /* failed to start trace */
  }
#endif
#if USE_SW_TIMERS /* create software timer */
  timerHndl = xTimerCreate("timer0", TIMER_PERIOD_MS/portTICK_RATE_MS, pdTRUE, (void *)0, vTimerCallback);
  if (timerHndl==NULL) {
    for(;;); /* failure! */
  }
  if (xTimerStart(timerHndl, 0)!=pdPASS) {
    for(;;); /* failure! */
  }
#endif
  PL_Init();
#if PL_HAS_RTOS
  RTOS_Run();
#else
  APP_Task(); /* does not return */
#endif
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
