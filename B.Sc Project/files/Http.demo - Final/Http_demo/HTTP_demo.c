/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    HTTP_DEMO.C
 *      Purpose: HTTP Server demo example
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2009 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/
 
/*----------------------------------------------------------------------------
																 www.ECA.ir
												AT91SAM7X256 Dev Board Rev.A
-----------------------------------------------------------------------------*/

#define LCD_PORT_A         //CHAR LCD pins definition
#define LCD_RS  2
#define LCD_RW  3
#define LCD_E   4
#define LCD_DB4 23
#define LCD_DB5 24
#define LCD_DB6 25
#define LCD_DB7 26

#include <stdio.h>
#include <RTL.h>
#include <Net_Config.h>
#include <AT91SAM7X256.H>                     /* AT91SAM7X256 definitions    */
#include "AT91SAM7X-EK.h"
#include "lcd.h"
#include "delay.h"

/* Clock Definitions */
#define EXT_OSC 18432000                      /*  External Oscillator MAINCK */
#define MCK     47923200                      /*  Master Clock               */
#define BAUD(b) ((MCK + 8*b)/(16*b))
#define TCNT    (MCK/16)/10                   /* Timer Counts for 100ms      */
#define LCD_RATE 20
BOOL LEDrun;
BOOL tick;
U32  dhcp_tout;
BOOL ft;
float ADC_Volt;

extern LOCALM localm[];                       /* Local Machine Settings      */
#define MY_IP localm[NETIF_ETH].IpAdr
// typedef struct localm {           /* << Local Machine info >>                */
//   U8  IpAdr[IP_ADRLEN];           /* Local IP Address                        */
//   U8  DefGW[IP_ADRLEN];           /* Default GateWay                         */
//   U8  NetMask[IP_ADRLEN];         /* Net Mask                                */
//   U8  PriDNS[IP_ADRLEN];          /* Primary DNS Server                      */
//   U8  SecDNS[IP_ADRLEN];          /* Secondary DNS Server                    */
// } LOCALM;

#define DHCP_TOUT   5                        /* DHCP timeout 5 seconds      */

static void init_io (void);

#ifdef RTX_KERNEL
 U64 tcp_stack[800/8];                        /* A bigger stack for tcp_task */

 /* Forward references */
 __task void init       (void);
 __task void blink_led  (void);
 __task void timer_task (void);
 __task void tcp_task   (void);
#endif

/*--------------------------- init ------------------------------------------*/

#ifndef RTX_KERNEL

static void init () {
  /* Add System initialisation code here */

  init_io ();
  init_TcpNet ();
  /* PITC Timer interval timer, reload to 100ms */
  *AT91C_PITC_PIMR = (TCNT - 1) | AT91C_PITC_PITEN;
	//ADC initalization
	*AT91C_ADC_CR = AT91C_ADC_SWRST ;
	*AT91C_ADC_CHER = AT91C_ADC_CH3 ;
	*AT91C_ADC_MR =  AT91C_ADC_SHTIM|AT91C_ADC_STARTUP|AT91C_ADC_PRESCAL
									|AT91C_ADC_SLEEP_NORMAL_MODE
	                |AT91C_ADC_LOWRES_10_BIT|AT91C_ADC_TRGEN_DIS;

}


#endif

/*--------------------------- timer_poll ------------------------------------*/

#ifndef RTX_KERNEL

static void timer_poll () {
  /* System tick timer running in poll mode */
  volatile U32 val;

  if (*AT91C_PITC_PISR & 1) {
    val = *AT91C_PITC_PIVR;
    /* Timer tick every 100 ms */
    timer_tick ();
    tick = __TRUE;
  }
}

#endif


/*--------------------------- init_io ---------------------------------------*/

static void init_io () {
  /* I/O Ports configured as Output. */
  *AT91C_PMC_PCER  = (1 << AT91C_ID_PIOB) |  /* Enable Clock for PIO (LEDs)  */
                     (1 << AT91C_ID_PIOA);   /*                  (Joystick)  */
  *AT91C_PIOA_PER  = 0xf<<19;         /* Enable PIO for LED1..4       */
  *AT91C_PIOA_OER  = 0xf<<19;         /* LED1..4 are Outputs          */
  *AT91C_PIOA_SODR = 0xf<<19;         /* Turn on LED's                */
	
	*AT91C_PIOB_PER  = 0xf<<19;         /* Enable PIO for LED5..8       */
  *AT91C_PIOB_OER  = 0xf<<19;         /* LED5..8 are Outputs          */
  *AT91C_PIOB_SODR = 0xf<<19;         /* Turn off LED's               */
	

  /* Configure DBGU for 115200 baud. */
  *AT91C_PIOA_IDR  =
  *AT91C_PIOA_PPUDR=
  *AT91C_PIOA_ASR  =
  *AT91C_PIOA_PDR  = AT91C_PA27_DRXD | AT91C_PA28_DTXD;

  *AT91C_DBGU_CR   = AT91C_US_RSTRX   | AT91C_US_RSTTX;
  *AT91C_DBGU_IDR  = 0xFFFFFFFF;
  *AT91C_DBGU_BRGR = BAUD(115200);
  *AT91C_DBGU_MR   = AT91C_US_PAR_NONE;
  *AT91C_DBGU_PTCR = AT91C_PDC_RXTDIS | AT91C_PDC_TXTDIS;
  *AT91C_DBGU_CR   = AT91C_US_RXEN    | AT91C_US_TXEN;
}


