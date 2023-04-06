/* @file fm_keypad.c
 *
 * @brief Módulo encargado de manejar las interrupciones provenientes del
 * teclado. Por ahora solo puede controlar los botones de arriba y abajo.
 * 
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

// Includes.
#include "main.h"
#include "stdio.h"
#include "fm_keypad.h"
#include "../fm_event/fm_event.h"
#include "../fm_debug/fm_debug.h"

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
 * Mapeo que tecla corresponde a que pin
 */
#define KEY_UP 	    GPIO_PIN_10
#define KEY_DOWN	GPIO_PIN_11
#define KEY_ENTER	GPIO_PIN_12
#define KEY_ESC     GPIO_PIN_13

//Debug.

/*
 * To temporally disable a block of code, use preprocessor's conditional
 * compilation features, eg, the following one should be used to increase the
 * the debug output information.
 *
 */
#ifndef NDEBUG
#endif

// Project variables, non-static, at least used in other file.

uint32_t previous_millis = 0;
uint32_t current_millis = 0;

// External variables.

extern osMessageQueueId_t h_event_queue;
extern osSemaphoreId_t debounce_semaphoreHandle;

// Global variables, statics.

// Private function prototypes.

// Public function bodies.

// Private function bodies.

// Interrupts

void HAL_GPIO_EXTI_Callback(uint16_t gpio_pin) // @suppress("Name convention for function")
{
    /*
     * Deshabilito interrupciones para evitar rebotes de los botones, hasta que
     * la tarea task_debounce termine su ejecución y se bloquee.
     */
    HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);

    /*
     * Variable que almacena el nombre del botón que se presionó.
     */
    fm_event_t event_now;

    #ifdef FM_DEBUG_KEYPAD
        char msg_buffer[10];
//        sprintf(msg_buffer,"DIFF = %u\n", diference);
//        fm_debug_msg_uart((uint8_t *)msg_buffer, sizeof(msg_buffer));
    #endif

    /*
     * Compruebo que botón fue el presionado.
     */
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

    /*
     * Pongo el nombre del botón presionado en la cola de eventos y libero el
     * semáforo de la tarea task_debounce, para que esta se bloquee durante el
     * tiempo necesario para que no haya rebotes de los botones.
     */
    osMessageQueuePut(h_event_queue, &event_now, 0, 0);
    osSemaphoreRelease(debounce_semaphoreHandle);
}

/*** end of file ***/
