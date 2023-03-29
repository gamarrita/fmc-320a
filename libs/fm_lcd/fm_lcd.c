/* @file fm_lcd.c
 *
 * @brief Este es el modulo que posee la inteligencia para manejar las opciones
 * que brinda la pantalla LCD, utilizando las funciones implementadas de
 * impresión de caracteres individuales en lcd.h.
 * Las funciones de este modulo serán usadas por librerías de mas alto nivel que
 * impriman menús o controlen máquinas de estado de pantallas, tales como
 * fm_menu_user.h.
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

// Includes.
#include "fm_lcd.h"
#include "lcd.h"
#include "../fm_computer/fm_computer.h"


// Typedef.

// Const data.

// Defines.
#define MSG_LENGTH 12
// Debug.

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
 * @brief Función que setea una serie de símbolos, puntos y dígitos en la
 * pantalla LCD, permitiendo mostrar el caudal acumulado y el rate, de forma
 * personalizada según las opciones que se elijan.
 * @param puntos de la fila superior e inferior a imprimir, de tipo point_t, y
 * unidades a utilizar en la medición de tipo symbols_t.
 * @retval None
 */

void fm_lcd_acm_rate(point_t high_point, point_t low_point, symbols_t left_unit,
symbols_t right_unit)
{
	char lcd_msg[MSG_LENGTH];

	fm_lcd_format_number_in_line(HIGH_ROW, fm_computer_get_acm(), lcd_msg,
	MSG_LENGTH);
	fm_lcd_puts(lcd_msg, HIGH_ROW);
	lcd_set_point(HIGH_ROW, high_point);

	fm_lcd_format_number_in_line(LOW_ROW, fm_computer_get_rate(), lcd_msg,
	MSG_LENGTH);
	fm_lcd_puts(lcd_msg, LOW_ROW);
	lcd_set_point(LOW_ROW, low_point);

	lcd_set_symbol(ACM, 0x0);
	lcd_set_symbol(RATE, 0x0);

	lcd_set_symbol(left_unit, 0x0);
	lcd_set_symbol(BACKSLASH, 0x0);
	lcd_set_symbol(right_unit, 0x0);
}

/*
 * @brief Función que permite setear el símbolo de bateria baja del
 * dispositivo, el cual puede configurarse con la pantalla parpadeando a una
 * velocidad especificada.
 * @param Velocidad de parpadeo de la pantalla de tipo blink_t definido en
 * lcd.h.
 * @retval None
 */

void fm_lcd_battery_low(blink_t speed)
{
	lcd_set_symbol(BATTERY, speed);
}

/*
 * @brief Función que limpia toda la pantalla.
 * @param  None
 * @retval None
 */
void fm_lcd_clear()
{
	lcd_clear_all();
}

/*
 * @brief Función que setea una serie de símbolos, puntos y dígitos en la
 * pantalla LCD, permitiendo mostrar la fecha y hora actual, de forma
 * personalizada según las opciones que se elijan.
 * @param Puntos de la fila superior e inferior a imprimir, de tipo point_t.
 * @retval None
 */

void fm_lcd_date_hour(point_t high_point_1, point_t high_point_2,
point_t low_point_1, point_t low_point_2)
{

	char lcd_msg[MSG_LENGTH];

	fm_lcd_format_number_in_line(HIGH_ROW, fm_computer_get_date(), lcd_msg,
	MSG_LENGTH);
	fm_lcd_puts(lcd_msg, HIGH_ROW);
	lcd_set_point(HIGH_ROW, high_point_1);
	lcd_set_point(HIGH_ROW, high_point_2);

	fm_lcd_format_number_in_line(LOW_ROW, fm_computer_get_hour(), lcd_msg,
	MSG_LENGTH);
	fm_lcd_puts(lcd_msg,LOW_ROW);
	lcd_set_point(LOW_ROW, low_point_1);
	lcd_set_point(LOW_ROW, low_point_2);
}

/*
 * @brief Función que formatea información pasada como parámetro para ser
 * colocada en una de las dos filas de la pantalla LCD.
 * @param Enumeracion rows_t de lcd.h
 * @retval arreglo con la información formateada tipo char.
 */
void fm_lcd_format_number_in_line(rows_t line, uint32_t data, char *p_str, int length)
{
	if (line == HIGH_ROW)
	{
		snprintf(p_str, length, "%8lu", data);
	}
	else if (line == LOW_ROW)
	{
		snprintf(p_str, length, "%7lu", data);
	}
}

/*
 * @brief Es la primera instrucción a llamar para usar el lcd, luego de
 * inicializar el lcd enciende todos los segmentos.
 * Para comprobar que el lcd esta funcionando se encienden todos los
 * segmentos por unos segundos y luego se lo apaga.
 * @param  None
 * @retval None
 */
