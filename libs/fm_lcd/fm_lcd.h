/* @file lcd_module.h
 *
 * @brief Modo de uso:
 *
 * 1) Al iniciar un nuevo proyecto puede usar el archivo lcd.ioc para configurar
 * automaticamente.
 *
 * 2) Se debe agregar la carpeta al proyecto, sobre el nombre del proyecto click
 * derecho new -> folder -> link to alternate location -> ....
 *
 * 3) Se debe inicar al ide que hay una nueva parpeta con codigo fuente click
 * derecho en el nombre del proyecto new -> soruce foler-> browse -> ....
 *
 * 4) #include "../../../../libs/fm_lcd/fm_lcd.h"
 *
 * 5) fm_lcd_init();
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

#ifndef FM_LCD_H_
#define FM_LCD_H_

#include "main.h"

void fm_lcd_clear();
void fm_lcd_init();
void fm_lcd_fill();
void fm_lcd_puts(const char *p_str, uint8_t row);
void fm_lcd_refresh();

// Defines.

#endif /* FM_LCD_H_ */

/*** end of file ***/
