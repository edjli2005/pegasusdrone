/*
 * -------------------------------------------
 *    MSP432 DriverLib - v4_00_00_11
 * -------------------------------------------
 *
 * --COPYRIGHT--,BSD,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/*******************************************************************************
 * MSP432 Timer_A - Variable PWM
 *
 *
 * Description: In this program, the Timer_A module is used to create a precision
 * PWM with an adjustable duty cycle from 5% (1ms) to 10% (2ms). The PWM initial period is 20ms
 * and is output on P7.7, P7.6, P7.5, and P7.4. The initial duty cycle of the PWM is 5%, however,
 * when the button is pressed on P1.1 or P1.4, the duty cycle is sequentially increased by 1.25% (2.5ms)
 * Once the duty cycle reaches 10%, the duty cycle is sequentially decreased by 1.25% (2.5ms) per button
 * press until it reaches 5% again.
 * This is the base code for operating 4 motors of a quadcopter using only one timer base.
 *
 *
 *
 *
 *                MSP432P401
 *             ------------------
 *         /|\|                  |
 *          | |                  |
 *          --|RST         P1.1  |<--Toggle Switch
 *            |            P1.4  |<--Toggle Switch
 *            |                  |
 *            |            P7.7  |--> Output PWM Timer A1.1
 *            |            P7.6  |--> Output PWM Timer A1.2
 *            |            P7.5  |--> Output PWM Timer A1.3
 *            |            P7.4  |--> Output PWM Timer A1.4
 *            |                  |
 *            |            P1.0  |--> LED Debug indicator
 *            |                  |
 *            |                  |
* Author: Timothy Logan, Robert Pulatie
 *******************************************************************************/
// DriverLib Includes
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

// Standard Includes
#include <stdint.h>
#include <stdbool.h>


#include <ti/devices/msp432p4xx/inc/msp432.h>
#include "timer_a_pwm_mode.h"

// page 48 msp432p401r
// page 14 MSP-EXP432P401R


// Timer_A1.1 PWM Configuration Parameter pin 7.7 primary (reg 1), MOTOR 1 CCW
Timer_A_PWMConfig pwmConfigA1_1 =
{
        TIMER_A_CLOCKSOURCE_ACLK, // 32kHz
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        640,
        TIMER_A_CAPTURECOMPARE_REGISTER_1,
        TIMER_A_OUTPUTMODE_RESET_SET,
        32 // 5% or 1ms duty cycle
};
// Timer_A1.2 PWM Configuration Parameter pin 7.6 primary, MOTOR 2 CCW
Timer_A_PWMConfig pwmConfigA1_2 =
{
        TIMER_A_CLOCKSOURCE_SMCLK, //12MHz
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        240000, // this num/ 12M = period
        TIMER_A_CAPTURECOMPARE_REGISTER_2,
        TIMER_A_OUTPUTMODE_RESET_SET,
        12000 // 5% or 1ms duty cycle
};
// Timer_A1.3 PWM Configuration Parameter pin 7.5 primary, MOTOR 3 CW
Timer_A_PWMConfig pwmConfigA1_3 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        240000,
        TIMER_A_CAPTURECOMPARE_REGISTER_3,
        TIMER_A_OUTPUTMODE_RESET_SET,
        12000 // 5% or 1ms duty cycle
};
// Timer_A1.4 PWM Configuration Parameter pin 7.4 primary (reg 4), MOTOR 4 CW
Timer_A_PWMConfig pwmConfigA1_4 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        240000,
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        12000 // 5% or 1ms duty cycle
};


// Function Prototypes

// configure pins and output PWM signals for driving the motors
void pwmInit(void)
{
    // configure pins for output of PWM signals
    // Configuring GPIO 7.7 as peripheral output Timer A1.1 PWM
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P7, GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);
    // Configuring GPIO 7.6 for Timer A1.2 PWM output
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P7, GPIO_PIN6, GPIO_PRIMARY_MODULE_FUNCTION);
    // Configuring GPIO 7.5 for Timer A1.3 PWM output
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P7, GPIO_PIN5, GPIO_PRIMARY_MODULE_FUNCTION);
    // Configuring GPIO 7.4 as peripheral output TIMER A1.4 for PWM output
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P7, GPIO_PIN4, GPIO_PRIMARY_MODULE_FUNCTION);


    // Configuring Timer_A to have a period of approximately 20ms and an initial duty cycle of 5% of that
    //generate PWM signals, TIMER A1 base
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_1);
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_2);
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_3);
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_4);
}