void fm_lcd_init()
{
	lcd_clear_all();
	lcd_init();
	// All segments will be on for a few seconds after initialization.
	pcf8553_write_all(0xFF); // @suppress("Avoid magic numbers")
	HAL_Delay(500); // @suppress("Avoid magic numbers")
	pcf8553_write_all(0x00); // @suppress("Avoid magic numbers")
}

/*
 * @brief Función que imprime en una de las dos filas del lcd, row 0 o row 1.
 * @param
 * @retval None
 */
void fm_lcd_puts(const char *c, const rows_t row)
{
	uint8_t col = 0;
	uint8_t col_limit;

	if (row == 0)
	{
		col_limit = LCD_ROW_0_SIZE;
	}
	else
	{
		col_limit = LCD_ROW_1_SIZE;
	}

	while ((*c) && (col < col_limit))
	{
		if(((*c >= '0') && (*c <= '9')) || (*c == ' '))
		{
			lcd_put_char(*c, col, row);
		}
		col++;
		c++;
	}
}

/*
 * @brief Función que permite actualizar la pantalla llamando a una función de
 * la librería de mas bajo nivel 'lcd.h'.
 * @param  None
 * @retval None
 */

void fm_lcd_refresh()
{
	lcd_refresh();
}

/*
 * @brief Función que setea una serie de símbolos, puntos y dígitos en la
 * pantalla LCD, permitiendo mostrar la temperatura del líquido y la exterior,
 * de forma personalizada según las opciones que se elijan.
 * @param Puntos de la fila superior e inferior a imprimir, de tipo point_t.
 * @retval None
 */

void fm_lcd_temp_temp(point_t high_point, point_t low_point)
{
	char lcd_msg[MSG_LENGTH];

	fm_lcd_format_number_in_line(HIGH_ROW, fm_computer_get_liq_temp(), lcd_msg,
	MSG_LENGTH);

	fm_lcd_puts(lcd_msg, HIGH_ROW);
	lcd_set_point(HIGH_ROW, high_point);

	fm_lcd_format_number_in_line(LOW_ROW, fm_computer_get_ext_temp(), lcd_msg,
	MSG_LENGTH);

	fm_lcd_puts(lcd_msg, LOW_ROW);
	lcd_set_point(LOW_ROW, low_point);

	lcd_set_symbol(CELSIUS, 0x0);
}

/*
 * @brief Función que setea una serie de símbolos, puntos y dígitos en la
 * pantalla LCD, permitiendo mostrar el caudal total y el rate, de forma
 * personalizada según las opciones que se elijan.
 * @param puntos de la fila superior e inferior a imprimir, de tipo point_t, y
 * unidades a utilizar en la medición de tipo symbols_t.
 * @retval None
 */

void fm_lcd_ttl_rate(point_t high_point, point_t low_point, symbols_t left_unit,
symbols_t right_unit)
{
	char lcd_msg[MSG_LENGTH];

	fm_lcd_format_number_in_line(HIGH_ROW, fm_computer_get_ttl(), lcd_msg,
	MSG_LENGTH);
	fm_lcd_puts(lcd_msg, HIGH_ROW);
	lcd_set_point(HIGH_ROW, high_point);

	fm_lcd_format_number_in_line(LOW_ROW, fm_computer_get_rate(), lcd_msg,
	MSG_LENGTH);
	fm_lcd_puts(lcd_msg, LOW_ROW);
	lcd_set_point(LOW_ROW, low_point);

	lcd_set_symbol(TTL, 0x0);
	lcd_set_symbol(RATE, 0x0);

	lcd_set_symbol(left_unit, 0x0);
	lcd_set_symbol(BACKSLASH, 0x0);
	lcd_set_symbol(right_unit, 0x0);
}

/*
 * @brief Función que setea una serie de símbolos y puntos en la pantalla
 * LCD, permitiendo mostrar la versión del caudalímetro, de forma personalizada
 * según las opciones que se elijan.
 * @param puntos de la fila inferior a imprimir, de tipo point_t.
 * @retval None
 */

void fm_lcd_version(point_t low_point)
{
	char lcd_msg[MSG_LENGTH];

	fm_lcd_format_number_in_line(LOW_ROW, fm_computer_get_version(), lcd_msg,
	MSG_LENGTH);
	lcd_set_symbol(VE, 0x0);


	fm_lcd_puts(lcd_msg, LOW_ROW);
	lcd_set_point(LOW_ROW, low_point);
}

// Interrupts

/*** end of file ***/
