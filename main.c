#include "stm32f103xb.h"
#include "Clock.h"
#include "Port.h"

void delay(void);

int main(void)
{
    Clock_Init(&Clock_Config);
    Port_Init(&Port_Config);


    while(1)
    {
        // blink led
        //port_pinWrite(GPIOC, 13, HIGH);
        delay();
        //port_pinWrite(GPIOC, 13, LOW);
        delay();
    }

    return 0;
}

void delay(void)
{
    int i;
    for(i=0; i<100000; i++)
    {
        ;
    }
}

//Startup code
__attribute__((naked, noreturn)) void Reset_Handler(void) {
 // memset .bss to zero, and copy .data section to RAM region
 extern long _sbss, _ebss, _sdata, _edata, _sidata;
 for (long *dst = &_sbss; dst < &_ebss; dst++) *dst = 0;
 for (long *dst = &_sdata, *src = &_sidata; dst < &_edata;) *dst++ = *src++;

 main();             // Call main()
 for (;;) (void) 0;  // Infinite loop in the case if main() returns
}

extern void _estack(void);  // Defined in link.ld

// 16 standard and 91 STM32-specific handlers
__attribute__((section(".vectors"))) void (*const tab[16 + 91])(void) = {
   _estack, Reset_Handler};
