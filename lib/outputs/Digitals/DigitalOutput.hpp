#pragma once

#ifndef DIGITAL_OUTPUT
#define DIGITAL_OUTPUT
#endif

#include "../../init/init.hpp"

class DigitalOutput
{
    public:
        DigitalOutput(DPIN);
        void SetUPPIN();
        void OutputSignal();
        void DeleteSignal();
    private:
        DPIN _pin;
};