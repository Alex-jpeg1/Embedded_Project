
#include "DigitalOutput.hpp"
#include <assert.h>
void digital_output::SetOutput(DPIN pin)
{
    volatile uint8_t* regPTR;

    if(pin >= DPIN::D0 && pin <= DPIN::D7)
        regPTR = &DDRD;
    else if(pin >= DPIN::D8 && pin <= DPIN::D13)
        regPTR = &DDRB;
    else 
        assert(ImpossibleCase<decltype(pin)> && "Bad value assign, program terminates");
    switch (pin)
    {
        case DPIN::D0:
            *regPTR |= (1 << DDD0);
            break;
        case DPIN::D1:
            *regPTR |= (1 << DDD1);
            break;
        case DPIN::D2:
            *regPTR |= (1 << DDD2);
            break;
        case DPIN::D3:
            *regPTR |= (1 << DDD3);
            break;
        case DPIN::D4:
            *regPTR |= (1 << DDD4);
            break;
        case DPIN::D5:
            *regPTR |= (1 << DDD5);
            break;
        case DPIN::D6:
            *regPTR |= (1 << DDD6);
            break;
        case DPIN::D7:
            *regPTR |= (1 << DDD7);
            break;
        case DPIN::D8:
            *regPTR |= (1 << DDB0);
            break;
        case DPIN::D9:
            *regPTR |= (1 << DDB1);
            break;
        case DPIN::D10:
            *regPTR |= (1 << DDB2);
            break;
        case DPIN::D11:
            *regPTR |= (1 << DDB3);
            break;
        case DPIN::D12:
            *regPTR |= (1 << DDB4);
            break;
        case DPIN::D13:
            *regPTR |= (1 << DDB5);
            break;
        default:
            assert(ImpossibleCase<decltype(pin)> && "Bad value assign, program terminates");
            break;
    }
}

void digital_output::OutPut(DPIN pin)
{
    volatile uint8_t* regPTR;

    if(pin >= DPIN::D0 && pin <= DPIN::D7)
        regPTR = &PORTD;
    else if(pin >= DPIN::D8 && pin <= DPIN::D13)
        regPTR = &PORTB;
    else 
        assert(ImpossibleCase<decltype(pin)> && "Bad value assign, program terminates");

    switch (pin)
    {
        case DPIN::D0:
            *regPTR |= (1 << PORTD0);
            break;
        case DPIN::D1:
            *regPTR |= (1 << PORTD1);
            break;
        case DPIN::D2:
            *regPTR |= (1 << PORTD2);
            break;
        case DPIN::D3:
            *regPTR |= (1 << PORTD3);
            break;
        case DPIN::D4:
            *regPTR |= (1 << PORTD4);
            break;
        case DPIN::D5:
            *regPTR |= (1 << PORTD5);
            break;
        case DPIN::D6:
            *regPTR |= (1 << PORTD6);
            break;
        case DPIN::D7:
            *regPTR |= (1 << PORTD7);
            break;
        case DPIN::D8:
            *regPTR |= (1 << PORTB0);
            break;
        case DPIN::D9:
            *regPTR |= (1 << PORTB1);
            break;
        case DPIN::D10:
            *regPTR |= (1 << PORTB2);
            break;
        case DPIN::D11:
            *regPTR |= (1 << PORTB3);
            break;
        case DPIN::D12:
            *regPTR |= (1 << PORTB4);
            break;
        case DPIN::D13:
            *regPTR |= (1 << PORTB5);
            break;
        default:
            assert(ImpossibleCase<decltype(pin)> && "Bad value assign, program terminates");
            break;
    }
}

void digital_output::DeleteSignal(DPIN pin)
{
    volatile uint8_t* regPTR;

    if(pin >= DPIN::D0 && pin <= DPIN::D7)
        regPTR = &PORTD;
    else if(pin >= DPIN::D8 && pin <= DPIN::D13)
        regPTR = &PORTB;
    else 
        assert(ImpossibleCase<DPIN> && "Bad value assign, program terminates");

    switch (pin)
    {
        case DPIN::D0:
            *regPTR &= ~(1 << PORTD0);
            break;
        case DPIN::D1:
            *regPTR &= ~(1 << PORTD1);
            break;
        case DPIN::D2:
            *regPTR &= ~(1 << PORTD2);
            break;
        case DPIN::D3:
            *regPTR &= ~(1 << PORTD3);
            break;
        case DPIN::D4:
            *regPTR &= ~(1 << PORTD4);
            break;
        case DPIN::D5:
            *regPTR &= ~(1 << PORTD5);
            break;
        case DPIN::D6:
            *regPTR &= ~(1 << PORTD6);
            break;
        case DPIN::D7:
            *regPTR &= ~(1 << PORTD7);
            break;
        case DPIN::D8:
            *regPTR &= ~(1 << PORTB0);
            break;
        case DPIN::D9:
            *regPTR &= ~(1 << PORTB1);
            break;
        case DPIN::D10:
            *regPTR &= ~(1 << PORTB2);
            break;
        case DPIN::D11:
            *regPTR &= ~(1 << PORTB3);
            break;
        case DPIN::D12:
            *regPTR &= ~(1 << PORTB4);
            break;
        case DPIN::D13:
            *regPTR &= ~(1 << PORTB5);
            break;
        default:
            assert(ImpossibleCase<DPIN> && "Bad value assign, program terminates");
            break;
    }
}


DigitalOutput::DigitalOutput(DPIN pin):_pin(pin){SetUPPIN();}
void DigitalOutput::SetUPPIN()
{
    digital_output::SetOutput(_pin);
}
void DigitalOutput::OutputSignal()
{
    digital_output::OutPut(_pin);
}
void DigitalOutput::DeleteSignal()
{
    digital_output::DeleteSignal(_pin);
}