/*-------------------------------------------------------------------------------
							 www.ECA.ir
					AT91SAM7X256 Dev Board Rev.A
			http://www.eca.ir/forum2/index.php?board=317.0
--------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------
S1 on = LED1 and LED2 on
S2 on = LED3 and LED4 on
S3 on = LED5 and LED6 on
S4 on = LED7 and LED8 on
S5 on = All LEDs and buzzer on

LED jumper and Buzzer jumper = on
--------------------------------------------------------------------------------*/
#include <AT91SAM7X256.h>


void delay(void){
	int i;
	for(i=0;i<1000000;i++);
}

int main(){
	
	AT91C_BASE_PMC->PMC_PCER = 1<<3; // az tarigh (AT91C_ID_PIOB which is 3 ) clk ro be kole port B vasl mikonim
	
	AT91C_BASE_PIOB->PIO_PER = (0x1f<<23) | (0xf<<19);// az 19-27 ro yek karde
	AT91C_BASE_PIOB->PIO_OER = (0xf<<19 ) ;// 19-22 output shode
	AT91C_BASE_PIOB->PIO_ODR = (0x1f<<23)  ;// 23-27 baraye input shodan output disable
	
	AT91C_BASE_PIOA->PIO_PER = 0xf<<19 | 1<<28 ;// A(19-22) output & A28 buzzer
	AT91C_BASE_PIOA->PIO_OER = 0xf<<19 | 1<<28 ;
	
	while(1){
		while((AT91C_BASE_PIOB->PIO_PDSR&(1<<23))==0) *AT91C_PIOA_SODR=3<<21; //dar halate adi key ==1 ast va vaghti mifesharim 0 mishavad
		while((AT91C_BASE_PIOB->PIO_PDSR&(1<<24))==0) {
			
			*AT91C_PIOA_SODR=   1<<28 ;
			*AT91C_PIOA_SODR= 0xf<<19 ;
			*AT91C_PIOB_SODR= 0xf<<19 ;
			
		}
		while((AT91C_BASE_PIOB->PIO_PDSR&(1<<25))==0) *AT91C_PIOA_SODR=3<<19;
		while((AT91C_BASE_PIOB->PIO_PDSR&(1<<26))==0) *AT91C_PIOB_SODR=3<<21;
		while((AT91C_BASE_PIOB->PIO_PDSR&(1<<27))==0) *AT91C_PIOB_SODR=3<<19;
				
		*AT91C_PIOA_CODR= (0xf<<19) | (1<<28) ;
		*AT91C_PIOB_CODR= (0xf<<19) ;
	}
}  
