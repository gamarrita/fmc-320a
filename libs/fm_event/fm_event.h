/* @file fm_event.h
 *
 * @brief Este módulo permite inicializar y declarar una serie de eventos que
 * serán introducidos en una cola de eventos, con el objetivo de que las
 * máquinas de estado sepan a que estado desplazarse.
 * 
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 */

#ifndef     FM_EVENT_H_
#define     FM_EVENT_H_

// includes

#include "main.h"
#include "cmsis_os.h"

// Macros, defines, microcontroller pins (dhs).

// Typedef.

typedef enum
{
    EVENT_NULL = 0,
    EVENT_LCD_REFRESH,
    EVENT_KEY_UP,
    EVENT_KEY_DOWN,
    EVENT_KEY_ENTER,
    EVENT_KEY_ESC,
    EVENT_END
} fm_event_t;

// Defines.

// Function prototypes

void fm_event_init();

#endif /* MODULE_H */

/*** end of file ***/
