/* @file fm_menu_config.c
 *
 * @brief
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

// Includes.

#include "fm_menu_config.h"
#include "stdio.h"
#include "../fm_event/fm_event.h"
#include "../fm_debug/fm_debug.h"

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

extern osMessageQueueId_t h_event_queue;

// Global variables, statics.

// Private function prototypes.

// Private function bodies.

// Public function bodies.

ptr_ret_menu_t fm_menu_conf_volume_unit(fm_event_t event_id)
{
    static uint8_t new_entry = 1;
    static uint8_t new_exit = 0;

    ptr_ret_menu_t ret_menu = (ptr_ret_menu_t) fm_menu_conf_volume_unit;
    fm_event_t event_now;

    if (new_entry == 1)
    {
        fm_lcd_clear();
        new_entry = 0;
    }

    lcd_set_symbol(BATTERY, 0x00);
    fm_lcd_refresh();

    switch (event_id)
    {
        case EVENT_KEY_UP:
        break;
        case EVENT_KEY_DOWN:
        break;
        case EVENT_KEY_ENTER:
        break;
        case EVENT_KEY_ESC:
            new_exit = 1;
            ret_menu = (ptr_ret_menu_t) fm_menu_conf_time_unit;
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        default:
        break;
    }

#ifdef FM_DEBUG_MENU
        char msg_buffer[] = "Configurar unidad de volumen\n";
        fm_debug_msg_uart((uint8_t *)msg_buffer, sizeof(msg_buffer));
    #endif

    if (new_exit == 1)
    {
        new_entry = 1;
        new_exit = 0;
    }

    return (ret_menu);
}

ptr_ret_menu_t fm_menu_conf_time_unit(fm_event_t event_id)
{
    static uint8_t new_entry = 1;
    static uint8_t new_exit = 0;

    ptr_ret_menu_t ret_menu = (ptr_ret_menu_t) fm_menu_conf_time_unit;
    fm_event_t event_now;

    if (new_entry == 1)
    {
        fm_lcd_clear();
        new_entry = 0;
    }

    lcd_set_symbol(POWER, 0x00);
    fm_lcd_refresh();

    switch (event_id)
    {
        case EVENT_KEY_UP:
        break;
        case EVENT_KEY_DOWN:
        break;
        case EVENT_KEY_ENTER:
        break;
        case EVENT_KEY_ESC:
            new_exit = 1;
            ret_menu = (ptr_ret_menu_t) fm_menu_conf_k_parameter;
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        default:
        break;
    }

#ifdef FM_DEBUG_MENU
        char msg_buffer[] = "Configurar unidad de tiempo\n";
        fm_debug_msg_uart((uint8_t *)msg_buffer, sizeof(msg_buffer));
    #endif

    if (new_exit == 1)
    {
        new_entry = 1;
        new_exit = 0;
    }

    return (ret_menu);
}

ptr_ret_menu_t fm_menu_conf_k_parameter(fm_event_t event_id)
{
    static uint8_t new_entry = 1;
    static uint8_t new_exit = 0;

    ptr_ret_menu_t ret_menu = (ptr_ret_menu_t) fm_menu_conf_k_parameter;
    fm_event_t event_now;

    if (new_entry == 1)
    {
        fm_lcd_clear();
        new_entry = 0;
    }

    lcd_set_symbol(E, 0x00);
    fm_lcd_refresh();

    switch (event_id)
    {
        case EVENT_KEY_UP:
        break;
        case EVENT_KEY_DOWN:
        break;
        case EVENT_KEY_ENTER:
        break;
        case EVENT_KEY_ESC:
            new_exit = 1;
            ret_menu = (ptr_ret_menu_t) fm_menu_show_version;
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        default:
        break;
    }

#ifdef FM_DEBUG_MENU
        char msg_buffer[] = "Configurar parametro K\n";
        fm_debug_msg_uart((uint8_t *)msg_buffer, sizeof(msg_buffer));
    #endif

    if (new_exit == 1)
    {
        new_entry = 1;
        new_exit = 0;
    }

    return (ret_menu);
}

// Interrupts

/*** end of file ***/
