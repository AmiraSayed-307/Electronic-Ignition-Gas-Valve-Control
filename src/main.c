/**
 * @file main.c
 * @brief Main logic for the Electronic Ignition Variable Gas Valve Control Module
 * 
 * This integrates all subsystem modules for ignition control, flame detection,
 * temperature regulation, and visual status indication. Triggered by Call-for-Heat.
 */

#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>

// Module headers
#include "cfh_signal.h"
#include "flame_sensor.h"
#include "ignitor_control.h"
#include "pilot_valve.h"
#include "potentiometer.h"
#include "rgb_feedback.h"
#include "servo_control.h"
#include "thermistor.h"

// === Helper Prototypes ===
static bool temperatureReached(void);
static void delay_ms(uint16_t ms);

// === Main Entry Point ===
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

    // === Peripheral Initialization ===
    PilotValve_Init();
    Ignitor_Init();
    servoInit();
    servoPWMInit();
    rgb_Init();
    Thermistor_Init();
    Flame_Init();
    Potentiometer_Init();
    callForHeat_Init();

    __enable_interrupt(); // Enable global interrupts

    // === Main Control Loop ===
    while (1)
    {
        if (callForHeat_Triggered()&&!temperatureReached())
        {
            rgb_SetColor(0, 0, 0); 
            // --- Call for Heat Active: Begin Ignition Sequence ---      
            PilotValve_Open();               // Enable pilot gas
            delay_ms(1000);                  // Allow valve to stabilize

            Ignitor_On();                    // Simulate ignition
            delay_ms(2000);                  

            if (Flame_Detect())              // Check if flame successfully lit
            {
                rgb_SetColor(0, 0, 0);
                servo_set(90);
                delay_ms(3000); 
                PilotValve_Close();
                servo_set(180);
                // Maintain temperature loop until setpoint reached
                while (!temperatureReached())
                {
                    rgb_SetColor(255, 0, 0);     // RED = heating

                    delay_ms(500);          // Stabilize control loop
                }
                delay_ms(1000); 
                servo_set(0);
                Ignitor_Off();                   // Stop ignition
                rgb_SetColor(0, 255, 0);     // GREEN = setpoint reached
                delay_ms(5000); 
            }
            else
            {
                // --- Ignition Failed: Shut Down ---
                PilotValve_Close();
                Ignitor_Off();                   // Stop ignition
                rgb_SetColor(255, 0, 255);   // MAGENTA = error
                delay_ms(5000);
            }
        }
        else
        {
            // --- Idle State ---
            PilotValve_Close();              // Ensure valve is closed
            servo_set(0);                    // Close main valve
            rgb_SetColor(0, 0, 255);         // BLUE = idle
        }

        delay_ms(250); // Polling interval
    }

}

// === Helper: Check if setpoint reached ===
static bool temperatureReached(void)
{
    return Thermistor_ReadRaw() >= Potentiometer_ReadRaw();
}

// === Helper: Delay in milliseconds (assuming SMCLK = 1MHz) ===
static void delay_ms(uint16_t ms)
{
    while (ms--) __delay_cycles(1000);
}


