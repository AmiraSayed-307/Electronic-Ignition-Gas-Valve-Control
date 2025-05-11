/**
 * @file    ignitor_control.c
 * @author  Amira Sayed
 * @brief   Ignitor LED control functions for MSP430FR2355 (P5.0).
 * 
 * This module provides initialization and control of the Ignitor LED 
 * connected to GPIO pin P5.0. It includes functions to initialize the 
 * pin, turn the LED on/off, and toggle it.
 */

#include <msp430.h>
#include "ignitor_control.h"

#define IGNITOR_PORT_DIR   P5DIR
#define IGNITOR_PORT_OUT   P5OUT
#define IGNITOR_PIN        BIT0

void Ignitor_Init(void)
{
    IGNITOR_PORT_DIR |= IGNITOR_PIN;   // Set P5.0 as output
    IGNITOR_PORT_OUT &= ~IGNITOR_PIN;  // Start with LED OFF
}

void Ignitor_On(void)
{
    IGNITOR_PORT_OUT |= IGNITOR_PIN;
}

void Ignitor_Off(void)
{
    IGNITOR_PORT_OUT &= ~IGNITOR_PIN;
}

void Ignitor_Toggle(void)
{
    IGNITOR_PORT_OUT ^= IGNITOR_PIN;
}
