#include "init.hpp"

void init()
{
    admux_init::init_ADMUX_MUX();
    admux_init::init_ADMUX_REFERENCE();

    adcsra_init::EnableConversion();
    adcsra_init::SetPrescaler();
}