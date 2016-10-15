/*-------------------------------------------------------------------------------
							 www.ECA.ir
					AT91SAM7X256 Dev Board Rev.A
			http://www.eca.ir/forum2/index.php?board=317.0
--------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------
Jumper set :
TFT LCD Jumper = ON
--------------------------------------------------------------------------------*/

#include <AT91SAM7x256.h>


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
#include "image.h"


int main(void) 
  {			 
	tftlcd_init();
	tftlcd_clear();
	tftlcd_write_pic(0,0,image);
	while(1);
  }  
