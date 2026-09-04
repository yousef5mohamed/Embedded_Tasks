#ifndef _RFID_CONFIG_H
#define _RFID_CONFIG_H

#include "../../MCAL/DIO/DIO_Private.h"

/* SDA / CS pin of the module */
#define RFID_CS_GROUP     Dio_GroupB
#define RFID_CS_PIN       Dio_Pin4

/* RST pin of the module */
#define RFID_RST_GROUP    Dio_GroupB
#define RFID_RST_PIN      Dio_Pin3

#endif
