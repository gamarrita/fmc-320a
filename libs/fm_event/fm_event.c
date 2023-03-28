/* @file fm_module.c
 *
 * @brief Each source file shall be comprised of some or all of the following
 * sections, in the order listed down below.
 * Comenzar cada nuevo archivo usando un template. Hay un templeate general a
 * todos los proyectos que puede ser usado hata el momento de introducir un 
 * cambio que solo respondera a un proyecto en progreso, es ese caso el
 * template pasara a ser parte del proyecto.
 * 
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

// Includes.
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
const osMessageQueueAttr_t event_queue_attributes =
{
    .name = "event_queue"
};

// Defines.

#define EVENT_QUEUE_LENGTH 4

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
osMessageQueueId_t h_event_queue;

// External variables.

// Global variables, statics.

// Private function prototypes.

// Private function bodies.

// Public function bodies.

void fm_event_init()
{
    h_event_queue = osMessageQueueNew(EVENT_QUEUE_LENGTH, sizeof(fm_event_t),
    &event_queue_attributes);
}

// Interrupts

/*** end of file ***/
