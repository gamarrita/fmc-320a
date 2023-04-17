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

typedef enum
{
    RES_0, RES_1, RES_2, RES_3
} sel_resolution_t;

typedef enum
{
    DIG_0, DIG_1, DIG_2, DIG_3, DIG_4, DIG_5, DIG_6, DIG_7
} sel_digit_t;

typedef enum
{
    VAL_0, VAL_1, VAL_2, VAL_3, VAL_4, VAL_5, VAL_6, VAL_7, VAL_8, VAL_9
} sel_value_t;

// Defines.

// Function prototypes

fmc_totalizer_t fm_factory_get_acm();
fmc_totalizer_t fm_factory_get_ttl();
fmc_totalizer_t fm_factory_get_rate();
fmc_temp_t fm_factory_get_temp();
fmc_fp_t fm_factory_get_units_tim();
fmc_fp_t fm_factory_get_units_vol();
fmc_fp_t fm_factory_get_k_factor();
void fm_factory_modify_k_factor_add(sel_digit_t digit_k);
void fm_factory_modify_k_factor_subs(sel_digit_t digit_k);
void fm_factory_modify_res_acm_ttl(sel_resolution_t units_res,
sel_resolution_t acm_res, sel_resolution_t ttl_res);
void fm_factory_modify_res_rate(sel_resolution_t units_res,
sel_resolution_t rate_res);
void fm_factory_modify_time_units(fmc_unit_time_t time_units);
void fm_factory_modify_volume_units(fmc_unit_volume_t volume_units);
void fm_factory_separate_k_factor();

#endif /* FM_FACTORY_H */

/*** end of file ***/
