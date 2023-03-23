/* @file fm_lcd.h
 *
 * @brief
 *
 * Este es el modulo que posee la inteligencia para manejar las opciones que
 * brinda la pantalla LCD, utilizando las funciones implementadas de impresión
 * de caracteres individuales en lcd.h.
 * Las funciones de este modulo serán usadas por librerías de mas alto nivel que
 * impriman menús o controlen máquinas de estado de pantallas, tales como
 * fm_menu_user.h.
 *
 * Modo de uso:
 *
 * 1) Al iniciar un nuevo proyecto puede usar el archivo lcd.ioc para configurar
 * automaticamente.
 *
 * 2) Se debe agregar la carpeta al proyecto, sobre el nombre del proyecto click
 * derecho new -> folder -> link to alternate location -> ....
 *
 * 3) Se debe indicar al IDE que hay una nueva carpeta con codigo fuente click
 * derecho en el nombre del proyecto new -> source folder-> browse -> ....
 *
 * 4) #include "../../../../libs/fm_lcd/fm_lcd.h"
 *
 * 5) fm_lcd_init();
 *
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

#ifndef FM_LCD_H_
#define FM_LCD_H_

// Includes.

#include "main.h"
#include "lcd.h"

// Macros, defines, microcontroller pins (dhs).

// Typedef.

// Defines.

// Function prototypes.

void fm_lcd_acm_rate(point_t high_point, point_t low_point, symbols_t left_unit,
symbols_t right_unit);
void fm_lcd_battery_low(blink_t speed);
void fm_lcd_clear();
void fm_lcd_date_hour(point_t high_point_1, point_t high_point_2,
point_t low_point_1, point_t low_point_2);
void fm_lcd_fill();
void fm_lcd_init();
void fm_lcd_puts(const char *p_str, uint8_t row);
void fm_lcd_refresh();
void fm_lcd_temp_temp(point_t high_point, point_t low_point);
void fm_lcd_ttl_rate(point_t high_point, point_t low_point, symbols_t left_unit,
symbols_t right_unit);
void fm_lcd_version(point_t low_point);

#endif /* FM_LCD_H_ */

/*** end of file ***/
