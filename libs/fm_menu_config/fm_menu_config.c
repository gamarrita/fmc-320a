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
#include "../fm_debug/fm_debug.h"
#include "../fm_calendar/fm_calendar.h"
#include "../fm_factory/fm_factory.h"

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
#define PASSWORD_LENGHT 4
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

int freeze_time;
int freeze_date;
uint8_t correct_password;

// External variables.

extern osMessageQueueId_t h_event_queue;

// Global variables, statics.

// Private function prototypes.

// Private function bodies.

// Public function bodies.

/*
 * @brief Función que imprime el menú de configuración de fecha y hora.
 * @param  Evento de presión de botones o refresh.
 * @retval Puntero al retorno de la función.
 */
ptr_ret_menu_t fm_menu_config_date_hour(fm_event_t event_id)
{
    static uint8_t new_entry = 1;
    static uint8_t new_exit = 0;

    ptr_ret_menu_t ret_menu = (ptr_ret_menu_t) fm_menu_config_date_hour;
    fm_event_t event_now;

    if (new_entry == 1)
    {
        fm_lcd_clear();
        new_entry = 0;
    }

    fm_lcd_date_hour(freeze_time, freeze_date);
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
            ret_menu = (ptr_ret_menu_t) fm_menu_show_init;
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        default:
        break;
    }

#ifdef FM_DEBUG_MENU
    char msg_buffer[] = "Configurar fecha y hora\n";
    fm_debug_msg_uart((uint8_t*) msg_buffer, sizeof(msg_buffer));
#endif

    if (new_exit == 1)
    {
        new_entry = 1;
        new_exit = 0;
    }

    return (ret_menu);
}

/*
 * @brief Función que imprime el menú de configuración de factor de expansión.
 * @param  Evento de presión de botones o refresh.
 * @retval Puntero al retorno de la función.
 */
ptr_ret_menu_t fm_menu_config_expansion(fm_event_t event_id)
{
    static uint8_t new_entry = 1;
    static uint8_t new_exit = 0;

    ptr_ret_menu_t ret_menu = (ptr_ret_menu_t) fm_menu_config_expansion;
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
            ret_menu = (ptr_ret_menu_t) fm_menu_show_version;
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        default:
        break;
    }

#ifdef FM_DEBUG_MENU
    char msg_buffer[] = "Configurar factor de expansion\n";
    fm_debug_msg_uart((uint8_t*) msg_buffer, sizeof(msg_buffer));
#endif

    if (new_exit == 1)
    {
        new_entry = 1;
        new_exit = 0;
    }

    return (ret_menu);
}

/*
 * @brief Función que imprime el menú de configuración del factor de calibración
 * K.
 * @param  Evento de presión de botones o refresh.
 * @retval Puntero al retorno de la función.
 */
ptr_ret_menu_t fm_menu_config_k_param(fm_event_t event_id)
{
    static uint8_t new_entry = 1;
    static uint8_t new_exit = 0;
    static sel_digit_t digit_modify = DIG_0;

    ptr_ret_menu_t ret_menu = (ptr_ret_menu_t) fm_menu_config_k_param;
    fm_event_t event_now;

    if (new_entry == 1)
    {
        fm_lcd_clear();
        new_entry = 0;
    }

    fm_lcd_k_factor();
    fm_lcd_refresh();

    switch (event_id)
    {
        case EVENT_KEY_UP:
            if (correct_password)
            {
                fm_factory_modify_k_factor_add(digit_modify);
            }
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        case EVENT_KEY_DOWN:
            if (correct_password)
            {
                fm_factory_modify_k_factor_subs(digit_modify);
            }
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        case EVENT_KEY_ENTER:
            if (correct_password)
            {
                if (digit_modify == DIG_0)
                {
                    digit_modify = DIG_1;
                }
                else if (digit_modify == DIG_1)
                {
                    digit_modify = DIG_2;
                }
                else if (digit_modify == DIG_2)
                {
                    digit_modify = DIG_3;
                }
                else if (digit_modify == DIG_3)
                {
                    digit_modify = DIG_4;
                }
                else if (digit_modify == DIG_4)
                {
                    digit_modify = DIG_5;
                }
                else if (digit_modify == DIG_5)
                {
                    digit_modify = DIG_6;
                }
                else if (digit_modify == DIG_6)
                {
                    digit_modify = DIG_7;
                }
                else if (digit_modify == DIG_7)
                {
                    digit_modify = DIG_0;
                }
            }
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        case EVENT_KEY_ESC:
            new_exit = 1;
            ret_menu = (ptr_ret_menu_t) fm_menu_config_units_vol;
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        default:
        break;
    }

#ifdef FM_DEBUG_MENU
    char msg_buffer[] = "Configurar parametro K\n";
    fm_debug_msg_uart((uint8_t*) msg_buffer, sizeof(msg_buffer));
#endif

    if (new_exit == 1)
    {
        new_entry = 1;
        new_exit = 0;
    }

    return (ret_menu);
}

