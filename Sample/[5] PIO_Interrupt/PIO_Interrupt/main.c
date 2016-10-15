/*-------------------------------------------------------------------------------
							 www.ECA.ir
					AT91SAM7X256 Dev Board Rev.A
			http://www.eca.ir/forum2/index.php?board=317.0
--------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------
Jumper set :
LED Jumper = ON
--------------------------------------------------------------------------------*/

#include <AT91SAM7X256.H>
#include "AIC.h"
#include "delay.h"


  void pio(void) __irq
{
		 *AT91C_PIOA_SODR = (0xF<<19);
		 delay_ms(100);
     *AT91C_PIOA_CODR = (0xF<<19);
		 delay_ms(100);
	
		 AT91C_BASE_AIC->AIC_EOICR = AT91C_BASE_AIC->AIC_ISR;
		 AT91C_BASE_AIC->AIC_EOICR = AT91C_BASE_PIOB->PIO_ISR;		 
}


int main(void)
{
	*AT91C_PMC_PCER = (1<<AT91C_ID_PIOB );//enable I/O Clock
	
	//define pins as input whit pullup resistors & glitch filter
	*AT91C_PIOB_PER =(AT91C_PIO_PB23);//define pins as input output
	*AT91C_PIOB_ODR =(AT91C_PIO_PB23);
	*AT91C_PIOB_IFER  |= (AT91C_PIO_PB23) ;	//Enable Input Filter
	*AT91C_PIOB_PPUER |= (AT91C_PIO_PB23) ;  //Enable Pull-Up Register	
	*AT91C_PIOB_IER  |= (AT91C_PIO_PB23) ;
	*AT91C_PIOA_PER  |= (0xF<<19);
	*AT91C_PIOA_OER  |= (0xF<<19); // set pins as output
	*AT91C_PIOA_CODR |= (0xF<<19); // clear down pins

	AIC_ConfigureInt(AT91C_ID_PIOB);
	AIC_EnableInt(AT91C_ID_PIOB);// enable PIOA interrupt

	while(1);
	}


