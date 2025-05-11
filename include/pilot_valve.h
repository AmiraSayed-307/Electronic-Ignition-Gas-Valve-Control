#ifndef PILOT_VALVE_H_
#define PILOT_VALVE_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Initialize the Pilot Solenoid Valve (P5.4) as an output.
 */
void PilotValve_Init(void);

/**
 * @brief Turn ON (energize) the pilot solenoid valve.
 */
void PilotValve_Open(void);

/**
 * @brief Turn OFF (de-energize) the pilot solenoid valve.
 */
void PilotValve_Close(void);

#endif /* PILOT_VALVE_H_ */
