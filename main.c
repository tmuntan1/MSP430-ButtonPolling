#include <msp430.h>

int main ( void )
{
    WDTCTL = WDTPW | WDTHOLD;       // Stop watchdog timer
    P1DIR |= BIT0;                  // Set P1.0 to output direction
    P1REN |= BIT3;                  // Enable pullup resistor on P1.3

    for ( ;; )
    {
        volatile unsigned int i;    // volatile to prevent optimization

        if ( (P1IN & BIT3) == 0 )   // If P1.3 is not pressed
        {
            P1OUT |= BIT0;          // Turn off led at P1.0
        }
        else
        {
            P1OUT &= ~BIT0;         // Turn on led at P1.0
        }
    }
}
