#ifndef KS0108_H
#define KS0108_H


#define KS0108_SCREEN_WIDTH		128
#define KS0108_SCREEN_HEIGHT	64


#define DISPLAY_SET_Y       0x40
#define DISPLAY_SET_X       0xB8
#define DISPLAY_START_LINE  0xC0
#define DISPLAY_ON_CMD		0x3E
#define ON	0x01
#define OFF	0x00
#define DISPLAY_STATUS_BUSY	0x80


void GLCD_Delay(void);
void GLCD_EnableController(unsigned char ) ;
void GLCD_DisableController(unsigned char );
unsigned char GLCD_ReadStatus(unsigned char );
void GLCD_WriteCommand(unsigned char , unsigned char ) ;
unsigned char GLCD_ReadData(void);
void GLCD_WriteData(unsigned char )	;
void GLCD_InitalizePorts(void);
unsigned char GLCD_ReadByteFromROMMemory(char *);


void GLCD_Initialize(void);
void GLCD_ClearScreen(void);
void GLCD_WriteChar(char );
void GLCD_WriteString(char *);
void GLCD_GoTo(unsigned char, unsigned char);
void GLCD_Bitmap(char *, unsigned char, unsigned char, unsigned char, unsigned char);
void GLCD_SetPixel(unsigned char , unsigned char , unsigned char );
void GLCD_Rectangle(unsigned char , unsigned char , unsigned char , unsigned char );
void GLCD_Circle(unsigned char , unsigned char  ,unsigned char );
void GLCD_Line(unsigned int ,unsigned int ,unsigned int ,unsigned int );


#ifdef GLCD_DATAPORT_A
#define KS0108_DATA_SET      *AT91C_PIOA_SODR
#define KS0108_DATA_CLR      *AT91C_PIOA_CODR
#define KS0108_DATA_OUT      *AT91C_PIOA_OER
#define KS0108_DATA_PIN      *AT91C_PIOA_PDSR
#define KS0108_DATA_PER      *AT91C_PIOA_PER
#define KS0108_DATA_ID        AT91C_ID_PIOA
#define KS0108_DATA_PPUER    *AT91C_PIOA_PPUER
#define KS0108_DATA_ODR      *AT91C_PIOA_ODR

#define KS0108_CTRL_SET      *AT91C_PIOA_SODR
#define KS0108_CTRL_CLR      *AT91C_PIOA_CODR
#define KS0108_CTRL_OUT      *AT91C_PIOA_OER
#define KS0108_CTRL_PIN      *AT91C_PIOA_PDSR
#define KS0108_CTRL_PPUDR    *AT91C_PIOA_PPUDR
#define KS0108_CTRL_PER      *AT91C_PIOA_PER
#define KS0108_CTRL_PPUER    *AT91C_PIOA_PPUER
#endif

#ifdef GLCD_DATAPORT_B
#define KS0108_DATA_SET      *AT91C_PIOB_SODR
#define KS0108_DATA_CLR      *AT91C_PIOB_CODR
#define KS0108_DATA_OUT      *AT91C_PIOB_OER
#define KS0108_DATA_PIN      *AT91C_PIOB_PDSR
#define KS0108_DATA_PER      *AT91C_PIOB_PER
#define KS0108_DATA_ID        AT91C_ID_PIOB
#define KS0108_DATA_PPUER    *AT91C_PIOB_PPUER
#define KS0108_DATA_ODR      *AT91C_PIOB_ODR

#define KS0108_CTRL_SET      *AT91C_PIOB_SODR
#define KS0108_CTRL_CLR      *AT91C_PIOB_CODR
#define KS0108_CTRL_OUT      *AT91C_PIOB_OER
#define KS0108_CTRL_PIN      *AT91C_PIOB_PDSR
#define KS0108_CTRL_PPUDR    *AT91C_PIOB_PPUDR
#define KS0108_CTRL_PER      *AT91C_PIOB_PER
#define KS0108_CTRL_PPUER    *AT91C_PIOB_PPUER
#endif


#define KS0108_RS      (1 << GLCD_RS)
#define KS0108_RW      (1 << GLCD_RW)
#define KS0108_EN      (1 << GLCD_EN)
#define KS0108_CS1     (1 << GLCD_CS2)
#define KS0108_CS2     (1 << GLCD_CS1)			
#define KS0108_CS3     (1 << GLCD_CS3)

