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
#include "../../../../libs/fm_computer/fm_computer.h"
#include "../../../../libs/fm_lcd/fm_lcd.h"
#include "stdio.h"
#include "string.h"



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

#define MSG_LENGTH 12 // Tamaño maximo para una linea en el LCD.

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

// External variables.

// Global variables, statics.

// Private function prototypes.

// Private function bodies.

// Public function bodies.

void fm_menu_ttl_rate()
{
	char msg[MSG_LENGTH];
	snprintf(msg, sizeof(msg), "%08lu", fm_computer_get_ttl());
	fm_lcd_puts(msg, 0);

	snprintf(msg, sizeof(msg), "%07lu", fm_computer_get_rate());
	fm_lcd_puts(msg, 1);

	fm_lcd_refresh();
}

void fm_menu_acm_rate()
{
	char msg[MSG_LENGTH];
	snprintf(msg, sizeof(msg), "%08lu", fm_computer_get_acm());
	fm_lcd_puts(msg, 0);

	snprintf(msg, sizeof(msg), "%07lu", fm_computer_get_rate());
	fm_lcd_puts(msg, 1);

	fm_lcd_refresh();
}



// Interrupts

/*** end of file ***/
