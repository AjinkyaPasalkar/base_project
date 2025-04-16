/** @file Dio.c
 *
 * @brief Control DIO
 *
 */

/*     Includes     */
#include "Dio.h"

void Dio_WritePin(GPIO_TypeDef * gpio,unsigned char pin, Dio_Level_t level)
{
    switch(level)
    {
        case (LOW):
            gpio->BRR |= 1 << pin;
            break;
        
        case (HIGH):
            gpio->BSRR |= 1 << pin;
            break;
        
        default:
            break;
    }
}
