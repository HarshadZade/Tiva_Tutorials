/*
 * receiving.c
 *
 *  Created on: 15-Jun-2019
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
#include  <string.h>
#include "fr_api.h"
char newch[50];
int main(void)
{

    //char *size;
    int i=0,j=0;
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3));
    UARTEnable(UART0_BASE);
    GPIOPinTypeUART(GPIO_PORTA_BASE,(GPIO_PIN_0 | GPIO_PIN_1));
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART5);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    UARTEnable(UART5_BASE);
    GPIOPinTypeUART(GPIO_PORTE_BASE,(GPIO_PIN_4 | GPIO_PIN_5));
    GPIOPinConfigure(GPIO_PE4_U5RX);
    GPIOPinConfigure(GPIO_PE5_U5TX);
    UARTConfigSetExpClk(UART5_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
    UARTCharPut(UART0_BASE, 'c');
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART5))
    {
    }
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0))
    {
    }
    while(1)
    {
        while(UARTCharsAvail(UART5_BASE))
        {
            //UARTCharPut(UART0_BASE, UARTCharGet(UART5_BASE));
            //for(i=0;newch[i] != '!';i++)
            //{
                newch[i] = UARTCharGet(UART5_BASE);
                i++;
                //if(newch[i] == '!')
                //{
                    //for(j=0;j<=i;j++)
                        //UARTCharPut(UART0_BASE, newch[j]);
                //}
            //}
        }
        //i=0;
        GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3), 0xFF);
        SysCtlDelay(1000000);
        GPIOPinWrite(GPIO_PORTF_BASE, (GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3), 0x00);
        SysCtlDelay(1000000);
    }
    }

