#include "init.hpp"
#include <avr/io.h>
#include <assert.h>

template<typename t>
constexpr bool ImpossibleCase = false;

void admux_init::init_ADMUX_MUX(APIN Pin)
{
    //Clear the bits before the set
    ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0));

    switch(Pin)
    {
        case APIN::A0:
            //Already cleared so no point in adding code
            break;
            
        case APIN::A1:
            ADMUX |= (1 << MUX0); // 0001
            break;
            
        case APIN::A2:
            ADMUX |= (1 << MUX1); // 0010
            break;
            
        case APIN::A3:
            ADMUX |= (1 << MUX1) | (1 << MUX0); // 0011
            break;
            
        case APIN::A4:
            ADMUX |= (1 << MUX2); // 0100
            break;
            
        case APIN::A5:
            ADMUX |= (1 << MUX2) | (1 << MUX0); // 0101
            break;
            
        default:
            assert(ImpossibleCase<decltype(Pin)> && "Impossible to evaluate a non case appeared");
            break;
    }
}


void admux_init::init_ADMUX_REFERENCE(VoltageReference ref)
{
    //clearing previous settings
    ADMUX &= ~((1<<REFS0) | (1<<REFS1));

    switch (ref)
    {
        case VoltageReference::AREF_VREF_OFF:
            //already cleared
        break;
        case VoltageReference::AVCC_EXTERNAL_ARREF:
            ADMUX |= 1<<REFS0;
        break;
        case VoltageReference::INTERNAL_11V_EXTERNAL_AREF:
            ADMUX |= 1<<REFS0 | 1<<REFS1;
        break;
        default:
            assert(ImpossibleCase<decltype(ref)> && "Cannot do anything value either reserved or invalid argument");
        break;
    }
}


void init()
{

}