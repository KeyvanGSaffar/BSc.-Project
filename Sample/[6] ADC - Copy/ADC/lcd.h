/* ----------------------------------------------------------------------------
library name :lcd.h -by this library you can work with at91sam family without
any long statment */

#ifndef lcd_INCLUDED_
#define lcd_INCLUDED_

#ifdef   LCD_PORT_A
#define   PIO_enable	     *AT91C_PIOA_PER 
#define   PIO_SetOutput	   *AT91C_PIOA_SODR 
#define   PIO_ClearOutput	 *AT91C_PIOA_CODR 
#define   PIO_CfgOutput    *AT91C_PIOA_OER 
#endif
#ifdef   LCD_PORT_B
#define   PIO_enable	     *AT91C_PIOB_PER
#define   PIO_SetOutput	   *AT91C_PIOB_SODR  
#define   PIO_ClearOutput	 *AT91C_PIOB_CODR
#define   PIO_CfgOutput    *AT91C_PIOB_OER 
#endif

#define F_CPU	18432000
#define clcd_minDelay()	 cwait(F_CPU/80000)
#define clcd_Delay()	   cwait(F_CPU/8000)

void lcd_init(void);
void lcd_putchar(char ch);
void lcd_command(char cmd);
void lcd_gotoxy(char x, char y);
void lcd_clear(void);
void lcd_clear_line(char y);
void lcd_shift_left(char n);
void lcd_shift_right(char n);
void lcd_puts(int num);
void lcd_putsf(char* data);
void lcd_define_char(const char *pc,char char_code);
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cwait (volatile int t) {
  for (;t; t--);
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void setD4567(char val)
{
	PIO_ClearOutput =((1<<LCD_DB4)|(1<<LCD_DB5)|(1<<LCD_DB6)|(1<<LCD_DB7));
	if (val & 0x80)
		PIO_SetOutput =(1<<LCD_DB7)	;
	if (val & 0x40)
		PIO_SetOutput =(1<<LCD_DB6);
	if (val & 0x20)
	PIO_SetOutput =(1<<LCD_DB5);
	if (val & 0x10)
	PIO_SetOutput =(1<<LCD_DB4);
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lcd_putchar(char ch)
{
	PIO_SetOutput =(1<<LCD_RS);
	setD4567(ch);
	PIO_SetOutput=(1<<LCD_E);
	clcd_minDelay();
	PIO_ClearOutput=(1<<LCD_E);
	clcd_minDelay();
	setD4567(ch<<4);
	PIO_SetOutput=(1<<LCD_E);
	clcd_minDelay();
	PIO_ClearOutput=(1<<LCD_E);
	clcd_Delay();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lcd_command(char cmd)	//Sends Command to LCD
{
	PIO_ClearOutput=(1<<LCD_RS);
	setD4567(cmd);
	PIO_SetOutput =(1<<LCD_E);
	clcd_minDelay();
	PIO_ClearOutput=(1<<LCD_E);
	clcd_minDelay();
	setD4567(cmd<<4);
	PIO_SetOutput =(1<<LCD_E);
	clcd_minDelay();
	PIO_ClearOutput =(1<<LCD_E);
	clcd_Delay();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lcd_init()
{
	PIO_enable =0XFFFFFFFF;
	PIO_CfgOutput = ((1<<LCD_RS)|(1<<LCD_RW)|(1<<LCD_E)|(1<<LCD_DB4)|(1<<LCD_DB5)|(1<<LCD_DB6)|(1<<LCD_DB7));
	PIO_ClearOutput = (1<<LCD_RW);
	clcd_Delay();
	setD4567(0);
	setD4567((1<<5)|(1<<4));
  PIO_SetOutput=(1<<LCD_E);
	clcd_minDelay();
  PIO_ClearOutput =(1<<LCD_E);
	clcd_Delay();
	setD4567((1<<5)|(1<<4));
	PIO_SetOutput =(1<<LCD_E);
	clcd_minDelay();
	PIO_ClearOutput =(1<<LCD_E);
	clcd_Delay();
	setD4567(1<<5);
	PIO_SetOutput =(1<<LCD_E);
	clcd_minDelay();
	PIO_ClearOutput =(1<<LCD_E);
	clcd_Delay();
	lcd_command(0x28);
	lcd_command(0x0c);
	clcd_Delay();
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lcd_gotoxy(char y, char x)	//Cursor to X Y position
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
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lcd_define_char(const char *pc,char char_code)
{
	char a , i;
	a = ((char_code<<3)|0x40) & 0xff;
	for (i = 0; i < 8 ;i++)
	{
		lcd_command(a++);
		clcd_Delay();
		lcd_putchar(pc[i]);
		clcd_Delay();
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lcd_clear(void)				//Clears LCD
{
	lcd_command(0x01);
lcd_command(0x02);
	clcd_Delay();
	clcd_Delay();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lcd_shift_left(char n)	//Scrol n of characters Right
{
	char i;
	for (i = 0 ; i < n ; i++)
	{
		lcd_command(0x1E);
		clcd_Delay();
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lcd_shift_right(char n)	//Scrol n of characters Left
{
	char i;
	for (i = 0 ; i < n ; i++)
	{
		lcd_command(0x18);
		clcd_Delay();
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lcd_putsf(char* data)	//Outputs string to LCD
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
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Display_off(void)
{
	lcd_command(0x08);
	clcd_Delay();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Display_on(void)
{
	lcd_command(0x0C);
	clcd_Delay();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cursor_off(void)
{
	lcd_command(0x0C);
	clcd_Delay();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cursor_on(void)
{
	lcd_command(0x0E);
	clcd_Delay();
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void cursor_blink(void)
{
	lcd_command(0x0F);
	clcd_Delay();
}
#endif
