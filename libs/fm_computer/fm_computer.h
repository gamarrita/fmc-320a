/* @file fm_computer.h
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
 */

#ifndef FM_COMPUTER_H_
#define FM_COMPUTER_H_

// includes

#include "main.h"
#include "string.h"

// Macros, defines, microcontroller pins (dhs).

// Typedef.

// Defines.

// Function prototypes

uint32_t fm_computer_get_acm();
uint32_t fm_computer_get_date();
uint32_t fm_computer_get_ext_temp();
uint32_t fm_computer_get_hour();
uint32_t fm_computer_get_liq_temp();
uint32_t fm_computer_get_rate();
uint32_t fm_computer_get_ttl();
uint32_t fm_computer_get_version();

#endif /* FM_COMPUTER_H_ */

/*** end of file ***/
