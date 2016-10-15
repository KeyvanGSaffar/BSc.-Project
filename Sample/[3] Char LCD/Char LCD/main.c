/*-------------------------------------------------------------------------------
							 www.ECA.ir
					AT91SAM7X256 Dev Board Rev.A
			http://www.eca.ir/forum2/index.php?board=317.0
--------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------
2 strbings will shown on char LCD.www.ECA.ir and AT91SAM7X256 Developed Board

CH-LCD jumper = on
--------------------------------------------------------------------------------*/

#include <AT91SAM7X256.h>


#define LCD_PORT_A         //CHAR LCD pins definition
#define LCD_RS  2
#define LCD_RW  3
#define LCD_E   4
#define LCD_DB4 23
#define LCD_DB5 24
#define LCD_DB6 25
#define LCD_DB7 26
 
#include "lcd.h"
#include "delay.h"

unsigned char code[]={'V','I','C','T','O','R','Y','7','X','2','5','6'};
int j;

int main (void) {
	lcd_init();
	lcd_clear();
		while(1){
			lcd_gotoxy(1,1);
			lcd_putsf("*K1 ft Farshad");
			delay_s(3);
			lcd_clear();
			lcd_gotoxy(1,3);
			for(j=1;j<8;j++){
			lcd_putchar(code[j-1]);
			delay_ms(200);
			}
			lcd_gotoxy(2,1);
			lcd_putsf("*Ferdowsi Uni");
			delay_s(4);
			lcd_clear();
		}
}

