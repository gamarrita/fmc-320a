/* @file fm_debug.c
 *
 * @brief Este modulo envía mensajes al UART o consola ITM
 *
 * Las funciones que terminan con _itm los mensajes de envian a la consola
 * de debugger, para poder ver los mensajes se tienen que configurar:
 *
 * En Cube MX:
 * - Sys->Debug->Trace Asynchronous Sw
 * - En Clock configuration puede elegir cualquier frecuencia para HCLK, pero
 * deberá recordarla.
 *
 * En Debug Configuration:
 * Debugger->Serial Wire Viewer SVW->Enable(marcar).
 * Clock Core (Mhz)- El valor que debía recordar, HCLK en Clock Configuration.
 *
 * Iniciada la sesión de debug: en la parte inferior deberia aparecer la
 * solapa ITM console, si no aparece se la busca y se la agrega, dos pasos
 * necesarias, habilitar el port_0 y click el boton rojo para iniciar "trace".
 *
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 *
 */

// Includes.
#include "fm_debug.h"

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
/*
 * Default minimo 1 mili-segundos,  por defecto 50 mili-segundos, para todo
 * otro delay hay que justificar.
 *
 */
#define DELAY_MIN       1
#define DELAY_DEFAULT   10

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

// Extern variables.

extern UART_HandleTypeDef huart2;

// Global variables, statics.

// Private function prototypes.

// Public function bodies.

/*
 * @brief Función que envía un número de 8 bits por el puerto UART.
 * @param Número a imprimir.
 * @retval None
 */
void fm_debug_uint8_uart(uint8_t num)
{
    char str[5]; // @suppress("Avoid magic numbers")
    snprintf(str, sizeof(str), "%u\n", num);
    fm_debug_msg_uart((uint8_t*) str, strlen(str));
}

/*
 * @brief Función que envía un número de 32 bits por el puerto UART.
 * @param Número a imprimir.
 * @retval None
 */
void fm_debug_uint32_uart(uint32_t num)
{
    char str[12]; // @suppress("Avoid magic numbers")
    snprintf(str, sizeof(str), "%lu\n", num);
    fm_debug_msg_uart((uint8_t*) str, strlen(str));
}

/*
 * @brief Esta funcion envía mensajes de debug, se puede ver al momento de
 * debugger. Se tienen que llevar ajuste en tres etapas diferentes:
 *
 * Al configurar con cubemx:
 * - Sys->Debug->Trace Asynchronous Sw
 * - En Clock configuration puede elegir cualquier frecuencia para HCLK, pero
 * deberá recordarla.
 *
 * En Debug Configuration:
 * Debugger->Serial Wire Viewer SVW->Enable(marcar).
 * Clock Core (MHz)- El valor que debía recordar, HCLK en Clock Configuration.
 *
 * Iniciada la sesión de debug: en la parte inferior debería aparecer la
 * solapa ITM console, si no aparece se la busca y se la agrega, dos pasos
 * necesarias, habilitar el port_0 y click el boton rojo para iniciar "trace".
 *
 */
void fm_debug_msg_itm(const uint8_t *msg, uint8_t len)
{
    while (*msg && len)
    {
        ITM_SendChar((uint32_t) *msg);
        len--;
        msg++;
    }
}

/*
 * @brief Esta funcion envía mensajes de debug por el uart2, la variable huart2,
 * el handler del periferico, se declara como extern. Notar que si el proyecto
 * que estamos usando no inicializo el uart2 fallara en la compilacion, hay que
 * agregar condicionales de pre-compilacion para contemplar el caso donde no
 * se use el uart2.
 * @param Mensaje a transmitir y su longitud.
 * @retval None
 *
 */
void fm_debug_msg_uart(const uint8_t *p_msg, uint8_t len)
{
    HAL_StatusTypeDef ret = HAL_BUSY;

    /*
     * La funcion HAL_UART_Transmit retornará sin hacer nada si esta siendo
     * ejecutada en otro hilo. La siguiente implementación no es buena porque
     * bloquea puede bloquear al sistema, una mejor solucion seria bloquear
     * por un corto tiempo, aun mejor seria implementar algo con RTOS.
     *
     */
    while (ret == HAL_BUSY)
    {
        ret = HAL_UART_Transmit(&huart2, p_msg, len, DELAY_DEFAULT);
    }

}

// Private function bodies.

/*** end of file ***/
