/*
 * gpio_ctrl.c
 *
 *  Created on: 2019. 5. 1.
 *      Author: user
 */
#include "xparameters.h"
#include "xgpio.h"

int main (void)
{
XGpio switches, leds;
int switches_check;
int count=0;
int pre_state=0;
xil_printf("-- Start of the Program -- \r\n");

XGpio_Initialize(&switches, XPAR_SWITCH_DEVICE_ID);
XGpio_SetDataDirection(&switches,1,0xffffffff);
XGpio_Initialize(&leds, XPAR_LED_DEVICE_ID);
XGpio_SetDataDirection(&leds,1,0x00000000);

while(1)
{
    switches_check = XGpio_DiscreteRead(&switches,1);
    if (switches_check != pre_state)
    {
    	if (switches_check == 0b10)
    	{
    		count = count + 1;
    		if (count >= 9) count = 0;
    	}
    	else if (switches_check == 0b01)
    	{
    		count = count - 1;
    		if (count <= 0) count = 0;
    	}
    	else
    		count = count;
    	pre_state = switches_check;
    }
    XGpio_DiscreteWrite(&leds,1,count);
    xil_printf("LED Status : %x\r\n", count);
   // sleep(1); // wait 1 sec
}
}


