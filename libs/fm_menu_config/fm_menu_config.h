/* @file fm_menu_config.h
 *
 * @brief A description of the module’s purpose.
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 */

#ifndef     FM_MENU_CONFIG_H_
#define     FM_MENU_CONFIG_H_

// includes

#include "main.h"
#include "../fm_lcd/fm_lcd.h"
#include "../fm_event/fm_event.h"
#include "../fm_menu_user/fm_menu_user.h"

// Macros, defines, microcontroller pins (dhs).

// Typedef.

typedef void* (*ptr_ret_menu_t)(fm_event_t);            // Un puntero a funcion
typedef       ptr_ret_menu_t (*ptr_fun_menu_t)(fm_event_t);

// Defines.

// Function prototypes

ptr_ret_menu_t fm_menu_conf_volume_unit(fm_event_t);
ptr_ret_menu_t fm_menu_conf_time_unit(fm_event_t);
ptr_ret_menu_t fm_menu_conf_k_parameter(fm_event_t);

#endif /* MENU_CONFIG_H */

/*** end of file ***/
