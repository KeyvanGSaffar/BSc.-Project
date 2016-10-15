/*----------------------------------------------------------------------------
 *      first project 
 *----------------------------------------------------------------------------
 *      Name:    first project
 *      Purpose: Show Temperature in 2x16 Character LCD
 *      Rev.:    V1.00
 *----------------------------------------------------------------------------
 *      source:
 *               www.armcenter.org
 *      Editor-> ali abrishami - ali.abrishami@gmail.com
 *---------------------------------------------------------------------------*/
#include <AT91SAM7X256.H>            
#include "LCD.h"
#include "adc.h"
#include <stdio.h>

int main (void) {
   int adc=0;
   char *temp;

   lcd_init();
   ADC_Initialize (48000000,5000000,10,1200);
   ADC_EnableChannel(5);

   lcd_clear();
   cursor_off();
   backlight_on();
   lcd_gotoxy(1,1);
   lcd_putsf("temperature:");

while (1) {
	adc=getadc(5);
    sprintf(temp,"%d",adc); //convert num to string
    lcd_gotoxy(2,1);
    lcd_putsf(temp); 	
	delay(10000);     
   	}
}
