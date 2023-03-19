/* @file lcd_module.c
 *
 * @brief Este es el modulo de mas alto nivel, las API, funciones que seran
 * usadas a lo largo de la aplicacion.
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

// Seccion de includess.
#include "fm_lcd.h"

#include "lcd.h"
#include "pcf8553.h"

// Varibles global static, solo visibles en este modulo.

/*
 * @brief Es la primera intrucion a llamar para usar el lcd, luego de
 * inicializar el lcd enciende todos los segmentos.
 * Para comprobar que el lcd esta funcionando se encienden todos los
 * segmentos por unos segundos y luego se lo apaga.
 */
void fm_lcd_init()
{
	lcd_init();

	// All segments will be on for a few seconds after initialization.
	pcf8553_write_all(0xFF); // @suppress("Avoid magic numbers")
	HAL_Delay(2000); // @suppress("Avoid magic numbers")
	pcf8553_write_all(0x00); // @suppress("Avoid magic numbers")
}

/*
 * @brief Imprime en una de las dos filas del lcd, row 0 o row 1.
 *
 */
void fm_lcd_puts(const char *c, const lcd_row_t row)
{
	uint8_t col = 0;
	uint8_t col_limit;

	if(row == 0)
	{
		col_limit = LCD_ROW_0_SIZE;
	}
	else
	{
		col_limit = LCD_ROW_1_SIZE;
	}

	while ((*c) && (col < col_limit))
	{
		if (*c >= '0' && *c <= '9')
		{
			lcd_put_char(*c, col, row);
		}
		col++;
		c++;
	}
}

/*
 * brief
 *
 */
void fm_lcd_refresh()
{
	pcf8553_dump();
}

/*** end of file ***/
