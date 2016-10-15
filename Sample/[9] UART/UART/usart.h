//usart.h revision v1.0


#ifndef uart_H
#define uart_H
#include <stdio.h>
#define echo 0		//if echo=0 then echo off and if echo=1 then echo on 

#ifndef F_CPU
#define F_CPU 18432000
#endif

int a,sync=1 ,Async=2 , mode;
int  BARD_RATE1,BARD_RATE0;


void usart0_init(unsigned long usart0_mode,unsigned long usart0_Baud0)
{
mode=0;	
	*AT91C_PMC_PCER|=(1<<AT91C_ID_US0);		
	*AT91C_PIOA_PDR|=(AT91C_PA0_RXD0 | AT91C_PA1_TXD0);		//Disable I/O,PA5=RXD0,PA6=TXD0
	*AT91C_PIOA_ASR|=(AT91C_PIO_PA0 | AT91C_PIO_PA1); // define	 peripheral A select regidtry		//Select PIO set A (hamun uart)
	*AT91C_US0_CR=0XAC;					//RESET UART
	*AT91C_US0_IDR = 0xFFFF; // all usart0 interrupts disabled
	*AT91C_US0_RTOR = 0; // receiver time-out (disabled)
  *AT91C_US0_TTGR = 0; // transmitter timeguard (disabled)
switch (usart0_mode)
	{
//for Synchronous mode***for Synchronous mode***for Synchronous mode***for Synchronous mode***for Synchronous mode***for Synchronous mode***for Synchronous mode***
	case 1:
	*AT91C_US0_MR = (AT91C_US_USMODE_NORMAL | AT91C_US_PAR_NONE |AT91C_US_CLKS_EXT | AT91C_US_CHRL_8_BITS | AT91C_US_SYNC |AT91C_US_CKLO  ); // 8-bit characters		
	//USART Mode Register=Normal MODE ,  No parity , External (SCK) ,  Character Length: 8 bits , Synchronous Mode Select ,
	// attention :in This  mode if USCLKS does not select the external clock SCK the USART drives the SCK pin (CLKO bit in US0_MR)
	//Oversampling Mode=8 , The NACK is not generated , The USART does not filter the receive line	,
	//if  you use  other Selected Clock , this  line  is true:
  //*AT91C_US0_BRGR=(((M_crystal*73/14)/2)/usart0_Baud0);			//BARD RATE
	*AT91C_US0_CR=0X50;					//SET UART
  *AT91C_US0_FIDI = 0; // FI over DI Ratio Value (disabled)
  *AT91C_US0_IF = 0; // IrDA Filter value (disabled)
	break;
//for Asynchronous mode***for Asynchronous mode***for Asynchronous mode***for Asynchronous mode***for Asynchronous mode***for Asynchronous mode***
	case 2 :
  *AT91C_US0_MR = (AT91C_US_USMODE_NORMAL | AT91C_US_PAR_NONE | // no parity
                      0x3 << 6); // 8-bit characters				//8bit,No,1Bit Stop
	*AT91C_US0_IDR = 0xFFFF; // all usart0 interrupts disabled
 	*AT91C_US0_BRGR=(((F_CPU*73/14)/2)/16/usart0_Baud0) ;			//BARD RATE
	*AT91C_US0_CR=0X50;					//SET UART
  *AT91C_US0_FIDI = 0; // FI over DI Ratio Value (disabled)
  *AT91C_US0_IF = 0; // IrDA Filter value (disabled)
	break;
	}
}
void usart1_init(unsigned long usart1_mode,unsigned long usart1_Baud0)
{
mode=1;
	
	*AT91C_PMC_PCER|=(1<<AT91C_ID_US1);		
	*AT91C_PIOA_PDR|=(AT91C_PA5_RXD1 | AT91C_PA6_TXD1);		//Disable I/O,PA5=RXD0,PA6=TXD0
	*AT91C_PIOA_ASR|=(AT91C_PIO_PA5 | AT91C_PIO_PA6); // define	 peripheral A select regidtry		//Select PIO set A (hamun uart)
	*AT91C_US1_CR=0XAC;					//RESET UART
	*AT91C_US1_IDR = 0xFFFF; // all usart0 interrupts disabled
	*AT91C_US1_RTOR = 0; // receiver time-out (disabled)
  *AT91C_US1_TTGR = 0; // transmitter timeguard (disabled)
switch (usart1_mode)
	{
//for Synchronous mode***for Synchronous mode***for Synchronous mode***for Synchronous mode***for Synchronous mode***for Synchronous mode***for Synchronous mode***
	case 1:
	*AT91C_US1_MR = (AT91C_US_USMODE_NORMAL | AT91C_US_PAR_NONE |AT91C_US_CLKS_EXT | AT91C_US_CHRL_8_BITS | AT91C_US_SYNC |AT91C_US_CKLO  ); // 8-bit characters		
	//USART Mode Register=Normal MODE ,  No parity , External (SCK) ,  Character Length: 8 bits , Synchronous Mode Select ,
	// attention :in This  mode if USCLKS does not select the external clock SCK the USART drives the SCK pin (CLKO bit in US0_MR)
	//Oversampling Mode=8 , The NACK is not generated , The USART does not filter the receive line	,
	//if  you use  other Selected Clock , this  line  is true:
  //*AT91C_US0_BRGR=(((M_crystal*73/14)/2)/usart0_Baud0);			//BARD RATE
	*AT91C_US1_CR=0X50;					//SET UART
  *AT91C_US1_FIDI = 0; // FI over DI Ratio Value (disabled)
  *AT91C_US1_IF = 0; // IrDA Filter value (disabled)
	break;
//for Asynchronous mode***for Asynchronous mode***for Asynchronous mode***for Asynchronous mode***for Asynchronous mode***for Asynchronous mode***
	case 2 :
  *AT91C_US1_MR = (AT91C_US_USMODE_NORMAL | AT91C_US_PAR_NONE | // no parity
                      0x3 << 6); // 8-bit characters				//8bit,No,1Bit Stop
	*AT91C_US1_IDR = 0xFFFF; // all usart0 interrupts disabled
 	*AT91C_US1_BRGR=(((F_CPU*73/14)/2)/16/usart1_Baud0) ;			//BARD RATE
	*AT91C_US1_CR=0X50;					//SET UART
  *AT91C_US1_FIDI = 0; // FI over DI Ratio Value (disabled)
  *AT91C_US1_IF = 0; // IrDA Filter value (disabled)
	break;
	}
}

                       // device specific header file



