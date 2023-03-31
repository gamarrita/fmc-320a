/* @file fm_module.c
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

#include "fm_calendar.h"
#include "stdio.h"
#include "stdlib.h"

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
RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;

extern RTC_HandleTypeDef hrtc;

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

void fm_calendar_get()
{
    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
}

int  fm_calendar_format_time()
{
    int time = 0;
    char time_arr[20]; // @suppress("Avoid magic numbers")

    fm_calendar_get();

    sprintf(time_arr,"%02d%02d%02d",sTime.Hours, sTime.Minutes, sTime.Seconds);

    /*
     * Esta instrucción está de mas ya que después se vuelve a formatear el
     * entero en un arreglo, pero por ahora se va a quedar así hasta que se
     * elimine el formatter de la libreria fm_lcd.h
     */
    time = atoi(time_arr);

    return (time);
}

int  fm_calendar_format_date()
{
    int date = 0;
    char date_arr[20]; // @suppress("Avoid magic numbers")

    fm_calendar_get();

    sprintf(date_arr,"%02d%02d20%02d",sDate.Date, sDate.Month, sDate.Year);

    /*
     * Esta instrucción está de mas ya que después se vuelve a formatear el
     * entero en un arreglo, pero por ahora se va a quedar así hasta que se
     * elimine el formatter de la libreria fm_lcd.h
     */
    date = atoi(date_arr);


    return (date);
}

// Interrupts

/*** end of file ***/
