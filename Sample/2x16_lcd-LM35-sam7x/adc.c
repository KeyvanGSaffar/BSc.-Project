/*----------------------------------------------------------------------------
 *      8-10 bit ADC Code 
 *----------------------------------------------------------------------------
 *      Name:    adc.C
 *      Purpose: Analog to Digital driver for sam7 controller
 *      Rev.:    V1.00
 *----------------------------------------------------------------------------
 *      source:
 *               www.armcenter.org
 *      Editor-> ali abrishami - ali.abrishami@gmail.com
 *---------------------------------------------------------------------------*/

#include <AT91SAM7X256.H>
	 AT91PS_PMC pPMC = AT91C_BASE_PMC ; 
	 AT91PS_PIO pPIO = AT91C_BASE_PIOA;
	 AT91PS_ADC adc = AT91C_BASE_ADC;
//------------------------------------------------------------------------
void ADC_EnableChannel(int channel)
{
    // Write to the CHER register
    adc->ADC_CHER = (1 << channel);
}
//------------------------------------------------------------------------
void ADC_SoftReset(void)
{
    adc->ADC_CR = AT91C_ADC_SWRST;    
}
//------------------------------------------------------------------------
static void ADC_CfgModeReg(unsigned int mode)
{
    // Clear the register
    adc->ADC_MR = 0;
    // Write to the MR register
    adc->ADC_MR = mode;
}
//------------------------------------------------------------------------
void ADC_StartConversion(void)
{
    adc->ADC_CR = AT91C_ADC_START;    
}
//------------------------------------------------------------------------
void ADC_Initialize (     
                     unsigned int mckClock,
                     unsigned int adcClock,
                     unsigned int startupTime,
                     unsigned int sampleAndHoldTime)
{
    unsigned int prescal;
    unsigned int startup;
    unsigned int shtim;
    // Example:
    // 5 MHz operation, 20us startup time, 600ns track and hold time
    // PRESCAL: Prescaler Rate Selection ADCClock = MCK / ( (PRESCAL+1) * 2 )
    // PRESCAL = [MCK / (ADCClock * 2)] -1 = [48/(5*2)]-1 = 3,8
    // PRESCAL =  4 -> 48/((4+1)*2) = 48/10 = 4.8MHz
    // 48/((3+1)*2) = 48/8 = 6MHz
    // Startup Time = (STARTUP+1) * 8 / ADCClock
    // STARTUP = [(Startup Time * ADCClock)/8]-1 = [(20 10e-6 * 5000000)/8]-1 = 11,5
    // STARTUP = 11 -> (11+1)*8/48000000 = 96/4800000 = 20us
    //
    // Sample & Hold Time = (SHTIM) / ADCClock
    // SHTIM = (HoldTime * ADCClock) = (600 10e-9 * 5000000) = 3
    // SHTIM   =  3 -> (3)/4800000 = 1/1600000 = 625ns
    prescal = (mckClock / (2*adcClock)) - 1;
    startup = ((adcClock/1000000) * startupTime / 8) - 1;
    shtim = (((adcClock/1000000) * sampleAndHoldTime)/1000);
     // Enable peripheral clock    
    AT91C_BASE_PMC->PMC_PCER = 1 << 4;       
    // Reset the controller
    ADC_SoftReset();
    // Write to the MR register
    ADC_CfgModeReg( ( (prescal<<8) & AT91C_ADC_PRESCAL) 
                  | ( (startup<<16) & AT91C_ADC_STARTUP) 
                  | ( (shtim<<24) & AT91C_ADC_SHTIM) );
}

int getadc(int channel){
int adc_val ;
ADC_StartConversion();
   switch(channel)
   {
      case 0: adc_val = adc->ADC_CDR0; break;
	  case 1: adc_val = adc->ADC_CDR1; break;
	  case 2: adc_val = adc->ADC_CDR2; break;
	  case 3: adc_val = adc->ADC_CDR3; break;
	  case 4: adc_val = adc->ADC_CDR4; break;
	  case 5: adc_val = adc->ADC_CDR5; break;
	  case 6: adc_val = adc->ADC_CDR6; break;
	  case 7: adc_val = adc->ADC_CDR7; break;
   }

return (adc_val);
}
