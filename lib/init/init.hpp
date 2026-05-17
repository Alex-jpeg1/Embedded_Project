#pragma once
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#ifdef MACRO

#define LED 5
#define BUTTON 2
#else
constexpr uint8_t LED = 5; 
constexpr uint8_t BUTTON = 2;
#endif

const uint8_t LedPin = 1<<LED;

const uint8_t ButtonPin = 1<<BUTTON;

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

extern void init();