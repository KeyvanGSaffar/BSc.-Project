/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */


//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include "twid.h"
#include "twi.h"
#include <at91sam7x256.h>

//------------------------------------------------------------------------------
//         Local types
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//         Global functions
//------------------------------------------------------------------------------


//-----------------------------------------------------------------------------
/// Asynchronously reads data from a slave on the TWI bus. An optional
/// callback function is triggered when the transfer is complete.
/// Returns 0 if the transfer has been started; otherwise returns a TWI error
/// code.
/// \param address  TWI slave address.
/// \param iaddress  Optional slave internal address.
/// \param isize  Internal address size in bytes.
/// \param pData  Data buffer for storing received bytes.
/// \param num  Number of bytes to read.
/// \param pAsync  Asynchronous transfer descriptor.
//-----------------------------------------------------------------------------
unsigned char TWID_Read(
    unsigned char address,
    unsigned int iaddress,
    unsigned char isize,
    unsigned char *pData,
    unsigned int num,
    int pAsync)
{
   
    // Set STOP signal if only one byte is sent
    if (num == 1) {

        TWI_Stop();
    }

    // Asynchronous transfer
    if (pAsync) {
        // Enable read interrupt and start the transfer
        TWI_EnableIt(AT91C_TWI_RXRDY);
        TWI_StartRead(address, iaddress, isize);
    }
    // Synchronous transfer
    else {

        // Start read
        TWI_StartRead(address, iaddress, isize);

        // Read all bytes, setting STOP before the last byte
        while (num > 0) {
						// Last byte
						if (num == 1) {

                TWI_Stop();
            }
            // Wait for byte then read and store it
						while(!TWI_ByteReceived());
            *pData++ = TWI_ReadByte();
						num--;
        }
				
        // Wait for transfer to be complete
				while(!TWI_TransferComplete());
        
    }
    return 0;
}

//------------------------------------------------------------------------------
/// Asynchronously sends data to a slave on the TWI bus. An optional callback
/// function is invoked whenever the transfer is complete.
/// \param address  Slave address.
/// \param iaddress  Optional slave internal address.
/// \param isize  Number of internal address bytes.
/// \param pData  Data buffer to send.
/// \param num  Number of bytes to send.
/// \param pAsync  Pointer to an Asynchronous transfer descriptor.
//------------------------------------------------------------------------------
unsigned char TWID_Write(
    unsigned char address,
    unsigned int iaddress,
    unsigned char isize,
    unsigned char *pData,
    unsigned int num,
    int pAsync)
{

    // Asynchronous transfer
    if (pAsync) {
        // Enable write interrupt and start the transfer
        TWI_StartWrite(address, iaddress, isize, *pData);
        TWI_EnableIt(AT91C_TWI_TXRDY);
    }
    // Synchronous transfer
    else {

        // Start write
        TWI_StartWrite(address, iaddress, isize, *pData++);
        

        // Send all bytes
        while (num > 0) {
         
           // Wait before sending the next byte
          while(!TWI_ByteSent());
          TWI_WriteByte(*pData++);
          num--;
        }
        
				// Wait for transfer to be complete
				while(!TWI_TransferComplete());
					minDel();
    
    }
    return 0;
}

