/** @file port.c
 * 
 * @brief Configure port pins
 *
 */

#include "port.h"

/*!
 * @brief Set pin mode.
 *
 * @return Success:0, Fail:1
 */
unsigned char port_pinMode(GPIO_TypeDef * port, unsigned char pin, port_pin_dir dir)
{
    unsigned char ret = 1;
    
    if (dir == input)
    {
        
    }
    else if (dir == output)
    {
        if (pin < 8)
        {
            
        }
        else
        {
            pin -= 8;
            // Set MODE = 10b --> Output mode, max speed 2 MHz
            port->CRH &= ~(0x3 << (pin * 4));
            port->CRH |= 0x2 << (pin * 4);
            
            // Set CNF = 01b --> General purpose output push pull
            port->CRH &= ~(0x3 << ((pin * 4) + 2));
            port->CRH |= 0x1 << ((pin * 4) + 2);
        }
    }
    else
    {
        
    }

    return ret;    
}

/*** end of file ***/
