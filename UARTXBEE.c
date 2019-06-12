/*
 * UARTXBEE.c
 *
 *  Created on: 11-Jun-2019
 *      Author: Harshad
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"


int main(void)
{
    char newch[29] = {0x7E, 0x00, 0x19, 0x10, 0x01, 0x00, 0x13, 0xA2, 0x00, 0x41, 0x63, 0xCB, 0xF7, 0xFF, 0xFE, 0x00, 0x00, 0x48, 0x65, 0x79, 0x20, 0x48, 0x6F, 0x74, 0x74, 0x69, 0x65, 0x21, 0x02};
    //char recv[29];
    int i = 0;
    //int k = 0;
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART3);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    UARTEnable(UART3_BASE);
    GPIOPinTypeUART(GPIO_PORTC_BASE,(GPIO_PIN_6 | GPIO_PIN_7));
    GPIOPinConfigure(GPIO_PC6_U3RX);
    GPIOPinConfigure(GPIO_PC7_U3TX);
    UARTConfigSetExpClk(UART3_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
    while(1)
    {
        for(i=0; i<=28; i++)
            {
            UARTCharPut(UART3_BASE, newch[i]);
            }
        //for(k=0; k<=28; k++)
        //{
        //recv[k] = UARTCharGet(UART4_BASE);
        //}
        i =0;
        //k++;
    }
}




