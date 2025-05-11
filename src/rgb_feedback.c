/**
 * @file    rgb_feedback.c
 * @author  Amira Sayed
 * @brief   RGB LED feedback control for MSP430FR2355 using TimerB3 PWM.
 * 
 * This module sets up PWM channels TB3.1, TB3.2, and TB3.3 on pins 
 * P6.0 (Red), P6.1 (Green), and P6.2 (Blue) to control the RGB LED.
 * It provides functions to initialize the PWM and to set the LED color 
 * via 8-bit RGB values (0–255). For common anode LEDs, the duty cycle
 * values are inverted.
 */

#include <msp430.h>
#include <stdint.h>
#include "rgb_feedback.h"

#define RGB_TIMER_PERIOD 255

void rgb_Init(void)
{
    // Configure P6.0, P6.1, P6.2 as PWM outputs (TimerB3.1/2/3)
    P6DIR |= BIT0 | BIT1 | BIT2;
    P6SEL0 |= BIT0 | BIT1 | BIT2;  // Select primary peripheral function (TB3)
    P6SEL1 &= ~(BIT0 | BIT1 | BIT2);

    // Stop TimerB3
    TB3CTL = TBSSEL__SMCLK | MC__STOP | TBCLR;

    // Set PWM period
    TB3CCR0 = RGB_TIMER_PERIOD;

    // Configure CCR1, CCR2, CCR3 as Reset/Set output mode
    TB3CCTL1 = OUTMOD_7;
    TB3CCTL2 = OUTMOD_7;
    TB3CCTL3 = OUTMOD_7;

    // Start timer in Up mode
    TB3CTL |= MC__UP;

    // Initialize LED to off (0% duty cycle)
    rgb_SetColor(0, 0, 0);
}

void rgb_SetColor(uint8_t r, uint8_t g, uint8_t b)
{
    // Invert values for common anode RGB LED
    TB3CCR1 = 255 - r;  // Red
    TB3CCR2 = 255 - g;  // Green
    TB3CCR3 = 255 - b;  // Blue
}
