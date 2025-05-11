# Electronic Ignition Variable Gas Valve Control Module

**Rowan University – Embedded Systems Project – Spring 2025** 
**Author:** Amira Sayed (AmiraSayed-307) 

## Description

This project implements a fully integrated electronic ignition and gas valve control system based on the MSP430FR2355 microcontroller.  
The system was designed, tested, and validated as part of the Rowan University Embedded Systems Spring 2025 course.

The control module supports safe and reliable electronic ignition of a heating appliance with automatic pilot valve control, flame sensor detection, and main valve modulation using a micro servo. The system also features RGB LED feedback and interrupt-driven Call-for-Heat signal handling.

## Features

- Call-for-Heat input detection (GPIO interrupt)
- Safe pilot ignition sequence with flame validation
- Servo-controlled main valve based on temperature setpoint vs actual temperature
- RGB LED status feedback for system state
- Modular embedded code structure for easy maintenance
- Clean project folder structure using Code Composer Studio conventions

## Project Structure

AS_ES_Final_Project/
├── include/ --> All .h header files
├── src/ --> All .c source files
├── Debug/ --> CCS debug output (not used for source)
├── driverlib/ --> Optional driver libraries
├── .settings/ --> Code Composer Studio settings
├── targetConfigs/ --> CCS target configurations
├── .ccsproject --> CCS project file
├── .cproject --> CCS project file
├── .project --> CCS project file
└── README.md --> This file

## Hardware Used

- MSP430FR2355 LaunchPad (MSP-EXP430FR2355)
- Smraza S51 micro servo
- Thermistor for boiler temperature measurement
- Potentiometer for setpoint adjustment
- Flame sensor: Thermocouple (analog voltage input)
- RGB LED for visual status
- Call-for-Heat interface using GPIO interrupt
- Ignitor LED to simulate ignition
- Solenoid Valve : Enable pilot gas line

## Hardware Files

The full project schematic and PCB design files are available on Altium 365 at: 
[Electronic Ignition Gas Valve Control PCB Project](https://rowan-university-8.365.altium.com/designs/4371E3AB-6447-4105-96EA-14A15F8EF8E9)


## How to Use

1. Clone this repository:

git clone https://github.com/AmiraSayed-307/Electronic-Ignition-Gas-Valve-Control.git


2. Open project folder in **Code Composer Studio (CCS)** 
3. Connect MSP-EXP430FR2355 LaunchPad 
4. Flash the project using CCS 
5. Connect external components as per system schematic 
6. System operates automatically after Call-for-Heat is triggered 

## Acknowledgements

- Texas Instruments (MSP430FR2355 platform) 
- Rowan University – ECE Department 
- Embedded Systems Spring 2025 Faculty 
- Karol Krupinski – For assistance with the thermocouple op-amp circuit during final hardware testing


## License

This project is for academic purposes only. 
All rights belong to Amira Sayed and Rowan University © 2025.

