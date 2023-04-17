/* @file fm_lcd.c
 *
 * @brief Este es el modulo que posee la inteligencia para manejar las opciones
 * que brinda la pantalla LCD, utilizando las funciones implementadas de
 * impresión de caracteres individuales en lcd.h.
 * Las funciones de este modulo serán usadas por librerías de mas alto nivel que
 * impriman menús o controlen máquinas de estado de pantallas, tales como
 * fm_menu_user.h.
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

// Includes.
#include "fm_lcd.h"
#include "../fm_factory/fm_factory.h"
#include "../fm_calendar/fm_calendar.h"
#include "../fm_temp_stm32/fm_temp_stm32.h"
#include "../fm_version/fm_version.h"
#include "../fmc/fmc.h"

// Typedef.

// Const data.

// Defines.
#define MSG_LENGTH    12
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
 * @brief Función que setea una serie de símbolos, puntos y dígitos en la
 * pantalla LCD, permitiendo mostrar el caudal acumulado y el rate, de forma
 * personalizada según las opciones que se elijan.
 * @param puntos de la fila superior e inferior a imprimir, de tipo point_t, y
 * unidades a utilizar en la medición de tipo symbols_t.
 * @retval None
 */
void fm_lcd_acm_rate()
{
    char lcd_msg[PCF8553_DATA_SIZE];

    fm_lcd_fp_to_str(fmc_get_acm().volume, ' ', LINE_0_DIGITS, lcd_msg,
    sizeof(lcd_msg));
    fm_lcd_fp_add_dot(fmc_get_acm().volume, lcd_msg, sizeof(lcd_msg));
    fm_lcd_puts(lcd_msg, HIGH_ROW);

    fm_lcd_fp_to_str(fmc_get_rate().volume, ' ', LINE_1_DIGITS, lcd_msg,
    sizeof(lcd_msg));
    fm_lcd_fp_add_dot(fmc_get_rate().volume, lcd_msg, sizeof(lcd_msg));
    fm_lcd_puts(lcd_msg, LOW_ROW);

    lcd_set_symbol(ACM, 0x0);
    lcd_set_symbol(RATE, 0x0);

    lcd_set_vol_unit(fmc_get_acm().unit_volume, 0x0);
    lcd_set_symbol(BACKSLASH, 0x0);
    lcd_set_time_unit(fmc_get_acm().unit_time, 0x0);
}

/*
 * @brief Función que setea una serie de símbolos, puntos y dígitos en la
 * pantalla LCD, permitiendo mostrar la temperatura del líquido y la exterior,
 * de forma personalizada según las opciones que se elijan.
 * @param Puntos de la fila superior e inferior a imprimir, de tipo point_t.
 * @retval None
 */
void fm_lcd_acm_temp()
{
    char lcd_msg[PCF8553_DATA_SIZE];

    fm_lcd_fp_to_str(fmc_get_acm().volume, ' ', LINE_0_DIGITS, lcd_msg,
    sizeof(lcd_msg));
    fm_lcd_fp_add_dot(fmc_get_acm().volume, lcd_msg, sizeof(lcd_msg));
    fm_lcd_puts(lcd_msg, HIGH_ROW);

    fm_lcd_fp_to_str(fmc_get_stm32_temp().temperature, ' ', LINE_1_DIGITS,
    lcd_msg, sizeof(lcd_msg));
    fm_lcd_fp_add_dot(fmc_get_stm32_temp().temperature, lcd_msg,
    sizeof(lcd_msg));
    fm_lcd_puts(lcd_msg, LOW_ROW);

    lcd_set_symbol(ACM, 0x0);
    lcd_set_vol_unit(fmc_get_stm32_temp().unit_volume_temp, 0x0);
}

/*
 * @brief Función que permite setear el símbolo de bateria baja del
 * dispositivo, el cual puede configurarse con la pantalla parpadeando a una
 * velocidad especificada.
 * @param Velocidad de parpadeo de la pantalla de tipo blink_t definido en
 * lcd.h.
 * @retval None
 */
void fm_lcd_battery_low(blink_t speed)
{
    lcd_set_symbol(BATTERY, speed);
}

/*
 * @brief Función que limpia toda la pantalla.
 * @param  None
 * @retval None
 */
void fm_lcd_clear()
{
    lcd_clear_all();
}

/*
 * @brief Función que setea una serie de símbolos, puntos y dígitos en la
 * pantalla LCD, permitiendo mostrar la fecha y hora actual, de forma
 * personalizada según las opciones que se elijan.
 * @param Puntos de la fila superior e inferior a imprimir, de tipo point_t.
 * @retval None
 */
void fm_lcd_date_hour(int time, int date)
{
    char lcd_msg[MSG_LENGTH];

    fm_lcd_format_number_in_line(HIGH_ROW, date, lcd_msg,
    MSG_LENGTH);
    fm_lcd_puts(lcd_msg, HIGH_ROW);
    lcd_set_point(HIGH_ROW, PNT_1);
    lcd_set_point(HIGH_ROW, PNT_3);

    fm_lcd_format_number_in_line(LOW_ROW, time, lcd_msg,
    MSG_LENGTH);
    fm_lcd_puts(lcd_msg, LOW_ROW);
    lcd_set_point(LOW_ROW, PNT_2);
    lcd_set_point(LOW_ROW, PNT_4);
}

