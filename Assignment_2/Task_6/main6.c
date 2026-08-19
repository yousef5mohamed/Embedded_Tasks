#include <stdint.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/Timer0/Timer0_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"

volatile uint16_t TimerTicks = 0;
volatile uint8_t DelayDone = 0;

void Timer0_1SecCallback(void)
{
    TimerTicks++;
    // CTC period = 2 ms, so 500 ticks = 1 second
    if (TimerTicks >= 500)
    {
        TimerTicks = 0;
        DelayDone = 1;
        TIMER0_Stop();
    }
}

void Timer0_Delay1Sec(void)
{
    DelayDone = 0;
    TimerTicks = 0;
    TIMER0_Start(Timer0_Prescaller64);
    while (DelayDone == 0)
    {
        // Wait until 1 second is completed
    }
}

int main(void)
{
    Timer0_Config_t TimerConfig =
    {
        Timer0_CTCMode,
        0,
        249,
        0,
        0
    };
    // Configure LED pin as output
    DIO_InitPin(Dio_GroupB, Dio_Pin1, Output);
    // Timer0 CTC: 8 MHz / 64 / 250 = 500 Hz = 2 ms
    TIMER0_Init(TimerConfig);
    TIMER0_SetCallBackFunction(Timer0_CompareMatchInterrupt, Timer0_1SecCallback);
    // Enable global interrupts
    GIE_Enable();
    while (1)
    {
        DIO_TogglePin(Dio_GroupB, Dio_Pin1);
        Timer0_Delay1Sec();
    }
    return 0;
}
