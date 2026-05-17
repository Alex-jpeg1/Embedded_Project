#pragma once
#include "../../init/init.hpp"
#include <stdint.h>

class Potentiometer
{
    public:
        Potentiometer(uint8_t PinNumber, uint16_t HighestValue);
        void AnalogReadData() noexcept;
        uint16_t GetRawValue() const noexcept;
        uint8_t GetPercentageValue() const noexcept;
    private:
        uint8_t _pinNumber;
        uint16_t _highestValue;
        uint16_t _currentReadVal;

};