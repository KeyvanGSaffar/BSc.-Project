/*-------------------------------------------------------------------------------
							 www.ECA.ir
					AT91SAM7X256 Dev Board Rev.A
			http://www.eca.ir/forum2/index.php?board=317.0
--------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------
Jumper set :
LED Jumper = ON
--------------------------------------------------------------------------------*/

#include <AT91SAM7X256.h>
#include "RTT.h"
#include "AIC.h"
#include "delay.h"

void rtt(void) __irq
{
	*AT91C_PIOA_SODR = 1<<19|1<<20|1<<21|1<<22;
	delay_ms(25);
	*AT91C_PIOA_CODR = 1<<19|1<<20|1<<21|1<<22;
	AT91C_BASE_AIC->AIC_EOICR = RTT_GetStatus();
}
 
int main(){
	
	*AT91C_PIOA_PER = 1<<19|1<<20|1<<21|1<<22;
	*AT91C_PIOA_OER = 1<<19|1<<20|1<<21|1<<22;
	*AT91C_PIOA_CODR = 1<<19|1<<20|1<<21|1<<22;
	
	AIC_ConfigureInt(AT91C_ID_SYS);
	AIC_EnableInt(AT91C_ID_SYS);
	
	RTT_SetPrescaler(32768);	
	RTT_EnableIT(AT91C_RTTC_RTTINCIEN);

	while(1);
}

		
	
	
	
