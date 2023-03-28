/* @file fm_keypad.c
 *
 * @brief
 * 
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

// Includes.
#include "main.h"
#include "fm_keypad.h"
#include "../fm_event/fm_event.h"

// Typedef.

/*
 * The names of all new data types, including structures, unions, and
 * enumerations, shall consist only of lowercase characters and internal
 * underscores and end with ‘_t’.
 * 
 * All new structures, unions, and enumerations shall be named via a typedef.
 * 
 */

// Const data.
// Defines.
/*
 * Mapeo que tecla correspondea que pin
 */
#define KEY_UP 	    GPIO_PIN_10
#define KEY_DOWN	GPIO_PIN_11
#define KEY_ENTER	GPIO_PIN_12
#define KEY_ESC     GPIO_PIN_13

//Debug.

/*
 * To temporaly disable a block of code, use preprocessor's conditional
 * compilation features, eg, the following one should be used to increase the
 * the debug output information.
 *
 */
#ifndef NDEBUG
#endif

// Project variables, non-static, at least used in other file.
uint16_t g_key_up_counter = 3;
uint16_t g_key_down_counter = 0;
uint16_t g_key_enter_counter = 3;
uint16_t g_key_esc_counter = 4;

// External variables.

extern osMessageQueueId_t h_event_queue;

// Global variables, statics.

// Private function prototypes.

// Public function bodies.

// Private function bodies.

// Interrupts

void HAL_GPIO_EXTI_Callback(uint16_t gpio_pin) // @suppress("Name convention for function")
{
    fm_event_t event_now;

    switch (gpio_pin)
    {
        case KEY_UP:
            event_now = EVENT_KEY_UP;
        break;
        case KEY_DOWN:
            event_now = EVENT_KEY_DOWN;
        break;
        case KEY_ENTER:
            event_now = EVENT_KEY_ENTER;
        break;
        case KEY_ESC:
            event_now = EVENT_KEY_ESC;
        break;
        default:
        break;
    }
    osMessageQueuePut(h_event_queue, &event_now, 0, 0);
}

/*** end of file ***/
