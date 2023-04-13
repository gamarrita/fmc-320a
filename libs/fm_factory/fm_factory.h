/* @file fm_factory.h
 *
 * @brief A description of the module’s purpose.
 *
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 */

#ifndef     FM_FACTORY_H_
#define     FM_FACTORY_H_

// includes
#include "main.h"
#include "../fmc/fmc.h"

// Macros, defines, microcontroller pins (dhs).

// Typedef.

// Defines.

// Function prototypes

fmc_totalizer_t fm_factory_get_acm();
fmc_totalizer_t fm_factory_get_ttl();
fmc_totalizer_t fm_factory_get_rate();
fmc_temp_t fm_factory_get_temp();
fmc_fp_t fm_factory_get_units_digits();
fmc_fp_t fm_factory_get_k_factor();

#endif /* FM_FACTORY_H */

/*** end of file ***/
