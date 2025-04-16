/** @file Dio.h
 *
 * @brief Control DIO
 *
 */

#ifndef __Dio_H
#define __Dio_H

/*     Includes     */
#include "registers.h"
#include "Dio_Cfg.h"


typedef enum
{
    LOW,
    HIGH
}Dio_Level_t;

/*     Global Variables     */


/*    Function Prototypes     */
void Dio_WritePin(GPIO_TypeDef * gpio,unsigned char pin, Dio_Level_t level);


#endif
