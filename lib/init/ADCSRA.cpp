#include "init.hpp"
#include <avr/io.h>

void adcsra_init::EnableConversion()
{
    ADCSRA |= 1<<ADEN;
}

void adcsra_init::StartConversion()
{
    ADCSRA |= 1<<ADSC;

    while((ADCSRA & (1<<ADSC)));
}
void adcsra_init::ReadData(uint16_t& target)
{
    target = ADC;
    ADCSRA |= 1<<ADIF;
}

void adcsra_init::SetPrescaler(PrescalerSelect prescalerVal)
{
    ADCSRA &= ~((1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0));

    switch (prescalerVal)
    {
        case PrescalerSelect::Val128:
            ADCSRA |= ((1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0));
        break;
        case PrescalerSelect::Val64:
            ADCSRA |= ((1<<ADPS2) | (1<<ADPS1));
        break;
        default:
            
        break;
    }
}