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

#include "fm_computer.h"

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

#define TTL_INIT_VALUE 98700
#define ACM_INIT_VALUE 140
#define RATE_INIT_VALUE 100

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
static uint32_t g_ttl 	= TTL_INIT_VALUE;
static uint32_t g_acm 	= ACM_INIT_VALUE;;
static uint32_t g_rate	= RATE_INIT_VALUE;;

// Private function prototypes.

// Private function bodies.

// Public function bodies.

uint32_t fm_computer_get_ttl()
{
	return (g_ttl);
}

uint32_t fm_computer_get_acm()
{
	return (g_acm);
}

uint32_t fm_computer_get_rate()
{
	return (g_rate);
}


// Interrupts

/*** end of file ***/
