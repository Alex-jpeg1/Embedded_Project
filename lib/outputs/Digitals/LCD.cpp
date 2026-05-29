#include "LCD.hpp"
#include <util/delay.h>

#ifdef LCD8TO4
LCD4BitConfig::LCD8To4Bits::LCD8To4Bits(DPIN RSPin, DPIN EnablePin, DPIN data0, DPIN data1, DPIN data2, DPIN data3)
    :_RSPin(RSPin),
     _EnablePin(EnablePin),
     _data0(data0),
     _data1(data1),
     _data2(data2),
     _data3(data3)
{
    _delay_ms(1000);
    for(int i=0;i<6;i++)
    {
        SendCommand(LCD8To4Commands::WakeUpCommands[i]);
    }
}

void LCD4BitConfig::LCD8To4Bits::SendCommand(LCD8To4BitsCommand commandVal)
{
    _RSPin.DeleteSignal();
    uint8_t highNibble = commandVal._val>>4;
    uint8_t lowNibble = commandVal._val & LOW_NIBBLE_EXTRACTOR;

    SendNibble(highNibble);
    SendNibble(lowNibble);
    if(commandVal._val == LCD_CLEAR) {
        _delay_ms(2);
    } else {
        _delay_us(50);
    }
}
void LCD4BitConfig::LCD8To4Bits::SendMessage(uint8_t row, uint8_t col, const char* Message)
{
    uint8_t ddram_address = col; 
    
    if (row == 1) {
        ddram_address += LCD_SIZE; 
    }

    SendCommand(LCD8To4BitsCommand(SET_DDRAM_ADDRESS | ddram_address));
    
    _RSPin.OutputSignal();

    while (*Message != '\0') 
    {
        uint8_t charData = (uint8_t)(*Message);
        
        uint8_t highNibble = charData >> 4;
        uint8_t lowNibble = charData & LOW_NIBBLE_EXTRACTOR;

        SendNibble(highNibble);
        SendNibble(lowNibble);
        
        ++Message;
        _delay_us(50);
    }
}
void LCD4BitConfig::LCD8To4Bits::SendNibble(uint8_t nibbleVal)
{
    (nibbleVal & (1 << 0)) ? _data0.OutputSignal() : _data0.DeleteSignal();
    (nibbleVal & (1 << 1)) ? _data1.OutputSignal() : _data1.DeleteSignal();
    (nibbleVal & (1 << 2)) ? _data2.OutputSignal() : _data2.DeleteSignal();
    (nibbleVal & (1 << 3)) ? _data3.OutputSignal() : _data3.DeleteSignal();

    _EnablePin.OutputSignal();
    
    _delay_us(1);
    
    _EnablePin.DeleteSignal();
}

#endif