/* @file fm_factory.c
 *
 * @brief Aquí se tienen los valores de fabrica, se usan al menos en las
 * siguientes situaciones:
 * Al encender el equipo por primera vez, las variables de entorno tomarán estos
 * valores.
 * Si el usuario tiene problemas puede resetear a valores de fabrica.
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

// Includes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fm_factory.h"
#include "../fmc/fmc.h"
#include "../fm_lcd/fm_lcd.h"

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
/*Los valores de fabrica por el momento coinciden con los de configuracion,
 no con los de entorno. En algún momento se puede necesitar separar valor
 de fabrica con los de configuración.
 */
static fmc_totalizer_t ttl_config =
{
    .pulse = 12000,
    .volume.num = 0,
    .volume.res = 2,
    .factor.num = 3000, // pulsos/unidad_volumen.
    .factor.res = 1,
    .unit_volume = LT,
    .unit_time = S,
};

static fmc_totalizer_t acm_config =
{
    .pulse = 6000,
    .volume.num = 0,
    .volume.res = 2,
    .factor.num = 3000, // pulsos/unidad_volumen.
    .factor.res = 1,
    .unit_volume = LT,
    .unit_time = S,
};

static fmc_totalizer_t rate_config =
{
    .pulse = 123500,
    .volume.num = 0,
    .volume.res = 0,
    .factor.num = 125000,
    .factor.res = 3,
    .unit_volume = LT,
    .unit_time = S,
};

static fmc_temp_t temperature_config =
{
    .temperature.num = 20,
    .temperature.res = 0,
    .unit_volume_temp = CELSIUS,
};

static fmc_date_time_t date_time_config =
{
    .day = 17,
    .month = 4,
    .year = 23,
    .hour = 17,
    .minute = 4,
    .second = 20,
};

static fmc_fp_t units_digits_tim =
{
    .num = 0,
    .res = 2,
};

static fmc_fp_t units_digits_vol =
{
    .num = 0,
    .res = 2,
};

static fmc_fp_t k_factor_config =
{
    .num = 14170,
    .res = 2,
};

static fmc_fp_t time_user =
{
    .num = 93000,
    .res = 0,
};

static fmc_fp_t date_user =
{
    .num = 19042023,
    .res = 0,
};

static fmc_fp_t time_config =
{
    .num = 93000,
    .res = 0,
};

static fmc_fp_t date_config =
{
    .num = 19042023,
    .res = 0,
};

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

sel_value_t k_array[LINE_1_DIGITS]; //Arreglo que almacena al factor K.

// External variables.

// Global variables, statics.

// Private function prototypes.

// Private function bodies.

// Public function bodies.

/*
 * @brief Función que devuelve el parámetro ACM almacenado en fm_factory.
 * @param None
 * @retval Parámetro ACM como estructura de tipo fmc_totalizer_t.
 */
fmc_totalizer_t fm_factory_get_acm()
{
    return (acm_config);
}

/*
 * @brief Función que devuelve el parámetro TTL almacenado en fm_factory.
 * @param None
 * @retval Parámetro TTL como estructura de tipo fmc_totalizer_t.
 */
fmc_totalizer_t fm_factory_get_ttl()
{
    return (ttl_config);
}

/*
 * @brief Función que devuelve el parámetro RATE almacenado en fm_factory.
 * @param None
 * @retval Parámetro RATE como estructura de tipo fmc_totalizer_t.
 */
fmc_totalizer_t fm_factory_get_rate()
{
    return (rate_config);
}

/*
 * @brief Función que devuelve el la temperatura interna del micro almacenado en
 * fm_factory.
 * @param None
 * @retval Temperatura interna del micro como estructura de tipo fmc_temp_t.
 */
fmc_temp_t fm_factory_get_temp()
{
    return (temperature_config);
}

/*
 * @brief Función que devuelve la configuración de resoluciones almacenado en
 * fm_factory.
 * @param None
 * @retval Configuración de resoluciones como estructura de tipo fmc_fp_t.
 */
fmc_fp_t fm_factory_get_units_tim()
{
    return (units_digits_tim);
}

/*
 * @brief Función que devuelve la configuración de resoluciones almacenado en
 * fm_factory.
 * @param None
 * @retval Configuración de resoluciones como estructura de tipo fmc_fp_t.
 */
fmc_fp_t fm_factory_get_units_vol()
{
    return (units_digits_vol);
}

/*
 * @brief Función que devuelve el factor K almacenado en fm_factory.
 * @param None
 * @retval Factor K.
 */
fmc_fp_t fm_factory_get_k_factor()
{
    return (k_factor_config);
}

/*
 * @brief Función que devuelve la fecha y la hora almacenada en fm_factory, como
 * parámetros individuales.
 * @param None
 * @retval Hora, minutos, segundos, día, mes y año almacenados en
 * date_time_config.
 */
fmc_date_time_t fm_factory_get_date_time()
{
    return(date_time_config);
}

