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

typedef enum
{
    UNIT_LITER = 'L',
    UNIT_METER_CUBIC = 'M',
    UNIT_CENTIGRADES = 'C',
    UNIT_VOLUME_END = 0xFF,
} fmc_unit_volume_t;

typedef enum
{
    UNIT_DAY = 'D',
    UNIT_HOUR = 'H',
    UNIT_MINUTE = 'M',
    UNIT_SECOND = 'S',
    UNIT_TIME_END = 0xFF,
} fmc_unit_time_t;

// Typedef.

typedef struct
{
    uint32_t num;
    uint8_t res;
} fmc_fp_t;

typedef struct
{
    uint64_t pulse;
    fmc_fp_t volume;
    fmc_fp_t factor; // Factor en pulsos / unidad de volumen
    fmc_unit_volume_t unit_volume;
} fmc_totalizer_t;

typedef struct
{
    fmc_fp_t temperature;
    fmc_unit_volume_t unit_volume_temp;
} fmc_temp_t;

// Defines.

// Function prototypes

uint32_t fm_computer_get_acm();
uint32_t fm_computer_get_ext_temp();
uint32_t fm_computer_get_rate();
uint32_t fm_computer_get_ttl();
uint32_t fm_computer_get_version();
void fm_computer_totalizer_clear_pulse(fmc_totalizer_t *p_totalizer);
fmc_totalizer_t fm_computer_totalizer_init(fmc_totalizer_t totalizer);
void fm_computer_totalizer_refresh(fmc_totalizer_t *p_totalizer);

#endif /* FM_COMPUTER_H_ */

/*** end of file ***/
