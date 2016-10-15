/*-------------------------------------------------------------------------------
							 www.ECA.ir
					AT91SAM7X256 Dev Board Rev.A
			http://www.eca.ir/forum2/index.php?board=317.0
--------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------
external intrupt 0 = active
puch int0 key = LED blinky

LED jumper = on
--------------------------------------------------------------------------------*/
#include <AT91SAM7X256.h>
#include "AIC.h"
#include "delay.h"


 
void exti(void) __irq
{
	*AT91C_PIOA_SODR |= (0xff<<19);          //reste leds
	delay_ms(50);                              //for waiting
	*AT91C_PIOA_CODR |= (0xff<<19);          // Set leds
	delay_ms(50);                              //for waiting

	AT91C_BASE_AIC->AIC_EOICR = AT91C_BASE_AIC->AIC_ISR;          //end of interrupt routine	
}



int main(void)
{
	*AT91C_PMC_PCER = (1<<AT91C_ID_IRQ0) ;   //enable IRQ1 clock	
	*AT91C_PIOA_PDR  |= AT91C_PIO_PA30 ;     //Desable pin as input/output   
	*AT91C_PIOA_ASR  |= AT91C_PIO_PA30 ;     //Define pin as A select Register						
	*AT91C_PIOA_PPUER|= AT91C_PIO_PA30 ;     //Enable Pull-Up Register	


	*AT91C_PIOA_OER  |= (0xff<<19) ;         //Define pin as A select Register
	*AT91C_PIOA_CODR |= (0xff<<19) ;	       //clear down leds

	AIC_ConfigureInt(AT91C_ID_IRQ0);         //Config Interrupt
	AIC_EnableInt(AT91C_ID_IRQ0);            //Enable Interrupt
	
	while(1);
} 