/*
 * @brief Función que imprime el menú de configuración del factor de calibración
 * Ko.
 * @param  Evento de presión de botones o refresh.
 * @retval Puntero al retorno de la función.
 */
ptr_ret_menu_t fm_menu_config_ko_param(fm_event_t event_id)
{
    static uint8_t new_entry = 1;
    static uint8_t new_exit = 0;

    ptr_ret_menu_t ret_menu = (ptr_ret_menu_t) fm_menu_config_ko_param;
    fm_event_t event_now;

    if (new_entry == 1)
    {
        fm_lcd_clear();
        new_entry = 0;
    }

    lcd_set_symbol(KO, 0x00);
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
            ret_menu = (ptr_ret_menu_t) fm_menu_config_units_vol;
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        default:
        break;
    }

#ifdef FM_DEBUG_MENU
    char msg_buffer[] = "Configurar parametro Ko\n";
    fm_debug_msg_uart((uint8_t*) msg_buffer, sizeof(msg_buffer));
#endif

    if (new_exit == 1)
    {
        new_entry = 1;
        new_exit = 0;
    }

    return (ret_menu);
}

/*
 * @brief Función que imprime el menú que permite introducir la contraseña del
 * caudalímetro. Posee un algoritmo que levanta una flag si la contraseña,
 * compuesta por las 4 teclas del teclado mecánico, es la misma que la
 * almacenada en memoria (DOWN -> UP -> UP -> ENTER).
 * @param  Evento de presión de botones o refresh.
 * @retval Puntero al retorno de la función.
 */
