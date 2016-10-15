
/*************************************************/
/*         VS1003 Header File                    */
/*         Modified to LPC1768 By :              */
/*         Ramin Jafarpour                       */
/*         ramin.jafarpour@hotmail.com           */ 
/*         www.ECA.ir                            */                                                     
/*************************************************/

#ifndef __VS1003B_H__
#define __VS1003B_H__



	  	 
#define VS1003B_SCK_BIT     6//1 
#define VS1003B_MOSI_BIT    5//3  
#define VS1003B_MISO_BIT    4//5 
#define VS1003B_XCS_BIT     3//0  
#define VS1003B_XDCS_BIT    2//4    													
#define VS1003B_DREQ_BIT    1//7		
#define VS1003B_XRESET_BIT 	0//6		

// -----------------------------																		 
#define DEFAULT_BASS_TREMBLE ((TREMBLE_VALUE<<12)|(TREMBLE_LOW_FS<<8)|(BASS_VALUE<<4)|(BASS_HIGH_FS))
#define	VS_W            2
#define VS_R            3
#define	VS_MODE_AD      0
#define	VS_BASS_AD      2
#define	VS_CLOCK_AD     3
#define	VS_VOL_AD	      11	/*      ADD VOLUME     */
#define VS_AIADDR_AD    10
#define TREMBLE_VALUE	  8		/* 0~15, 8 means off   */
#define TREMBLE_LOW_FS	8		/* 0~15, 0Hz-15KHz, lower frequency of tremble enhancement */
#define BASS_VALUE	    0		/* 0~15, 0 means off   */
#define BASS_HIGH_FS	  8		/* 2~15, up limit frequency of bass enhancement */
#define DEFAULT_VOLUME  0x3333	/* default volumn */
#define CLOCK_REG       0xE000        //SCI CLOCKF = 0xFFD0  SC MULT = 7  SC ADD = 3  SC FREQ = 0x3E8 = 1000 XTALI = 1000*4000+8000000 = 12 MHz                                  
//    CLOCK_REG = 0xAFD0 = 0b101 01 11111010000
//                           \\\ \\ \\\\\\\\\\\
//                           \\\ \\            ----> SC FREQ 00 ~ 10  Clock frequency                   2000 = 11111010000
//                           \\\   ----------------> SC ADD  11 ~ 12  Allowed multiplier addition       2    = 10
//                              -------------------> SC MULT 13 ~ 15  Clock multiplier                  5    = 101

#define VS1003B_XCS_H()	  	*AT91C_PIOB_SODR = 1<<VS1003B_XCS_BIT
#define VS1003B_XCS_L()	  	*AT91C_PIOB_CODR = 1<<VS1003B_XCS_BIT
#define VS1003B_XRESET_H() 	*AT91C_PIOB_SODR = 1<<VS1003B_XRESET_BIT
#define VS1003B_XRESET_L()  *AT91C_PIOB_CODR = 1<<VS1003B_XRESET_BIT
#define VS1003B_XDCS_H()    *AT91C_PIOB_SODR = 1<<VS1003B_XDCS_BIT
#define VS1003B_XDCS_L()    *AT91C_PIOB_CODR = 1<<VS1003B_XDCS_BIT
#define VS1003B_SCK_H()     *AT91C_PIOB_SODR = 1<<VS1003B_SCK_BIT
#define VS1003B_SCK_L()     *AT91C_PIOB_CODR = 1<<VS1003B_SCK_BIT
#define VS1003B_MOSI_H()    *AT91C_PIOB_SODR = 1<<VS1003B_MOSI_BIT
#define VS1003B_MOSI_L()    *AT91C_PIOB_CODR = 1<<VS1003B_MOSI_BIT

#define VS1003B_DREQ_PIN  ((*AT91C_PIOB_PDSR>>VS1003B_DREQ_BIT)&1)//PIN CHEK
#define VS1003B_MISO_PIN  ((*AT91C_PIOB_PDSR>>VS1003B_MISO_BIT)&1)//PIN CHEK


void PORT_INI(){

		//config pins
		*AT91C_PMC_PCER  = 1<<AT91C_ID_PIOA | 1<<AT91C_ID_PIOB ;
		*AT91C_PIOB_PER  = (1<<VS1003B_XRESET_BIT | 1<<VS1003B_XCS_BIT | 1<<VS1003B_XDCS_BIT | 1 <<VS1003B_SCK_BIT  | 1<<VS1003B_MOSI_BIT);
		*AT91C_PIOB_OER  = (1<<VS1003B_XRESET_BIT | 1<<VS1003B_XCS_BIT | 1<<VS1003B_XDCS_BIT | 1 <<VS1003B_SCK_BIT  | 1<<VS1003B_MOSI_BIT);
		*AT91C_PIOB_SODR = (1<<VS1003B_XRESET_BIT | 1<<VS1003B_XCS_BIT | 1<<VS1003B_XDCS_BIT | 1 <<VS1003B_SCK_BIT  | 1<<VS1003B_MOSI_BIT);
	
		//delay_ms(10);
		*AT91C_PIOB_PER  = (1<<VS1003B_MISO_BIT | 1<<VS1003B_DREQ_BIT);
		*AT91C_PIOB_ODR  = (1<<VS1003B_MISO_BIT | 1<<VS1003B_DREQ_BIT);
		//delay_ms(10);
}

unsigned char VS1003B_Init(void);        /* Initialization, include prot and chip config */
void VS1003B_SoftReset(void);                /* Software reset, clear decode time and jump out midi or wma playing*/
void VS1003B_SetVolume(unsigned int vol); /* Set volume */

void VS_WRITE(void);
void VS1003B_WRITE_DATA(unsigned char data, char bitNum);
void BITWAIT_DREQ_HIGH(void);

/****************************************************************************************/
#endif

