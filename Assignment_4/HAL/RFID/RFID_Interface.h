#ifndef _RFID_INTERFACE_H
#define _RFID_INTERFACE_H

#include <stdint.h>

#include "../../COMMON/Definition.h"
#include "../../COMMON/Bitmath.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/SPI/SPI_Interface.h"

#include "RFID_Private.h"
#include "RFID_Config.h"

/* return codes for RFID_CheckCard() / RFID_Init() */
#define RFID_OK          0     // card found, UID is valid
#define RFID_NOTAGERR    1     // no card in the field
#define RFID_ERR         2     // communication / CRC error

#define RFID_UID_LEN     4     // UID length for Mifare Classic 1K/4K

/* Sets up the SPI pins (CS, RST) and configures the MFRC522.
 * Call this once before using any other RFID function.               */
void RFID_Init(void);

/* Polls for a card in the field. On RFID_OK, CardID holds the 4-byte
 * UID of the card. CardID must point to a buffer of RFID_UID_LEN.    */
uint8_t RFID_CheckCard(uint8_t *CardID);

/* Puts the currently selected card back to sleep (HALT state).       */
void RFID_Halt(void);

#endif
