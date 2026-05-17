#include "Potentiometer.hpp"

Potentiometer::Potentiometer(APIN PinNumber, uint16_t HighestValue):
    _pinNumber(PinNumber),
    _highestValue(HighestValue)
{}

void Potentiometer::AnalogReadData() noexcept
{
    adcsra_init::StartConversion();
    adcsra_init::ReadData(_currentReadVal);
}

const uint16_t& Potentiometer::GetRawValue() const noexcept
{
    return _currentReadVal;
}

uint8_t Potentiometer::GetPercentageValue() const noexcept
{
    return static_cast<uint8_t>((_currentReadVal * 100UL/_highestValue));
}