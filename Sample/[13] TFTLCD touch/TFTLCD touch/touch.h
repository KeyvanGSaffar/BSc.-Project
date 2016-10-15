// Touch.h raminmicro@gmail.com
// Header File for Resistive Touch Screen 


#ifndef touch_INCLUDED_
#define touch_INCLUDED_

#define    Xm       AT91C_PIO_PB28
#define    Yp       AT91C_PIO_PB29
#define    Xp       AT91C_PIO_PA30
#define    Ym       AT91C_PIO_PA29



#include "adc.h"

int touch(int *x,int *y){
	int a,b;
	/*  
	  X-  PB.28   AD6
    Y-  PB.29   AD7
    X+  PA.30   AD4
    Y+  PA.29   AD5   
	*/

	config_adc(0x04);
	AT91F_PIO_CfgOutput  (AT91C_BASE_PIOB, AT91C_PIO_PB28);
	AT91F_PIO_CfgOutput  (AT91C_BASE_PIOA, AT91C_PIO_PA30);
	AT91F_PIO_CfgInput   (AT91C_BASE_PIOB, AT91C_PIO_PA29);
	AT91F_PIO_CfgInput   (AT91C_BASE_PIOA, AT91C_PIO_PB29);
	AT91F_PIO_SetOutput  (AT91C_BASE_PIOB, AT91C_PIO_PB28);
	AT91F_PIO_ClearOutput(AT91C_BASE_PIOA, AT91C_PIO_PA30);   
	start_adc();
	b = read_adc(2);  //PB.29  AD2
	delay_us(100);

	config_adc(0x10);
	AT91F_PIO_CfgOutput  (AT91C_BASE_PIOB, AT91C_PIO_PA29);
	AT91F_PIO_CfgOutput  (AT91C_BASE_PIOA, AT91C_PIO_PB29);
	AT91F_PIO_CfgInput   (AT91C_BASE_PIOB, AT91C_PIO_PB28);
	AT91F_PIO_CfgInput   (AT91C_BASE_PIOA, AT91C_PIO_PA30);
	AT91F_PIO_SetOutput  (AT91C_BASE_PIOB, AT91C_PIO_PA29);
	AT91F_PIO_ClearOutput(AT91C_BASE_PIOA, AT91C_PIO_PB29);  
	start_adc();
	a = read_adc(4);  //AD4
		
	*y = a;
	*x = b;

	return 1;
}


#endif
