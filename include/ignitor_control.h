#ifndef IGNITOR_CONTROL_H_
#define IGNITOR_CONTROL_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Initialize the Ignitor LED (connected to P5.0) as an output.
 */
void Ignitor_Init(void);

/**
 * @brief Turn the Ignitor LED ON (P5.0 = HIGH).
 */
void Ignitor_On(void);

/**
 * @brief Turn the Ignitor LED OFF (P5.0 = LOW).
 */
void Ignitor_Off(void);

/**
 * @brief Toggle the state of the Ignitor LED (P5.0).
 */
void Ignitor_Toggle(void);

#endif /* IGNITOR_CONTROL_H_ */