// enabling buttons 1.1 and 1.4 for easy throttle control
 void enableButtons(void)
 {
     // P1.1 for button interrupt
     MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1);
     MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN1);
     MAP_GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN1);
     // P1.4 for button interrupt
     MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN4);
     MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN4);
     MAP_GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN4);

     // Enabling interrupts
     MAP_Interrupt_enableInterrupt(INT_PORT1);



     // Set P1.0 to output direction (LED)
     // debug purposes
     MAP_GPIO_setAsOutputPin(GPIO_PORT_P1,GPIO_PIN0);
 }



// In future, will read from RC controller
// For now, ensures the throttle is between 0 and 100%
int32_t getNewThrottle1(void)
{
    int32_t throttle = 0;
    if(pwmConfigA1_1.dutyCycle == 64) //   10% cycle at 128,           OG 28800 90%
    {
        throttle = -8;             // 1.25% change
    }
    if(pwmConfigA1_1.dutyCycle == 32) //   5% cycle, 1ms          OG 28800 90%
    {
        throttle = 8;
    }
    return throttle;
}

// Throttle motor 1 depending on input throttle from controller
// For now, only 25% increments
void throttleMotor1(int32_t throttle)
{
    pwmConfigA1_1.dutyCycle += throttle; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms     OG 3200 10%
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_1);
}


// In future, will read from RC controller
// For now, ensures the throttle is between 0 and 100%
int32_t getNewThrottle2(void)
{
    int32_t throttle = 0;
    if(pwmConfigA1_2.dutyCycle == 24000) //   10% cycle at 128,           OG 28800 90%
    {
        throttle = -3000;
    }
    if(pwmConfigA1_2.dutyCycle == 12000) //   5% cycle, 1ms          OG 28800 90%
    {
        throttle = 3000;
    }
    return throttle;
}

// Throttle motor 2 depending on input throttle from controller
// For now, only 25% increments
void throttleMotor2(int32_t throttle)
{
    pwmConfigA1_2.dutyCycle += throttle; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms     OG 3200 10%
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_2);
}


// In future, will read from RC controller
// For now, ensures the throttle is between 0 and 100%
int32_t getNewThrottle3(void)
{
    int32_t throttle = 0;
    if(pwmConfigA1_3.dutyCycle == 24000) //   10% cycle at 128,           OG 28800 90%
    {
        throttle = -3000;
    }
    if(pwmConfigA1_3.dutyCycle == 12000) //   5% cycle, 1ms          OG 28800 90%
    {
        throttle = 3000;
    }
    return throttle;
}

// Throttle motor 3 depending on input throttle from controller
// For now, only 25% increments
void throttleMotor3(int32_t throttle)
{
    pwmConfigA1_3.dutyCycle += throttle; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms     OG 3200 10%
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_3);
}


// In future, will read from RC controller
// For now, ensures the throttle is between 0 and 100%
int32_t getNewThrottle4(void)
{
    int32_t throttle = 0;
    if(pwmConfigA1_4.dutyCycle == 24000) //   10% cycle at 128,           OG 28800 90%
    {
        throttle = -3000;
    }
    if(pwmConfigA1_4.dutyCycle == 12000) //   5% cycle, 1ms          OG 28800 90%
    {
        throttle = 3000;
    }
    return throttle;
}

// Throttle motor 4 depending on input throttle from controller
// For now, only 25% increments
void throttleMotor4(int32_t throttle)
{
    pwmConfigA1_4.dutyCycle += throttle; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms     OG 3200 10%
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_4);
}




