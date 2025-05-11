/**
 * @file    cfh_signal.h
 * @author  Amira Sayed
 * @brief   Call-for-Heat signal interrupt-based monitor (P3.0 input).
 */

#ifndef CFH_SIGNAL_H_
#define CFH_SIGNAL_H_

#include <stdbool.h>

/**
 * @brief  Initialize CFH pin (P3.0) with interrupt on edge.
 */
void callForHeat_Init(void);

/**
 * @brief  Returns whether CFH is currently active.
 * @return true if CFH is HIGH, false if LOW.
 */
bool callForHeat_Triggered(void);

#endif /* CFH_SIGNAL_H_ */
