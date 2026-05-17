#define F_CPU 16000000UL
#define MACRO
#include "../lib/init/init.hpp"



int main(void)
{
    init();

    while(1)
    {
        if((PIND & ButtonPin )!= 0)
        {
            ChangeState(StartLED);
        }
        else
        {
            ChangeState(CloseLED);
        }
    }
    return 0;
}
