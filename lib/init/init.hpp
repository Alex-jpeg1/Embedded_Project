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

extern void init();

extern void CloseLED();

extern void StartLED();

extern void ChangeState(void (*stateFunction)());
