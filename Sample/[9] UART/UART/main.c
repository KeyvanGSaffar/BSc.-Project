/*-------------------------------------------------------------------------------
							 www.ECA.ir
					AT91SAM7X256 Dev Board Rev.A
			http://www.eca.ir/forum2/index.php?board=317.0
--------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------
Jumper set :
CH-LCD Jumper = ON
RS232 Jumper = ON

Baud rate : 9600
--------------------------------------------------------------------------------*/

#include <AT91SAM7X256.H> 
//#include "lib_AT91SAM7X256.H" 
#include "delay.h"
#include "usart.h"
#include <stdio.h>

#define LCD_PORT_A           //CHAR LCD pins definition
#define LCD_RS  2
#define LCD_RW  3
#define LCD_E   4
#define LCD_DB4 23
#define LCD_DB5 24
#define LCD_DB6 25
#define LCD_DB7 26

#include "lcd.h"  

int main (void) {
	lcd_init(); 
  lcd_clear();
  cursor_off();
	lcd_putsf("Uart Test");
	delay_s(1);
	usart0_init(2,9600);       //USART0
	//usart1_init(2,9600);     //USART1
	
	printf("www.ECA.ir Example\t");
	while (1) {
		lcd_gotoxy(1,1); 
		lcd_putsf("Recievid data :");
		lcd_putchar(getkey());
		delay_ms(100);
	}
}
