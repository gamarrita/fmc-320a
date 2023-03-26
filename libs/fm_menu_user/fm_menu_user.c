/* @file fm_menu_user.c
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
 *
 */

// Includes.
#include "fm_menu_user.h"
#include "stdio.h"
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

// External variables.

// Global variables, statics.

// Private function prototypes.

// Private function bodies.

// Public function bodies.

/*
 * @brief Función que imprime el menú de acm y rate en la pantalla, con
 * unidades y puntos específicos.
 * @param  None
 * @retval None
 */

ptr_ret_menu_t fm_menu_show_acm_rate()
{
	fm_lcd_clear();
	fm_lcd_acm_rate(PNT_5, PNT_5, GL, H);
	fm_lcd_refresh();
	return  ((ptr_ret_menu_t) fm_menu_show_alert_battery);
}

/*
 * @brief Función que imprime el menú de alerta por bateria baja en la
 * pantalla, a una velocidad especificada.
 * @param  None
 * @retval None
 */

ptr_ret_menu_t fm_menu_show_alert_battery()
{
	fm_lcd_battery_low(HIGH_SPEED);
	fm_lcd_refresh();
	return ((ptr_ret_menu_t) fm_menu_show_date_hour);
}

/*
 * @brief Función que imprime el menú de fecha y hora en la pantalla, con
 * unidades y puntos específicos.
 * @param  None
 * @retval None
 */

ptr_ret_menu_t fm_menu_show_date_hour()
{
	fm_lcd_clear();
	fm_lcd_date_hour(PNT_1, PNT_3, PNT_2, PNT_4);
	fm_lcd_refresh();
	return ((ptr_ret_menu_t)fm_menu_show_temp_temp);
}

/*
 * @brief Función que imprime el menú de temperatura del líquido y exterior en
 * la pantalla, con puntos específicos.
 * @param  None
 * @retval None
 */

ptr_ret_menu_t fm_menu_show_temp_temp()
{
	fm_lcd_clear();
	fm_lcd_temp_temp(PNT_6, PNT_5);
	fm_lcd_refresh();
	return ((ptr_ret_menu_t)fm_menu_show_ttl_rate);
}

/*
 * @brief Función que imprime el menú de ttl y rate en la pantalla, con
 * unidades y puntos específicos.
 * @param  None
 * @retval None
 */

ptr_ret_menu_t fm_menu_show_ttl_rate()
{
	fm_lcd_clear();
	fm_lcd_ttl_rate(PNT_4, PNT_5, LT, S);
	fm_lcd_refresh();
	return ((ptr_ret_menu_t)fm_menu_show_version);
}

/*
 * @brief Función que imprime el menú con la versión del caudalímetro en la
 * pantalla, con puntos específicos.
 * @param  None
 * @retval None
 */

ptr_ret_menu_t fm_menu_show_version()
{
	fm_lcd_clear();
	fm_lcd_version(PNT_5);
	fm_lcd_refresh();
	return ((ptr_ret_menu_t)fm_menu_show_acm_rate);
}

// Interrupts

/*** end of file ***/
