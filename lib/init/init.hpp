#pragma once
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#ifndef BAD_VALUE_ENUM
#define BAD_VALUE_ENUM
    template<typename t>
    constexpr bool ImpossibleCase = false;
#endif


enum class VoltageReference
{
    AREF_VREF_OFF,
    AVCC_EXTERNAL_ARREF,
    RESERVED, //this returns an error when called so do not call it
    INTERNAL_11V_EXTERNAL_AREF
};


//pins codifications
enum class APIN
{
    A0,
    A1,
    A2,
    A3,
    A4, 
    A5
};

//modify using this inside the init function
class admux_init
{
    public:
        admux_init() = delete;
        static void init_ADMUX_REFERENCE(VoltageReference = VoltageReference::AVCC_EXTERNAL_ARREF);
        static void init_ADMUX_MUX(APIN = APIN::A0);
};

enum class PrescalerSelect
{
    Val128, //this is the value that should be picked to guarantee a good frequency
    Val64 //works aswell but for this purpose the other is better
};

class adcsra_init
{
    public:
        adcsra_init() = delete;
        static void EnableConversion(); //this function enables the adc
        static void StartConversion(); //this function is used to start a conversion and awaits for the conversion to complete
        static void SetPrescaler(PrescalerSelect);
        static void ReadData(uint16_t&); //this function reads the data from the registers
};

extern void init();