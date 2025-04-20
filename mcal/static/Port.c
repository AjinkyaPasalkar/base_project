/** @file Port.c
 *
 * @brief Control ports
 *
 */

/*     Includes     */
#include "Port.h"

static void lPort_SetMode(GPIO_TypeDef * port, unsigned char pin, Port_Mode_t mode);

void Port_Init(const Port_Config_t *config)
{
    unsigned char pin;

    // Init Port C
    for (pin = 0; pin < PORT_MAX_PINS; pin++)
    {
        lPort_SetMode(GPIOC, pin, config->PORT_CCfg[pin]);
    }
}

static void lPort_SetMode(GPIO_TypeDef * port, unsigned char pin, Port_Mode_t mode)
{
    volatile unsigned int * ptr_reg;
    if (pin <= 7)
    {
        ptr_reg = &(port->CRL);
    }
    else
    {
        pin -= 8;
        ptr_reg = &(port->CRH);
    }

    switch (mode)
    {
        case PORT_OUTPUT_PUSHPULL:
            // Set MODE = 10b --> Output mode, max speed 2 MHz
           *ptr_reg &= ~(0x3 << (pin * 4));
           *ptr_reg |=   0x2 << (pin * 4) ;

           // Set CNF = 01b --> General purpose output, push pull
           *ptr_reg &= ~(0x3 << ((pin * 4) + 2));
           *ptr_reg |=   0x1 << ((pin * 4) + 2) ;
            break;

        case PORT_INPUT_PULLDOWN:
            // Set MODE = 00b --> Input mode
            *ptr_reg &= ~(0x3 << (pin * 4));

            // Set CNF = 01b --> Floating input
            *ptr_reg &= ~(0x3 << ((pin * 4) + 2));
            *ptr_reg |=   0x1 << ((pin * 4) + 2) ;
            break;

        default:
            break;
    }
}
