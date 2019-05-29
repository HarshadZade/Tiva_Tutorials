/*
 * UART_interrupts.c
 *
 *  Created on: 29-May-2019
 *      Author: Harshad
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"

#include "inc/hw_sysctl.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/uart.h"

void   UARTIntHandler(void)
{
    //GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xFF);
    uint32_t Stat;
    Stat = UARTIntStatus(UART0_BASE, true);
    UARTIntClear(UART0_BASE, Stat);
    //while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0))
    //{
    //}
    //while(1)
    //{
        while(UARTCharsAvail(UART0_BASE))
        {
            GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3), 0x00);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xFF);
            UARTCharPutNonBlocking(UART0_BASE,  UARTCharGetNonBlocking(UART0_BASE));
        }
    //}
}

int main(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    UARTEnable(UART0_BASE);

    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE,(GPIO_PIN_0 | GPIO_PIN_1));
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
    IntMasterEnable();
    IntEnable(INT_UART0);
    UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3));

     UARTCharPut(UART0_BASE, 'E');
     UARTCharPut(UART0_BASE, 'n');
     UARTCharPut(UART0_BASE, 't');
     UARTCharPut(UART0_BASE, 'e');
     UARTCharPut(UART0_BASE, 'r');
     UARTCharPut(UART0_BASE, ' ');
     UARTCharPut(UART0_BASE, 'T');
     UARTCharPut(UART0_BASE, 'e');
     UARTCharPut(UART0_BASE, 'x');
     UARTCharPut(UART0_BASE, 't');
     UARTCharPut(UART0_BASE, ':');
     UARTCharPut(UART0_BASE, ' ');

    while(1)
    {
        GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3), 0xFF);
        SysCtlDelay(1000000);
        GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3), 0x00);
        SysCtlDelay(1000000);
    }

}



