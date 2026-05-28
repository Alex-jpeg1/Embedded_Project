#include <avr/io.h>

#define F_CPU 16000000UL
#include "../lib/outputs/Digitals/DigitalOutput.hpp"
#include "../lib/init/init.hpp"
#include "../lib/inputs/Potentiometer/Potentiometer.hpp"


int main(void)
{
    Potentiometer pot(APIN::A0);
    DigitalOutput warningLedHumidityLow(DPIN::D2);
    DigitalOutput WarningLedHumidityLowExtreme(DPIN::D3);
    init();

    while(1)
    {
        pot.AnalogReadData();

        if(pot.GetPercentageValue() < 50)
        {
            warningLedHumidityLow.OutputSignal();
            if(pot.GetPercentageValue() < 25)
            {
                WarningLedHumidityLowExtreme.OutputSignal();
            }
            else
            {
                WarningLedHumidityLowExtreme.DeleteSignal();
            }
        }
        else
        {
            WarningLedHumidityLowExtreme.DeleteSignal();
            warningLedHumidityLow.DeleteSignal();
        }

    }
    return 0;
}