/*
 * @brief Función que formatea información pasada como parámetro para ser
 * colocada en una de las dos filas de la pantalla LCD.
 * @param Enumeracion rows_t de lcd.h
 * @retval arreglo con la información formateada tipo char.
 */
void fm_lcd_format_number_in_line(rows_t line, uint32_t data, char *p_str,
int length)
{
    if (line == HIGH_ROW)
    {
        snprintf(p_str, length, "%8lu", data);
    }
    else if (line == LOW_ROW)
    {
        snprintf(p_str, length, "%7lu", data);
    }
}

/*
 * Agrega el punto decimal a una string que representa un entero.
 * Esta funcion es típicamente usada luego de  fm_lcd_u32_to_str();
 *
 * @param fp numero con punto decimal
 * @param p_str puntero al string destino
 * @param str_size tamaño del string
 *
 */
int fm_lcd_fp_add_dot(fmc_fp_t fp, char *p_str, int str_size)
{
    int idx_end;
    int idx_now;

    /*
     * Si la resolución asignada por el usuario es 0, no hay nada que hacer.
     */
    if (fp.res == 0)
    {
        return (0);
    }

    idx_now = strlen(p_str); //Como indice apunta a terminador nulo.

    /*
     * Chequeo de contorno para ver si entra el punto o no.
     */

    if ((idx_now + 1 + 1) >= str_size)
    {
        return (-1);
    }

    idx_end = idx_now - fp.res; //Como índice apunta a donde debe ir el '.'

    /*
     * Desplazo posiciones en el arreglo hasta llegar a la posición donde debe
     * ir ubicado el '.'
     */
    while (idx_now != idx_end)
    {
        p_str[idx_now + 1] = p_str[idx_now];
        idx_now--;
    }
    p_str[idx_now + 1] = p_str[idx_now];
    p_str[idx_now] = '.';

    return (0);
}

/*
 * @brief Convierte un numero con punto decimal a una string, pero sin el punto
 *
 * @param fp numero con punto decimal.
 * @param leading_char caracter de relleno, cero para no rellenar.
 * @param al rellenar debemos indicar a que ancho con esta variable.
 * @param p_str string destino, por referencia.
 * @param str_size tamaño del string.
 */
int fm_lcd_fp_to_str(fmc_fp_t fp, char leading_char, int str_width, char *p_str,
int str_size)
{
    int idx_1 = 0;

    /*
     * Este es el unico chequeo de contorno. Verifica que el tamaño del string
     * no sea menor a PCF8553_DATA_SIZE, calculado como suficiente para operar
     * con las líneas del lcd.
     */
    if (str_size < PCF8553_DATA_SIZE)
    {
        return (-1);
    }

    /*
     * Esta linea es necesaria para representa bien a num = 0
     */
    p_str[idx_1] = fp.num % 10 + '0';

    uint32_t num_aux = fp.num;

    /*
     * Almaceno el número de atrás para adelante hasta que llegar al primer
     * dígito inclusive
     */
    while (fp.num / 10)
    {
        idx_1++;
        fp.num /= 10;
        p_str[idx_1] = fp.num % 10 + '0';
    }

    /*
     * Si se midió 0 pulsos, se rellena con 0 hasta pasar el punto y asi se
     * mantiene la resolución deseada.
     */
    if (num_aux == 0)
    {
        while (idx_1 < fp.res)
        {
            idx_1++;
            p_str[idx_1] = fp.num % 10 + '0';
        }
    }

    /*
     * Si el caracter a completar no es 0, se lo debe agregar al final del
     * arreglo hasta completar el largo de la linea (7 u 8 caracteres + \0).
     */
    if (leading_char)
    {
        while (idx_1 < str_width - 1)
        {
            idx_1++;
            p_str[idx_1] = leading_char;
        }
    }
    p_str[idx_1] = '\0';
    idx_1--;

    /*
     *Esta sección da vuelta el arreglo ya que se completó al revés.
     */
    int idx_2 = 0;
    char ch_temp;

    while (idx_1 > idx_2)
    {
        ch_temp = p_str[idx_1];
        p_str[idx_1] = p_str[idx_2];
        p_str[idx_2] = ch_temp;
        idx_1--;
        idx_2++;
    }

    return (0);
}

/*
 * @brief Es la primera instrucción a llamar para usar el lcd, luego de
 * inicializar el lcd enciende todos los segmentos.
 * Para comprobar que el lcd esta funcionando se encienden todos los
 * segmentos por unos segundos y luego se lo apaga.
 * @param  None
 * @retval None
 */
void fm_lcd_init()
{
    lcd_clear_all();
    lcd_init();

    /*
     * Se encienden todos los segmentos por 500 milisegundos al iniciar.
     */
    pcf8553_write_all(0xFF); // @suppress("Avoid magic numbers")
    HAL_Delay(3000); // @suppress("Avoid magic numbers")
    pcf8553_write_all(0x00); // @suppress("Avoid magic numbers")
}

