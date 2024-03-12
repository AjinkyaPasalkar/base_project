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
uint8_t port_pinMode(GPIO_TypeDef * port, uint8_t pin, port_pin_dir dir)
{
    volatile uint32_t *ptr_reg; // Port configuration register address
    
    if (pin > 15)
    {
        return 1;
    }
    
    // if pin<8 then use CRL. if pin>8 then use CRH
    ptr_reg = &(port->CRL) + (pin >> 3);
    
    // if pin > 8 then pin -= 8
    pin &= 7;
    
    if (dir == input)
    {
        
    }
    else if (dir == output)
    {
       // Set MODE = 10b --> Output mode, max speed 2 MHz
       *ptr_reg &= ~(0x3 << (pin * 4));
       *ptr_reg |=   0x2 << (pin * 4) ;
       
       // Set CNF = 01b --> General purpose output, push pull
       *ptr_reg &= ~(0x3 << ((pin * 4) + 2));
       *ptr_reg |=   0x1 << ((pin * 4) + 2) ;
    }
    else
    {
        
    }

    return 0;    
}

/*** end of file ***/
