/**
 * @file    flame_sensor.h
 * @author  Amira Sayed
 * @brief   Direct ADC flame detection using K-type thermocouple on A1 (P1.1).
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include <stdint.h>

/**
 * @brief  Initialize ADC for flame sensor input (A1).
 */
void Flame_Init(void);

/**
 * @brief  Detect flame presence based on ADC voltage threshold.
 * @return 1 if flame detected, 0 otherwise.
 */
uint8_t Flame_Detect(void);

#endif /* FLAME_SENSOR_H_ */
