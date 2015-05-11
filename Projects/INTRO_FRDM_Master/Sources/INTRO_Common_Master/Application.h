/**
 * \file
 * \brief Interface to application logic.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * In this module the application logic is implemented.
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_


#include "Event.h"

/*!
 * \brief Prints a debugging string to the shell
 * \param str String to be printed.
 */
void APP_DebugPrint(unsigned char *str);

/*!
 * \brief Application event handler.
 * \param event Event to be handled.
 */
void APP_HandleEvents(EVNT_Handle event);

/*!
 * \brief Runs the application main loop.
 */
void APP_Run(void);


#endif /* APPLICATION_H_ */
