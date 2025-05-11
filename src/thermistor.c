/**
 * @file    thermistor.c
 * @author  Amira Sayed
 * @brief   ADC12_B single-channel read of thermistor on A6.
 *
 * Clock assumptions:
 *   • DCO ~ 1 MHz (default after reset)
 *   • SMCLK = DCO
 */

#include <msp430.h>
#include "thermistor.h"

void Thermistor_Init(void)
{
    /* Select analog function for P1.6 (A6) */
    P1SEL0 |= BIT6;
    P1SEL1 |= BIT6;

    /* Hold ADC in reset while configuring */
    ADCCTL0 &= ~ADCENC;

    /* ADC12_B control registers */
    ADCCTL0  = ADCSHT_2 | ADCON;          /* 16 ADC clk S&H, ADC on            */
    ADCCTL1  = ADCSHP    | ADCSSEL_2;     /* sample‑and‑hold pulse, SMCLK      */
    ADCCTL2  = ADCRES_2;                  /* 12‑bit conversion resolution      */
    ADCMCTL0 = ADCINCH_6;                 /* input channel A6, VR+=AVCC, VR‑=AVSS */

    ADCCTL0 |= ADCENC;                    /* enable ADC conversions            */
}

uint16_t Thermistor_ReadRaw(void)
{
    ADCCTL0 &= ~ADCENC;
    ADCMCTL0 = ADCINCH_6;         // A6 = P1.6 for Thermistor
    ADCCTL0 |= ADCENC;
    ADCCTL0 |= ADCSC;
    while (ADCCTL1 & ADCBUSY);

    return ADCMEM0;
}

