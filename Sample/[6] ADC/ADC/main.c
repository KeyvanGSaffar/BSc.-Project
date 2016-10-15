/*-------------------------------------------------------------------------------
							 www.ECA.ir
					AT91SAM7X256 Dev Board Rev.A
			http://www.eca.ir/forum2/index.php?board=317.0
--------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------
Jumper set :
CH-LCD Jumper = ON
--------------------------------------------------------------------------------*/

#include <At91SAM7X256.h>
#include <stdio.h>
#include "delay.h"

#define LCD_PORT_A         //CHAR LCD pins definition
#define LCD_RS  2
#define LCD_RW  3
#define LCD_E   4
#define LCD_DB4 23
#define LCD_DB5 24
#define LCD_DB6 25
#define LCD_DB7 26
 
#include "lcd.h"


int main(){
	unsigned int x;
	float y;
	char buf[5];
	lcd_init();
	
	*AT91C_ADC_CR = AT91C_ADC_SWRST ;
	*AT91C_ADC_CHER = AT91C_ADC_CH3 ;
	*AT91C_ADC_MR =  AT91C_ADC_SHTIM|AT91C_ADC_STARTUP|AT91C_ADC_PRESCAL
									|AT91C_ADC_SLEEP_NORMAL_MODE
	                |AT91C_ADC_LOWRES_10_BIT|AT91C_ADC_TRGEN_DIS;
	
	while(1){
		lcd_gotoxy(1,1);
		lcd_putsf("Vin Value:");
		*AT91C_ADC_CR = AT91C_ADC_START;
		while((*AT91C_ADC_SR&AT91C_ADC_EOC3)==0);
		x=*AT91C_ADC_CDR3 & AT91C_ADC_DATA;
		y=(3.3*x)/1023;
		sprintf(buf,"%f   ",y);
		lcd_gotoxy(1,12);
		lcd_putsf(buf);
		delay_ms(1000);
	}
} 
