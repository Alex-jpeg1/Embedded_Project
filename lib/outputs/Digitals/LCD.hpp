#pragma once
#include "DigitalOutput.hpp"
#include <stdint.h>

#define LOW_NIBBLE_EXTRACTOR 0x0F
#define LCD_SIZE 0x40
#define SET_DDRAM_ADDRESS 0x80
#define LCD_CLEAR 0x01
namespace LCD4BitConfig{
#ifdef LCD8TO4

class LCD8To4BitsCommand
{
    public:
    LCD8To4BitsCommand(uint8_t val):_val(val){}
    uint8_t _val;
};

class LCD8To4Commands
{
    public:
        inline static const LCD8To4BitsCommand WakeUpCommands[] = {0x33, 0x32, 0x28, 0x0C, 0x06, 0x01};
};
class LCD8To4Bits
{
    public:
        LCD8To4Bits(DPIN RSPin, DPIN EnablePin, DPIN data0, DPIN data1, DPIN data2, DPIN data3);
        void SendMessage(uint8_t row, uint8_t col, const char* Message);
    private:
        void SendCommand(LCD8To4BitsCommand commandVal);
        void SendNibble(uint8_t nibbleVal);
        DigitalOutput _RSPin;
        DigitalOutput _EnablePin;
        DigitalOutput _data0;
        DigitalOutput _data1;
        DigitalOutput _data2;
        DigitalOutput _data3;

};
#endif
}
