# Pegasus Pizza Delivery Drone
2017 SMU Senior Design Project by Team Pegasus

Visit our website at: [pegasusdrone.wordpress.com](http://pegasusdrone.wordpress.com)

Team:
* Austin Flanagan, BS Mechanical Engineering, MS Mechanical Engineering
* Alyssa Holland, BS Mechanical Engineering
* Edward Li, BS Electrical Engineering, MA Design & Innovation
* Robert Pulatie, BS Electrical Engineering
* Samantha Reeve, BS Mechanical Engineering

This respository contains all the code progress our team made throughout the course of Spring 2017. Below is a breakdown of what the repository's contents are:

Folder/File | Purpose
--- | ---
Octanis1-Mainboard-Firmware_MSP_EXP432P401RLP | This folder contains the firmware written for a custom MSP432-based controller used in a weather rover. More information about this project can be found at their [website](http://octanis.org/) or their [Github](https://github.com/octanis1).
boostxl_sensors_sensorGui_msp432p401r_MSP_EXP432P401R_nortos_ccs | timer_a_pwm_mode is a file added to the original example sensors boosterpack in an attempt to implement motor control alongside sensor data input. Code is non-functional.
ppmreceiverread | Example code that allows for data to be read in from a RC controller (we used a [Futaba Radio System](http://www.helipal.com/futaba-8fg-super-r6208sb-hv-receiver-radio-system.html)). This code will only run in Arduino.
timer_a_pwm_mode_MSP_EXP432P401R_nortos_ccs | Modified example program that allows for control of four brushless motors based on button inputs from the MSP432 Launchpad. In this program, the Timer_A module is used to create a precision PWM with an adjustable duty cycle from 5% (1ms) to 10% (2ms). The PWM initial period is 20ms and is output on P7.7, P7.6, P7.5, and P7.4. The initial duty cycle of the PWM is 5%, however, when the button is pressed on P1.1 or P1.4, the duty cycle is sequentially increased by 1.25% (2.5ms). Once the duty cycle reaches 10%, the duty cycle is sequentially decreased by 1.25% (2.5ms) per button press until it reaches 5% again. This is the base code for operating 4 motors of a quadcopter using only one timer base.
Error-614 fix.PNG | Method for fixing the error below.
error-614 encountered.PNG | An error we encountered the first time we tried flashing the example project.

If you have any questions about this code, please contact rpulatie@smu.edu.
