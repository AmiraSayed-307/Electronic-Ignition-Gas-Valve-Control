/**
 * @file    pilot_valve.c
 * @author  Amira Sayed
 * @brief   Pilot solenoid valve control functions for MSP430FR2355 (P5.4).
 * 
 * This module provides initialization and control of the pilot solenoid valve 
 * connected to GPIO pin P5.4. It includes functions to energize (open) and 
 * de-energize (close) the valve safely.
 */

#include <msp430.h>
#include "pilot_valve.h"

#define PILOT_VALVE_PORT_DIR   P5DIR
#define PILOT_VALVE_PORT_OUT   P5OUT
#define PILOT_VALVE_PIN        BIT4

void PilotValve_Init(void)
{
    PILOT_VALVE_PORT_DIR |= PILOT_VALVE_PIN;   // Set P5.4 as output
    PILOT_VALVE_PORT_OUT &= ~PILOT_VALVE_PIN;  // Ensure valve is OFF initially
}

void PilotValve_Open(void)
{
    PILOT_VALVE_PORT_OUT |= PILOT_VALVE_PIN;   // Energize solenoid
}

void PilotValve_Close(void)
{
    PILOT_VALVE_PORT_OUT &= ~PILOT_VALVE_PIN;  // De-energize solenoid
}
