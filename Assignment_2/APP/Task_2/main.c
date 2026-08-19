#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer0/Timer0_Interface.h"

int main(void)
{
    Timer0_Config_t TimerConfig =
    {
        Timer0_FastPWM,
        0,
        0,
        Timer0_OC0NinInverting,
        50
    };
    // Configure PB3 / OC0 as Output
    DIO_InitPin(Dio_GroupB, Dio_Pin3, Output);
    // Initialize Timer0 in Fast PWM mode
    TIMER0_Init(TimerConfig);
    // Start Timer0 with Prescaler = 8 
    TIMER0_Start(Timer0_Prescaller8);
    while(1)
    {
        // LED brightness = 50% 
        TIMER0_SetPWMDutyCycle(50);
    }
    return 0;
}