ptr_ret_menu_t fm_menu_config_pass(fm_event_t event_id)
{
    static uint8_t new_entry = 1;
    static uint8_t new_exit = 0;

    /*
     * Arreglo estático que almacena la contraseña que ingresa el usuario.
     * Inicialmente está relleno con ceros.
     */
    static uint8_t password[PASSWORD_LENGHT] =
    {
        0,
        0,
        0,
        0
    };
    static uint8_t password_index = 0;

    ptr_ret_menu_t ret_menu = (ptr_ret_menu_t) fm_menu_config_pass;
    fm_event_t event_now;

    if (new_entry == 1)
    {
        correct_password = 0;
        fm_lcd_clear();
        new_entry = 0;
    }

    lcd_set_symbol(PASS, 0x00);

    /*
     * Cada vez que se introduce un dígito de la contraseña, aparece un 8 nuevo
     * en la pantalla, hasta 3 veces (luego de la cuarta vez, se pasa al menú
     * de configuración del factor K).
     */
    if (password_index == 1)
    {
        lcd_set_symbol(PASS1, 0x00);
    }
    else if (password_index == 2)
    {
        lcd_set_symbol(PASS2, 0x00);
    }
    else if (password_index == 3)
    {
        lcd_set_symbol(PASS3, 0x00);
    }
    fm_lcd_refresh();

    switch (event_id)
    {
        case EVENT_KEY_UP:
            password[password_index] = 1;

            if (password_index < 3)
            {
                event_now = EVENT_LCD_REFRESH;
                osMessageQueuePut(h_event_queue, &event_now, 0, 0);
                password_index++;
            }
            else
            {
                new_exit = 1;
                ret_menu = (ptr_ret_menu_t) fm_menu_config_k_param;
                event_now = EVENT_LCD_REFRESH;
                osMessageQueuePut(h_event_queue, &event_now, 0, 0);

                freeze_date = fm_calendar_format_date();
                freeze_time = fm_calendar_format_time();
            }
        break;
        case EVENT_KEY_DOWN:
            password[password_index] = 2;

            if (password_index < 3)
            {
                event_now = EVENT_LCD_REFRESH;
                osMessageQueuePut(h_event_queue, &event_now, 0, 0);
                password_index++;
            }
            else
            {
                new_exit = 1;
                ret_menu = (ptr_ret_menu_t) fm_menu_config_k_param;
                event_now = EVENT_LCD_REFRESH;
                osMessageQueuePut(h_event_queue, &event_now, 0, 0);

                freeze_date = fm_calendar_format_date();
                freeze_time = fm_calendar_format_time();
            }
        break;
        case EVENT_KEY_ENTER:
            password[password_index] = 3; // @suppress("Avoid magic numbers")

            if (password_index < 3)
            {
                event_now = EVENT_LCD_REFRESH;
                osMessageQueuePut(h_event_queue, &event_now, 0, 0);
                password_index++;
            }
            else
            {
                new_exit = 1;
                ret_menu = (ptr_ret_menu_t) fm_menu_config_k_param;
                event_now = EVENT_LCD_REFRESH;
                osMessageQueuePut(h_event_queue, &event_now, 0, 0);

                freeze_date = fm_calendar_format_date();
                freeze_time = fm_calendar_format_time();
            }
        break;
        case EVENT_KEY_ESC:
            password[password_index] = 4; // @suppress("Avoid magic numbers")

            if (password_index < 3)
            {
                event_now = EVENT_LCD_REFRESH;
                osMessageQueuePut(h_event_queue, &event_now, 0, 0);
                password_index++;
            }
            else
            {
                new_exit = 1;
                ret_menu = (ptr_ret_menu_t) fm_menu_config_k_param;
                event_now = EVENT_LCD_REFRESH;
                osMessageQueuePut(h_event_queue, &event_now, 0, 0);

                freeze_date = fm_calendar_format_date();
                freeze_time = fm_calendar_format_time();
            }
        break;
        default:
        break;
    }

#ifdef FM_DEBUG_MENU
    char msg_buffer[] = "Password\n";
    fm_debug_msg_uart((uint8_t*) msg_buffer, sizeof(msg_buffer));
#endif

    if (new_exit == 1 && password_index >= 3)
    {
        /*
         * Si la contraseña ingresada es correcta, se activa una flag global que
         * permite modificar los parámetros de los menús de configuración.
         */
        if (password[0] == 2 && password[1] == 1 && password[2] == 1
        && password[3] == 3)
        {
            correct_password = 1;
        }

        /*
         * Reinicio el arreglo de la contraseña ingresada.
         */
        password_index = 0;
        password[0] = 0;
        password[1] = 0;
        password[2] = 0;
        password[3] = 0;
        new_entry = 1;
        new_exit = 0;
    }

    return (ret_menu);
}

/*
 * @brief Función que imprime el menú de configuración del factor de Span.
 * @param  Evento de presión de botones o refresh.
 * @retval Puntero al retorno de la función.
 */
ptr_ret_menu_t fm_menu_config_span(fm_event_t event_id)
{
    static uint8_t new_entry = 1;
    static uint8_t new_exit = 0;

    ptr_ret_menu_t ret_menu = (ptr_ret_menu_t) fm_menu_config_span;
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
            ret_menu = (ptr_ret_menu_t) fm_menu_config_expansion;
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        default:
        break;
    }

#ifdef FM_DEBUG_MENU
    char msg_buffer[] = "Configurar Span\n";
    fm_debug_msg_uart((uint8_t*) msg_buffer, sizeof(msg_buffer));
#endif

    if (new_exit == 1)
    {
        new_entry = 1;
        new_exit = 0;
    }

    return (ret_menu);
}

/*
 * @brief Función que imprime el menú de configuración tanto de las unidades de
 * volumen y tiempo, como de la resolución de las medidas.
 * @param  Evento de presión de botones o refresh.
 * @retval Puntero al retorno de la función.
 */
