/*-------------------------------------------------------------------------*
                               www.ECA.ir
                       AT91SAM7X256 Dev Board Rev.A
 *-------------------------------------------------------------------------*/

extern void rtt(void) __irq;

void AIC_ConfigureInt(unsigned int source);
void AIC_EnableInt(unsigned int source);
void AIC_DisableInt(unsigned int source);

//-----------------------------------------------------------------------------
void AIC_ConfigureInt(unsigned int source)
{
    // Disable the interrupt first
    AT91C_BASE_AIC->AIC_IDCR = (1<<source);
    // Configure mode and handler
    AT91C_BASE_AIC->AIC_SMR[source] = 0;									  
    AT91C_BASE_AIC->AIC_SVR[source] = (unsigned int) rtt ;			
}
//------------------------------------------------------------------------------
/// Enables interrupts 
//------------------------------------------------------------------------------
void AIC_EnableInt(unsigned int source)
{
    AT91C_BASE_AIC->AIC_IECR = 1 << source;					
}
//------------------------------------------------------------------------------
/// Disables interrupts 
//------------------------------------------------------------------------------
void AIC_DisableInt(unsigned int source)
{
    AT91C_BASE_AIC->AIC_IDCR = 1 << source;
} 
