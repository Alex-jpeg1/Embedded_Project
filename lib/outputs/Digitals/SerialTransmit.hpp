#pragma once
#include "avr/io.h"
#include <stdint.h>

inline void USART_Init(uint16_t ubrr) {
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;
    UCSR0B = (1<<TXEN0) | (1<<RXEN0);
    UCSR0C = (3<<UCSZ00);
}

inline void USART_Transmit(unsigned char data) {
    while (!(UCSR0A & (1<<UDRE0)));
    UDR0 = data;
}
inline void USART_Print(const char* str) {
    while (*str) {
        USART_Transmit(*str++);
    }
}