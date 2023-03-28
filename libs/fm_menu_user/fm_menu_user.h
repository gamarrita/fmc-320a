/* @file fm_menu_user.h
 *
 * @brief Este modulo se encarga de la impresión de menús que son accesibles por
 * el usuario del caudalímetro en la pantalla LCD. Para ello hace uso de la
 * librería de mas bajo nivel fm_lcd.h que se encarga de la inteligencia para
 * este fin.
 *
 * IMPORTANTE: En un futuro se creará una máquina de estados basada en punteros
 * a función que se vincule directamente con esta librería para el pasaje entre
 * menús. Por el momento solo se implementará una versión rudimentaria de la
 * misma en una tarea del sistema operativo para chequear su funcionalidad, pero
 * puede que en el futuro esto se pase a otra libreria llamada por ejemplo
 * fm_fsm_menu_user.h o algo similar (sand).
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 */

#ifndef FM_MENU_USER_H_
#define FM_MENU_USER_H_

// includes
#include "main.h"
#include "../../../libs/fm_lcd/fm_lcd.h"
#include "../fm_event/fm_event.h"

// Macros, defines, microcontroller pins (dhs).

// Typedef.

// Lo siguiente es una tecnica para lograr que:
// Una funcion retorna un puntero a funcion, donde
// el tipo de funcion retornada es el de la funcion que se esta ejecutando.
typedef void* (*ptr_ret_menu_t)(fm_event_t);      // Un puntero a funcion
typedef ptr_ret_menu_t (*ptr_fun_menu_t)(fm_event_t);   //

// Defines.

// Function prototypes
ptr_ret_menu_t fm_menu_show_acm_rate(fm_state_t *actual_state, fm_event_t);
ptr_ret_menu_t fm_menu_show_alert_battery(fm_state_t *actual_state, fm_event_t);
ptr_ret_menu_t fm_menu_show_date_hour(fm_state_t *actual_state, fm_event_t);
ptr_ret_menu_t fm_menu_show_temp_temp(fm_state_t *actual_state, fm_event_t);
ptr_ret_menu_t fm_menu_show_ttl_rate(fm_state_t *actual_state, fm_event_t);
ptr_ret_menu_t fm_menu_show_version(fm_state_t *actual_state, fm_event_t);

#endif /* FM_MENU_USER_H_ */

/*** end of file ***/
