/**
 * \file
 * \brief Platform implementation module.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This implements the platform module.
 * Here the platform gets initialized, and all platform dependent macros get defined.
 */
/*!
**  @addtogroup PLATFORM_module Platform module documentation
**  @{
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

void PL_Init(void) {
#if PL_HAS_LED
  LED_Init();
#endif
#if PL_HAS_EVENTS
  EVNT_Init();
#endif
#if PL_HAS_TIMER
  TMR_Init();
#endif
#if PL_HAS_KEYS
  KEY_Init();
#endif
#if PL_HAS_MEALY
  MEALY_Init();
#endif
#if PL_HAS_TRIGGER
  TRG_Init();
#endif
#if PL_HAS_BUZZER
  BUZ_Init();
#endif
#if PL_HAS_DEBOUNCE
  DBNC_Init();
#endif
#if PL_HAS_RTOS
  RTOS_Init();
#endif
#if PL_HAS_SHELL
  SHELL_Init();
#endif
#if PL_HAS_SHELL_QUEUE
  SQUEUE_Init();
#endif
#if PL_HAS_SEMAPHORE
  SEM_Init();
#endif
#if PL_HAS_REFLECTANCE
  REF_Init();
#endif
#if PL_HAS_MOTOR
  MOT_Init();
#endif
#if PL_HAS_MOTOR_TACHO
  TACHO_Init();
#endif
#if PL_HAS_PID
  PID_Init();
#endif
#if PL_HAS_DRIVE
  DRV_Init();
#endif
#if PL_HAS_ULTRASONIC
  US_Init();
#endif
#if PL_HAS_ACCEL
  ACCEL_Init();
#endif
#if PL_HAS_RADIO
  RNETA_Init();
#endif
#if PL_HAS_REMOTE
  REMOTE_Init();
#endif
#if PL_HAS_WATCHDOG
  WDT_Init();
#endif
}

void PL_Deinit(void) {
#if PL_HAS_WATCHDOG
  WDT_Deinit();
#endif
#if PL_HAS_REMOTE
  REMOTE_Deinit();
#endif
#if PL_HAS_RADIO
  RNETA_Deinit();
#endif
#if PL_HAS_ACCEL
  ACCEL_Deinit();
#endif
#if PL_HAS_ULTRASONIC
  US_Deinit();
#endif
#if PL_HAS_DRIVE
  DRV_Deinit();
#endif
#if PL_HAS_PID
  PID_Deinit();
#endif
#if PL_HAS_MOTOR_TACHO
  TACHO_Deinit();
#endif
#if PL_HAS_MOTOR
  MOT_Deinit();
#endif
#if PL_HAS_REFLECTANCE
  REF_Deinit();
#endif
#if PL_HAS_SEMAPHORE
  SEM_Deinit();
#endif
#if PL_HAS_SHELL_QUEUE
  SQUEUE_Deinit();
#endif
#if PL_HAS_SHELL
  SHELL_Deinit();
#endif
#if PL_HAS_RTOS
  RTOS_Deinit();
#endif
#if PL_HAS_DEBOUNCE
  DBNC_Deinit();
#endif
#if PL_HAS_BUZZER
  BUZ_Deinit();
#endif
#if PL_HAS_TRIGGER
  TRG_Deinit();
#endif
#if PL_HAS_MEALY
  MEALY_Deinit();
#endif
#if PL_HAS_KEYS
  KEY_Deinit();
#endif
#if PL_HAS_TIMER
  TMR_Deinit();
#endif
#if PL_HAS_EVENTS
  EVNT_Deinit();
#endif
#if PL_HAS_LED
  LED_Deinit();
#endif
}

/*!
** @}
*/
