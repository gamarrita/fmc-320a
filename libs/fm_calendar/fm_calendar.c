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
 * @brief Toma los valores de fecha y hora del calendario del RTC, pero no los
 * usa.
 * @param None
 * @retval None
 */
void fm_calendar_get()
{
    __HAL_RTC_WRITEPROTECTION_DISABLE(&hrtc);
    HAL_RTC_WaitForSynchro(&hrtc);
    __HAL_RTC_WRITEPROTECTION_ENABLE(&hrtc);

    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
}

int fm_calendar_get_hour()
{
    fm_calendar_get();
    return (sTime.Hours);
}
int fm_calendar_get_minute()
{
    fm_calendar_get();
    return (sTime.Minutes);
}
int fm_calendar_get_second()
{
    fm_calendar_get();
    return (sTime.Seconds);
}
int fm_calendar_get_day()
{
    fm_calendar_get();
    return (sDate.Date);
}
int fm_calendar_get_month()
{
    fm_calendar_get();
    return (sDate.Month);
}
int fm_calendar_get_year()
{
    fm_calendar_get();
    return (sDate.Year);
}

/*
 * @brief Formatea la hora en el formato hh.mm.ss.
 * @param None
 * @retval Entero que contiene la hora, minutos y segundos concatenados.
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
 * @brief Formatea la fecha en el formato dd.mm.aaaa.
 * @param None
 * @retval Entero que contiene el día, el mes y el año concatenados.
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
