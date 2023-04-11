/* @file fm_calendar.c
 *
 * Este modulo se encarga de recibir los datos de la fecha y hora actuales,
 * provenientes del periférico RTC, y de formatearlos para que puedan ser
 * correctamente impresos en la pantalla LCD.
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

// Includes.
#include "fm_calendar.h"
#include "stdio.h"
#include "stdlib.h"
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
RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;

extern RTC_HandleTypeDef hrtc;

// Defines.

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
 * Toma los valores de fecha y hora del calendario del RTC, pero no los usa.
 */
void fm_calendar_get()
{
    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
}

/*
 * Le da formato a la hora, minutos y segundos para que puedan ser impresos en
 * el lcd. Para esto, se los concatena en una variable entera con atoi.
 */
int fm_calendar_format_time()
{
    int time = 0;
    char time_arr[PCF8553_DATA_SIZE];

    fm_calendar_get();

    sprintf(time_arr, "%02d%02d%02d", sTime.Hours, sTime.Minutes,
    sTime.Seconds);

    /*
     * Esta instrucción está de mas ya que después se vuelve a formatear el
     * entero en un arreglo, pero por ahora se va a quedar así hasta que se
     * elimine el formatter de la libreria fm_lcd.h
     */
    time = atoi(time_arr);

    return (time);
}

/*
 * Le da formato al día, mes y año para que puedan ser impresos en
 * el lcd. Para esto, se los concatena en una variable entera con atoi. Se
 * añade un '20' en frente al año para que se escriba la fecha total en formato
 * dd.mm.aaaa.
 */
int fm_calendar_format_date()
{
    int date = 0;
    char date_arr[PCF8553_DATA_SIZE];

    fm_calendar_get();

    sprintf(date_arr, "%02d%02d20%02d", sDate.Date, sDate.Month, sDate.Year);

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
