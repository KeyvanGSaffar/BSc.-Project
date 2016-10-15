/*-------------------------------------------------------------------------------
							 www.ECA.ir
					AT91SAM7X256 Dev Board Rev.A
			http://www.eca.ir/forum2/index.php?board=317.0
--------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------
Jumper set :
TFT LCD Jumper = ON
--------------------------------------------------------------------------------*/

#include <AT91SAM7X256.H> 
#include "lib_AT91SAM7X256.H"
#include "delay.h"

 
#define family_sam7x                         //TFTLCD pins definition
#define TFTLCD_DATAPORT_B             
#define TFTLCD_DATAPORT_OFFSET      0

#define TFTLCD_CONTROLPORT_A          
#define TFTLCD_RST                  7
#define TFTLCD_RS                   4
#define TFTLCD_CS                   2
#define TFTLCD_WR                   3
#define TFTLCD_RD                   13 
#define PORTRAIT

#include "tftlcd_functions.h"
#include "touch.h"
#include <stdio.h>

int x1,y1,color=RED;
char lcd_buffer[20];

int main(void) 
  {			 

	tftlcd_init();
	tftlcd_clear();	
	tftlcd_draw_rectangle(0,280,239,319,1,BLACK);
	tftlcd_draw_rectangle(2,282,38,317,1,RED);
	tftlcd_draw_rectangle(42,282,78,317,1,GREEN);
	tftlcd_draw_rectangle(82,282,118,317,1,BLUE);
	tftlcd_draw_rectangle(122,282,158,317,1,WHITE);
	delay_ms(100);

	while(1) {
			
		if (touch(&x1,&y1) == 1) {
			x1=(240*(802-x1))/660 ;
			sprintf(lcd_buffer,"X=%d   ",x1);	     
			tftlcd_gotoxy(21,18);
			tftlcd_puts(lcd_buffer,color,BLACK,0);
			y1=(320*(923-y1))/753 ;
			sprintf(lcd_buffer,"Y=%d   ",y1);	
			tftlcd_gotoxy(21,19);
			tftlcd_puts(lcd_buffer,color,BLACK,0);

			if (y1 > 280&& y1 <320) {	 // 10%
				 if (x1>160) tftlcd_draw_rectangle(0,0,239,279,1,WHITE);
				 if	(x1<160) color = WHITE; 
				 if (x1<120) color = BLUE; 
				 if (x1<80)  color = GREEN;
				 if (x1<40)  color = RED;

			}else tftlcd_draw_circle(x1,y1,3,1,color);	// draw circle in touch position

		}else tftlcd_draw_rectangle(160,280,239,319,1,BLACK); //clear X , Y
		
			
	};
}   

