/* @file fm_module.h
 *
 * @brief A description of the module’s purpose.
 *
 * @par
 * 
 * COPYRIGHT NOTE: (c) 2023 FLOWMEET. All right reserved.
 */

// includes


#ifndef FM_MENU_H_
#define FM_MENU_H_

// Macros, defines, microcontroller pins (dhs).

// Typedef.

typedef enum
{
	MENU_TTL_RATE,
	MENU_ACM_RATE,
	MENU_END
}fm_menu_t;

// Defines.

// Function prototypes

void fm_menu_ttl_rate();
void fm_menu_acm_rate();

#endif /* MODULE_H */

/*** end of file ***/
