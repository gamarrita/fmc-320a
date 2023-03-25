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

// Macros, defines, microcontroller pins (dhs).

// Typedef.

// Defines.

// Function prototypes
void fm_menu_begin();
void fm_menu_show_acm_rate();
void fm_menu_show_alert_battery();
void fm_menu_show_date_hour();
void fm_menu_show_temp_temp();
void fm_menu_show_ttl_rate();
void fm_menu_show_version();

#endif /* FM_MENU_USER_H_ */

/*** end of file ***/