#define DISPLAY_STATUS_BUSY	0x80


static const char font5x8[] = {
0x00, 0x00, 0x00, 0x00, 0x00,// (spacja)
0x00, 0x00, 0x5F, 0x00, 0x00,// !
0x00, 0x07, 0x00, 0x07, 0x00,// "
0x14, 0x7F, 0x14, 0x7F, 0x14,// #
0x24, 0x2A, 0x7F, 0x2A, 0x12,// $
0x23, 0x13, 0x08, 0x64, 0x62,// %
0x36, 0x49, 0x55, 0x22, 0x50,// &
0x00, 0x05, 0x03, 0x00, 0x00,// '
0x00, 0x1C, 0x22, 0x41, 0x00,// (
0x00, 0x41, 0x22, 0x1C, 0x00,// )
0x08, 0x2A, 0x1C, 0x2A, 0x08,// *
0x08, 0x08, 0x3E, 0x08, 0x08,// +
0x00, 0x50, 0x30, 0x00, 0x00,// ,
0x08, 0x08, 0x08, 0x08, 0x08,// -
0x00, 0x30, 0x30, 0x00, 0x00,// .
0x20, 0x10, 0x08, 0x04, 0x02,// /
0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
0x00, 0x42, 0x7F, 0x40, 0x00,// 1
0x42, 0x61, 0x51, 0x49, 0x46,// 2
0x21, 0x41, 0x45, 0x4B, 0x31,// 3
0x18, 0x14, 0x12, 0x7F, 0x10,// 4
0x27, 0x45, 0x45, 0x45, 0x39,// 5
0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
0x01, 0x71, 0x09, 0x05, 0x03,// 7
0x36, 0x49, 0x49, 0x49, 0x36,// 8
0x06, 0x49, 0x49, 0x29, 0x1E,// 9
0x00, 0x36, 0x36, 0x00, 0x00,// :
0x00, 0x56, 0x36, 0x00, 0x00,// ;
0x00, 0x08, 0x14, 0x22, 0x41,// <
0x14, 0x14, 0x14, 0x14, 0x14,// =
0x41, 0x22, 0x14, 0x08, 0x00,// >
0x02, 0x01, 0x51, 0x09, 0x06,// ?
0x32, 0x49, 0x79, 0x41, 0x3E,// @
0x7E, 0x11, 0x11, 0x11, 0x7E,// A
0x7F, 0x49, 0x49, 0x49, 0x36,// B
0x3E, 0x41, 0x41, 0x41, 0x22,// C
0x7F, 0x41, 0x41, 0x22, 0x1C,// D
0x7F, 0x49, 0x49, 0x49, 0x41,// E
0x7F, 0x09, 0x09, 0x01, 0x01,// F
0x3E, 0x41, 0x41, 0x51, 0x32,// G
0x7F, 0x08, 0x08, 0x08, 0x7F,// H
0x00, 0x41, 0x7F, 0x41, 0x00,// I
0x20, 0x40, 0x41, 0x3F, 0x01,// J
0x7F, 0x08, 0x14, 0x22, 0x41,// K
0x7F, 0x40, 0x40, 0x40, 0x40,// L
0x7F, 0x02, 0x04, 0x02, 0x7F,// M
0x7F, 0x04, 0x08, 0x10, 0x7F,// N
0x3E, 0x41, 0x41, 0x41, 0x3E,// O
0x7F, 0x09, 0x09, 0x09, 0x06,// P
0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
0x7F, 0x09, 0x19, 0x29, 0x46,// R
0x46, 0x49, 0x49, 0x49, 0x31,// S
0x01, 0x01, 0x7F, 0x01, 0x01,// T
0x3F, 0x40, 0x40, 0x40, 0x3F,// U
0x1F, 0x20, 0x40, 0x20, 0x1F,// V
0x7F, 0x20, 0x18, 0x20, 0x7F,// W
0x63, 0x14, 0x08, 0x14, 0x63,// X
0x03, 0x04, 0x78, 0x04, 0x03,// Y
0x61, 0x51, 0x49, 0x45, 0x43,// Z
0x00, 0x00, 0x7F, 0x41, 0x41,// [
0x02, 0x04, 0x08, 0x10, 0x20,// "\"
0x41, 0x41, 0x7F, 0x00, 0x00,// ]
0x04, 0x02, 0x01, 0x02, 0x04,// ^
0x40, 0x40, 0x40, 0x40, 0x40,// _
0x00, 0x01, 0x02, 0x04, 0x00,// `
0x20, 0x54, 0x54, 0x54, 0x78,// a
0x7F, 0x48, 0x44, 0x44, 0x38,// b
0x38, 0x44, 0x44, 0x44, 0x20,// c
0x38, 0x44, 0x44, 0x48, 0x7F,// d
0x38, 0x54, 0x54, 0x54, 0x18,// e
0x08, 0x7E, 0x09, 0x01, 0x02,// f
0x08, 0x14, 0x54, 0x54, 0x3C,// g
0x7F, 0x08, 0x04, 0x04, 0x78,// h
0x00, 0x44, 0x7D, 0x40, 0x00,// i
0x20, 0x40, 0x44, 0x3D, 0x00,// j
0x00, 0x7F, 0x10, 0x28, 0x44,// k
0x00, 0x41, 0x7F, 0x40, 0x00,// l
0x7C, 0x04, 0x18, 0x04, 0x78,// m
0x7C, 0x08, 0x04, 0x04, 0x78,// n
0x38, 0x44, 0x44, 0x44, 0x38,// o
0x7C, 0x14, 0x14, 0x14, 0x08,// p
0x08, 0x14, 0x14, 0x18, 0x7C,// q
0x7C, 0x08, 0x04, 0x04, 0x08,// r
0x48, 0x54, 0x54, 0x54, 0x20,// s
0x04, 0x3F, 0x44, 0x40, 0x20,// t
0x3C, 0x40, 0x40, 0x20, 0x7C,// u
0x1C, 0x20, 0x40, 0x20, 0x1C,// v
0x3C, 0x40, 0x30, 0x40, 0x3C,// w
0x44, 0x28, 0x10, 0x28, 0x44,// x
0x0C, 0x50, 0x50, 0x50, 0x3C,// y
0x44, 0x64, 0x54, 0x4C, 0x44,// z
0x00, 0x08, 0x36, 0x41, 0x00,// {
0x00, 0x00, 0x7F, 0x00, 0x00,// |
0x00, 0x41, 0x36, 0x08, 0x00,// }
0x08, 0x08, 0x2A, 0x1C, 0x08,// ->
0x08, 0x1C, 0x2A, 0x08, 0x08 // <-
};
//

