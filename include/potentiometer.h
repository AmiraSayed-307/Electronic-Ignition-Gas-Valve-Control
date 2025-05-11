/**
 * @file    potentiometer.h
 * @author  Amira Sayed
 * @brief   Potentiometer driver (ADC channel A5, P1.5) for MSP430FR2355.
 *
 * Provides simple initialisation and raw 12‑bit reads.
 */

#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_

#include <stdint.h>

/**
 * @brief  Configure ADC12_B to sample A5 (P1.5).
 */
void Potentiometer_Init(void);

/**
 * @brief  Return one 12‑bit ADC reading from A5.
 * @return 0 – 4095 raw code (VR+ = AVCC, VR‑ = AVSS)
 */
uint16_t Potentiometer_ReadRaw(void);

#endif /* POTENTIOMETER_H_ */
