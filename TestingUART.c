/*
 * TestingUART.c
 *
 *  Created on: 27-May-2019
 *      Author: Harshad
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_gpio.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"


int main(void)
{
    char newch[10];
    int i = 0;
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    UARTEnable(UART0_BASE);
    GPIOPinTypeUART(GPIO_PORTA_BASE,(GPIO_PIN_0 | GPIO_PIN_1));
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
    UARTCharPut(UART0_BASE, 'c');
    while(1)
        {
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0))
            {
            }
//UARTCharPut(UART0_BASE, 'c');
        while(UARTCharsAvail(UART0_BASE))
            {
                newch[i] = UARTCharGetNonBlocking(UART0_BASE);
                i++;
            }
        for(i=0;i<5;i++)
            {
            UARTCharPut(UART0_BASE, newch[i]);
            }
        i=0;
        }
}


