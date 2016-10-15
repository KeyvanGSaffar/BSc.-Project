/*-------------------------------------------------------------------------------
							 www.ECA.ir
					AT91SAM7X256 Dev Board Rev.A
			http://www.eca.ir/forum2/index.php?board=317.0
--------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------
Jumper set :
LED Jumper = ON
SCL Jumper = ON
SDA Jumper = ON
--------------------------------------------------------------------------------*/

#include <at91sam7x256.h>
#include "TWI.h"
#include "TWID.h"
#include "math.h"


#define  TWCK     400000
#define  MCK      47923200
#define  AT24C02_ADDRESS  0x50


void delay(void){
	int i=1000000;
	while(i--);
}

int main(void){
	unsigned char k;
	unsigned char buf[8];
	
	*AT91C_PIOA_PDR = (1<<10)|(1<<11);
	*AT91C_PIOA_MDER= (1<<10)|(1<<11);
	*AT91C_PIOA_ASR = (1<<10)|(1<<11);
	
	AT91C_BASE_PMC->PMC_PCER |= 1<<AT91C_ID_TWI;
	
	*AT91C_PIOA_PER |= 0xf<<19;
	*AT91C_PIOA_OER |= 0xf<<19;
	*AT91C_PIOB_PER |= 0xf<<19;
	*AT91C_PIOB_OER |= 0xf<<19;
	
	TWI_ConfigureMaster( TWCK , MCK );
	
	//write buf array
	for(k=0;k<8;k++){
		buf[k+1]=power(2,k);
	}
	
	//write buf array in EEPROM Page
  TWID_Write(AT24C02_ADDRESS,0x00,1,buf,8,0);
	
	//clear buf array
	for(k=0;k<8;k++){
		buf[k+1]=0;
	}
	
	//read EEPROM page and save in buf
	TWID_Read(AT24C02_ADDRESS,0x00,1,buf,8,0);
	
	//show reading data from EEPROM by Board LEDs
	while(1){
		
		for(k=0;k<8;k++){
			*AT91C_PIOA_CODR = 0xf<<19 ;
			*AT91C_PIOB_CODR = 0xf<<19 ;
			*AT91C_PIOA_SODR = buf[k]<<19;
			*AT91C_PIOB_SODR = buf[k]<<15;
			delay();
		}
	} 
}



