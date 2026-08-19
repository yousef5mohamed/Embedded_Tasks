#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"

int main(void)
{
    // Configure PA2 as Output 
    DIO_InitPin(Dio_GroupA, Dio_Pin2, Output);

    while(1)
    {
        // Turn Buzzer ON
        DIO_WritePin(Dio_GroupA, Dio_Pin2, High);
        // 1-second pulse
        _delay_ms(1000);
        // Turn Buzzer OFF
        DIO_WritePin(Dio_GroupA, Dio_Pin2, Low);
        // Wait before next pulse
        _delay_ms(1000);
    }
    return 0;
}