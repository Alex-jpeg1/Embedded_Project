#include <avr/io.h>

#define F_CPU 16000000UL
#define LOW_HUMIDITY_PERC_VAL 50
#define DANGER_HUMIDITY_PERC_VAL 25
#define LCD8TO4
#include "../lib/outputs/Digitals/LCD.hpp"
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

        if(pot.GetPercentageValue() < LOW_HUMIDITY_PERC_VAL)
        {
            warningLedHumidityLow.OutputSignal();
            if(pot.GetPercentageValue() < DANGER_HUMIDITY_PERC_VAL)
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
