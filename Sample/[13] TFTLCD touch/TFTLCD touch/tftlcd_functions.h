/*
    ....::::: In The Name Of GOD :::::....

    TFT LCD (ILI9325-ILI9320 LCD Driver) Functions V2
    By Armin Ghani     2009/12/18 

	Modified By Ramin Jafarpour		2011/12/12
	ramin.jafarpour@hotmail.com
	
	www.ECA.ir
	
		changelog in v1.1 :
			-fix lcd_gotoxy problem (20*30)
			-add tftlcd_fill Function
			-add tftlcd_init_hispeed Function
			
		changelog in v2.0 2012/12/12:
			-add Support to LPC17xx
			-add Support to LPC23xx
			

*/

#ifndef _TFTLCD_FUNCTIONS_H_
#define _TFTLCD_FUNCTIONS_H_

/* LCD Pin Register Definitions */

#ifdef family_lpc17xx 
// LPC17XX Series 

	#ifdef TFTLCD_DATAPORT_0
		#define _TFTLCD_DATAPORT_DIR_ LPC_GPIO0->FIODIR
		#define _TFTLCD_DATAPORT_SET_ LPC_GPIO0->FIOSET	
		#define _TFTLCD_DATAPORT_CLR_ LPC_GPIO0->FIOCLR
		#define _TFTLCD_DATAPORT_PIN_ LPC_GPIO0->FIOPIN
	#elif defined TFTLCD_DATAPORT_1
		#define _TFTLCD_DATAPORT_DIR_ LPC_GPIO1->FIODIR
		#define _TFTLCD_DATAPORT_SET_ LPC_GPIO1->FIOSET	
		#define _TFTLCD_DATAPORT_CLR_ LPC_GPIO1->FIOCLR
		#define _TFTLCD_DATAPORT_PIN_ LPC_GPIO1->FIOPIN
	#elif defined TFTLCD_DATAPORT_2
		#define _TFTLCD_DATAPORT_DIR_ LPC_GPIO2->FIODIR
		#define _TFTLCD_DATAPORT_SET_ LPC_GPIO2->FIOSET	
		#define _TFTLCD_DATAPORT_CLR_ LPC_GPIO2->FIOCLR
		#define _TFTLCD_DATAPORT_PIN_ LPC_GPIO2->FIOPIN
	#elif defined TFTLCD_DATAPORT_3
		#define _TFTLCD_DATAPORT_DIR_ LPC_GPIO3->FIODIR
		#define _TFTLCD_DATAPORT_SET_ LPC_GPIO3->FIOSET	
		#define _TFTLCD_DATAPORT_CLR_ LPC_GPIO3->FIOCLR
		#define _TFTLCD_DATAPORT_PIN_ LPC_GPIO3->FIOPIN
	#else 
		# error  Please Define DATAPORT
	#endif	

	#ifdef TFTLCD_CONTROLPORT_0
		#define _TFTLCD_CONTROLPORT_DIR_ LPC_GPIO0->FIODIR	
		#define _TFTLCD_CONTROLPORT_SET_ LPC_GPIO0->FIOSET	
		#define _TFTLCD_CONTROLPORT_CLR_ LPC_GPIO0->FIOCLR
	#elif defined TFTLCD_CONTROLPORT_1
		#define _TFTLCD_CONTROLPORT_DIR_ LPC_GPIO1->FIODIR	
		#define _TFTLCD_CONTROLPORT_SET_ LPC_GPIO1->FIOSET	
		#define _TFTLCD_CONTROLPORT_CLR_ LPC_GPIO1->FIOCLR
	#elif defined TFTLCD_CONTROLPORT_2
		#define _TFTLCD_CONTROLPORT_DIR_ LPC_GPIO2->FIODIR	
		#define _TFTLCD_CONTROLPORT_SET_ LPC_GPIO2->FIOSET	
		#define _TFTLCD_CONTROLPORT_CLR_ LPC_GPIO2->FIOCLR
	#elif defined TFTLCD_CONTROLPORT_3
		#define _TFTLCD_CONTROLPORT_DIR_ LPC_GPIO3->FIODIR	
		#define _TFTLCD_CONTROLPORT_SET_ LPC_GPIO3->FIOSET	
		#define _TFTLCD_CONTROLPORT_CLR_ LPC_GPIO3->FIOCLR
	#else 
		# error  Please Define CONTROLPORT
	#endif
	
	#define TFTLCD_RST_LOW                 _TFTLCD_CONTROLPORT_CLR_ = (1 << TFTLCD_RST)
	#define TFTLCD_RST_HIGH                _TFTLCD_CONTROLPORT_SET_ = (1 << TFTLCD_RST)
	#define TFTLCD_RS_LOW                  _TFTLCD_CONTROLPORT_CLR_ = (1 << TFTLCD_RS)
	#define TFTLCD_RS_HIGH                 _TFTLCD_CONTROLPORT_SET_ = (1 << TFTLCD_RS)
	#define TFTLCD_CS_LOW                  _TFTLCD_CONTROLPORT_CLR_ = (1 << TFTLCD_CS)
	#define TFTLCD_CS_HIGH                 _TFTLCD_CONTROLPORT_SET_ = (1 << TFTLCD_CS)			
	#define TFTLCD_RD_LOW                  _TFTLCD_CONTROLPORT_CLR_ = (1 << TFTLCD_RD)
	#define TFTLCD_RD_HIGH                 _TFTLCD_CONTROLPORT_SET_ = (1 << TFTLCD_RD)
	#define TFTLCD_WR_LOW                  _TFTLCD_CONTROLPORT_CLR_ = (1 << TFTLCD_WR)
	#define TFTLCD_WR_HIGH                 _TFTLCD_CONTROLPORT_SET_ = (1 << TFTLCD_WR)    
	#define TFTLCD_DATAPORT_INPUT		   _TFTLCD_DATAPORT_DIR_ &= (~(0xFFFF << TFTLCD_DATAPORT_OFFSET))
	#define TFTLCD_DATAPORT_OUTPUT         _TFTLCD_DATAPORT_DIR_ |= (0xFFFF << TFTLCD_DATAPORT_OFFSET)                     
	#define TFTLCD_DATAPORT_CLEAR          _TFTLCD_DATAPORT_CLR_ = (0xFFFF << TFTLCD_DATAPORT_OFFSET)

