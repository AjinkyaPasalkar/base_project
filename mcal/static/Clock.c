/** @file Clock.c
 * 
 * @brief Control clocks
 *
 */

/*     Includes     */
#include "Clock.h"

void Clock_Init(const Clock_Config_t *config)
{
    if (config->IOPORT_C == 1)
    {
        RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    }
}
