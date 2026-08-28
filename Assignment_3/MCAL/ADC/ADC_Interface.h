#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include <stdint.h>

#include "../../COMMON/Definition.h"
#include "../../COMMON/Bitmath.h"
#include "../Atmega16regmap.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

void ADC_Init(Adc_Config_t Configuration);
uint16_t ADC_ReadChannelPolling(uint8_t Channel, uint32_t Timeout);
void ADC_StartConversionInterrupt(uint8_t Channel);
void ADC_SetCallBack(void (*Copy_pvCallBack)(uint16_t));

#endif