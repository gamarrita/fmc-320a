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
static const uint32_t g_scalar[] =
{
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000
};

// Defines.
#define ACM_INIT_VALUE 140
#define EXT_TEMP_INIT_VALUE 253
#define RATE_INIT_VALUE 100
#define TTL_INIT_VALUE 9870

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
static uint32_t g_acm = ACM_INIT_VALUE;
static uint32_t g_ext_temp = EXT_TEMP_INIT_VALUE;
static uint32_t g_rate = RATE_INIT_VALUE;
static uint32_t g_ttl = TTL_INIT_VALUE;

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
 * @brief Esta función limpia la cantidad de pulsos leidos por el contador de
 * pulsos.
 * @param  puntero a estructura que contiene datos como la cantidad de pulsos
 * leidos, valor y resolución del caudal/volumen, entre otros.
 * @retval None
 */
void fm_computer_totalizer_clear_pulse(fmc_totalizer_t *p_totalizer)
{
    p_totalizer->pulse = 0;
    fm_computer_totalizer_refresh(p_totalizer);
}

/*
 * @brief
 * @param
 * @retval None
 */
fmc_totalizer_t fm_computer_totalizer_init(fmc_totalizer_t totalizer)
{
    fm_computer_totalizer_refresh(&totalizer);

    return (totalizer);
}

/*
 * @brief Esta función refresca el volumen obtenido de dividir los pulsos leidos
 * por el factor correspondiente.
 * @param  puntero a estructura que contiene datos como la cantidad de pulsos
 * leidos, valor y resolución del caudal/volumen, entre otros.
 * @retval None
 */
void fm_computer_totalizer_refresh(fmc_totalizer_t *p_totalizer)
{
    uint64_t result;

    /*
     * result es la cantidad de pulsos almacenados en la estructura p_totalizer.
     */
    result = (uint64_t) p_totalizer->pulse;

    /*
     * Pulsos escalados en el factor y en la resolucion a mostrar.
     */
    result *= g_scalar[p_totalizer->factor.res + p_totalizer->volume.res];

    /*
     * Obtengo el valor numérico del volumen dividiendo los pulsos escalados
     * por el factor.
     */
    result /= p_totalizer->factor.num;

    p_totalizer->volume.num = (uint32_t) result;

}

// Interrupts

/*** end of file ***/
