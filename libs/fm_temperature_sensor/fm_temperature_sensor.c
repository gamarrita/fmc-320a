/* @file fm_temperature_sensor.c
 *
 * @brief Each source file shall be comprised of some or all of the following
 * sections, in the order listed down below.
 * Comenzar cada nuevo archivo usando un template. Hay un template general a
 * todos los proyectos que puede ser usado hasta el momento de introducir un
 * cambio que solo responderá a un proyecto en progreso, es ese caso el
 * template pasará a ser parte del proyecto.
 *
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

// Includes.
#include "fm_temperature_sensor.h"

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
extern ADC_HandleTypeDef hadc1;
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

// External variables.

// Global variables, statics.

// Private function prototypes.

// Private function bodies.

// Public function bodies.

void fm_int_temperature_get()
{
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 100);
    HAL_ADC_Stop(&hadc1);
}

int fm_int_temperature_format()
{
    uint16_t raw_value;
    int temp_celcius;

    fm_int_temperature_get();
    raw_value = HAL_ADC_GetValue(&hadc1);
    temp_celcius = __HAL_ADC_CALC_TEMPERATURE(3285, raw_value, ADC_RESOLUTION_12B);

    return(temp_celcius);
}

// Interrupts

/*** end of file ***/

