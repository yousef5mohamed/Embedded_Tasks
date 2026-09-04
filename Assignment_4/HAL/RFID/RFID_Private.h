#ifndef _RFID_PRIVATE_H
#define _RFID_PRIVATE_H

#include <stdint.h>

/* MFRC522 registers (only the ones this driver actually uses) */
#define RFID_REG_COMMAND            0x01
#define RFID_REG_COM_IRQ_EN         0x02
#define RFID_REG_COM_IRQ            0x04
#define RFID_REG_DIV_IRQ            0x05
#define RFID_REG_ERROR              0x06
#define RFID_REG_FIFO_DATA          0x09
#define RFID_REG_FIFO_LEVEL         0x0A
#define RFID_REG_CONTROL            0x0C
#define RFID_REG_BIT_FRAMING        0x0D
#define RFID_REG_MODE               0x11
#define RFID_REG_TX_CONTROL         0x14
#define RFID_REG_TX_ASK             0x15
#define RFID_REG_CRC_RESULT_MSB     0x21
#define RFID_REG_CRC_RESULT_LSB     0x22
#define RFID_REG_T_MODE             0x2A
#define RFID_REG_T_PRESCALER        0x2B
#define RFID_REG_T_RELOAD_H         0x2C
#define RFID_REG_T_RELOAD_L         0x2D

/* PCD = reader commands */
#define PCD_IDLE                    0x00
#define PCD_AUTHENT                 0x0E
#define PCD_TRANSCEIVE               0x0C
#define PCD_RESETPHASE              0x0F
#define PCD_CALCCRC                 0x03

/* PICC = card commands */
#define PICC_REQIDL                 0x26   /* request idle cards      */
#define PICC_WUPA                   0x52   /* wake up idle/halted cards */
#define PICC_ANTICOLL               0x93   /* anti-collision / UID    */
#define PICC_HALT                   0x50   /* put the card to sleep   */

/* --- internal helpers, not part of the public API --- */
static void    RFID_WriteRegister(uint8_t Reg, uint8_t Value);
static uint8_t RFID_ReadRegister(uint8_t Reg);
static void    RFID_SetBitMask(uint8_t Reg, uint8_t Mask);
static void    RFID_ClearBitMask(uint8_t Reg, uint8_t Mask);
static void    RFID_AntennaOn(void);

static uint8_t RFID_ToCard(uint8_t Command, uint8_t *SendData, uint8_t SendLen,
                            uint8_t *BackData, uint16_t *BackLenBits);

static uint8_t RFID_Request(uint8_t ReqMode, uint8_t *TagType);
static uint8_t RFID_Anticoll(uint8_t *SerNum);
static void    RFID_CalculateCRC(uint8_t *Data, uint8_t Len, uint8_t *Result);

#endif
