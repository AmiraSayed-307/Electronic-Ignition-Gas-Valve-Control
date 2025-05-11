/**
 * @file    potentiometer.c
 * @author  Amira Sayed
 * @brief   ADC12_B single‑channel read of potentiometer on A5.
 *
 * Clock assumptions:
 *   • DCO ~ 1 MHz (default after reset)
 *   • SMCLK = DCO
 */

#include <msp430.h>
#include "potentiometer.h"

void Potentiometer_Init(void)
{
    /* Select analog function for P1.5 (A5) */
    P1SEL0 |= BIT5;
    P1SEL1 |= BIT5;

    /* Hold ADC in reset while configuring */
    ADCCTL0 &= ~ADCENC;

    /* ADC12_B control registers */
    ADCCTL0  = ADCSHT_2 | ADCON;          /* 16 ADC clk S&H, ADC on            */
    ADCCTL1  = ADCSHP    | ADCSSEL_2;     /* sample‑and‑hold pulse, SMCLK      */
    ADCCTL2  = ADCRES_2;                  /* 12‑bit conversion resolution      */
    ADCMCTL0 = ADCINCH_5;                 /* input channel A5, VR+=AVCC, VR‑=AVSS */

    ADCCTL0 |= ADCENC;                    /* enable ADC conversions            */
}

uint16_t Potentiometer_ReadRaw(void)
{
    ADCCTL0 &= ~ADCENC;
    ADCMCTL0 = ADCINCH_5;         // A5 = P1.5 for Potentiometer
    ADCCTL0 |= ADCENC;
    ADCCTL0 |= ADCSC;
    while (ADCCTL1 & ADCBUSY);

    return ADCMEM0;
}

