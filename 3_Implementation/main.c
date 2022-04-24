#include <avr/io.h> //header to enable data flow control over pins
#define F_CPU 1000000 //telling controller crystal frequency
#include <util/delay.h> //header to enable delay function in program

int main(void)
{
    DDRB = 0b11111100; //PB0,PB1 are used as inputs and reset are used as outputs
    int x=0; // taking a integer
    while(1)
    {
               if (bit_is_clear(PINB,1)) // In presence of darkness (When there is darkness pin goes low)
               {
                     if (bit_is_set(PINB,0)) //When there is motion (motion sensor gives high output on presence of human being)
                    {
                          x=1; //set x when both conditions are satified
                    }
               }

             if (x==1) //when x is set
            {
                 PORTB |=(1<<PINB2); //trigger transistor to drive power led
                _delay_ms(220); //wait 220ms (can be changed for higher duartion)
                PORTB &=~(1<<PINB2); //turn on transistor trigger
                x=0; // reset x
            }
     }
}
