/*----------------------------------------------------------------------------
 *      Real Time Timer 
 *---------------------------------------------------------------------------*/

#include <AT91SAM7X256.H>
 
 
void RTT_SetPrescaler(unsigned short prescaler);
unsigned int RTT_GetTime(void);
void RTT_EnableIT(unsigned int sources);
unsigned int RTT_GetStatus(void);
void RTT_SetAlarm(unsigned int time);

//------------------------------------------------------------------------------
/// Changes the prescaler value of the given RTT and restarts it. This function
/// disables RTT interrupt sources.
/// \param prescaler  Prescaler value for the RTT.
//------------------------------------------------------------------------------
void RTT_SetPrescaler(unsigned short prescaler)
{
   
    *AT91C_RTTC_RTMR = (prescaler | AT91C_RTTC_RTTRST);
}

//------------------------------------------------------------------------------
/// Returns the current value of the RTT timer value.
//------------------------------------------------------------------------------
unsigned int RTT_GetTime(void)
{
    return *AT91C_RTTC_RTVR;
}

//------------------------------------------------------------------------------
/// Enables the specified RTT interrupt sources.
/// \param sources  Bitmask of interrupts to enable.
//------------------------------------------------------------------------------
void RTT_EnableIT(unsigned int sources)
{
    *AT91C_RTTC_RTMR |= sources;
}

//------------------------------------------------------------------------------
/// Returns the status register value of the given RTT.
/// \param rtt  Pointer to an AT91S_RTTC instance.
//------------------------------------------------------------------------------
unsigned int RTT_GetStatus(void)
{
    return *AT91C_RTTC_RTSR;
}

//------------------------------------------------------------------------------
/// Configures the RTT to generate an alarm at the given time.
/// \param time  Alarm time.
//------------------------------------------------------------------------------
void RTT_SetAlarm(unsigned int time)
{
    *AT91C_RTTC_RTAR = time - 1;
}

//EOF