fmc_fp_t fm_factory_get_fp_date()
{
    return(date_user);
}

fmc_fp_t fm_factory_get_fp_time()
{
    return(time_user);
}

fmc_fp_t fm_factory_get_fp_date_conf()
{
    return(date_config);
}

fmc_fp_t fm_factory_get_fp_time_conf()
{
    return(time_config);
}

void fm_factory_modify_fp_date(int date)
{
    date_user.num = date;
}

void fm_factory_modify_fp_time(int time)
{
    time_user.num = time;
}

void fm_factory_modify_date(int mod_day, int mod_month, int mod_year)
{
    date_time_config.day = mod_day;
    date_time_config.month = mod_month;
    date_time_config.year = mod_year;

    date_config.num = mod_day * 1000000 + mod_month * 10000 + 2000 + mod_year;
}

void fm_factory_modify_time(int mod_hour, int mod_minute, int mod_second)
{
    date_time_config.hour = mod_hour;
    date_time_config.minute = mod_minute;
    date_time_config.second = mod_second;

    time_config.num = mod_hour * 10000 + mod_minute * 100 + mod_second;
}

/*
 * @brief Función que resta uno al dígito pasado como parámetro del factor K.
 * @param Digito a modificar del factor K de la enumeración sel_digit_t.
 * @retval None
 */
void fm_factory_modify_k_factor_subs(sel_digit_t digit_k)
{
    uint32_t k_new_num = 0;
    fm_factory_separate_k_factor();
    if (k_array[LINE_1_DIGITS - 1 - digit_k] > VAL_0)
    {
        k_array[LINE_1_DIGITS - 1 - digit_k]--;
    }
    else
    {
        k_array[LINE_1_DIGITS - 1 - digit_k] = VAL_9;
    }

    for (int i = 0; i <= LINE_1_DIGITS - 1; i++)
    {
        k_new_num = (k_new_num * 10) + k_array[i];
    }

    k_factor_config.num = k_new_num;
}

/*
 * @brief Función que suma uno al dígito pasado como parámetro del factor K.
 * @param Digito a modificar del factor K de la enumeración sel_digit_t.
 * @retval None
 */
void fm_factory_modify_k_factor_add(sel_digit_t digit_k)
{
    uint32_t k_new_num = 0;
    fm_factory_separate_k_factor();
    if (k_array[LINE_1_DIGITS - 1 - digit_k] < VAL_9)
    {
        k_array[LINE_1_DIGITS - 1 - digit_k]++;
    }
    else
    {
        k_array[LINE_1_DIGITS - 1 - digit_k] = VAL_0;
    }

    for (int i = 0; i <= LINE_1_DIGITS - 1; i++)
    {
        k_new_num = (k_new_num * 10) + k_array[i];
    }

    k_factor_config.num = k_new_num;
}

/*
 * @brief modifica la resolución de los factores acm y ttl.
 * @param Resoluciones de fabrica, y de los parámetros ACM y TTL.
 * @retval None
 */
void fm_factory_modify_res_acm_ttl(sel_resolution_t units_res,
sel_resolution_t acm_res, sel_resolution_t ttl_res)
{
    units_digits_vol.res = units_res;
    acm_config.volume.res = acm_res;
    ttl_config.volume.res = ttl_res;
}

/*
 * @brief modifica la resolución del factor rate.
 * @param Resolución de fabrica, y del parámetro rate.
 * @retval None
 */
void fm_factory_modify_res_rate(sel_resolution_t units_res,
sel_resolution_t rate_res)
{
    units_digits_tim.res = units_res;
    rate_config.volume.res = rate_res;
}

/*
 * @brief Modifica las unidades de tiempo que se muestran en los menús de
 * usuario.
 * @param A que unidad se quiere cambiar.
 * @retval None
 */
void fm_factory_modify_time_units(fmc_unit_time_t time_units)
{
    acm_config.unit_time = time_units;
    ttl_config.unit_time = time_units;
    rate_config.unit_time = time_units;
}

/*
 * @brief Modifica las unidades de volumen que se muestran en los menús de
 * usuario.
 * @param A que unidad se quiere cambiar.
 * @retval None
 */
void fm_factory_modify_volume_units(fmc_unit_volume_t volume_units)
{
    acm_config.unit_volume = volume_units;
    ttl_config.unit_volume = volume_units;
    rate_config.unit_volume = volume_units;
}

/*
 * @brief Función que separa en dígitos el factor K y los guarda en un arreglo
 * global.
 * @param None
 * @retval None
 */
void fm_factory_separate_k_factor()
{
    uint32_t k_num;
    int i = 7;
    k_num = fm_factory_get_k_factor().num;

    while (i >= 0)
    {
        if (k_num > 0)
        {
            k_array[i] = k_num % 10;
            k_num /= 10;
        }
        else
        {
            k_array[i] = 0;
        }
        i--;
    }
}

// Interrupts

/*** end of file ***/
