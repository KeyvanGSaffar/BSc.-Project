
/*************************************************/
/*         VS1003 Header File                    */
/*         Modified to LPC1768 By :              */
/*         Ramin Jafarpour                       */
/*         ramin.jafarpour@hotmail.com           */ 
/*         www.ECA.ir                            */                                                     
/*************************************************/


#include "VS1003B.h"


#define uchar unsigned char
#define uint  unsigned int

unsigned char VS_COMMAND,DATA_HIGH,DATA_LOW;



/*-------------------------------------------------------------------------------------------
				    	 VS1003 init for starting play
---------------------------------------------------------------------------------------------*/
unsigned char VS1003B_Init()
{

		VS1003B_XDCS_L();
		VS1003B_XRESET_L();
		//delay_us(5);
		VS1003B_XCS_H();
		VS1003B_XDCS_H();
		VS1003B_XRESET_H();
		BITWAIT_DREQ_HIGH();
		VS1003B_XRESET_L();
    VS1003B_WRITE_DATA(0,8);
		VS1003B_XDCS_H();
		//delay_us(15);
		VS1003B_XRESET_H();
		//delay_us(2);
		VS1003B_XRESET_H();
		VS_COMMAND=VS_MODE_AD;
		DATA_HIGH=8;
		DATA_LOW=0;
		VS_WRITE();
		VS_COMMAND=VS_CLOCK_AD;
		DATA_HIGH=251;
		DATA_LOW=232;	// Data_high = &B11111011 : Data_low = &B11101000  crystal
		VS_WRITE();
		VS_COMMAND=VS_AIADDR_AD;
		DATA_HIGH=0;
		DATA_LOW=0;	
		VS_WRITE();
		VS_COMMAND=VS_VOL_AD;
		DATA_HIGH=0;
		DATA_LOW=0;	
		VS_WRITE();
	return 1;

}
/*-------------------------------------------------------------------------------------------
							         VS1003 Soft reset
---------------------------------------------------------------------------------------------*/
void VS1003B_SoftReset()
{
		PORT_INI();//vs pin init
		VS_COMMAND=0;
		DATA_HIGH=0;
		DATA_LOW=4;	
		VS_WRITE();	
		//delay_us(30);
}




/*-------------------------------------------------------------------------------------------
				 Set Volume
---------------------------------------------------------------------------------------------*/
void VS1003B_SetVolume(unsigned int vol)
{
      
             
}									


/*-------------------------------------------------------------------------------------------
				 Write the Command with to byte data in to VS1003
---------------------------------------------------------------------------------------------*/

void VS_WRITE()
{
	VS1003B_XCS_L();
	VS1003B_WRITE_DATA(VS_W,8);
	VS1003B_WRITE_DATA(VS_COMMAND,8);
	VS1003B_WRITE_DATA(DATA_HIGH,8);
	VS1003B_WRITE_DATA(DATA_LOW,8);
	VS1003B_XCS_H();   
	//delay_us(2);
	BITWAIT_DREQ_HIGH();
}


void VS1003B_WRITE_DATA(unsigned char data, char bitNum){
int i=0,dly;		  
   	VS1003B_MOSI_L();
   	VS1003B_SCK_L();
  	for(i=bitNum-1; i>=0; i--){

  		if( data & (1<<i) )VS1003B_MOSI_H();
	   	else VS1003B_MOSI_L();
	 	VS1003B_SCK_H();
		for (dly=0;dly<10;dly++);
  	 	VS1003B_SCK_L();
     	VS1003B_MOSI_L();
  	}
}

/*-------------------------------------------------------------------------------------------
							 Wait for DREQ be HIGH
---------------------------------------------------------------------------------------------*/
void BITWAIT_DREQ_HIGH() {  
		
		while ((*AT91C_PIOB_PDSR & (1<<VS1003B_DREQ_BIT))==0);

}