/*
 * @brief Función que permite escribir lo necesario para la pantalla de
 * configuración del factor de calibración K.
 * @param  Unidad de volumen y unidad de tiempo.
 * @retval None
 */
void fm_lcd_k_factor()
{
    char lcd_msg[PCF8553_DATA_SIZE];

    fm_lcd_fp_to_str(fm_factory_get_k_factor(), '0', LINE_0_DIGITS, lcd_msg,
    sizeof(lcd_msg));
    fm_lcd_fp_add_dot(fm_factory_get_k_factor(), lcd_msg, sizeof(lcd_msg));
    fm_lcd_puts(lcd_msg, HIGH_ROW);

    lcd_set_vol_unit(fmc_get_acm().unit_volume, 0x0);
}

/*
 * @brief Función que imprime en una de las dos filas del lcd, row 0 o row 1.
 * @param
 * @retval None
 */
void fm_lcd_puts(const char *c, const rows_t row)
{
    uint8_t col = 0;
    uint8_t col_limit;

    if (row == 0)
    {
        col_limit = LINE_0_DIGITS - 1;
    }
    else
    {
        col_limit = LINE_1_DIGITS - 1;
    }

    while ((*c) && (col < col_limit))
    {
        if (((*c >= '0') && (*c <= '9')) || (*c == ' ') || (*c == '.'))
        {
            lcd_put_char(*c, col, row);
        }
        col++;
        c++;
        if (*c == '.')
        {
            col--;
        }
    }
}

/*
 * @brief Función que permite actualizar la pantalla llamando a una función de
 * la librería de mas bajo nivel 'lcd.h'.
 * @param  None
 * @retval None
 */
void fm_lcd_refresh()
{
    lcd_refresh();
}

/*
 * @brief Función que setea una serie de símbolos, puntos y dígitos en la
 * pantalla LCD, permitiendo mostrar el caudal total y el rate, de forma
 * personalizada según las opciones que se elijan.
 * @param puntos de la fila superior e inferior a imprimir, de tipo point_t, y
 * unidades a utilizar en la medición de tipo symbols_t.
 * @retval None
 */
void fm_lcd_ttl_rate()
{
    char lcd_msg[PCF8553_DATA_SIZE];

    fm_lcd_fp_to_str(fmc_get_ttl().volume, ' ', LINE_0_DIGITS, lcd_msg,
    sizeof(lcd_msg));
    fm_lcd_fp_add_dot(fmc_get_ttl().volume, lcd_msg, sizeof(lcd_msg));
    fm_lcd_puts(lcd_msg, HIGH_ROW);

    fm_lcd_fp_to_str(fmc_get_rate().volume, ' ', LINE_1_DIGITS, lcd_msg,
    sizeof(lcd_msg));
    fm_lcd_fp_add_dot(fmc_get_rate().volume, lcd_msg, sizeof(lcd_msg));
    fm_lcd_puts(lcd_msg, LOW_ROW);

    lcd_set_symbol(TTL, 0x0);
    lcd_set_symbol(RATE, 0x0);

    lcd_set_vol_unit(fmc_get_ttl().unit_volume, 0x0);
    lcd_set_symbol(BACKSLASH, 0x0);
    lcd_set_time_unit(fmc_get_ttl().unit_time, 0x0);
}

/*
 * @brief Función que permite escribir lo necesario para la pantalla de
 * configuración de unidades de volumen y tiempo y la resolución de la medida.
 * @param  Unidad de volumen y unidad de tiempo.
 * @retval None
 */
void fm_lcd_units()
{
    char lcd_msg[PCF8553_DATA_SIZE];

    fm_lcd_fp_to_str(fm_factory_get_units_digits(), '0', LINE_0_DIGITS, lcd_msg,
    sizeof(lcd_msg));
    fm_lcd_fp_add_dot(fm_factory_get_units_digits(), lcd_msg, sizeof(lcd_msg));
    fm_lcd_puts(lcd_msg, HIGH_ROW);

    lcd_set_vol_unit(fmc_get_acm().unit_volume, 0x0);
    lcd_set_symbol(BACKSLASH, 0x0);
    lcd_set_time_unit(fmc_get_acm().unit_time, 0x0);
}

/*
 * @brief Función que setea una serie de símbolos y puntos en la pantalla
 * LCD, permitiendo mostrar la versión del caudalímetro, de forma personalizada
 * según las opciones que se elijan.
 * @param puntos de la fila inferior a imprimir, de tipo point_t.
 * @retval None
 */
void fm_lcd_version(point_t low_point1, point_t low_point2)
{
    char lcd_msg[MSG_LENGTH];

    fm_lcd_format_number_in_line(LOW_ROW, fm_version_get(), lcd_msg,
    MSG_LENGTH);
    fm_lcd_puts(lcd_msg, LOW_ROW);
    lcd_set_point(LOW_ROW, low_point1);
    lcd_set_point(LOW_ROW, low_point2);

    lcd_set_symbol(VE, 0x0);
}

// Interrupts

/*** end of file ***/