ptr_ret_menu_t fm_menu_config_units_tim(fm_event_t event_id)
{
    static uint8_t new_entry = 1;
    static uint8_t new_exit = 0;

    ptr_ret_menu_t ret_menu = (ptr_ret_menu_t) fm_menu_config_units_tim;
    fm_event_t event_now;

    if (new_entry == 1)
    {
        fm_lcd_clear();
        new_entry = 0;
    }

    fm_lcd_units_tim();
    fm_lcd_refresh();

    switch (event_id)
    {
        case EVENT_KEY_UP:
            if (correct_password)
            {
                if (fm_factory_get_rate().unit_time == H)
                {
                    fm_factory_modify_time_units(D);
                }
                else if (fm_factory_get_rate().unit_time == D)
                {
                    fm_factory_modify_time_units(S);
                }
                else if (fm_factory_get_rate().unit_time == S)
                {
                    fm_factory_modify_time_units(M);
                }
                else if (fm_factory_get_rate().unit_time == M)
                {
                    fm_factory_modify_time_units(H);
                }
                fm_lcd_clear();
            }
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        case EVENT_KEY_DOWN:
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        case EVENT_KEY_ENTER:
            if (correct_password)
            {
                if (fm_factory_get_units_tim().res == RES_0)
                {
                    fm_factory_modify_res_rate(RES_1, RES_1);
                }
                else if (fm_factory_get_units_tim().res == RES_1)
                {
                    fm_factory_modify_res_rate(RES_2, RES_2);
                }
                else if (fm_factory_get_units_tim().res == RES_2)
                {
                    fm_factory_modify_res_rate(RES_3, RES_3);
                }
                else if (fm_factory_get_units_tim().res == RES_3)
                {
                    fm_factory_modify_res_rate(RES_0, RES_0);
                }
            }
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        case EVENT_KEY_ESC:
            new_exit = 1;
            ret_menu = (ptr_ret_menu_t) fm_menu_config_date_hour;
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        default:
        break;
    }

#ifdef FM_DEBUG_MENU
    char msg_buffer[] = "Configurar unidades de tiempo y resolucion\n";
    fm_debug_msg_uart((uint8_t*) msg_buffer, sizeof(msg_buffer));
#endif

    if (new_exit == 1)
    {
        new_entry = 1;
        new_exit = 0;
    }

    return (ret_menu);
}

/*
 * @brief Función que imprime el menú de configuración tanto de las unidades de
 * volumen y tiempo, como de la resolución de las medidas.
 * @param  Evento de presión de botones o refresh.
 * @retval Puntero al retorno de la función.
 */
ptr_ret_menu_t fm_menu_config_units_vol(fm_event_t event_id)
{
    static uint8_t new_entry = 1;
    static uint8_t new_exit = 0;

    ptr_ret_menu_t ret_menu = (ptr_ret_menu_t) fm_menu_config_units_vol;
    fm_event_t event_now;

    if (new_entry == 1)
    {
        fm_lcd_clear();
        new_entry = 0;
    }

    fm_lcd_units_vol();
    fm_lcd_refresh();

    switch (event_id)
    {
        case EVENT_KEY_UP:
            if (correct_password)
            {
                if (fm_factory_get_acm().unit_volume == LT)
                {
                    fm_factory_modify_volume_units(M3);
                }
                else if (fm_factory_get_acm().unit_volume == M3)
                {
                    fm_factory_modify_volume_units(KG);
                }
                else if (fm_factory_get_acm().unit_volume == KG)
                {
                    fm_factory_modify_volume_units(GL);
                }
                else if (fm_factory_get_acm().unit_volume == GL)
                {
                    fm_factory_modify_volume_units(BR);
                }
                else if (fm_factory_get_acm().unit_volume == BR)
                {
                    fm_factory_modify_volume_units(NOTHING);
                }
                else if (fm_factory_get_acm().unit_volume == NOTHING)
                {
                    fm_factory_modify_volume_units(LT);
                }
                fm_lcd_clear();
            }
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        case EVENT_KEY_DOWN:
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        case EVENT_KEY_ENTER:
            if (correct_password)
            {
                if (fm_factory_get_units_vol().res == RES_0)
                {
                    fm_factory_modify_res_acm_ttl(RES_1, RES_1, RES_1);
                }
                else if (fm_factory_get_units_vol().res == RES_1)
                {
                    fm_factory_modify_res_acm_ttl(RES_2, RES_2, RES_2);
                }
                else if (fm_factory_get_units_vol().res == RES_2)
                {
                    fm_factory_modify_res_acm_ttl(RES_3, RES_3, RES_3);
                }
                else if (fm_factory_get_units_vol().res == RES_3)
                {
                    fm_factory_modify_res_acm_ttl(RES_0, RES_0, RES_0);
                }
            }
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        case EVENT_KEY_ESC:
            new_exit = 1;
            ret_menu = (ptr_ret_menu_t) fm_menu_config_units_tim;
            event_now = EVENT_LCD_REFRESH;
            osMessageQueuePut(h_event_queue, &event_now, 0, 0);
        break;
        default:
        break;
    }

#ifdef FM_DEBUG_MENU
    char msg_buffer[] = "Configurar unidades de volumen y resolucion\n";
    fm_debug_msg_uart((uint8_t*) msg_buffer, sizeof(msg_buffer));
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
