#ifndef _SPI_PRIVATE_H
#define _SPI_PRIVATE_H
#include <stdint.h>

#define SPI_SPIE      7
#define SPI_SPE       6
#define SPI_DORD      5
#define SPI_MSTR      4
#define SPI_CPOL      3
#define SPI_CPHA      2
#define SPI_SPR1      1
#define SPI_SPR0      0

#define SPI_SPIF      7
#define SPI_WCOL      6 
#define SPI_SPI2X     0


#define SPI_MSB       7
#define SPI_LSB       0


#define SPI_Prescaller4_NormalSpeed        0 
#define SPI_Prescaller16_NormalSpeed       1
#define SPI_Prescaller64_NormalSpeed       2 
#define SPI_Prescaller128_NormalSpeed      3

#define SPI_Prescaller2_DoubleSpeed        4
#define SPI_Prescaller8_DoubleSpeed        5
#define SPI_Prescaller32_DoubleSpeed       6
#define SPI_Prescaller64_DoubleSpeed       7

#define LSB_First 0
#define MSB_First 1

#define Master_mode 1
#define Slave_mode  0

#define SPI_CPOL_LOW  0
#define SPI_CPOL_HIGH 1

#define SPI_SAMPLE_LEADING  0
#define SPI_SAMPLE_TRAILING 1

void __vector_12(void) __attribute__((signal,used));

typedef struct 
{
    uint8_t ModeSelect ;
    uint8_t DataOrder ;
    uint8_t ClockPolarity ;
    uint8_t ClockPhase ;
    uint8_t ClockRate ;
     
     
} SPI_Config_t ;

#endif