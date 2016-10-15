#ifndef adc_INCLUDED_
#define adc_INCLUDED_

void config_adc(char adc);
unsigned int adc_data;	
void start_adc(void);
void config_adc(char adc)
{
*AT91C_ADC_CR = AT91C_ADC_SWRST;                                  
*AT91C_ADC_CHER = (adc);                    
*AT91C_ADC_MR = 0x0f1f3f00;			
*AT91C_ADC_IDR = 0xffffffff;	
}
void start_adc(void){
*AT91C_ADC_CR = AT91C_ADC_START; 
} 
unsigned int read_adc(char channel)	
{
switch (channel)
{
	case 0:
	
		   while ((*AT91C_ADC_SR & AT91C_ADC_EOC0) == 0);  	
	adc_data = (unsigned int) *AT91C_ADC_CDR0 & AT91C_ADC_DATA;
		
break;
		
	case 1:
	
		   while ((*AT91C_ADC_SR & AT91C_ADC_EOC1) == 0);  		 
	adc_data = (unsigned int) *AT91C_ADC_CDR1 & AT91C_ADC_DATA;
	break;
		case 2:
	
		   while ((*AT91C_ADC_SR & AT91C_ADC_EOC2) == 0);  		 
	adc_data = (unsigned int) *AT91C_ADC_CDR2 & AT91C_ADC_DATA;
	
	break;
	
	case 3:
	
		   while ((*AT91C_ADC_SR & AT91C_ADC_EOC3) == 0);  	 
	adc_data = (unsigned int) *AT91C_ADC_CDR3 & AT91C_ADC_DATA;
	
	break;
		case 4:
	
		   while ((*AT91C_ADC_SR & AT91C_ADC_EOC4) == 0);  	
	adc_data = (unsigned int) *AT91C_ADC_CDR4 & AT91C_ADC_DATA;
		
	 break;

	case 5:
	
		   while ((*AT91C_ADC_SR & AT91C_ADC_EOC5) == 0);  	  
	adc_data = (unsigned int) *AT91C_ADC_CDR5 & AT91C_ADC_DATA;

	break;
		case 6:
	
		   while ((*AT91C_ADC_SR & AT91C_ADC_EOC6) == 0);  	
	adc_data = (unsigned int) *AT91C_ADC_CDR6 & AT91C_ADC_DATA;
	
	break;

	case 7:
	
		   while ((*AT91C_ADC_SR & AT91C_ADC_EOC7) == 0);  		  
	adc_data = (unsigned int) *AT91C_ADC_CDR7 & AT91C_ADC_DATA;
	break;

}
	return(adc_data);	
} 



#endif