int sendchar (int ch)  {                 /* Write character to Serial Port    */
if (mode==0) {
  if (ch == '\n')  {                            // Check for CR
    while (!((*AT91C_US0_CSR) & AT91C_US_TXRDY)); // Wait for Empty Tx Buffer
    *AT91C_US0_THR = '\r';
	}
	  while (!((*AT91C_US0_CSR) & AT91C_US_TXRDY));   // Wait for Empty Tx Buffer
  return (*AT91C_US0_THR = ch); 
  } 
else{
  if (ch == '\n')  {                            // Check for CR
    while (!((*AT91C_US1_CSR) & AT91C_US_TXRDY)); // Wait for Empty Tx Buffer
    *AT91C_US1_THR = '\r';
	}
		  while (!((*AT91C_US1_CSR) & AT91C_US_TXRDY));   // Wait for Empty Tx Buffer
  return (*AT91C_US1_THR = ch);
	}	                     // Output CR
  }
                // Transmit Character


int getkey (void)  {                    
 if (mode==0) {
  while (!((*AT91C_US0_CSR) & AT91C_US_RXRDY));   // Wait for Empty Rx Buffer
  return (*AT91C_US0_RHR );
    } 
else{ 
  while (!((*AT91C_US1_CSR) & AT91C_US_RXRDY));   // Wait for Empty Rx Buffer
  return (*AT91C_US1_RHR );
    }                      // recieve Character
}


#pragma import(__use_no_semihosting_swi)     // disable semihosting


struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;
// simplified fputc version that only redirects STDOUT
int fputc(int ch, FILE *f) {
// redirect STDOUT
  return (sendchar(ch));
}
// simplified fgetc version that only redirects STDIN
int fgetc(FILE *f) {
volatile int in;
#if echo
in=sendchar(getkey());
#else
in=getkey();
#endif
if (in==0x000D){
in=0x000A;}
return (in);
// redirect STDIN
//  return (sendchar(getkey()));
}


int ferror(FILE *f) {
/* Your implementation of ferror */
  return EOF;
}


void _ttywrch(int ch) {
  sendchar (ch);
}

void _sys_exit(int return_code) {
  while (1);  /* endless loop */
}
#endif
