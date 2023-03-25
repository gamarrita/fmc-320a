/* @file fm_computer.c
 *
 * @brief Este es el módulo que se encarga de obtener datos de los sensores,
 * relojes, y registros incorporados al hardware del caudalímetro, vease,
 * sensores de temperatura, de caudal, de volumen, y registros que indiquen
 * por ejemplo la versión actual del caudalímetro.
 * 
 * IMPORTANTE: Actualmente esta información no se obtiene de dichos sensores o
 * registros, sinó que se definen valores constantes para las pruebas
 * iniciales (sand).
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
#define ACM_INIT_VALUE 140
#define DATE_INIT_VALUE 22032023
#define EXT_TEMP_INIT_VALUE 253
#define HOUR_INIT_VALUE 93000
#define LIQ_TEMP_INIT_VALUE 53
#define RATE_INIT_VALUE 100
#define TTL_INIT_VALUE 9870
#define VERSION_INIT_VALUE 10

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
static uint32_t g_acm = ACM_INIT_VALUE;
static uint32_t g_date = DATE_INIT_VALUE;
static uint32_t g_ext_temp = EXT_TEMP_INIT_VALUE;
static uint32_t g_hour = HOUR_INIT_VALUE;
static uint32_t g_liq_temp = LIQ_TEMP_INIT_VALUE;
static uint32_t g_rate = RATE_INIT_VALUE;
static uint32_t g_ttl = TTL_INIT_VALUE;
static uint32_t g_version = VERSION_INIT_VALUE;

// Private function prototypes.

// Private function bodies.

// Public function bodies.

/*
 * @brief Función que obtiene el valor del caudal acumulado y lo devuelve como
 * parámetro de retorno.
 * @param  None
 * @retval caudal acumulado g_acm de tipo uint32_t definido como global.
 */

uint32_t fm_computer_get_acm()
{
	return (g_acm);
}

/*
 * @brief Función que obtiene la fecha actual y lo devuelve como parámetro de
 * retorno.
 * @param  None
 * @retval fecha g_date de tipo uint32_t definido como global.
 */

uint32_t fm_computer_get_date()
{
	return (g_date);
}

/*
 * @brief Función que obtiene el valor de la temperatura externa y lo devuelve
 * como parámetro de retorno.
 * @param  None
 * @retval temperatura externa g_ext_temp de tipo uint32_t definido como
 * global.
 */

uint32_t fm_computer_get_ext_temp()
{
	return (g_ext_temp);
}

/*
 * @brief Función que obtiene el valor de la hora actual y lo devuelve como
 * parámetro de retorno.
 * @param  None
 * @retval hora actual g_hour de tipo uint32_t definido como global.
 */

uint32_t fm_computer_get_hour()
{
	return (g_hour);
}

/*
 * @brief Función que obtiene el valor de la temperatura del líquido y lo
 * devuelve como parámetro de retorno.
 * @param  None
 * @retval temperatura del líquido g_liq_temp de tipo uint32_t definido como
 * global.
 */

uint32_t fm_computer_get_liq_temp()
{
	return (g_liq_temp);
}

/*
 * @brief Función que obtiene el valor del caudal instantaneo 'rate' y lo
 * devuelve como parámetro de retorno.
 * @param  None
 * @retval caudal instantaneo g_rate de tipo uint32_t definido como global.
 */

uint32_t fm_computer_get_rate()
{
	return (g_rate);
}

/*
 * @brief Función que obtiene el valor del caudal histórico y lo devuelve como
 * parámetro de retorno.
 * @param  None
 * @retval caudal histórico g_ttl de tipo uint32_t definido como global.
 */

uint32_t fm_computer_get_ttl()
{
	return (g_ttl);
}

/*
 * @brief Función que obtiene la versión del caudalímetro y la devuelve como
 * parámetro de retorno.
 * @param  None
 * @retval versión del caudalímetro g_version de tipo uint32_t definido como
 * global.
 */

uint32_t fm_computer_get_version()
{
	return (g_version);
}

// Interrupts

/*** end of file ***/
