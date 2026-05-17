#include "init.hpp"

void init()
{
    DDRB |= LedPin;
    DDRD &= ~ ButtonPin;
}

void CloseLED()
{
    PORTB &= ~LedPin;
}

void StartLED()
{
    PORTB |= LedPin;
}

void ChangeState(void (*stateFunction)())
{
    stateFunction();
}