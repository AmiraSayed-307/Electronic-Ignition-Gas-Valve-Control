#include <msp430.h>
#include "flame_sensor.h"

#define FLAME_ADC_CHANNEL  ADCINCH_3   // A3 = P1.3
#define FLAME_THRESHOLD    1500          // Start low; tune later

void Flame_Init(void)
{
    // Set P1.3 to analog function
    P1SEL0 |= BIT3;
    P1SEL1 |= BIT3;

    // Configure ADC for A3 input (P1.3)
    ADCCTL0 &= ~ADCENC;
    ADCCTL0  = ADCSHT_2 | ADCON;
    ADCCTL1  = ADCSHP | ADCSSEL_2;
    ADCCTL2  = ADCRES_2;               // 12-bit resolution
    ADCMCTL0 = FLAME_ADC_CHANNEL;     // A3 channel
    ADCCTL0 |= ADCENC;
}

uint8_t Flame_Detect(void)
{
    ADCCTL0 &= ~ADCENC;
    ADCMCTL0 = ADCINCH_3;         // A3 = P1.3 for Flame
    ADCCTL0 |= ADCENC;
    ADCCTL0 |= ADCSC;
    while (ADCCTL1 & ADCBUSY);

    uint16_t raw = ADCMEM0;
    return (raw > FLAME_THRESHOLD) ? 1 : 0;
}

