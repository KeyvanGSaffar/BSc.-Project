

int getadc(int channel);

void ADC_Initialize (     
                     unsigned int mckClock,
                     unsigned int adcClock,
                     unsigned int startupTime,
                     unsigned int sampleAndHoldTime);
void ADC_EnableChannel(int channel);
