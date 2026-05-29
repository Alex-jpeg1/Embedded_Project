#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
#define LOW_HUMIDITY_PERC_VAL 50
#define DANGER_HUMIDITY_PERC_VAL 25
#define SERIAL_PORT 9600
#include "../lib/outputs/Digitals/SerialTransmit.hpp"
#include "../lib/outputs/Digitals/LCD.hpp"
//#include "../lib/outputs/Digitals/DigitalOutput.hpp"
#include "../lib/init/init.hpp"
#include "../lib/inputs/Potentiometer/Potentiometer.hpp"

const char valuesToRepresent[101][4] = {
    "0##", "1##", "2##", "3##", "4##", "5##", "6##", "7##", "8##", "9##",
    "10#", "11#", "12#", "13#", "14#", "15#", "16#", "17#", "18#", "19#",
    "20#", "21#", "22#", "23#", "24#", "25#", "26#", "27#", "28#", "29#",
    "30#", "31#", "32#", "33#", "34#", "35#", "36#", "37#", "38#", "39#",
    "40#", "41#", "42#", "43#", "44#", "45#", "46#", "47#", "48#", "49#",
    "50#", "51#", "52#", "53#", "54#", "55#", "56#", "57#", "58#", "59#",
    "60#", "61#", "62#", "63#", "64#", "65#", "66#", "67#", "68#", "69#",
    "70#", "71#", "72#", "73#", "74#", "75#", "76#", "77#", "78#", "79#",
    "80#", "81#", "82#", "83#", "84#", "85#", "86#", "87#", "88#", "89#",
    "90#", "91#", "92#", "93#", "94#", "95#", "96#", "97#", "98#", "99#",
    "100"
};

int main(void)
{
    Potentiometer pot(APIN::A0);
    DigitalOutput warningLedHumidityLow(DPIN::D8);
    DigitalOutput WarningLedHumidityLowExtreme(DPIN::D9);
    LCD4BitConfig::LCD8To4Bits humidityLCD(DPIN::D5,DPIN:: D4, DPIN::D3, DPIN::D2, DPIN::D11, DPIN::D10);
    USART_Init(103);
    init();
    //humidityLCD.SendMessage(0, 0, "HUMIDITY");

    while(1)
    {
        pot.AnalogReadData();
        uint8_t humidityValue = pot.GetPercentageValue();
        if(humidityValue< LOW_HUMIDITY_PERC_VAL)
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
        humidityLCD.SendMessage(0, 0, valuesToRepresent[humidityValue]);
        USART_Print(valuesToRepresent[humidityValue]);
        _delay_ms(100);
    }
    return 0;
}