#elif defined family_lpc23xx
// LPC23XX Series 
	#ifdef TFTLCD_DATAPORT_0
		#define _TFTLCD_DATAPORT_DIR_ FIO0DIR
		#define _TFTLCD_DATAPORT_SET_ FIO0SET	
		#define _TFTLCD_DATAPORT_CLR_ FIO0CLR
		#define _TFTLCD_DATAPORT_PIN_ FIO0PIN
	#elif defined TFTLCD_DATAPORT_1
		#define _TFTLCD_DATAPORT_DIR_ FIO1DIR
		#define _TFTLCD_DATAPORT_SET_ FIO1SET	
		#define _TFTLCD_DATAPORT_CLR_ FIO1CLR
		#define _TFTLCD_DATAPORT_PIN_ FIO1PIN
	#elif defined TFTLCD_DATAPORT_2
		#define _TFTLCD_DATAPORT_DIR_ FIO2DIR
		#define _TFTLCD_DATAPORT_SET_ FIO2SET	
		#define _TFTLCD_DATAPORT_CLR_ FIO2CLR
		#define _TFTLCD_DATAPORT_PIN_ FIO2PIN
	#elif defined TFTLCD_DATAPORT_3
		#define _TFTLCD_DATAPORT_DIR_ FIO3DIR
		#define _TFTLCD_DATAPORT_SET_ FIO3SET
		#define _TFTLCD_DATAPORT_CLR_ FIO3CLR
		#define _TFTLCD_DATAPORT_PIN_ FIO3PIN
	#else 
		# error  Please Define DATAPORT
	#endif	

	#ifdef TFTLCD_CONTROLPORT_0
		#define _TFTLCD_CONTROLPORT_DIR_ FIO0DIR	
		#define _TFTLCD_CONTROLPORT_SET_ FIO0SET	
		#define _TFTLCD_CONTROLPORT_CLR_ FIO0CLR
	#elif defined TFTLCD_CONTROLPORT_1
		#define _TFTLCD_CONTROLPORT_DIR_ FIO1DIR	
		#define _TFTLCD_CONTROLPORT_SET_ FIO1SET	
		#define _TFTLCD_CONTROLPORT_CLR_ FIO1CLR
	#elif defined TFTLCD_CONTROLPORT_2
		#define _TFTLCD_CONTROLPORT_DIR_ FIO2DIR	
		#define _TFTLCD_CONTROLPORT_SET_ FIO2SET
		#define _TFTLCD_CONTROLPORT_CLR_ FIO2CLR
	#elif defined TFTLCD_CONTROLPORT_3
		#define _TFTLCD_CONTROLPORT_DIR_ FIO3DIR	
		#define _TFTLCD_CONTROLPORT_SET_ FIO3SET	
		#define _TFTLCD_CONTROLPORT_CLR_ FIO3CLR
	#else 
		# error  Please Define CONTROLPORT
	#endif
	
	#define TFTLCD_RST_LOW                 _TFTLCD_CONTROLPORT_CLR_ = (1 << TFTLCD_RST)
	#define TFTLCD_RST_HIGH                _TFTLCD_CONTROLPORT_SET_ = (1 << TFTLCD_RST)
	#define TFTLCD_RS_LOW                  _TFTLCD_CONTROLPORT_CLR_ = (1 << TFTLCD_RS)
	#define TFTLCD_RS_HIGH                 _TFTLCD_CONTROLPORT_SET_ = (1 << TFTLCD_RS)
	#define TFTLCD_CS_LOW                  _TFTLCD_CONTROLPORT_CLR_ = (1 << TFTLCD_CS)
	#define TFTLCD_CS_HIGH                 _TFTLCD_CONTROLPORT_SET_ = (1 << TFTLCD_CS)			
	#define TFTLCD_RD_LOW                  _TFTLCD_CONTROLPORT_CLR_ = (1 << TFTLCD_RD)
	#define TFTLCD_RD_HIGH                 _TFTLCD_CONTROLPORT_SET_ = (1 << TFTLCD_RD)
	#define TFTLCD_WR_LOW                  _TFTLCD_CONTROLPORT_CLR_ = (1 << TFTLCD_WR)
	#define TFTLCD_WR_HIGH                 _TFTLCD_CONTROLPORT_SET_ = (1 << TFTLCD_WR)    
	#define TFTLCD_DATAPORT_INPUT		   _TFTLCD_DATAPORT_DIR_ &= (~(0xFFFF << TFTLCD_DATAPORT_OFFSET))
	#define TFTLCD_DATAPORT_OUTPUT         _TFTLCD_DATAPORT_DIR_ |= (0xFFFF << TFTLCD_DATAPORT_OFFSET)                     
	#define TFTLCD_DATAPORT_CLEAR          _TFTLCD_DATAPORT_CLR_ = (0xFFFF << TFTLCD_DATAPORT_OFFSET)


#elif defined family_sam7x
// SAM7 Series 
#ifdef TFTLCD_DATAPORT_A
	#define _TFTLCD_DATAPORT_ID_	   AT91C_ID_PIOA
	#define _TFTLCD_DATAPORT_PER_	   *AT91C_PIOA_PER
	#define _TFTLCD_DATAPORT_PDR_	   *AT91C_PIOA_PDR
	#define _TFTLCD_DATAPORT_OER_	   *AT91C_PIOA_OER
	#define _TFTLCD_DATAPORT_ODR_	   *AT91C_PIOA_ODR
	#define _TFTLCD_DATAPORT_PUER_	   *AT91C_PIOA_PPUER
	#define _TFTLCD_DATAPORT_PUDR_	   *AT91C_PIOA_PPUDR
	#define _TFTLCD_DATAPORT_PDSR_	   *AT91C_PIOA_PDSR
	#define _TFTLCD_DATAPORT_SODR_	   *AT91C_PIOA_SODR
	#define _TFTLCD_DATAPORT_CODR_	   *AT91C_PIOA_CODR
#endif
#ifdef TFTLCD_DATAPORT_B
	#define _TFTLCD_DATAPORT_ID_	   AT91C_ID_PIOB
	#define _TFTLCD_DATAPORT_PER_	   *AT91C_PIOB_PER
	#define _TFTLCD_DATAPORT_PDR_	   *AT91C_PIOB_PDR
	#define _TFTLCD_DATAPORT_OER_	   *AT91C_PIOB_OER
	#define _TFTLCD_DATAPORT_ODR_	   *AT91C_PIOB_ODR
	#define _TFTLCD_DATAPORT_PUER_	   *AT91C_PIOB_PPUER
	#define _TFTLCD_DATAPORT_PUDR_	   *AT91C_PIOB_PPUDR
	#define _TFTLCD_DATAPORT_PDSR_	   *AT91C_PIOB_PDSR
	#define _TFTLCD_DATAPORT_SODR_	   *AT91C_PIOB_SODR
	#define _TFTLCD_DATAPORT_CODR_	   *AT91C_PIOB_CODR
#endif

#ifdef TFTLCD_CONTROLPORT_A
	#define _TFTLCD_CONTROLPORT_ID_	       AT91C_ID_PIOA
	#define _TFTLCD_CONTROLPORT_PER_	   *AT91C_PIOA_PER
	#define _TFTLCD_CONTROLPORT_PDR_	   *AT91C_PIOA_PDR
	#define _TFTLCD_CONTROLPORT_OER_	   *AT91C_PIOA_OER
	#define _TFTLCD_CONTROLPORT_ODR_	   *AT91C_PIOA_ODR
	#define _TFTLCD_CONTROLPORT_PUER_	   *AT91C_PIOA_PPUER
	#define _TFTLCD_CONTROLPORT_PUDR_	   *AT91C_PIOA_PPUDR
	#define _TFTLCD_CONTROLPORT_SODR_	   *AT91C_PIOA_SODR
	#define _TFTLCD_CONTROLPORT_CODR_	   *AT91C_PIOA_CODR
#endif
#ifdef TFTLCD_CONTROLPORT_B
	#define _TFTLCD_CONTROLPORT_ID_	       AT91C_ID_PIOB
	#define _TFTLCD_CONTROLPORT_PER_	   *AT91C_PIOB_PER
	#define _TFTLCD_CONTROLPORT_PDR_	   *AT91C_PIOB_PDR
	#define _TFTLCD_CONTROLPORT_OER_	   *AT91C_PIOB_OER
	#define _TFTLCD_CONTROLPORT_ODR_	   *AT91C_PIOB_ODR
	#define _TFTLCD_CONTROLPORT_PUER_	   *AT91C_PIOB_PPUER
	#define _TFTLCD_CONTROLPORT_PUDR_	   *AT91C_PIOB_PPUDR
	#define _TFTLCD_CONTROLPORT_SODR_	   *AT91C_PIOB_SODR
	#define _TFTLCD_CONTROLPORT_CODR_	   *AT91C_PIOB_CODR
#endif

