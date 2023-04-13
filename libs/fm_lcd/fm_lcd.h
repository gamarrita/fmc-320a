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

#ifndef     FM_LCD_H_
#define     FM_LCD_H_

// Includes.

#include "main.h"
#include "lcd.h"
#include "stdio.h"

#include "../fmc/fmc.h"

// Macros, defines, microcontroller pins (dhs).

// Typedef.

// Defines.

// Function prototypes.

void fm_lcd_acm_rate(fmc_unit_volume_t left_unit, fmc_unit_time_t right_unit);
void fm_lcd_acm_temp();
void fm_lcd_battery_low(blink_t speed);
void fm_lcd_clear();
void fm_lcd_date_hour(int time, int date);
void fm_lcd_fill();
void fm_lcd_format_number_in_line(rows_t line, uint32_t data, char *p_str,
int length);
int fm_lcd_fp_add_dot(fmc_fp_t fp, char *p_str, int str_size);
int fm_lcd_fp_to_str(fmc_fp_t fp, char leading_char, int str_width, char *p_str,
int str_size);
void fm_lcd_init();
void fm_lcd_k_factor(fmc_unit_volume_t volume_unit, point_t high_point);
void fm_lcd_puts(const char *p_str, uint8_t row);
void fm_lcd_refresh();
void fm_lcd_ttl_rate(fmc_unit_volume_t left_unit, fmc_unit_time_t right_unit);
void fm_lcd_units(fmc_unit_volume_t left_unit, fmc_unit_time_t right_unit);
void fm_lcd_version(point_t low_point1, point_t low_point2);

#endif /* FM_LCD_H_ */

/*** end of file ***/
