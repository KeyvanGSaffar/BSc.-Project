/*----------------------------------------------------------------------------
 *      RL-ARM - FlashFS
 *----------------------------------------------------------------------------
 *      Name:    SPI_SAM7X.c
 *      Purpose: Serial Peripheral Interface Driver for Atmel AT91SAM7X
 *      Rev.:    V4.10
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2010 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include <File_Config.h>
#include <AT91SAM7X256.H>               /* AT91SAM7X256 definitions          */

/*----------------------------------------------------------------------------
 *      User configuration part
 *---------------------------------------------------------------------------*/

//-------- <<< Use Configuration Wizard in Context Menu >>> -----------------

//<h>SPI Configuration for SAM7X
//  <o>Configured Drive  <2=> SPI Flash <4=> Memory Card
//  <i>SPI functions are used for this drive
//</h>
#define CFG_DRIVE  4

//------------- <<< end of configuration section >>> -----------------------

#if CFG_DRIVE == 2
 #define SPI_CS    0
 #define SPI_SS    AT91C_PA12_SPI0_NPCS0         /* SPI DATA Flash */
#else
 #define SPI_CS    1
 #define SPI_SS    AT91C_PA15_SPI0_NPCS3         /* SPI SD Card    */
#endif
#define SPI_PCS    (~(1<<SPI_CS) & 0x0F)         /* set PCS according CS */

#define RDRF       0x00000001
#define TDRE       0x00000002

/*----------------------------------------------------------------------------
 *      SPI Driver Functions
 *----------------------------------------------------------------------------
 *  Required functions for SPI driver module:
 *   - void spi_init     ()
 *   - void spi_ss       (U32 ss)
 *   - U8   spi_send     (U8 outb)
 *   - void spi_hi_speed (BOOL on)
 *---------------------------------------------------------------------------*/

/*--------------------------- spi_init --------------------------------------*/

void spi_init (void) {
  /* Initialize and enable the SSP Interface module. */

  /* Enable Clocks */
  AT91C_BASE_PMC->PMC_PCER        = (1 << AT91C_ID_PIOA) |
                                    (1 << AT91C_ID_SPI0) ;

  /* SPI0_MISO, SPI0_MOSI, SPI0_SPCK are SPI0 pins */
  AT91C_BASE_PIOA->PIO_ASR        = AT91C_PA16_SPI0_MISO |
                                    AT91C_PA17_SPI0_MOSI |
                                    AT91C_PA18_SPI0_SPCK ;
  AT91C_BASE_PIOA->PIO_PDR        = AT91C_PA16_SPI0_MISO |
                                    AT91C_PA17_SPI0_MOSI |
                                    AT91C_PA18_SPI0_SPCK ;

  /* SPIO_NPCS1 is GPIO, output set to high. */
  AT91C_BASE_PIOA->PIO_PER        = SPI_SS;
  AT91C_BASE_PIOA->PIO_OER        = SPI_SS;
  AT91C_BASE_PIOA->PIO_SODR       = SPI_SS;

  /* Initialize SPI0 Controller */
  AT91C_BASE_SPI0->SPI_CR         = AT91C_SPI_SWRST;
  AT91C_BASE_SPI0->SPI_MR         = AT91C_SPI_MSTR | AT91C_SPI_MODFDIS;

  /* Set DLYBCT = 0(10ns), DLYBS = 15(300ns), SBCR = 3(16MHz SPI clock) */
  AT91C_BASE_SPI0->SPI_CSR[SPI_CS] = AT91C_SPI_CPOL | AT91C_SPI_BITS_8 |
                                     (0 << 24) | (15 << 16) | (3 << 8) ;
  /* Use NPCSx as chip select. */
  AT91C_BASE_SPI0->SPI_MR        &= 0xFFF0FFFF;
  AT91C_BASE_SPI0->SPI_MR        |= ((SPI_PCS<<16) & AT91C_SPI_PCS);
  AT91C_BASE_SPI0->SPI_CR         = AT91C_SPI_SPIEN;
}

/*--------------------------- spi_hi_speed ----------------------------------*/

void spi_hi_speed (BOOL on) {
  /* Set a SPI clock to low/high speed for SD/MMC. */
  U32 csr;

  csr = AT91C_BASE_SPI0->SPI_CSR[SPI_CS] & 0xFFFF00FF;
  if (on == __TRUE) {
    /* Max. 16 MBit used for Data Transfer. */
    AT91C_BASE_SPI0->SPI_CSR[SPI_CS] = csr | (3 << 8);
  }
  else {
    /* Max. 400 kBit used in Card Initialization. */
    /* here we use 600 kBit */
    AT91C_BASE_SPI0->SPI_CSR[SPI_CS] = csr | (80 << 8);
  }
}


/*--------------------------- spi_ss ----------------------------------------*/

void spi_ss (U32 ss) {
  /* Enable/Disable SPI Chip Select (drive it high or low). */

  if (ss) {
    AT91C_BASE_PIOA->PIO_SODR = SPI_SS;
  }
  else {
    AT91C_BASE_PIOA->PIO_CODR = SPI_SS;
  }
}


/*--------------------------- spi_send --------------------------------------*/

U8 spi_send (U8 outb) {
  /* Write and Read a byte on SPI interface. */

  /* Wait until TDRE is set. */
  while ((AT91C_BASE_SPI0->SPI_SR & TDRE) != TDRE);
  AT91C_BASE_SPI0->SPI_TDR = outb;

  /* Wait until RDRF is set. */
  while ((AT91C_BASE_SPI0->SPI_SR & RDRF) != RDRF);
  return ((U8)(AT91C_BASE_SPI0->SPI_RDR & 0x0000FFFF));
}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
