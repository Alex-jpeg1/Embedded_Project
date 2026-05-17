#pragma once
#include "../../init/init.hpp"
#include <stdint.h>

class Potentiometer
{
    public:
        Potentiometer(APIN PinNumber, uint16_t HighestValue = 1023);
        void AnalogReadData() noexcept;
        const uint16_t& GetRawValue() const noexcept;
        uint8_t GetPercentageValue() const noexcept;
    private:
        APIN _pinNumber;
        uint16_t _highestValue;
        uint16_t _currentReadVal;
};