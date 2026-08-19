#include "../../MCAL/DIO/DIO_Interface.h"

int main(void)
{
    uint8_t SensorState;
    // Configure IR Sensor pin as Input 
    DIO_InitPin(Dio_GroupD, Dio_Pin2, Input);
    // Configure LED pin as Output
    DIO_InitPin(Dio_GroupD, Dio_Pin3, Output);
    while(1)
    {
        // Read IR Sensor
        DIO_ReadPin(Dio_GroupD, Dio_Pin2, &SensorState);
        if(SensorState == High)
        {
            // Object detected
            DIO_WritePin(Dio_GroupD, Dio_Pin3, High);
        }
        else
        {
            // No object detected
            DIO_WritePin(Dio_GroupD, Dio_Pin3, Low);
        }
    }
    return 0;
}