#define TFTLCD_RST_LOW                 _TFTLCD_CONTROLPORT_CODR_ = (1 << TFTLCD_RST)
#define TFTLCD_RST_HIGH                _TFTLCD_CONTROLPORT_SODR_ = (1 << TFTLCD_RST)
#define TFTLCD_RS_LOW                  _TFTLCD_CONTROLPORT_CODR_ = (1 << TFTLCD_RS)
#define TFTLCD_RS_HIGH                 _TFTLCD_CONTROLPORT_SODR_ = (1 << TFTLCD_RS)
#define TFTLCD_CS_LOW                  _TFTLCD_CONTROLPORT_CODR_ = (1 << TFTLCD_CS)
#define TFTLCD_CS_HIGH                 _TFTLCD_CONTROLPORT_SODR_ = (1 << TFTLCD_CS)			
#define TFTLCD_RD_LOW                  _TFTLCD_CONTROLPORT_CODR_ = (1 << TFTLCD_RD)
#define TFTLCD_RD_HIGH                 _TFTLCD_CONTROLPORT_SODR_ = (1 << TFTLCD_RD)
#define TFTLCD_WR_LOW                  _TFTLCD_CONTROLPORT_CODR_ = (1 << TFTLCD_WR)
#define TFTLCD_WR_HIGH                 _TFTLCD_CONTROLPORT_SODR_ = (1 << TFTLCD_WR)    
#define TFTLCD_DATAPORT_INPUT		   _TFTLCD_DATAPORT_ODR_ = (0xFFFF << TFTLCD_DATAPORT_OFFSET)
#define TFTLCD_DATAPORT_OUTPUT         _TFTLCD_DATAPORT_OER_ = (0xFFFF << TFTLCD_DATAPORT_OFFSET)                      
#define TFTLCD_DATAPORT_CLEAR          _TFTLCD_DATAPORT_CODR_ = (0xFFFF << TFTLCD_DATAPORT_OFFSET)

#endif

/* LCD Command Codes */
#define TS_INS_START_OSC            0x00
#define TS_INS_DRIV_OUT_CTRL        0x01
#define TS_INS_DRIV_WAV_CTRL        0x02
#define TS_INS_ENTRY_MOD            0x03
#define TS_INS_RESIZE_CTRL          0x04
#define TS_INS_DISP_CTRL1           0x07
#define TS_INS_DISP_CTRL2           0x08
#define TS_INS_DISP_CTRL3           0x09
#define TS_INS_DISP_CTRL4           0x0A
#define TS_INS_RGB_DISP_IF_CTRL1    0x0C
#define TS_INS_FRM_MARKER_POS       0x0D
#define TS_INS_RGB_DISP_IF_CTRL2    0x0F
#define TS_INS_POW_CTRL1            0x10
#define TS_INS_POW_CTRL2            0x11
#define TS_INS_POW_CTRL3            0x12
#define TS_INS_POW_CTRL4            0x13
#define TS_INS_GRAM_HOR_AD          0x20
#define TS_INS_GRAM_VER_AD          0x21
#define TS_INS_RW_GRAM              0x22
#define TS_INS_POW_CTRL7            0x29
#define TS_INS_FRM_RATE_COL_CTRL    0x2B
#define TS_INS_GAMMA_CTRL1          0x30
#define TS_INS_GAMMA_CTRL2          0x31
#define TS_INS_GAMMA_CTRL3          0x32
#define TS_INS_GAMMA_CTRL4          0x35 
#define TS_INS_GAMMA_CTRL5          0x36
#define TS_INS_GAMMA_CTRL6          0x37
#define TS_INS_GAMMA_CTRL7          0x38
#define TS_INS_GAMMA_CTRL8          0x39
#define TS_INS_GAMMA_CTRL9          0x3C
#define TS_INS_GAMMA_CTRL10         0x3D
#define TS_INS_HOR_START_AD         0x50
#define TS_INS_HOR_END_AD           0x51
#define TS_INS_VER_START_AD         0x52
#define TS_INS_VER_END_AD           0x53
#define TS_INS_GATE_SCAN_CTRL1      0x60
#define TS_INS_GATE_SCAN_CTRL2      0x61
#define TS_INS_GATE_SCAN_CTRL3      0x6A
#define TS_INS_PART_IMG1_DISP_POS   0x80
#define TS_INS_PART_IMG1_START_AD   0x81
#define TS_INS_PART_IMG1_END_AD     0x82
#define TS_INS_PART_IMG2_DISP_POS   0x83
#define TS_INS_PART_IMG2_START_AD   0x84
#define TS_INS_PART_IMG2_END_AD     0x85
#define TS_INS_PANEL_IF_CTRL1       0x90
#define TS_INS_PANEL_IF_CTRL2       0x92
#define TS_INS_PANEL_IF_CTRL3       0x93
#define TS_INS_PANEL_IF_CTRL4       0x95
#define TS_INS_PANEL_IF_CTRL5       0x97
#define TS_INS_PANEL_IF_CTRL6       0x98           

#ifdef PORTRAIT
#define TS_SIZE_X                   240
#define TS_SIZE_Y                   320
#define TS_VAL_ENTRY_MOD            0x0030
#define TS_INS_GRAM_ADX             TS_INS_GRAM_HOR_AD
#define TS_INS_GRAM_ADY             TS_INS_GRAM_VER_AD
#define TS_INS_START_ADX            TS_INS_HOR_START_AD
#define TS_INS_END_ADX              TS_INS_HOR_END_AD
#define TS_INS_START_ADY            TS_INS_VER_START_AD
#define TS_INS_END_ADY              TS_INS_VER_END_AD
#endif

#ifdef LANDSCAPE
#define TS_SIZE_X					320
#define TS_SIZE_Y					240
#define TS_VAL_ENTRY_MOD			0x0028
#define TS_INS_GRAM_ADX				TS_INS_GRAM_VER_AD
#define TS_INS_GRAM_ADY				TS_INS_GRAM_HOR_AD
#define TS_INS_START_ADX   			TS_INS_VER_START_AD
#define TS_INS_END_ADX   			TS_INS_VER_END_AD
#define TS_INS_START_ADY   			TS_INS_HOR_START_AD
#define TS_INS_END_ADY   			TS_INS_HOR_END_AD
#endif

#define RED                         0x001F
#define GREEN                       0x07E0
#define BLUE                        0xF800
#define YELLOW                      0x07FF
#define PURPLE                      0xF81F
#define BLACK                       0x0000
#define WHITE                       0xFFFF

#define HIGH 1
#define LOW  0

void tftlcd_write_index_register(int);
void tftlcd_write_wdr(int);
int tftlcd_read_rdr(void);
void tftlcd_write_command(int,int);
void tftlcd_clear(void);
void tftlcd_init(void);
void tftlcd_write_pixel(int,int,int);
int tftlcd_read_pixel(int,int);
void tftlcd_draw_line(int,int,int,int,int);
void tftlcd_draw_rectangle(int,int,int,int,char,int);
void tftlcd_draw_circle(int,int,int,char,int); 
void tftlcd_write_pic(int,int,const unsigned short *);
void tftlcd_gotoxy(int,int);
void tftlcd_putchar(char,int,int,int);
void tftlcd_putsf(const char *,int,int,int);
void tftlcd_puts(char *,int,int,int);
void tftlcd_fill(int color);
void tftlcd_init_hispeed(int,int,int,int);


#endif




