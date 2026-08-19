#include <util/delay.h>
#include "../../MCAL/DIO/DIO_Interface.h"

int main(void)
{
    // Configure PB0 as output
    DIO_InitPin(Dio_GroupB, Dio_Pin0, Output);

    while (1)
    {
        // Toggle LED every 500 ms
        DIO_TogglePin(Dio_GroupB, Dio_Pin0);
        _delay_ms(500);
    }

    return 0;
}
