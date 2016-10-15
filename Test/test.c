# include <AT91SAM7X256.H> /* AT91SAMT7X256 definitions */ 
void k_delay (void);

int main(){
	
		*AT91C_PIOA_PER = (1<<19)|(1<<20)|(1<<21)|(1<<22);
		*AT91C_PIOA_OER = (1<<19)|(1<<20)|(1<<21)|(1<<22);
		
		*AT91C_PIOB_PER = (1<<19)|(1<<20)|(1<<21)|(1<<22);
		*AT91C_PIOB_OER = (1<<19)|(1<<20)|(1<<21)|(1<<22);
	
	while(1){
		*AT91C_PIOA_SODR = (1<<19)|(1<<20)|(1<<21)|(1<<22);
		*AT91C_PIOB_CODR = (1<<19)|(1<<20)|(1<<21)|(1<<22);
		
		k_delay();
		
		*AT91C_PIOA_CODR = (1<<19)|(1<<20)|(1<<21)|(1<<22);
		*AT91C_PIOB_SODR = (1<<19)|(1<<20)|(1<<21)|(1<<22);
		
		k_delay();
		
	}
}  

void k_delay (void) {
unsigned int i;
	for (i=0;i<2000;i++);
}
