#include <msp430.h>
#include "servo_control.h"

void servoInit(){
    P2DIR |= SERVO_PIN;             // Set P2.1 as output
    P2OUT &= ~SERVO_PIN;            // Set it low initially
}

void servoPWMInit(){
    TB1CCR0 = 21000;                // 50Hz PWM -> 20ms period
    TB1CCR2 = 1050;                 // Initialize CCR2 to roughly 1ms, full rotation left (open)
    TB1CCTL2 |= CCIE;               // Enable CCR2 interrupt
    TB1CTL |= TBSSEL__SMCLK | MC__UP | TBIE | TBCLR; // SMCLK, Up mode, Overflow IRQ
}



void servo_set(int angle){

    TB1CCR2 = (6*angle) + 1050;

}

#pragma vector=TIMER1_B1_VECTOR
__interrupt void TIMER1_B1_ISR(void)
{
    switch(__even_in_range(TB1IV, TB1IV_TBIFG))
    {
        case TB1IV_NONE:    break;
        case TB1IV_TBCCR1:  break;
        case TB1IV_TBCCR2:  P2OUT &= ~SERVO_PIN; break;  // Turn servo off
        case TB1IV_TBIFG:   P2OUT |= SERVO_PIN;  break;  // Turn servo on
        default: break;
    }
}

