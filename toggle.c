

/**
 * main.c
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"

#include "inc/hw_sysctl.h"
#include "inc/hw_gpio.h"

#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
int main(void)
{
    int Val=0;
    int CrSt=0;
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xFF);
    GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);

    while(1)
    {
        Val = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4);
        if( (Val & GPIO_PIN_4)==0)

            CrSt^=GPIO_PIN_1;

        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, CrSt);

        SysCtlDelay(1000000);

    }
 // return 0;
}
