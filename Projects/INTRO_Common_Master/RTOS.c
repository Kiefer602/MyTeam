/**
 * \file
 * \brief Real Time Operating System (RTOS) main program.
 * \author Erich Styger, erich.styger@hslu.ch
 */

#include "Platform.h"
#if PL_HAS_RTOS
#include "RTOS.h"
#include "FRTOS1.h"
#include "LED.h"
#include "Event.h"
#include "Keys.h"
#include "Mealy.h"
#include "Application.h"
#include "Reflectance.h"
#include "Motor.h"
#include "Shell.h"
#if PL_HAS_WATCHDOG
  #include "Watchdog.h"
#endif

static volatile bool SW1Pressed = FALSE;

void RTOS_ButtonSW1Press(void) {
  SW1Pressed = TRUE;
}

#if 0
static void T2(void* param) {
  for(;;) {
    LED1_Neg();
  }
}

static void T3(void* param) {
  for(;;) {
    LED2_Neg();
  }
}
#endif

static void AppTask(void* param) {
  SHELL_SendString("INFO: Application startup!\r\n");
  EVNT_SetEvent(EVNT_STARTUP); /* set startup event */
  for(;;) {
    EVNT_HandleEvent(APP_HandleEvents);
#if PL_HAS_KEYS && PL_NOF_KEYS>0
    KEY_Scan(); /* scan keys */
#endif
#if PL_HAS_MEALY
    MEALY_Step();
#endif
    LED1_Neg();
#if PL_IS_ROBO
    if (SW1Pressed) {
      SW1Pressed = FALSE;
      if (MOT_GetVal(MOT_GetMotorHandle(MOT_MOTOR_LEFT))!=0xFFFF || MOT_GetVal(MOT_GetMotorHandle(MOT_MOTOR_RIGHT))!=0xFFFF) {
        MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_LEFT), 0);
        MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), 0);
      } else if (REF_IsReady()) {
        MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_LEFT), 10);
        MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), 10);
      }
    }
    if (REF_IsReady()) {
      if (REF_GetLineValue()!=3500) { /* 3500 is (7*1000)/2 ==> full black middle line */
        /* turn off motors */
        MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_LEFT), 0);
        MOT_SetSpeedPercent(MOT_GetMotorHandle(MOT_MOTOR_RIGHT), 0);
      }
    }
#endif
#if PL_HAS_WATCHDOG
    WDT_IncTaskCntr(WDT_TASK_ID_MAIN, 10);
#endif
    FRTOS1_vTaskDelay(10/portTICK_RATE_MS);
  }
}

void RTOS_Run(void) {
  FRTOS1_vTaskStartScheduler();
  /* does usually not return here */
}

void RTOS_Init(void) {
  /*! \todo Add tasks here */
#if 1
  if (FRTOS1_xTaskCreate(AppTask, (signed portCHAR *)"App", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error */
  }
#endif
#if 0
  if (FRTOS1_xTaskCreate(T2, (signed portCHAR *)"T2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error */
  }
  if (FRTOS1_xTaskCreate(T3, (signed portCHAR *)"T3", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error */
  }
#endif
}

void RTOS_Deinit(void) {
}

#endif /* PL_HAS_RTOS */
