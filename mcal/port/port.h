/** @file port.h
 * 
 * @brief Configure pins and ports.
 *
 */ 

#ifndef PORT_H
#define PORT_H

#include "stm32f103xb.h"

typedef enum pin_dir_e
{
    input,
    output,
    alternate
}port_pin_dir;

typedef enum cnf_input_e
{
    input_analog,
    input_floating,
    input_pull_down,
    input_pull_up
}port_cnf_input;

typedef enum cnf_output_e
{
    output_push_pull,
    output_open_drain,
    alt_push_pull,
    alt_open_drain
}port_cnf_output;

typedef enum mode_e
{
    max_output_speed_10MHz = 1,
    max_output_speed_2MHz,
    max_output_speed_50MHz
}port_speed;

typedef enum pin_state_e
{
    LOW,
    HIGH
}pin_state;

typedef struct
{
    GPIO_TypeDef * port;
    unsigned char pin;
    port_pin_dir dir;
    port_cnf_input cnf_input;
    port_cnf_output cnf_output;
    port_speed speed;
} pin_config_t;

uint8_t port_pinMode(GPIO_TypeDef * port, uint8_t pin, port_pin_dir dir);
uint8_t port_pinWrite(GPIO_TypeDef * port, uint8_t pin, pin_state state);

#endif /* PORT_H */

/*** end of file ***/
