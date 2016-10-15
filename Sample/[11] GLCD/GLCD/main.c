/*-------------------------------------------------------------------------------
							 www.ECA.ir
					AT91SAM7X256 Dev Board Rev.A
			http://www.eca.ir/forum2/index.php?board=317.0
--------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------
Jumper set :
G-LCD Jumper = ON
CAN ON Jumper = ON
CAN TX Jumper = ON
--------------------------------------------------------------------------------*/

#include <AT91SAM7X256.h>
#include "pic.h"

#define GLCD_DATAPORT_A      //GLCD pins definition 
#define GLCD_RS			 2
#define GLCD_RW	     3
#define GLCD_EN			 4
#define GLCD_CS1		 12
#define GLCD_CS2	   13
#define GLCD_D0		   19

#include "ks0108.h"



void Delay(void){
int i;
for(i=0;i<2000000;i++);
}

int main(){

GLCD_Initialize();
GLCD_ClearScreen();
GLCD_Bitmap(data,0,0,128,64);
Delay();
Delay();
GLCD_ClearScreen();
GLCD_Circle(30,56,6);
GLCD_Line(28,51,100,12);
GLCD_Line(80,12,91,5);
GLCD_Line(33,60,49,52);
GLCD_Line(80,12,81,8);
GLCD_Line(80,12,84,12);
GLCD_Line(49,52,45,52);
GLCD_Line(49,52,48,56);
GLCD_Circle(98,7,6);
GLCD_Rectangle(0,0,128,64);
	
	
	
	while(1)
	{
		GLCD_GoTo(55,6);
		GLCD_WriteString("           ");
		GLCD_GoTo(10,1);
		GLCD_WriteString("www.ECA.ir");
		Delay();
		GLCD_GoTo(10,1);
		GLCD_WriteString("           ");
		GLCD_GoTo(65,6);
		GLCD_WriteString("GLCD TEST");
		Delay();
	} 
}
