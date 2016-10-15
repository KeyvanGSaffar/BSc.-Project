/*-------------------------------------------------------------------------------
							 www.ECA.ir
					AT91SAM7X256 Dev Board Rev.A
			http://www.eca.ir/forum2/index.php?board=317.0
--------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------
Jumper set :
LED Jumper = ON
--------------------------------------------------------------------------------*/

#include <at91sam7x256.h>

int main(){
	
	*AT91C_PMC_PCER = 1<<AT91C_ID_PWMC;
	
	*AT91C_PIOB_PDR = (1<<19)|(1<<20);
	*AT91C_PIOB_MDER = (1<<19)|(1<<20);
	*AT91C_PIOB_PPUER = (1<<19)|(1<<20);
	*AT91C_PIOB_ASR = (1<<19)|(1<<20);
	
	//configure PWM0&PWM1 whit frequency of 1Hz and 
	//50% duty cycle  for PWM0, 25% duty cycle  for PWM1  
	*AT91C_PWMC_CH0_CMR = 0x20A;
	*AT91C_PWMC_CH1_CMR = 0x20A;
	*AT91C_PWMC_CH0_CPRDR= 0xb6d0;
	*AT91C_PWMC_CH1_CPRDR= 0xb6d0;
	*AT91C_PWMC_CH0_CDTYR= 0x5b68;
	*AT91C_PWMC_CH1_CDTYR= 0x2db4;
	*AT91C_PWMC_ENA= 0x3;
	
	while(1);	
	  
}  

