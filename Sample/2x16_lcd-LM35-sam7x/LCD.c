/*----------------------------------------------------------------------------
 *      2x16 Character LCD Code 
 *----------------------------------------------------------------------------
 *      Name:    LCD.C
 *      Purpose: LCD module 2x16 driver for sam7 controller
 *      Rev.:    V1.00
 *----------------------------------------------------------------------------
 *      source:
 *               www.armcenter.org
 *      Editor-> ali abrishami - ali.abrishami@gmail.com
 *---------------------------------------------------------------------------*/
#include <AT91SAM7X256.H>
#include "LCD.h"


#define SAYNA                      /* for sayna board (sam7x256)          */

#ifdef SAYNA
 #define LCD_DB4   AT91C_PIO_PA14
 #define LCD_DB5   AT91C_PIO_PA12
 #define LCD_DB6   AT91C_PIO_PA9
 #define LCD_DB7   AT91C_PIO_PA8
 #define LCD_RS    AT91C_PIO_PA15
 #define LCD_E 	   AT91C_PIO_PB29
 #define LCD_BL    AT91C_PIO_PA2
#else  /* for sayn board (sam7s256) */
 #define LCD_DB4   AT91C_PIO_PA11
 #define LCD_DB5   AT91C_PIO_PA26
 #define LCD_DB6   AT91C_PIO_PA25
 #define LCD_DB7   AT91C_PIO_PA24
 #define LCD_RS    AT91C_PIO_PA31
 #define LCD_E 	   AT91C_PIO_PA2
 #define LCD_BL    AT91C_PIO_PA0
#endif 

/*--------------------------- delay -----------------------------------------*/
void delay (int cnt) {
  while (cnt--);
}
/*--------------------------- enable ----------------------------------------*/
void enable (void) {
	delay (900);
*AT91C_PIOB_SODR |=LCD_E;
    delay (900);
*AT91C_PIOB_CODR |=LCD_E;
    delay (900);
}
/*--------------------------- lcd_write -----------------------------------------*/
void lcd_write(char val)
{
   *AT91C_PIOA_CODR |=(LCD_DB4|LCD_DB5|LCD_DB6|LCD_DB7);
   if (val & 0x80)
      *AT91C_PIOA_SODR |=LCD_DB7;
   if (val & 0x40)
      *AT91C_PIOA_SODR |=LCD_DB6;
   if (val & 0x20)
      *AT91C_PIOA_SODR |=LCD_DB5;
   if (val & 0x10)
      *AT91C_PIOA_SODR |=LCD_DB4;
}
/*--------------------------- lcd_putchar -----------------------------------------*/
void lcd_putchar(char ch)
{
   *AT91C_PIOA_SODR =LCD_RS;
   lcd_write(ch);
   enable();
   lcd_write(ch<<4);
   enable();
}
/*--------------------------- lcd_command -----------------------------------------*/
void lcd_command(char cmd)   //Sends Command to LCD
{
   *AT91C_PIOA_CODR=LCD_RS;
   lcd_write(cmd);
   enable();
   lcd_write(cmd<<4);
   enable();
}
/*--------------------------- lcd_init -----------------------------------------*/
void lcd_init()
{
   *AT91C_PIOA_PER |= (LCD_RS|LCD_DB4|LCD_DB5|LCD_DB6|LCD_DB7|LCD_BL);
   *AT91C_PIOA_OER |= (LCD_RS|LCD_DB4|LCD_DB5|LCD_DB6|LCD_DB7|LCD_BL);
 #ifdef SAYNA
   *AT91C_PIOB_PER |= LCD_E;
   *AT91C_PIOB_OER |= LCD_E;
 #else
   *AT91C_PIOA_PER |= LCD_E;
   *AT91C_PIOA_OER |= LCD_E;
 #endif
   lcd_write(1<<5);
   enable();
   lcd_command(0x28);  //4 bit - 2 lines - 5x7 dots
   lcd_command(0x0c);
   delay (1000);
}
/*--------------------------- lcd_gotox -----------------------------------------*/
void lcd_gotoxy(char y, char x)   //Cursor to X Y position
{
   char DDRAMAddr;
x=x-1;
   switch(y)
   {
      case 1: DDRAMAddr = 0x00+x; break;
      case 2: DDRAMAddr = 0x40+x; break;
      case 3: DDRAMAddr = 0x14+x; break;
      case 4: DDRAMAddr = 0x54+x; break;
      default: DDRAMAddr = 0x00+x;
   }
   lcd_command(1<<7 | DDRAMAddr);
}
/*--------------------------- lcd_define_char -----------------------------------------*/
void lcd_define_char(const char *pc,char char_code)
{
  char a , i;
   a = ((char_code<<3)|0x40) & 0xff;
   for (i = 0; i < 8 ;i++)
   {
      lcd_command(a++);
      delay (1000);
      lcd_putchar(pc[i]);
      delay (1000);
   }	  
	
}
/*--------------------------- lcd_puts -----------------------------------------*/
 void lcd_puts(int num)
{
   int i,j;
   int p,f=0;
   char ch[5];
 for(i=0;i<5;i++)
   {
     p=1;
     for(j=4-i;j>0;j--)
       p = p*10;
     ch[i] = (num/p);
    if (num>=p && !f){
     f=1;
    }
     num =num - ch[i] *p ;
    ch[i] = ch[i] +48;
     if(f) lcd_putchar(ch[i]);
   }
}
/*--------------------------- lcd_putsf -----------------------------------------*/
void lcd_putsf(char* data)   //Outputs string to LCD
{
   char *p;
   p = data;
   if (!p)
      return;
   for(; *p ; )
   {
      lcd_putchar(*p);
      p++;
   }
}
/*--------------------------- lcd_clear -----------------------------------------*/
void lcd_clear(void)            //Clears LCD
{
   lcd_command(0x01);
   lcd_command(0x02);
   delay (1000);
}
/*--------------------------- lcd_shift_left -----------------------------------------*/
void lcd_shift_right(int n)   //Scrol n of characters Right
{
   char i;
   for (i = 0 ; i < n ; i++)
   {
      lcd_command(0x1E);
      delay (1000);
   }
}
/*--------------------------- lcd_shift_right -----------------------------------------*/
void lcd_shift_left(int n)   //Scrol n of characters Left
{
   char i;
   for (i = 0 ; i < n ; i++)
   {
      lcd_command(0x18);
      delay (1000);
   }
}
/*--------------------------- Display_off -----------------------------------------*/
void Display_off(void)
{
   lcd_command(0x08);
   delay (1000);
}
/*--------------------------- Display_on -----------------------------------------*/
void Display_on(void)
{
   lcd_command(0x0C);
   delay (1000);
}
/*--------------------------- cursor_off -----------------------------------------*/
void cursor_off(void)
{
   lcd_command(0x0C);
   delay (1000);
}
/*--------------------------- cursor_on -----------------------------------------*/
void cursor_on(void)
{
   lcd_command(0x0E);
   delay (1000);
}
/*--------------------------- cursor_blink -----------------------------------------*/
void cursor_blink(void)
{
   lcd_command(0x0F);
   delay (1000);
}
/*--------------------------- backlight_on -----------------------------------------*/
void backlight_on(void)
{
*AT91C_PIOA_SODR |= LCD_BL;
}
/*--------------------------- backlight_off -----------------------------------------*/
void backlight_off(void)
{
*AT91C_PIOA_CODR |= LCD_BL;
}
/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
