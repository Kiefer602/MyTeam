/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : LEDBit2.h
**     Project     : robo
**     Processor   : MK22FX512VLQ12
**     Component   : LED
**     Version     : Component 01.063, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-03-09, 08:47, # CodeGen: 0
**     Abstract    :
**          This component implements a universal driver for a single LED.
**     Settings    :
**          Component name                                 : LEDBit2
**          Turned On with initialization                  : no
**          HW Interface                                   : 
**            On/Off                                       : Enabled
**              Pin                                        : LEDpin
**            PWM                                          : Disabled
**            High Value means ON                          : no
**          Shell                                          : Disabled
**     Contents    :
**         Init       - void LEDBit2_Init(void);
**         Deinit     - void LEDBit2_Deinit(void);
**         On         - void LEDBit2_On(void);
**         Off        - void LEDBit2_Off(void);
**         Neg        - void LEDBit2_Neg(void);
**         Get        - byte LEDBit2_Get(void);
**         Put        - void LEDBit2_Put(byte val);
**         SetRatio16 - void LEDBit2_SetRatio16(word ratio);
**
**     License   : Open Source (LGPL)
**     Copyright : Erich Styger, 2013, all rights reserved.
**     Web       : www.mcuoneclipse.com
**     This an open source software implementing a driver using Processor Expert.
**     This is a free software and is opened for education, research and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file LEDBit2.h
** @version 01.00
** @brief
**          This component implements a universal driver for a single LED.
*/         
/*!
**  @addtogroup LEDBit2_module LEDBit2 module documentation
**  @{
*/         

#ifndef __LEDBit2_H
#define __LEDBit2_H

/* MODULE LEDBit2. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "LEDpin2.h"

#include "Cpu.h"

#define LEDBit2_ClrVal()    LEDpin2_ClrVal() /* put the pin on low level */
#define LEDBit2_SetVal()    LEDpin2_SetVal() /* put the pin on high level */
#define LEDBit2_SetInput()  LEDpin2_SetInput() /* use the pin as input pin */
#define LEDBit2_SetOutput() LEDpin2_SetOutput() /* use the pin as output pin */

#define LEDBit2_PARSE_COMMAND_ENABLED  0 /* set to 1 if method ParseCommand() is present, 0 otherwise */


#define LEDBit2_On() LEDpin2_ClrVal()
/*
** ===================================================================
**     Method      :  LEDBit2_On (component LED)
**     Description :
**         This turns the LED on.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDBit2_Off() LEDpin2_SetVal()
/*
** ===================================================================
**     Method      :  LEDBit2_Off (component LED)
**     Description :
**         This turns the LED off.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDBit2_Neg() LEDpin2_NegVal()
/*
** ===================================================================
**     Method      :  LEDBit2_Neg (component LED)
**     Description :
**         This negates/toggles the LED
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDBit2_Get() (!(LEDpin2_GetVal()))
/*
** ===================================================================
**     Method      :  LEDBit2_Get (component LED)
**     Description :
**         This returns logical 1 in case the LED is on, 0 otherwise.
**     Parameters  : None
**     Returns     :
**         ---             - Status of the LED (on or off)
** ===================================================================
*/

#define LEDBit2_Init() LEDBit2_Off()
/*
** ===================================================================
**     Method      :  LEDBit2_Init (component LED)
**     Description :
**         Performs the LED driver initialization.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDBit2_Put(val)  ((val) ? LEDBit2_On() : LEDBit2_Off())
/*
** ===================================================================
**     Method      :  LEDBit2_Put (component LED)
**     Description :
**         Turns the LED on or off.
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - value to define if the LED has to be on or
**                           off.
**     Returns     : Nothing
** ===================================================================
*/

void LEDBit2_Deinit(void);
/*
** ===================================================================
**     Method      :  LEDBit2_Deinit (component LED)
**     Description :
**         Deinitializes the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void LEDBit2_SetRatio16(word ratio);
/*
** ===================================================================
**     Method      :  LEDBit2_SetRatio16 (component LED)
**     Description :
**         Method to specify the duty cycle. If using a PWM pin, this
**         means the duty cycle is set. For On/off pins, values smaller
**         0x7FFF means off, while values greater means on.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ratio           - Ratio value, where 0 means 'off' and
**                           0xffff means 'on'
**     Returns     : Nothing
** ===================================================================
*/

/* END LEDBit2. */

#endif
/* ifndef __LEDBit2_H */
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
