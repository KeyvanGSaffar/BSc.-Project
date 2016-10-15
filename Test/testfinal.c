# include <AT91SAM7X256.H> /* AT91SAMT7X256 definitions */ 
int status[32];
void k_delay (void);

int main(){
	
		*AT91C_PIOA_PER = 0xf<<19;
		*AT91C_PIOA_OER = 0xf<<19;
		*AT91C_PMC_PCER = 1<<3;
		
	
	
		*AT91C_PIOB_PER = (0xf<<19)|(1<<23);
		*AT91C_PIOB_OER = 0xf<<19;
  	*AT91C_PIOB_ODR = (1<<23);
		*AT91C_PIOA_CODR = 0xf<<19;
	while(1){
		//status = *AT91C_PIOA_PDSR;
		//if(status[0] == 1)

		while((*AT91C_PIOB_PDSR&(1<<23))==0){	*AT91C_PIOA_SODR =(1<<21)|(1<<22);
		
		//*AT91C_PIOB_CODR = 0xFF;
		
		//k_delay();
			
		//*AT91C_PIOA_OER = (1<<19)|(1<<20)|(1<<21)|(1<<22);
		//*AT91C_PIOB_SODR = (1<<19)|(1<<20)|(1<<21)|(1<<22);
		
			k_delay();
			*AT91C_PIOA_CODR =(1<<21)|(1<<22);
			*AT91C_PIOA_SODR =(1<<20)|(1<<19);

			k_delay();
			*AT91C_PIOA_CODR = 0xf<<19;
		}
		
	}
}  

void k_delay (void) {
unsigned int i;
	for (i=0;i<2000;i++);
}
