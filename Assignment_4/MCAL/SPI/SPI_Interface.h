#ifndef _SPI_INTERFACE_H
#define _SPI_INTERFACE_H

#include <stdint.h>

#include "../../COMMON/Definition.h"
#include "../../COMMON/Bitmath.h"
#include "../Atmega32regmap.h"

#include "SPI_Private.h"
#include "SPI_Config.h"


void SPI_Init(SPI_Config_t SPI_Config);

void SPI_SendData(uint8_t Data);


void SPI_SetCallBack(void (*CopyFunc)(void));

void SPI_EnableInterrupt(void);

void SPI_DisableInterrupt(void);

uint8_t SPI_Transfer(uint8_t Data);





#endif