/**
 * @file    cfh_signal.c
 * @author  Amira Sayed
 * @brief   Edge-triggered detection of Call-for-Heat signal on P3.0.
 */

#include <msp430.h>
#include "cfh_signal.h"

static volatile bool cfh_active = false;

void callForHeat_Init(void)
{
    P3DIR &= ~BIT0;         // Set P3.0 as input
    P3REN |= BIT0;          // Enable pull resistor
    P3OUT &= ~BIT0;         // Pull-down
    P3IES |= BIT0;          // Interrupt on HIGH-to-LOW initially (falling)
    P3IFG &= ~BIT0;         // Clear flag
    P3IE  |= BIT0;          // Enable interrupt
}

bool callForHeat_Triggered(void)
{
    return cfh_active;
}

#pragma vector=PORT3_VECTOR
__interrupt void Port_3_ISR(void)
{
    if (P3IFG & BIT0)
    {
        if (P3IN & BIT0)
        {
            cfh_active = true;        // Rising edge → CFH ON
            P3IES |= BIT0;            // Switch to falling edge
        }
        else
        {
            cfh_active = false;       // Falling edge → CFH OFF
            P3IES &= ~BIT0;           // Switch to rising edge
        }

        P3IFG &= ~BIT0;               // Clear interrupt flag
    }
}