/*--------------------------- fputc -----------------------------------------*/

int fputc (int ch, FILE *f)  {
  /* Debug output to serial port. */

  if (ch == '\n')  {
    while (!(*AT91C_DBGU_CSR & AT91C_US_TXRDY));
    *AT91C_DBGU_THR = '\r';                 /* output CR                    */
  }
  while (!(*AT91C_DBGU_CSR & AT91C_US_TXRDY));
  *AT91C_DBGU_THR = ch;
  return (ch);
}


/*--------------------------- LED_out ---------------------------------------*/

void LED_out (U32 val) {

  *AT91C_PIOA_CODR = 0xf<<19;
	*AT91C_PIOB_CODR = 0xf<<19;
	
  if (val & 1 ) {
    *AT91C_PIOA_SODR = 1<<19;           /* Turn LED1 On                 */
  }
  if (val & 2) {
    *AT91C_PIOA_SODR = 1<<20;           /* Turn LED2 On                 */
  }
  if (val & 4) {
    *AT91C_PIOA_SODR = 1<<21;           /* Turn LED3 On                 */
  }
  if (val & 8) {
    *AT91C_PIOA_SODR = 1<<22;           /* Turn LED4 On                 */
  }
	if (val & 0x10 ) {
    *AT91C_PIOB_SODR = 1<<19;           /* Turn LED5 On                 */
  }
  if (val & 0x20) {
    *AT91C_PIOB_SODR = 1<<20;           /* Turn LED6 On                 */
  }
  if (val & 0x40) {
    *AT91C_PIOB_SODR = 1<<21;           /* Turn LED7 On                 */
  }
  if (val & 0x80) {
    *AT91C_PIOB_SODR = 1<<22;           /* Turn LED8 On                 */
  }
}


/*--------------------------- get_button ------------------------------------*/

U8 get_button (void) {
  /* Read ARM Digital Input */
  U32 keyA,keyB,val = 0;

  keyB = *AT91C_PIOB_PDSR;
	keyA = *AT91C_PIOA_PDSR;
  if ((keyB & AT91B_SW1) == 0) {
    /* Check if SW1 is pressed */
    val |= 0x01;
  }
  if ((keyB & AT91B_SW2) == 0) {
    /* Check if SW2 is pressed */
    val |= 0x02;
  }
  if ((keyB & AT91B_SW3) == 0) {
    /* Check if SW3 is pressed */
    val |= 0x04;
  }
  if ((keyB & AT91B_SW4) == 0) {
    /* Check if SW4 is pressed */
    val |= 0x08;
  }
  if ((keyB & AT91B_SW5) == 0) {
    /* Check if SW5 is pressed */
    val |= 0x10;
  }
	if ((keyA & AT91B_SW6) == 0) {
    /* Check if SW4 is pressed */
    val |= 0x20;
  }
  if ((keyA & AT91B_SW7) == 0) {
    /* Check if SW5 is pressed */
    val |= 0x40;
  }
  return (val);
}


/*--------------------------- dhcp_check ------------------------------------*/

static void dhcp_check () {
  /* Monitor DHCP IP address assignment. */

  if (tick == __FALSE || dhcp_tout == 0) {
    return;
  }

  if (mem_test (&MY_IP, 0, IP_ADRLEN) == __FALSE) {
    /* Success, DHCP has already got the IP address. */
    dhcp_tout = 0;
    return;
  }
  if (--dhcp_tout == 0) {
    /* A timeout, disable DHCP and use static IP address. */
    dhcp_disable ();
  }
}


/*--------------------------- blink_led -------------------------------------*/

#ifndef RTX_KERNEL

static void blink_led () {
  /* Blink the LEDs on AT91SAM7X board */
  const U8 led_val[16] = { 0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF,
												   0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,0x00};
  static U32 cnt;

  if (tick == __TRUE) {
    /* Every 100 ms */
    tick = __FALSE;
    if (LEDrun == __TRUE) {
      LED_out (led_val[cnt]);
      if (++cnt >= sizeof(led_val)) {
        cnt = 0;
      }
    }
  }
}

#endif

/*-------------------------------- LCD --------------------------------------*/
void LCD (unsigned char code[]) {
	lcd_clear();	
	lcd_gotoxy(1,3);
	lcd_putchar(*(code-1));	
	for(; *code ; )
	{
		lcd_putchar(*code);
		code++;
	}
		
}
float getADC(void){
	return ADC_Volt;
}




/*---------------------------------------------------------------------------*/

#ifndef RTX_KERNEL

int main (void) {
	unsigned int x;
	unsigned int i=0;
	unsigned int d=0;
	unsigned int f;
//	char buf[5];

  /* Main Thread of the TcpNet */
  init ();
  LEDrun = __TRUE;
	ft=__TRUE;
  dhcp_tout = DHCP_TOUT;
	lcd_init();
	LCD ("farshad and k1");

	while (1) {
		i=0;
		d=0;
		*AT91C_ADC_CR = AT91C_ADC_START;
		for (i=0;i<5;i++){
			x=*AT91C_ADC_CDR3 & AT91C_ADC_DATA;
			d=x+d;
		}
		f=d/5;
		ADC_Volt=(f*256)/1024;
    timer_poll ();
    main_TcpNet ();
    dhcp_check ();		
    blink_led ();
		}
}

#endif


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