/*
// Timer_A1.1 PWM Configuration Parameter pin 7.7 primary (reg 1), MOTOR 1 CCW
Timer_A_PWMConfig pwmConfigA1_1 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        1280, // this num/ 64k = period       OG 32000
        TIMER_A_CAPTURECOMPARE_REGISTER_1,
        TIMER_A_OUTPUTMODE_RESET_SET,
        64 // 5% or 1ms duty cycle             OG 3200
        //96 // 7.5% or 1.5ms duty cycle        cannot start above throttle 0     OG 3200
};
// Timer_A1.2 PWM Configuration Parameter pin 7.6 primary, MOTOR 2 CCW
Timer_A_PWMConfig pwmConfigA1_2 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        1280, // this num/ 64k = period       OG 32000
        TIMER_A_CAPTURECOMPARE_REGISTER_2,
        TIMER_A_OUTPUTMODE_RESET_SET,
        64 // 5% or 1ms duty cycle             OG 3200
};
// Timer_A1.3 PWM Configuration Parameter pin 7.5 primary, MOTOR 3 CW
Timer_A_PWMConfig pwmConfigA1_3 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        1280, // this num/ 64k = period       OG 32000
        TIMER_A_CAPTURECOMPARE_REGISTER_3,
        TIMER_A_OUTPUTMODE_RESET_SET,
        64 // 5% or 1ms duty cycle             OG 3200
};
// Timer_A1.4 PWM Configuration Parameter pin 7.4 primary (reg 4), MOTOR 4 CW
Timer_A_PWMConfig pwmConfigA1_4 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        1280, // this num/ 64k = period       OG 32000
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        64 // 5% or 1ms duty cycle             OG 3200
};


int main(void)
{
    // Halting the watchdog
    MAP_WDT_A_holdTimer();

    // Setting MCLK to REFO at 128Khz for LF mode
    // Setting SMCLK to 64Khz
    MAP_CS_setReferenceOscillatorFrequency(CS_REFO_128KHZ);
    MAP_CS_initClockSignal(CS_MCLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    MAP_CS_initClockSignal(CS_SMCLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_2);
    MAP_PCM_setPowerState(PCM_AM_LF_VCORE0);

    // P1.1 for button interrupt
    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN1);
    MAP_GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN1);
    // P1.4 for button interrupt
    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN4);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN4);
    MAP_GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN4);

    // Configuring GPIO 7.7 as peripheral output Timer A1.1 PWM
    // Configuring GPIO 7.6 for Timer A1.2 PWM output
    // Configuring GPIO 7.5 for Timer A1.3 PWM output
    // Configuring GPIO 7.4 as peripheral output TIMER A1.4 for PWM output
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P7, GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P7, GPIO_PIN6, GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P7, GPIO_PIN5, GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P7, GPIO_PIN4, GPIO_PRIMARY_MODULE_FUNCTION);


    // Set P1.0 to output direction (LED)
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P1,GPIO_PIN0);

    // Configuring Timer_A to have a period of approximately 20ms and an initial duty cycle of 5% of that (64 ticks)
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_1);
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_2);
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_3);
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_4);

    // Enabling interrupts and starting the watchdog timer
    MAP_Interrupt_enableInterrupt(INT_PORT1);
    MAP_Interrupt_enableSleepOnIsrExit();
    MAP_Interrupt_enableMaster();

    // Sleeping when not in use
    while (1)
    {
        MAP_PCM_gotoLPM0();
    }
}

// Port1 ISR - This ISR will progressively step up the duty cycle of the PWM  on a button press
void PORT1_IRQHandler(void)
{
    volatile uint32_t i;
    int32_t speedChange;           // %percent change on button press 16 for 1.25% increase or 0.25ms 32 for 2.5% or .5ms
    uint32_t status = MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P1);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, status);

    if (status & GPIO_PIN1) // if button 1.1 is pressed
    {
        // TimerA1.1 pin 7.7 Motor 1 CCW
        if(pwmConfigA1_1.dutyCycle == 128) //   10% cycle at 128,           OG 28800 90%
        {
            speedChange = -16;
        }
        if(pwmConfigA1_1.dutyCycle == 64) //   5% cycle, 1ms          OG 28800 90%
        {
            speedChange = 16;
        }
        pwmConfigA1_1.dutyCycle += speedChange; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms     OG 3200 10%
        MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_1);

        // TimerA1.2 pin 7.6 Motor 2 CCW
        if(pwmConfigA1_2.dutyCycle == 128) //   10% cycle at 128,           OG 28800 90%
        {
            speedChange = -16;
        }
        if(pwmConfigA1_2.dutyCycle == 64) //   5% cycle, 1ms          OG 28800 90%
        {
            speedChange = 16;
        }
        pwmConfigA1_2.dutyCycle += speedChange; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms     OG 3200 10%
        MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_2);

        // Toggle P1.0 output - Button Press debug purposes
        MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1,GPIO_PIN0);
    }
    if (status & GPIO_PIN4) // if button 1.4 is pressed
    {
        // TimerA1.3 pin 7.5 Motor 3 CW
        if(pwmConfigA1_3.dutyCycle == 128) //   10% cycle at 128,           OG 28800 90%
        {
            speedChange = -16;
        }
        if(pwmConfigA1_3.dutyCycle == 64) //   5% cycle, 1ms          OG 28800 90%
        {
            speedChange = 16;
        }
        pwmConfigA1_3.dutyCycle += speedChange; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms     OG 3200 10%
        MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_3);

        // TimerA1.4 pin 7.4 Motor 4 CW
        if(pwmConfigA1_4.dutyCycle == 128) //   10% cycle at 128,           OG 28800 90%
        {
            speedChange = -16;
        }
        if(pwmConfigA1_4.dutyCycle == 64) //   5% cycle, 1ms          OG 28800 90%
        {
            speedChange = 16;
        }
        pwmConfigA1_4.dutyCycle += speedChange; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms     OG 3200 10%
        MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_4);

        // Toggle P1.0 output - Button Press debug purposes
        MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1,GPIO_PIN0);
    }
}
*/
