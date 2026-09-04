#include "SPI_Interface.h"
#include "../DIO/DIO_Interface.h"


static void (*PF_SPI)(void)= Null;


void SPI_Init(SPI_Config_t SPI_Config)
{
// PB4 = SS, PB5 = MOSI, PB6 = MISO, PB7 = SCK
    DIO_InitPin(Dio_GroupB, Dio_Pin4, Output);
    DIO_WritePin(Dio_GroupB, Dio_Pin4, High);
    DIO_InitPin(Dio_GroupB, Dio_Pin5, Output);
    DIO_InitPin(Dio_GroupB, Dio_Pin6, Input);
    DIO_InitPin(Dio_GroupB, Dio_Pin7, Output);

if(SPI_Config.DataOrder==LSB_First)
{
    SetBit(SPCR_Reg,SPI_DORD);
}
else if (SPI_Config.DataOrder==MSB_First)
{
  ClearBit(SPCR_Reg,SPI_DORD);
}


if(SPI_Config.ModeSelect==Master_mode)
{
   SetBit(SPCR_Reg,SPI_MSTR);
}
else if(SPI_Config.ModeSelect==Slave_mode)
{
  ClearBit(SPCR_Reg,SPI_MSTR);
}


if(SPI_Config.ClockPolarity==SPI_CPOL_LOW)
{
    ClearBit(SPCR_Reg,SPI_CPOL);
}
else if(SPI_Config.ClockPolarity==SPI_CPOL_HIGH)
{
    SetBit(SPCR_Reg,SPI_CPOL);
}

if(SPI_Config.ClockPhase==SPI_SAMPLE_LEADING)
{
    ClearBit(SPCR_Reg,SPI_CPHA);
}
else if(SPI_Config.ClockPhase==SPI_SAMPLE_TRAILING)
{
    SetBit(SPCR_Reg,SPI_CPHA);
}


if (SPI_Config.ClockRate==SPI_Prescaller4_NormalSpeed)
{
ClearBit(SPSR_Reg,SPI_SPI2X);
ClearBit(SPCR_Reg,SPI_SPR1);
ClearBit(SPCR_Reg,SPI_SPR0);
}
else if(SPI_Config.ClockRate==SPI_Prescaller16_NormalSpeed)
{
ClearBit(SPSR_Reg,SPI_SPI2X);
ClearBit(SPCR_Reg,SPI_SPR1);
SetBit(SPCR_Reg,SPI_SPR0);
}
else if(SPI_Config.ClockRate==SPI_Prescaller64_NormalSpeed)
{
ClearBit(SPSR_Reg,SPI_SPI2X);
SetBit(SPCR_Reg,SPI_SPR1);
ClearBit(SPCR_Reg,SPI_SPR0);
}
else if(SPI_Config.ClockRate==SPI_Prescaller128_NormalSpeed)
{
ClearBit(SPSR_Reg,SPI_SPI2X);
SetBit(SPCR_Reg,SPI_SPR1);
SetBit(SPCR_Reg,SPI_SPR0);
}
else if(SPI_Config.ClockRate==SPI_Prescaller2_DoubleSpeed)
{
SetBit(SPSR_Reg,SPI_SPI2X);
ClearBit(SPCR_Reg,SPI_SPR1);
ClearBit(SPCR_Reg,SPI_SPR0);
}
else if(SPI_Config.ClockRate==SPI_Prescaller8_DoubleSpeed)
{
SetBit(SPSR_Reg,SPI_SPI2X);
ClearBit(SPCR_Reg,SPI_SPR1);
SetBit(SPCR_Reg,SPI_SPR0);
}
else if(SPI_Config.ClockRate==SPI_Prescaller32_DoubleSpeed)
{
SetBit(SPSR_Reg,SPI_SPI2X);
SetBit(SPCR_Reg,SPI_SPR1);
ClearBit(SPCR_Reg,SPI_SPR0);
}
else if(SPI_Config.ClockRate==SPI_Prescaller64_DoubleSpeed)
{
SetBit(SPSR_Reg,SPI_SPI2X);
SetBit(SPCR_Reg,SPI_SPR1);
SetBit(SPCR_Reg,SPI_SPR0);
}
SetBit(SPCR_Reg,SPI_SPE);
}
void SPI_SendData(uint8_t Data)
{
    SPDR_Reg = Data;

    while(ReadBit(SPSR_Reg, SPI_SPIF) == 0);
}


void SPI_EnableInterrupt(void)
{
    SetBit(SPCR_Reg, SPI_SPIE);
}
void SPI_DisableInterrupt(void)
{
    ClearBit(SPCR_Reg, SPI_SPIE);
}


uint8_t SPI_Transfer(uint8_t Data)
{
    // SPDR = Data ; 
    SPDR_Reg = Data;
    // Start Enable for SPI 
    // Waiting Flag 
    while(ReadBit(SPSR_Reg, SPI_SPIF) == 0);
    // Clear Flag 
    // Get the SPDR  
    return SPDR_Reg;
}
void SPI_SetCallBack(void (*CopyFunc)(void))
{
    PF_SPI = CopyFunc;
}
void __vector_12(void)
{
    if(PF_SPI != Null)
    {
        PF_SPI();
    }
}