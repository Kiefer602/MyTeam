/* ###################################################################
**     Filename    : main.c
**     Project     : INTRO_FRDM_Master
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-02-23, 08:25, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "UTIL1.h"
#include "WAIT1.h"
#include "LedBit1.h"
#include "BitIoLdd3.h"
#include "LedBit2.h"
#include "BitIoLdd4.h"
#include "LedBit3.h"
#include "BitIoLdd5.h"
#include "CS1.h"
#include "HF1.h"
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "CLS1.h"
#include "AS1.h"
#include "ASerialLdd1.h"
#include "SW1.h"
#include "ExtIntLdd1.h"
#include "SW2.h"
#include "ExtIntLdd2.h"
#include "SW3.h"
#include "ExtIntLdd3.h"
#include "PTA.h"
#include "SW4.h"
#include "ExtIntLdd4.h"
#include "SW5.h"
#include "BitIoLdd8.h"
#include "SW6.h"
#include "BitIoLdd9.h"
#include "SW7.h"
#include "ExtIntLdd5.h"
#include "FRTOS1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "LEDcpp.h"
#include "Platform.h"
#include "LED.h"
#include "Application.h"

#if 0
void foo(void) {
}
static void (*f)(void) = foo;
int *p = 0, j;
#endif

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  APP_Run();
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.4 [05.11]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/