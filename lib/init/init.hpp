#pragma once
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#ifndef BAD_VALUE_ENUM
#define BAD_VALUE_ENUM
    template<typename t>
    constexpr bool ImpossibleCase = false;
#endif

//Analogs read will be down 
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
        static void SetPrescaler(PrescalerSelect = PrescalerSelect::Val128);
        static void ReadData(uint16_t&); //this function reads the data from the registers
};
//end of setting up analog reads

//start of digital outputs setting
#ifdef DIGITAL_OUTPUT
enum class DPIN
{
    D0,
    D1,
    D2,
    D3,
    D4,
    D5,
    D6,
    D7,
    D8,
    D9,
    D10,
    D11,
    D12,
    D13
};//the digital pins
class digital_output
{
    public:
    digital_output() = delete;
    static void SetOutput(DPIN);
    static void OutPut(DPIN);
    static void DeleteSignal(DPIN);
};
#endif
//end of digital outputs setting
extern void init();