//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
unsigned char screen_x = 0, screen_y = 0;
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_Initialize(void)
{
unsigned char i;
GLCD_InitalizePorts();
for(i = 0; i < 3; i++)
  GLCD_WriteCommand((DISPLAY_ON_CMD | ON), i);
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_GoTo(unsigned char x, unsigned char y)
{
unsigned char i;
screen_x = x;
screen_y = y;

for(i = 0; i < KS0108_SCREEN_WIDTH/64; i++)
  {
  GLCD_WriteCommand(DISPLAY_SET_Y | 0,i);
  GLCD_WriteCommand(DISPLAY_SET_X | y,i);
  GLCD_WriteCommand(DISPLAY_START_LINE | 0,i);
  }
GLCD_WriteCommand(DISPLAY_SET_Y | (x % 64), (x / 64));
GLCD_WriteCommand(DISPLAY_SET_X | y, (x / 64));
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_ClearScreen(void)
{
unsigned char i, j;
for(j = 0; j < KS0108_SCREEN_HEIGHT/8; j++)
  {
  GLCD_GoTo(0,j);
  for(i = 0; i < KS0108_SCREEN_WIDTH; i++)
    GLCD_WriteData(0x00);
  }
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_WriteChar(char charToWrite)
{
int i;
charToWrite -= 32; 
for(i = 0; i < 5; i++) 
  GLCD_WriteData(GLCD_ReadByteFromROMMemory((char *)((int)font5x8 + (5 * charToWrite) + i))); 
GLCD_WriteData(0x00);
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_WriteString(char * stringToWrite)
{
while(*stringToWrite)
  GLCD_WriteChar(*stringToWrite++);
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_SetPixel(unsigned char x, unsigned char y, unsigned char color)
{
unsigned char tmp;
GLCD_GoTo(x, (y / 8));
tmp = GLCD_ReadData();
GLCD_GoTo(x, (y / 8));
tmp = GLCD_ReadData();
GLCD_GoTo(x, (y / 8));
tmp |= (1 << (y % 8));
GLCD_WriteData(tmp);
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_Bitmap(char * bmp, unsigned char x, unsigned char y, unsigned char dx, unsigned char dy)
{
unsigned char i, j;
for(j = 0; j < dy / 8; j++)
  {
  GLCD_GoTo(x,y + j);
  for(i = 0; i < dx; i++) 
    GLCD_WriteData(GLCD_ReadByteFromROMMemory(bmp++));
  }
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------

unsigned char GLCD_ReadByteFromROMMemory(char * ptr)
{
return *(ptr);
}


//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_InitalizePorts(void)
{
	*AT91C_PMC_PCER =  (1 << KS0108_DATA_ID);	
	KS0108_DATA_PER |= (0xFF << GLCD_D0);
	KS0108_DATA_OUT |= (0xFF << GLCD_D0);
	KS0108_DATA_PPUER |= (0xFF << GLCD_D0);
	KS0108_CTRL_PER |=(KS0108_CS1 | KS0108_CS2  | KS0108_RS | KS0108_RW | KS0108_EN);
	KS0108_CTRL_OUT |=(KS0108_CS1 | KS0108_CS2  | KS0108_RS | KS0108_RW | KS0108_EN);
	KS0108_CTRL_PPUDR |=(KS0108_CS1 | KS0108_CS2  | KS0108_RS | KS0108_RW | KS0108_EN);
	KS0108_CTRL_SET |= (KS0108_CS1 | KS0108_CS2  );
}

//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_WriteData(unsigned char dataToWrite)
{
unsigned int byte;
while(GLCD_ReadStatus(screen_x / 64)&DISPLAY_STATUS_BUSY);
KS0108_DATA_OUT |= (0xFF << GLCD_D0);
KS0108_CTRL_CLR |= KS0108_RW;
KS0108_CTRL_SET |= KS0108_RS;
byte = dataToWrite;
KS0108_DATA_SET |= (byte << GLCD_D0 );
byte ^= 0xff;
KS0108_DATA_CLR = (byte << GLCD_D0 );
GLCD_EnableController(screen_x / 64);
KS0108_CTRL_SET |= KS0108_EN;
GLCD_Delay();
KS0108_CTRL_CLR |= KS0108_EN;
GLCD_DisableController(screen_x / 64);
screen_x++;
}

//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadData(void)
{
unsigned char data;
while(GLCD_ReadStatus(screen_x / 64)&DISPLAY_STATUS_BUSY);
KS0108_DATA_ODR |= (0xFF << GLCD_D0);
KS0108_CTRL_SET |= (KS0108_RW | KS0108_RS);
GLCD_EnableController(screen_x / 64);
KS0108_CTRL_SET |= KS0108_EN;
GLCD_Delay();
data = (KS0108_DATA_PIN >>  GLCD_D0)&0xff;
KS0108_CTRL_CLR = KS0108_EN;
GLCD_DisableController(screen_x / 64);
screen_x++;
return data;
}

//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_WriteCommand(unsigned char commandToWrite, unsigned char controller)
{
unsigned int command;
while(GLCD_ReadStatus(controller)&DISPLAY_STATUS_BUSY);
KS0108_DATA_OUT |= (0xFF << GLCD_D0);
KS0108_CTRL_CLR |= (KS0108_RW | KS0108_RS);
GLCD_EnableController(controller);
command=commandToWrite;
KS0108_DATA_SET |= (command << GLCD_D0);
command ^= 0xff;
KS0108_DATA_CLR |= (command << GLCD_D0);

KS0108_CTRL_SET |= KS0108_EN;
GLCD_Delay();
KS0108_CTRL_CLR |= KS0108_EN;
GLCD_DisableController(controller);
}

//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadStatus(unsigned char controller)
{
unsigned char status;
KS0108_DATA_ODR |= (0xFF << GLCD_D0);
KS0108_CTRL_SET |= KS0108_RW;
KS0108_CTRL_CLR |= KS0108_RS;
GLCD_EnableController(controller);
KS0108_CTRL_SET |= KS0108_EN;
GLCD_Delay();
status = (KS0108_DATA_PIN >> GLCD_D0);
KS0108_CTRL_CLR |= KS0108_EN;
GLCD_DisableController(controller);
return status;
}

//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_DisableController(unsigned char controller)
{
switch(controller){
	case 0 : KS0108_CTRL_SET = KS0108_CS1; break;
	case 1 : KS0108_CTRL_SET = KS0108_CS2; break;
	//case 2 : KS0108_CTRL_SET = KS0108_CS3; break;
	}
}

//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_EnableController(unsigned char controller)
{
switch(controller){
	case 0 : KS0108_CTRL_CLR = KS0108_CS1; break;
	case 1 : KS0108_CTRL_CLR = KS0108_CS2; break;
	//case 2 : KS0108_CTRL_CLR = KS0108_CS3; break;
	}
}


 
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_Delay(void)
{
char i;

for(i=0 ; i<10 ;i++);
}


//#include "graphic.h"

extern void GLCD_SetPixel(unsigned char x, unsigned char y, unsigned char color);

const unsigned char color = 1;
const unsigned char clear = 0;


//


void GLCD_Rectangle(unsigned char x, unsigned char y, unsigned char b, unsigned char a)
{
  unsigned char j; 
  for (j = 0; j < a; j++) {
		GLCD_SetPixel(x, y + j, clear);
		GLCD_SetPixel(x + b - 1, y + j, clear);
	}
 
  for (j = 0; j < b; j++)	{
		GLCD_SetPixel(x + j, y, clear);
		GLCD_SetPixel(x + j, y + a - 1, clear);
	}
}


void GLCD_Circle(unsigned char cx, unsigned char cy ,unsigned char radius)
{
int x, y, xchange, ychange, radiusError;
x = radius;
y = 0;
xchange = 1 - 2 * radius;
ychange = 1;
radiusError = 0;
while(x >= y)
  {
  GLCD_SetPixel(cx+x, cy+y, color); 
  GLCD_SetPixel(cx-x, cy+y, color); 
  GLCD_SetPixel(cx-x, cy-y, color);
  GLCD_SetPixel(cx+x, cy-y, color); 
  GLCD_SetPixel(cx+y, cy+x, color); 
  GLCD_SetPixel(cx-y, cy+x, color); 
  GLCD_SetPixel(cx-y, cy-x, color); 
  GLCD_SetPixel(cx+y, cy-x, color); 
  y++;
  radiusError += ychange;
  ychange += 2;
  if ( 2*radiusError + xchange > 0 )
    {
    x--;
	radiusError += xchange;
	xchange += 2;
	}
  }
}
//

void GLCD_Line(unsigned int X1,unsigned int Y1,unsigned int X2,unsigned int Y2)
{
int CurrentX, CurrentY, Xinc, Yinc, 
    Dx, Dy, TwoDx, TwoDy, 
	TwoDxAccumulatedError, TwoDyAccumulatedError;

Dx = (X2-X1); 
Dy = (Y2-Y1); 

TwoDx = Dx + Dx; 
TwoDy = Dy + Dy; 

CurrentX = X1; 
CurrentY = Y1; 

Xinc = 1;  
Yinc = 1; 

if(Dx < 0) 
  {
  Xinc = -1; 
  Dx = -Dx;  
  TwoDx = -TwoDx; 
  }

if (Dy < 0) 
  {
  Yinc = -1; 
  Dy = -Dy; 
  TwoDy = -TwoDy; 
  }

GLCD_SetPixel(X1,Y1, color); 

if ((Dx != 0) || (Dy != 0))
  {
 
  if (Dy <= Dx) 
    { 
    TwoDxAccumulatedError = 0;  
    do 
	  {
      CurrentX += Xinc; 
      TwoDxAccumulatedError += TwoDy;
      if(TwoDxAccumulatedError > Dx) 
        {
        CurrentY += Yinc; 
        TwoDxAccumulatedError -= TwoDx; 
        }
       GLCD_SetPixel(CurrentX,CurrentY, color);
       }while (CurrentX != X2); 
     }
   else 
      {
      TwoDyAccumulatedError = 0; 
      do 
	    {
        CurrentY += Yinc; 
        TwoDyAccumulatedError += TwoDx;
        if(TwoDyAccumulatedError>Dy) 
          {
          CurrentX += Xinc;
          TwoDyAccumulatedError -= TwoDy;
          }
         GLCD_SetPixel(CurrentX,CurrentY, color); 
         }while (CurrentY != Y2);
    }
  }
}


#endif
