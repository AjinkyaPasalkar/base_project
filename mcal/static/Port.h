/** @file Port.h
 *
 * @brief Control ports
 *
 */

#ifndef __Port_H
#define __Port_H

/*     Includes     */
#include "registers.h"
#include "Port_Cfg.h"

#define PORT_MAX_PINS   16U

typedef enum
{
    PORT_OUTPUT_PUSHPULL,
    PORT_OUTPUT_OPENDRAIN,
    PORT_AF_PUSHPULL,
    PORT_AF_OPENDRAIN,
    PORT_INPUT_ANALOG,
    PORT_INPUT_FLOATING,
    PORT_INPUT_PULLDOWN,
    PORT_INPUT_PULLUP
}Port_Mode_t;

typedef struct
{
    Port_Mode_t PORT_ACfg[PORT_MAX_PINS];
    Port_Mode_t PORT_BCfg[PORT_MAX_PINS];
    Port_Mode_t PORT_CCfg[PORT_MAX_PINS];
    Port_Mode_t PORT_DCfg[PORT_MAX_PINS];
}Port_Config_t;

/*     Global Variables     */
extern const Port_Config_t Port_Config;

/*    Function Prototypes     */
void Port_Init(const Port_Config_t *config);

#endif