/* Global Variables */
int x_text=0,y_text=0;
const char font8x16[97][16]=
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // space 0x20
0x00,0x00,0x18,0x3C,0x3C,0x3C,0x18,0x18,0x18,0x00,0x18,0x18,0x00,0x00,0x00,0x00, // !
0x00,0x63,0x63,0x63,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // "
0x00,0x00,0x00,0x36,0x36,0x7F,0x36,0x36,0x36,0x7F,0x36,0x36,0x00,0x00,0x00,0x00, // #
0x0C,0x0C,0x3E,0x63,0x61,0x60,0x3E,0x03,0x03,0x43,0x63,0x3E,0x0C,0x0C,0x00,0x00, // $
0x00,0x00,0x00,0x00,0x00,0x61,0x63,0x06,0x0C,0x18,0x33,0x63,0x00,0x00,0x00,0x00, // %
0x00,0x00,0x00,0x1C,0x36,0x36,0x1C,0x3B,0x6E,0x66,0x66,0x3B,0x00,0x00,0x00,0x00, // &
0x00,0x30,0x30,0x30,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // '
0x00,0x00,0x0C,0x18,0x18,0x30,0x30,0x30,0x30,0x18,0x18,0x0C,0x00,0x00,0x00,0x00, // (
0x00,0x00,0x18,0x0C,0x0C,0x06,0x06,0x06,0x06,0x0C,0x0C,0x18,0x00,0x00,0x00,0x00, // )
0x00,0x00,0x00,0x00,0x42,0x66,0x3C,0xFF,0x3C,0x66,0x42,0x00,0x00,0x00,0x00,0x00, // *
0x00,0x00,0x00,0x00,0x18,0x18,0x18,0xFF,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0x00, // +
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x30,0x00,0x00, // ,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // -
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00, // .
0x00,0x00,0x01,0x03,0x07,0x0E,0x1C,0x38,0x70,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00, // / (forward slash)
0x00,0x00,0x3E,0x63,0x63,0x63,0x6B,0x6B,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00, // 0 0x30
0x00,0x00,0x0C,0x1C,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3F,0x00,0x00,0x00,0x00, // 1
0x00,0x00,0x3E,0x63,0x03,0x06,0x0C,0x18,0x30,0x61,0x63,0x7F,0x00,0x00,0x00,0x00, // 2
0x00,0x00,0x3E,0x63,0x03,0x03,0x1E,0x03,0x03,0x03,0x63,0x3E,0x00,0x00,0x00,0x00, // 3
0x00,0x00,0x06,0x0E,0x1E,0x36,0x66,0x66,0x7F,0x06,0x06,0x0F,0x00,0x00,0x00,0x00, // 4
0x00,0x00,0x7F,0x60,0x60,0x60,0x7E,0x03,0x03,0x63,0x73,0x3E,0x00,0x00,0x00,0x00, // 5
0x00,0x00,0x1C,0x30,0x60,0x60,0x7E,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00, // 6
0x00,0x00,0x7F,0x63,0x03,0x06,0x06,0x0C,0x0C,0x18,0x18,0x18,0x00,0x00,0x00,0x00, // 7
0x00,0x00,0x3E,0x63,0x63,0x63,0x3E,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00, // 8
0x00,0x00,0x3E,0x63,0x63,0x63,0x63,0x3F,0x03,0x03,0x06,0x3C,0x00,0x00,0x00,0x00, // 9
0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00, // :
0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x18,0x18,0x18,0x30,0x00,0x00, // ;
0x00,0x00,0x00,0x06,0x0C,0x18,0x30,0x60,0x30,0x18,0x0C,0x06,0x00,0x00,0x00,0x00, // <
0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00, // =
0x00,0x00,0x00,0x60,0x30,0x18,0x0C,0x06,0x0C,0x18,0x30,0x60,0x00,0x00,0x00,0x00, // >
0x00,0x00,0x3E,0x63,0x63,0x06,0x0C,0x0C,0x0C,0x00,0x0C,0x0C,0x00,0x00,0x00,0x00, // ?
0x00,0x00,0x3E,0x63,0x63,0x6F,0x6B,0x6B,0x6E,0x60,0x60,0x3E,0x00,0x00,0x00,0x00, // @ 0x40
0x00,0x00,0x08,0x1C,0x36,0x63,0x63,0x63,0x7F,0x63,0x63,0x63,0x00,0x00,0x00,0x00, // A
0x00,0x00,0x7E,0x33,0x33,0x33,0x3E,0x33,0x33,0x33,0x33,0x7E,0x00,0x00,0x00,0x00, // B
0x00,0x00,0x1E,0x33,0x61,0x60,0x60,0x60,0x60,0x61,0x33,0x1E,0x00,0x00,0x00,0x00, // C
0x00,0x00,0x7C,0x36,0x33,0x33,0x33,0x33,0x33,0x33,0x36,0x7C,0x00,0x00,0x00,0x00, // D
0x00,0x00,0x7F,0x33,0x31,0x34,0x3C,0x34,0x30,0x31,0x33,0x7F,0x00,0x00,0x00,0x00, // E
0x00,0x00,0x7F,0x33,0x31,0x34,0x3C,0x34,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00, // F
0x00,0x00,0x1E,0x33,0x61,0x60,0x60,0x6F,0x63,0x63,0x37,0x1D,0x00,0x00,0x00,0x00, // G
0x00,0x00,0x63,0x63,0x63,0x63,0x7F,0x63,0x63,0x63,0x63,0x63,0x00,0x00,0x00,0x00, // H
0x00,0x00,0x3C,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00, // I
0x00,0x00,0x0F,0x06,0x06,0x06,0x06,0x06,0x06,0x66,0x66,0x3C,0x00,0x00,0x00,0x00, // J
0x00,0x00,0x73,0x33,0x36,0x36,0x3C,0x36,0x36,0x33,0x33,0x73,0x00,0x00,0x00,0x00, // K
0x00,0x00,0x78,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x33,0x7F,0x00,0x00,0x00,0x00, // L
0x00,0x00,0x63,0x77,0x7F,0x6B,0x63,0x63,0x63,0x63,0x63,0x63,0x00,0x00,0x00,0x00, // M
0x00,0x00,0x63,0x63,0x73,0x7B,0x7F,0x6F,0x67,0x63,0x63,0x63,0x00,0x00,0x00,0x00, // N
0x00,0x00,0x1C,0x36,0x63,0x63,0x63,0x63,0x63,0x63,0x36,0x1C,0x00,0x00,0x00,0x00, // O
0x00,0x00,0x7E,0x33,0x33,0x33,0x3E,0x30,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00, // P 0x50
0x00,0x00,0x3E,0x63,0x63,0x63,0x63,0x63,0x63,0x6B,0x6F,0x3E,0x06,0x07,0x00,0x00, // Q
0x00,0x00,0x7E,0x33,0x33,0x33,0x3E,0x36,0x36,0x33,0x33,0x73,0x00,0x00,0x00,0x00, // R
0x00,0x00,0x3E,0x63,0x63,0x30,0x1C,0x06,0x03,0x63,0x63,0x3E,0x00,0x00,0x00,0x00, // S
0x00,0x00,0xFF,0xDB,0x99,0x18,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00, // T
0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00, // U
0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x36,0x1C,0x08,0x00,0x00,0x00,0x00, // V
0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x6B,0x6B,0x7F,0x36,0x36,0x00,0x00,0x00,0x00, // W
0x00,0x00,0xC3,0xC3,0x66,0x3C,0x18,0x18,0x3C,0x66,0xC3,0xC3,0x00,0x00,0x00,0x00, // X
0x00,0x00,0xC3,0xC3,0xC3,0x66,0x3C,0x18,0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00, // Y
0x00,0x00,0x7F,0x63,0x43,0x06,0x0C,0x18,0x30,0x61,0x63,0x7F,0x00,0x00,0x00,0x00, // Z
0x00,0x00,0x3C,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x3C,0x00,0x00,0x00,0x00, // [
0x00,0x00,0x80,0xC0,0xE0,0x70,0x38,0x1C,0x0E,0x07,0x03,0x01,0x00,0x00,0x00,0x00, // \ (back slash)
0x00,0x00,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00,0x00,0x00,0x00, // ]
0x08,0x1C,0x36,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ^
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00, // _
0x18,0x18,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ` 0x60
0x00,0x00,0x00,0x00,0x00,0x3C,0x46,0x06,0x3E,0x66,0x66,0x3B,0x00,0x00,0x00,0x00, // a
0x00,0x00,0x70,0x30,0x30,0x3C,0x36,0x33,0x33,0x33,0x33,0x6E,0x00,0x00,0x00,0x00, // b
0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x60,0x60,0x60,0x63,0x3E,0x00,0x00,0x00,0x00, // c
0x00,0x00,0x0E,0x06,0x06,0x1E,0x36,0x66,0x66,0x66,0x66,0x3B,0x00,0x00,0x00,0x00, // d
0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x63,0x7E,0x60,0x63,0x3E,0x00,0x00,0x00,0x00, // e
0x00,0x00,0x1C,0x36,0x32,0x30,0x7C,0x30,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00, // f
0x00,0x00,0x00,0x00,0x00,0x3B,0x66,0x66,0x66,0x66,0x3E,0x06,0x66,0x3C,0x00,0x00, // g
0x00,0x00,0x70,0x30,0x30,0x36,0x3B,0x33,0x33,0x33,0x33,0x73,0x00,0x00,0x00,0x00, // h
0x00,0x00,0x0C,0x0C,0x00,0x1C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1E,0x00,0x00,0x00,0x00, // i
0x00,0x00,0x06,0x06,0x00,0x0E,0x06,0x06,0x06,0x06,0x06,0x66,0x66,0x3C,0x00,0x00, // j
0x00,0x00,0x70,0x30,0x30,0x33,0x33,0x36,0x3C,0x36,0x33,0x73,0x00,0x00,0x00,0x00, // k
0x00,0x00,0x1C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1E,0x00,0x00,0x00,0x00, // l
0x00,0x00,0x00,0x00,0x00,0x6E,0x7F,0x6B,0x6B,0x6B,0x6B,0x6B,0x00,0x00,0x00,0x00, // m
0x00,0x00,0x00,0x00,0x00,0x6E,0x33,0x33,0x33,0x33,0x33,0x33,0x00,0x00,0x00,0x00, // n
0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00, // o
0x00,0x00,0x00,0x00,0x00,0x6E,0x33,0x33,0x33,0x33,0x3E,0x30,0x30,0x78,0x00,0x00, // p 0x70
0x00,0x00,0x00,0x00,0x00,0x3B,0x66,0x66,0x66,0x66,0x3E,0x06,0x06,0x0F,0x00,0x00, // q
0x00,0x00,0x00,0x00,0x00,0x6E,0x3B,0x33,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00, // r
0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x38,0x0E,0x03,0x63,0x3E,0x00,0x00,0x00,0x00, // s
0x00,0x00,0x08,0x18,0x18,0x7E,0x18,0x18,0x18,0x18,0x1B,0x0E,0x00,0x00,0x00,0x00, // t
0x00,0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x3B,0x00,0x00,0x00,0x00, // u
0x00,0x00,0x00,0x00,0x00,0x63,0x63,0x36,0x36,0x1C,0x1C,0x08,0x00,0x00,0x00,0x00, // v
0x00,0x00,0x00,0x00,0x00,0x63,0x63,0x63,0x6B,0x6B,0x7F,0x36,0x00,0x00,0x00,0x00, // w
0x00,0x00,0x00,0x00,0x00,0x63,0x36,0x1C,0x1C,0x1C,0x36,0x63,0x00,0x00,0x00,0x00, // x
0x00,0x00,0x00,0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x3F,0x03,0x06,0x3C,0x00,0x00, // y
0x00,0x00,0x00,0x00,0x00,0x7F,0x66,0x0C,0x18,0x30,0x63,0x7F,0x00,0x00,0x00,0x00, // z
0x00,0x00,0x0E,0x18,0x18,0x18,0x70,0x18,0x18,0x18,0x18,0x0E,0x00,0x00,0x00,0x00, // {
0x00,0x00,0x18,0x18,0x18,0x18,0x18,0x00,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00, // |
0x00,0x00,0x70,0x18,0x18,0x18,0x0E,0x18,0x18,0x18,0x18,0x70,0x00,0x00,0x00,0x00, // }
0x00,0x00,0x3B,0x6E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ~
0x00,0x70,0xD8,0xD8,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00  // DEL
};

#if ( defined family_lpc17xx | defined family_lpc23xx |defined family_sam7x )
__asm void wait()
{
    nop
    BX lr
}
#endif


void wait_ms(int count)
{
unsigned long counter = count ;
#ifdef family_lpc23xx
	counter *= 7200;
#elif defined family_lpc17xx
	counter *= 10000;
#elif defined family_sam7x
	counter *= 5000;
#endif

	while(counter--);
}

void wait_delay(int count)
{
	while(count--);
}

/* LCD functions: */ 
//-----------------------------------------------------------------------
// Write Into The Index Register Of LCD
//-----------------------------------------------------------------------
void tftlcd_write_index_register(int command)
	{
	TFTLCD_RS_LOW;
	TFTLCD_DATAPORT_CLEAR;

#if ( defined family_lpc17xx || defined family_lpc23xx )
	_TFTLCD_DATAPORT_SET_ = (command << TFTLCD_DATAPORT_OFFSET);
	wait();
	TFTLCD_CS_LOW;
	wait();	

#elif defined family_sam7x
	_TFTLCD_DATAPORT_SODR_ = (command << TFTLCD_DATAPORT_OFFSET);
	TFTLCD_CS_LOW;

#endif

	TFTLCD_CS_HIGH;
	TFTLCD_DATAPORT_CLEAR;
	TFTLCD_RS_HIGH;
	}

//-----------------------------------------------------------------------
// Write Into The WDR Register
//-----------------------------------------------------------------------
void tftlcd_write_wdr(int data)
	{ 
#if ( defined family_lpc17xx || defined family_lpc23xx )
	_TFTLCD_DATAPORT_SET_ = (data << TFTLCD_DATAPORT_OFFSET);
	TFTLCD_CS_LOW;
	wait();
    TFTLCD_CS_HIGH;
	wait();

#elif defined family_sam7x 
	_TFTLCD_DATAPORT_SODR_ = (data << TFTLCD_DATAPORT_OFFSET);
	TFTLCD_CS_LOW;
    TFTLCD_CS_HIGH;

#endif

	}

//-----------------------------------------------------------------------
// Read RDR LCD Register
//-----------------------------------------------------------------------
int tftlcd_read_rdr(void)
	{		  
	int rdr_data;
	TFTLCD_DATAPORT_INPUT;
	TFTLCD_RD_LOW;
	TFTLCD_WR_HIGH;
	TFTLCD_CS_LOW;
	wait_delay(50);
#if ( defined family_lpc17xx || defined family_lpc23xx )
	rdr_data = (_TFTLCD_DATAPORT_PIN_ & (0xFFFF << TFTLCD_DATAPORT_OFFSET));

#elif defined family_sam7x 
	rdr_data = (_TFTLCD_DATAPORT_PDSR_ & (0xFFFF << TFTLCD_DATAPORT_OFFSET));

#endif
	TFTLCD_CS_HIGH;
	TFTLCD_RD_HIGH;
	TFTLCD_WR_LOW;
    TFTLCD_DATAPORT_OUTPUT;
	return rdr_data;
	}

//-----------------------------------------------------------------------
// Send A Command 
//-----------------------------------------------------------------------
void tftlcd_write_command(int index,int argument)
	{
	tftlcd_write_index_register(index);
	wait();
	tftlcd_write_wdr(argument);
	}

//-----------------------------------------------------------------------
// Clear The LCD Screen
//-----------------------------------------------------------------------
void tftlcd_clear(void)
{
	tftlcd_fill(0xFFFFFF);	

}

void tftlcd_fill(int color)
{
	int counter;

  	#ifdef PORTRAIT
    tftlcd_write_index_register(TS_INS_START_ADX);
    tftlcd_write_wdr(0);
    tftlcd_write_index_register(TS_INS_END_ADX);
    tftlcd_write_wdr(239);
    tftlcd_write_index_register(TS_INS_GRAM_ADX);
    tftlcd_write_wdr(0);
    tftlcd_write_index_register(TS_INS_START_ADY);
    tftlcd_write_wdr(0);
    tftlcd_write_index_register(TS_INS_END_ADY);
    tftlcd_write_wdr(319); 
	tftlcd_write_index_register(TS_INS_GRAM_ADY);
    tftlcd_write_wdr(319);
    #endif
	#ifdef LANDSCAPE
    tftlcd_write_index_register(TS_INS_START_ADX);
    tftlcd_write_wdr(0);
    tftlcd_write_index_register(TS_INS_END_ADX);
    tftlcd_write_wdr(319);
    tftlcd_write_index_register(TS_INS_GRAM_ADX);
    tftlcd_write_wdr(0);
    tftlcd_write_index_register(TS_INS_START_ADY);
    tftlcd_write_wdr(0);
    tftlcd_write_index_register(TS_INS_END_ADY);
    tftlcd_write_wdr(239); 
	tftlcd_write_index_register(TS_INS_GRAM_ADY);
    tftlcd_write_wdr(0);
    #endif 
	   
    tftlcd_write_index_register(TS_INS_RW_GRAM);

    for(counter = 0;counter < 76800;counter++)
        tftlcd_write_wdr(color);
}

void tftlcd_init_hispeed(int start_x,int end_x,int start_y,int end_y)
{
  	#ifdef PORTRAIT
    tftlcd_write_index_register(TS_INS_START_ADX);
    tftlcd_write_wdr(start_x);
    tftlcd_write_index_register(TS_INS_END_ADX);
    tftlcd_write_wdr(end_x);
    tftlcd_write_index_register(TS_INS_GRAM_ADX);
    tftlcd_write_wdr(0);
    tftlcd_write_index_register(TS_INS_START_ADY);
    tftlcd_write_wdr(start_y);
    tftlcd_write_index_register(TS_INS_END_ADY);
    tftlcd_write_wdr(end_y); 
	tftlcd_write_index_register(TS_INS_GRAM_ADY);
    tftlcd_write_wdr(319);
    #endif
	

	#ifdef LANDSCAPE
    tftlcd_write_index_register(TS_INS_START_ADX);
    tftlcd_write_wdr(start_x);
    tftlcd_write_index_register(TS_INS_END_ADX);
    tftlcd_write_wdr(end_x);
    tftlcd_write_index_register(TS_INS_GRAM_ADX);
    tftlcd_write_wdr(0);
    tftlcd_write_index_register(TS_INS_START_ADY);
    tftlcd_write_wdr(start_y);
    tftlcd_write_index_register(TS_INS_END_ADY);
    tftlcd_write_wdr(end_y); 
	tftlcd_write_index_register(TS_INS_GRAM_ADY);
    tftlcd_write_wdr(0);
    #endif 

	tftlcd_write_index_register(TS_INS_RW_GRAM);
}

//-----------------------------------------------------------------------
// LCD Initialization
//-----------------------------------------------------------------------
void tftlcd_init(void)
	{

#if ( defined family_lpc17xx || defined family_lpc23xx )
	_TFTLCD_DATAPORT_DIR_ |= (0xFFFF << TFTLCD_DATAPORT_OFFSET); // output
	_TFTLCD_CONTROLPORT_DIR_ |= (1 << TFTLCD_RST) | (1 << TFTLCD_RS) | (1 << TFTLCD_CS) | (1 << TFTLCD_WR) | (1 << TFTLCD_RD);
	_TFTLCD_CONTROLPORT_SET_ = (1 << TFTLCD_RST) | (1 << TFTLCD_CS) | (1 << TFTLCD_RD); 
	_TFTLCD_CONTROLPORT_CLR_ = (1 << TFTLCD_WR);


#elif defined family_sam7x 
	*AT91C_PMC_PCER = (1 << _TFTLCD_DATAPORT_ID_) | (1 << _TFTLCD_CONTROLPORT_ID_); 
	_TFTLCD_DATAPORT_PER_ = (0xFFFF << TFTLCD_DATAPORT_OFFSET);	//PIO mode
	_TFTLCD_DATAPORT_OER_ = (0xFFFF << TFTLCD_DATAPORT_OFFSET); // output
	_TFTLCD_DATAPORT_PUER_ = (0xFFFF << TFTLCD_DATAPORT_OFFSET); //pullup
	_TFTLCD_CONTROLPORT_PER_ = (1 << TFTLCD_RST) | (1 << TFTLCD_RS) | (1 << TFTLCD_CS) | (1 << TFTLCD_WR) | (1 << TFTLCD_RD);
	_TFTLCD_CONTROLPORT_OER_ = (1 << TFTLCD_RST) | (1 << TFTLCD_RS) | (1 << TFTLCD_CS) | (1 << TFTLCD_WR) | (1 << TFTLCD_RD);
	_TFTLCD_CONTROLPORT_PUDR_ = (1 << TFTLCD_RST) | (1 << TFTLCD_RS) | (1 << TFTLCD_CS) | (1 << TFTLCD_WR) | (1 << TFTLCD_RD);
	_TFTLCD_CONTROLPORT_SODR_ = (1 << TFTLCD_RST) | (1 << TFTLCD_CS) | (1 << TFTLCD_RD); 
	_TFTLCD_CONTROLPORT_CODR_ = (1 << TFTLCD_WR);

#endif	   
    // Reset LCD Chipset
    TFTLCD_RST_LOW;
    wait_ms(100);           
    TFTLCD_RST_HIGH;          
    wait_ms(100);
				   
		tftlcd_write_index_register(0x00E3);
		tftlcd_write_wdr(0x3008); 					//set the internal timing
		tftlcd_write_index_register(0x00E7);
		tftlcd_write_wdr(0x0012); 					//set the internal timing
		tftlcd_write_index_register(0x00EF);
		tftlcd_write_wdr(0x1231); 					//set the internal timing
		tftlcd_write_index_register(TS_INS_START_OSC);
		tftlcd_write_wdr(0x0001); 					//start oscillator
		wait_ms(50);

		tftlcd_write_index_register(TS_INS_DRIV_OUT_CTRL);
		tftlcd_write_wdr(0x0100); 					//set SS, SM
		tftlcd_write_index_register(TS_INS_DRIV_WAV_CTRL);
		tftlcd_write_wdr(0x0700); 					//set 1 line inversion
	
		tftlcd_write_index_register(TS_INS_ENTRY_MOD);
		tftlcd_write_wdr(TS_VAL_ENTRY_MOD);			//set GRAM write direction, BGR=0

		tftlcd_write_index_register(TS_INS_RESIZE_CTRL);
		tftlcd_write_wdr(0x0000); 					//no resizing

		tftlcd_write_index_register(TS_INS_DISP_CTRL2);
		tftlcd_write_wdr(0x0202); 					//front & back porch periods = 2
		tftlcd_write_index_register(TS_INS_DISP_CTRL3);
		tftlcd_write_wdr(0x0000); 					
		tftlcd_write_index_register(TS_INS_DISP_CTRL4);
		tftlcd_write_wdr(0x0000); 					
		tftlcd_write_index_register(TS_INS_RGB_DISP_IF_CTRL1);
		tftlcd_write_wdr(0x0000); 					//select system interface				
		tftlcd_write_index_register(TS_INS_FRM_MARKER_POS);
		tftlcd_write_wdr(0x0000); 					
		tftlcd_write_index_register(TS_INS_RGB_DISP_IF_CTRL2);
		tftlcd_write_wdr(0x0000);					
	
		tftlcd_write_index_register(TS_INS_POW_CTRL1);
		tftlcd_write_wdr(0x0000);
		tftlcd_write_index_register(TS_INS_POW_CTRL2);
		tftlcd_write_wdr(0x0007); 					
		tftlcd_write_index_register(TS_INS_POW_CTRL3);
		tftlcd_write_wdr(0x0000);
		tftlcd_write_index_register(TS_INS_POW_CTRL4);
		tftlcd_write_wdr(0x0000); 					
		wait_ms(200);

		tftlcd_write_index_register(TS_INS_POW_CTRL1);
		tftlcd_write_wdr(0x1690);
		tftlcd_write_index_register(TS_INS_POW_CTRL2);
		tftlcd_write_wdr(0x0227); //tftlcd_write_wdr(0x0137); 					
		wait_ms(50);

		tftlcd_write_index_register(TS_INS_POW_CTRL3);
		tftlcd_write_wdr(0x001A); //tftlcd_write_wdr(0x013C);
		wait_ms(50);

		tftlcd_write_index_register(TS_INS_POW_CTRL4);
		tftlcd_write_wdr(0x1800); //tftlcd_write_wdr(0x1400);
		tftlcd_write_index_register(TS_INS_POW_CTRL7);
		tftlcd_write_wdr(0x002A); //tftlcd_write_wdr(0x0007);
		wait_ms(50);

		tftlcd_write_index_register(TS_INS_GRAM_HOR_AD);
		tftlcd_write_wdr(0x0000);
		tftlcd_write_index_register(TS_INS_GRAM_VER_AD);
		tftlcd_write_wdr(0x0000);

		tftlcd_write_index_register(TS_INS_GAMMA_CTRL1);
		tftlcd_write_wdr(0x0007);
		tftlcd_write_index_register(TS_INS_GAMMA_CTRL2);
		tftlcd_write_wdr(0x0605);
		tftlcd_write_index_register(TS_INS_GAMMA_CTRL3);
		tftlcd_write_wdr(0x0106);
		tftlcd_write_index_register(TS_INS_GAMMA_CTRL4);
		tftlcd_write_wdr(0x0206);
		tftlcd_write_index_register(TS_INS_GAMMA_CTRL5);
		tftlcd_write_wdr(0x0808);
		tftlcd_write_index_register(TS_INS_GAMMA_CTRL6);
		tftlcd_write_wdr(0x0007);
		tftlcd_write_index_register(TS_INS_GAMMA_CTRL7);
		tftlcd_write_wdr(0x0201);
		tftlcd_write_index_register(TS_INS_GAMMA_CTRL8);
		tftlcd_write_wdr(0x0007);
		tftlcd_write_index_register(TS_INS_GAMMA_CTRL9);
		tftlcd_write_wdr(0x0602);
		tftlcd_write_index_register(TS_INS_GAMMA_CTRL10);
		tftlcd_write_wdr(0x0808);

		tftlcd_write_index_register(TS_INS_HOR_START_AD);
		tftlcd_write_wdr(0x0000);
		tftlcd_write_index_register(TS_INS_HOR_END_AD);
		tftlcd_write_wdr(0x00EF);
		tftlcd_write_index_register(TS_INS_VER_START_AD);
		tftlcd_write_wdr(0x0000);
		tftlcd_write_index_register(TS_INS_VER_END_AD);
		tftlcd_write_wdr(0x013F);
		tftlcd_write_index_register(TS_INS_GATE_SCAN_CTRL1);
		tftlcd_write_wdr(0xA700);
		tftlcd_write_index_register(TS_INS_GATE_SCAN_CTRL2);
		tftlcd_write_wdr(0x0001);
		tftlcd_write_index_register(TS_INS_GATE_SCAN_CTRL3);
		tftlcd_write_wdr(0x0000);

		tftlcd_write_index_register(TS_INS_PART_IMG1_DISP_POS);
		tftlcd_write_wdr(0x0000);
		tftlcd_write_index_register(TS_INS_PART_IMG1_START_AD);
		tftlcd_write_wdr(0x0000);
		tftlcd_write_index_register(TS_INS_PART_IMG1_END_AD);
		tftlcd_write_wdr(0x0000);
		tftlcd_write_index_register(TS_INS_PART_IMG2_DISP_POS);
		tftlcd_write_wdr(0x0000);
		tftlcd_write_index_register(TS_INS_PART_IMG2_START_AD);
		tftlcd_write_wdr(0x0000);
		tftlcd_write_index_register(TS_INS_PART_IMG2_END_AD);
		tftlcd_write_wdr(0x0000);

		tftlcd_write_index_register(TS_INS_PANEL_IF_CTRL1);
		tftlcd_write_wdr(0x0010);
		tftlcd_write_index_register(TS_INS_PANEL_IF_CTRL2);
		tftlcd_write_wdr(0x0000);
		tftlcd_write_index_register(TS_INS_PANEL_IF_CTRL3);
		tftlcd_write_wdr(0x0003);
		tftlcd_write_index_register(TS_INS_PANEL_IF_CTRL4);
		tftlcd_write_wdr(0x0110);
		tftlcd_write_index_register(TS_INS_PANEL_IF_CTRL5);
		tftlcd_write_wdr(0x0000);
		tftlcd_write_index_register(TS_INS_PANEL_IF_CTRL6);
		tftlcd_write_wdr(0x0000);

		tftlcd_write_index_register(TS_INS_DISP_CTRL1);
		tftlcd_write_wdr(0x0133);
	
		tftlcd_fill(WHITE);
	}

//-----------------------------------------------------------------------
// Turn On A Pixel On The LCD Screen
//-----------------------------------------------------------------------
void tftlcd_write_pixel(int x,int y,int color)
    {
	if(x < 0) x = 0;
	if(y < 0) y = 0;
	#ifdef PORTRAIT
	if(x > 239) x = 239;
	if(y > 319) y = 319;
	#endif
	#ifdef LANDSCAPE
	if(x > 319) x = 319;
	if(y > 239) y = 239;
	x = 319 - x;
	#endif

	tftlcd_write_index_register(TS_INS_START_ADX);
    tftlcd_write_wdr(x);
    tftlcd_write_index_register(TS_INS_END_ADX);
    tftlcd_write_wdr(x);
    tftlcd_write_index_register(TS_INS_GRAM_ADX);
    tftlcd_write_wdr(x);

    #ifdef PORTRAIT
	y = 319 - y;
	y = 319 - y;
    tftlcd_write_index_register(TS_INS_START_ADY);
    tftlcd_write_wdr(y);
    tftlcd_write_index_register(TS_INS_END_ADY);
    tftlcd_write_wdr(y); 
	tftlcd_write_index_register(TS_INS_GRAM_ADY);
    tftlcd_write_wdr(y);
    #endif
	#ifdef LANDSCAPE
    tftlcd_write_index_register(TS_INS_START_ADY);
    tftlcd_write_wdr(y);
    tftlcd_write_index_register(TS_INS_END_ADY);
    tftlcd_write_wdr(y); 
	tftlcd_write_index_register(TS_INS_GRAM_ADY);
    tftlcd_write_wdr(y);
    #endif 
	   
    tftlcd_write_index_register(TS_INS_RW_GRAM);

	tftlcd_write_wdr(color);
    }

//-----------------------------------------------------------------------
// Read A Pixel Color On The LCD Screen
//-----------------------------------------------------------------------
int tftlcd_read_pixel(int x,int y)
    { 
	if(x < 0) x = 0;
	if(y < 0) y = 0;
	#ifdef PORTRAIT
	if(x > 239) x = 239;
	if(y > 319) y = 319;
	#endif
	#ifdef LANDSCAPE
	if(x > 319) x = 319;
	if(y > 239) y = 239;
	x = 319 - x;
	#endif

	tftlcd_write_index_register(TS_INS_START_ADX);
    tftlcd_write_wdr(x);
    tftlcd_write_index_register(TS_INS_END_ADX);
    tftlcd_write_wdr(x);
    tftlcd_write_index_register(TS_INS_GRAM_ADX);
    tftlcd_write_wdr(x);

    #ifdef PORTRAIT
	y = 319 - y;
	y = 319 - y;
    tftlcd_write_index_register(TS_INS_START_ADY);
    tftlcd_write_wdr(y);
    tftlcd_write_index_register(TS_INS_END_ADY);
    tftlcd_write_wdr(y); 
	tftlcd_write_index_register(TS_INS_GRAM_ADY);
    tftlcd_write_wdr(y);
    #endif
	#ifdef LANDSCAPE
    tftlcd_write_index_register(TS_INS_START_ADY);
    tftlcd_write_wdr(y);
    tftlcd_write_index_register(TS_INS_END_ADY);
    tftlcd_write_wdr(y); 
	tftlcd_write_index_register(TS_INS_GRAM_ADY);
    tftlcd_write_wdr(y);
    #endif 
	   
    tftlcd_write_index_register(TS_INS_RW_GRAM);

	tftlcd_read_rdr();
    return tftlcd_read_rdr();
    }

//-----------------------------------------------------------------------
// Draw A Line With X0,Y0 And X1,Y1 Coordinates
//-----------------------------------------------------------------------
void tftlcd_draw_line(int x0,int y0,int x1,int y1,int color) 
    {
    int dy=y1-y0;
    int dx=x1-x0;
    int stepx,stepy;
    if(dy<0) {dy=-dy;stepy=-1;} else {stepy=1;}
    if(dx<0) {dx=-dx;stepx=-1;} else {stepx=1;}
    dy<<=1; 
    dx<<=1; 
    tftlcd_write_pixel(x0,y0,color);
    if(dx>dy) 
      {
      int fraction=dy-(dx>>1); 
      while(x0!=x1) 
        {
        if(fraction>=0) 
          {
          y0+=stepy;
          fraction-=dx; 
          }
        x0+=stepx;
        fraction+=dy; 
        tftlcd_write_pixel(x0,y0,color);
        }
      } 
    else 
      {
      int fraction=dx-(dy>>1);
      while (y0 != y1) 
        {
        if(fraction>=0) 
          {
          x0+=stepx;
          fraction-=dy;
          }
        y0+=stepy;
        fraction+=dx;
        tftlcd_write_pixel(x0,y0,color);
        }
      }
    }

//-----------------------------------------------------------------------
// Draw A Fill(1) Or No Fill(0) Rectangular With Specified Color    
//-----------------------------------------------------------------------
void tftlcd_draw_rectangle(int x0,int y0,int x1,int y1,char fill,int color)
    {
	if(x0 < 0) x0 = 0;
	if(y0 < 0) y0 = 0;
	#ifdef PORTRAIT
	if(x1 > 239) x1 = 239;
	if(y1 > 319) y1 = 319;
	#endif
	#ifdef LANDSCAPE
	if(x1 > 319) x1 = 319;
	if(y1 > 239) y1 = 239;
	#endif
	 
    if(fill)
      {
      int counter_x,counter_y; 
     
      for(counter_y = y0;counter_y <= y1;counter_y++)
        {
        for(counter_x = x0;counter_x <= x1;counter_x++)
            tftlcd_write_pixel(counter_x,counter_y,color);
        };	  
      } 
    else
      {
      tftlcd_draw_line(x0,y0,x1,y0,color);
      tftlcd_draw_line(x1,y0,x1,y1,color);
      tftlcd_draw_line(x1,y1,x0,y1,color); 
      tftlcd_draw_line(x0,y1,x0,y0,color);
      };
    }

//-----------------------------------------------------------------------
// Draw A Fill(1) Or No Fill(0) Circle With Specified Color 
//-----------------------------------------------------------------------
void tftlcd_draw_circle(int x0,int y0,int radius,char fill,int color) 
    { 
    int x_offset=0,y_offset=radius,errorr=1-radius; 

    do 
      { 
      if(fill) 
        { 
        tftlcd_draw_line(x0-x_offset,y0+y_offset,x0+x_offset,y0+y_offset,color); 
        tftlcd_draw_line(x0-x_offset,y0-y_offset,x0+x_offset,y0-y_offset,color); 
        tftlcd_draw_line(x0-y_offset,y0+x_offset,x0+y_offset,y0+x_offset,color); 
        tftlcd_draw_line(x0-y_offset,y0-x_offset,x0+y_offset,y0-x_offset,color); 
        } 
      else 
        { 
        tftlcd_write_pixel(x_offset+x0,y_offset+y0,color); 
        tftlcd_write_pixel(y_offset+x0,x_offset+y0,color); 
        tftlcd_write_pixel(x0-x_offset,y_offset+y0,color); 
        tftlcd_write_pixel(x0-y_offset,x_offset+y0,color); 
        tftlcd_write_pixel(y_offset+x0,y0-x_offset,color); 
        tftlcd_write_pixel(x_offset+x0,y0-y_offset,color); 
        tftlcd_write_pixel(x0-x_offset,y0-y_offset,color); 
        tftlcd_write_pixel(x0-y_offset,y0-x_offset,color); 
        } 

      if(errorr<0) 
        errorr+=(3+(2*(x_offset++))); 
      else 
        errorr+=(5+(2*((x_offset++)-(y_offset--)))); 
      }while(x_offset<=y_offset); 
    } 

//-----------------------------------------------------------------------
// Show A Picture On The LCD Screen
//-----------------------------------------------------------------------
void tftlcd_write_pic(int x0,int y0,const unsigned short *pointer)
     {
	 int x1 = x0 + ((int)*pointer++), y1 = y0 + ((int)*pointer++),counter_x,counter_y;
	 					  
	 if(x0 < 0) x0 = 0;
	 if(y0 < 0) y0 = 0;
	  
	 for(counter_y = y0;counter_y < y1;counter_y++)
	 	{
		for(counter_x = x0;counter_x < x1;counter_x++)
			tftlcd_write_pixel(counter_x,counter_y,(int)*pointer++);
		}; 
     }

//-----------------------------------------------------------------------
// Show A Picture On The LCD Screen
//-----------------------------------------------------------------------
void tftlcd_write_pic_fast(const unsigned short *pointer)
     {
	 //int x1 =((int)*pointer++), y1 =((int)*pointer++);
	 int x1=240,y1=320;
	 unsigned long int i = x1*y1;

	 pointer+=2;					  
	tftlcd_init_hispeed(0,x1-1,0,y1-1);
	TFTLCD_RS_HIGH;

	  
	 for(i=0;i<76800;i++)
	 	{
				TFTLCD_CS_LOW;
				TFTLCD_WR_LOW;
				TFTLCD_DATAPORT_CLEAR;

#if ( defined family_lpc17xx | defined family_lpc23xx )
				_TFTLCD_DATAPORT_SET_ = (((int)*pointer++) << TFTLCD_DATAPORT_OFFSET);

#elif defined family_sam7x 
				_TFTLCD_DATAPORT_SODR_ = (((int)*pointer++) << TFTLCD_DATAPORT_OFFSET);

#endif
				wait();
				TFTLCD_WR_HIGH;
				TFTLCD_CS_HIGH;
		}
     }
        
//-----------------------------------------------------------------------
// This Functions Goes The Cursor To X And Y Positions
//-----------------------------------------------------------------------                
void tftlcd_gotoxy(int x,int y)
    {
    if(x>29 || y>19) 
        {
        y+=x/30;
        x%=30;
        }
    x_text=x;
    y_text=y;
    }

//-----------------------------------------------------------------------
// Puts A Character On The LCD Screen
//-----------------------------------------------------------------------
void tftlcd_putchar(char character,int forground_color,int background_color,int transparent_mode)
    {  
    int width_counter,length_counter;
    int character_segment_data;
	
    for(length_counter=0;length_counter<16;length_counter++)
        {
        character_segment_data=font8x16[character-0x20][length_counter];
        for(width_counter=0;width_counter<8;width_counter++)
            {
            if(character_segment_data & (0x80>>width_counter)) 
              tftlcd_write_pixel((x_text*8)+width_counter,(y_text*16)+length_counter,forground_color);
			else
			  {
			  if(!transparent_mode)
			    tftlcd_write_pixel((x_text*8)+width_counter,(y_text*16)+length_counter,background_color);
			  else
                tftlcd_write_pixel((x_text*8)+width_counter,(y_text*16)+length_counter,tftlcd_read_pixel((x_text*8)+width_counter,(y_text*16)+length_counter));
			  };
			};
        };
    
    if(++x_text>29)
        {            
        x_text=0;
        if(++y_text>19) y_text=0;
        };
    }  
    
//-----------------------------------------------------------------------
// Show A String That Stored In The Flash Memory Of The Microcontroller
//-----------------------------------------------------------------------    
void tftlcd_putsf(const char *string,int forground_color,int background_color,int transparent_mode)
    {
    while(*string)
      tftlcd_putchar(*string++,forground_color,background_color,transparent_mode);
    }

//-----------------------------------------------------------------------
// Show A String That Stored In The SRAM Of The Microcontroller
//-----------------------------------------------------------------------     
void tftlcd_puts(char *string,int forground_color,int background_color,int transparent_mode)
    {
    while(*string)
      tftlcd_putchar(*string++,forground_color,background_color,transparent_mode);
    }


