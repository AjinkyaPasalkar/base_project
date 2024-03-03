/** @file port.h
 * 
 * @brief Configure pins and ports.
 *
 */ 

#ifndef PORT_H
#define PORT_H

enum mode
{
    max_output_speed_10MHz = 1,
    max_output_speed_2MHz,
    max_output_speed_50MHz
};

enum configuration_input
{
    input_analog,
    input_floating,
    input_push_pull
};

#endif /* PORT_H */

/*** end of file ***/
