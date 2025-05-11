/**
 * @file    thermistor.h
 * @author  Amira Sayed
 * @brief   Thermistor driver (ADC channel A6, P1.6) for MSP430FR2355.
 *
 * Provides simple initialisation and raw 12-bit reads.
 */

#ifndef THERMISTOR_H_
#define THERMISTOR_H_

#include <stdint.h>

/**
 * @brief  Configure ADC12_B to sample A6 (P1.6).
 */
void Thermistor_Init(void);

/**
 * @brief  Return one 12‑bit ADC reading from A6.
 * @return 0 – 4095 raw code (VR+ = AVCC, VR‑ = AVSS)
 */
uint16_t Thermistor_ReadRaw(void);

#endif /* THERMISTOR_H_ */
