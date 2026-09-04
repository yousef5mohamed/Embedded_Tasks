#include "COMMON/Definition.h"
#include "COMMON/Bitmath.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
#include "HAL/RFID/RFID_Interface.h"

/* LED on PORTA pin0, lights up when a card is detected */
#define LED_GROUP   Dio_GroupA
#define LED_PIN     Dio_Pin0

int main(void)
{
    uint8_t CardID[RFID_UID_LEN];
    uint8_t Status;

    SPI_Config_t SPI_Config;
    SPI_Config.ModeSelect    = Master_mode;
    SPI_Config.DataOrder     = MSB_First;
    SPI_Config.ClockPolarity = SPI_CPOL_LOW;
    SPI_Config.ClockPhase    = SPI_SAMPLE_LEADING;
    SPI_Config.ClockRate     = SPI_Prescaller16_NormalSpeed;

    DIO_InitPin(LED_GROUP, LED_PIN, Output);
    DIO_WritePin(LED_GROUP, LED_PIN, Low);

    /* SPI_Init() configures the ATmega32 hardware SPI pins. */
    SPI_Init(SPI_Config);
    RFID_Init();

    while (1)
    {
        Status = RFID_CheckCard(CardID);

        if (Status == RFID_OK)
        {
            /* card found -> turn the LED on */
            DIO_WritePin(LED_GROUP, LED_PIN, High);

            RFID_Halt();
        }
        else
        {
            DIO_WritePin(LED_GROUP, LED_PIN, Low);
        }
    }
}