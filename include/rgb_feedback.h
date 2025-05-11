// rgb_feedback.h
// RGB LED feedback control for MSP430FR2355
// Provides initialization and color setting functions using PWM

#ifndef RGB_FEEDBACK_H_
#define RGB_FEEDBACK_H_

#include <stdint.h>

/**
 * @brief Initializes PWM output for RGB LED on P6.0 (Red), P6.1 (Green), P6.2 (Blue)
 *        using Timer B3 channels.
 */
void rgb_Init(void);

/**
 * @brief Sets the RGB LED color.
 *
 * @param r Red component (0–255)
 * @param g Green component (0–255)
 * @param b Blue component (0–255)
 */
void rgb_SetColor(uint8_t r, uint8_t g, uint8_t b);

#endif /* RGB_FEEDBACK_H_ */
