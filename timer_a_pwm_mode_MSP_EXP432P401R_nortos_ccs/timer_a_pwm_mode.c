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
 * Original Description: In this example, the Timer_A module is used to create a precision
 * PWM with an adjustable duty cycle. The PWM initial period is 200 ms and is
 * output on P2.4. The initial duty cycle of the PWM is 10%, however when the
 * button is pressed on P1.1 the duty cycle is sequentially increased by 10%.
 * Once the duty cycle reaches 90%, the duty cycle is reset to 10% on the
 * following button press.
 *
 * Second Description: In this program, the Timer_A module is used to create a precision
 * PWM with an adjustable duty cycle from 5% (1ms) to 10% (2ms). The PWM initial period is 20ms
 * and is output on P2.4, P7.7, P5.6, and P10.5. The initial duty cycle of the PWM is 5%, however,
 * when the button is pressed on P1.1 or P1.4, the duty cycle is sequentially increased by 1.25% (2.5ms)
 * Once the duty cycle reaches 10%, the duty cycle is sequentially decreased by 1.25% (2.5ms) per button
 * press until it reaches 5% again.
 * This is the base code for operating 4 motors of a quadcopter.
 *
 * Final Description: In this program, the Timer_A module is used to create a precision
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
/*
//PWM variables
const uint32_t clockDutyCycle = 1280; // this num/ 64k = period = 0.02
const uint32_t initialClockDutyCycle = clockDutyCycle*0.05; // 5% or 1ms duty cycle


// Timer_A1.1 PWM Configuration Parameter pin 7.7 primary (reg 1), MOTOR 1 CCW
Timer_A_PWMConfig pwmConfigA1_1 =
{
        TIMER_A_CLOCKSOURCE_SMCLK, //64k
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        clockDutyCycle, // this num/ 3M = period
        TIMER_A_CAPTURECOMPARE_REGISTER_1,
        TIMER_A_OUTPUTMODE_RESET_SET,
        initialClockDutyCycle // 5% or 1ms duty cycle
        //96 // 7.5% or 1.5ms duty cycle        cannot start above throttle 0
};
// Timer_A1.2 PWM Configuration Parameter pin 7.6 primary, MOTOR 2 CCW
Timer_A_PWMConfig pwmConfigA1_2 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        clockDutyCycle,
        TIMER_A_CAPTURECOMPARE_REGISTER_2,
        TIMER_A_OUTPUTMODE_RESET_SET,
        initialClockDutyCycle // 5% or 1ms duty cycle
};
// Timer_A1.3 PWM Configuration Parameter pin 7.5 primary, MOTOR 3 CW
Timer_A_PWMConfig pwmConfigA1_3 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        clockDutyCycle,
        TIMER_A_CAPTURECOMPARE_REGISTER_3,
        TIMER_A_OUTPUTMODE_RESET_SET,
        initialClockDutyCycle // 5% or 1ms duty cycle
};
// Timer_A1.4 PWM Configuration Parameter pin 7.4 primary (reg 4), MOTOR 4 CW
Timer_A_PWMConfig pwmConfigA1_4 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        clockDutyCycle,
        TIMER_A_CAPTURECOMPARE_REGISTER_4,
        TIMER_A_OUTPUTMODE_RESET_SET,
        initialClockDutyCycle // 5% or 1ms duty cycle
};
*/


/*
// Timer_A1.1 PWM Configuration Parameter pin 7.7 primary (reg 1), MOTOR 1 CCW
Timer_A_PWMConfig pwmConfigA1_1 =
{
        TIMER_A_CLOCKSOURCE_SMCLK, //12MHz
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        240000, // this num/ 3M = period
        TIMER_A_CAPTURECOMPARE_REGISTER_1,
        TIMER_A_OUTPUTMODE_RESET_SET,
        12000 // 5% or 1ms duty cycle
};
*/



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

/*

// Timer_A PWM Configuration Parameter pin 2.4 primary, MOTOR 1 CCW
Timer_A_PWMConfig pwmConfig0 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        1280, // this num/ 64k = period       OG 32000
        TIMER_A_CAPTURECOMPARE_REGISTER_1,
        TIMER_A_OUTPUTMODE_RESET_SET,
        64 // 5% or 1ms duty cycle             OG 3200
};

// Timer_A1 PWM Configuration Parameter pin 7.7 primary, MOTOR 2 CCW
Timer_A_PWMConfig pwmConfig1 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        1280, // this num/ 64k = period       OG 32000
        TIMER_A_CAPTURECOMPARE_REGISTER_1,
        TIMER_A_OUTPUTMODE_RESET_SET,
        64 // 5% or 1ms duty cycle             OG 3200
        //96 // 7.5% or 1.5ms duty cycle        cannot start above throttle 0     OG 3200
};

// Timer_A2 PWM Configuration Parameter pin 5.6 primary, MOTOR 3 CW
Timer_A_PWMConfig pwmConfig2 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        1280, // this num/ 64k = period       OG 32000
        TIMER_A_CAPTURECOMPARE_REGISTER_1,
        TIMER_A_OUTPUTMODE_RESET_SET,
        64 // 5% or 1ms duty cycle             OG 3200
};

// Timer_A3 PWM Configuration Parameter pin 10.5 primary, MOTOR 4 CW
Timer_A_PWMConfig pwmConfig3 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,
        TIMER_A_CLOCKSOURCE_DIVIDER_1,
        1280, // this num/ 64k = period       OG 32000
        TIMER_A_CAPTURECOMPARE_REGISTER_1,
        TIMER_A_OUTPUTMODE_RESET_SET,
        64 // 5% or 1ms duty cycle             OG 3200
};

*/


int main(void)
{
    // Halting the watchdog
    MAP_WDT_A_holdTimer();

    // Setting MCLK to REFO at 128Khz for LF mode
    // Setting SMCLK to 64Khz
    MAP_CS_setReferenceOscillatorFrequency(CS_REFO_128KHZ);
    MAP_CS_initClockSignal(CS_MCLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    MAP_CS_initClockSignal(CS_SMCLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_2);
/*
    // Configuring pins for peripheral/crystal HFXT
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_PJ, GPIO_PIN3 | GPIO_PIN4, GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_CS_setExternalClockSourceFrequency(32768, 48000000);
    MAP_PCM_setCoreVoltageLevel(PCM_AM_LDO_VCORE0);
    MAP_FlashCtl_setWaitState(FLASH_BANK0, 1);
    MAP_FlashCtl_setWaitState(FLASH_BANK1, 1);
    MAP_CS_startHFXT(false);
    MAP_CS_initClockSignal(CS_SMCLK, CS_HFXTCLK_SELECT, CS_CLOCK_DIVIDER_4);
*/





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
/*
    // Configuring GPIO 2.4 as peripheral output Timer A0.1 PWM
    // Configuring GPIO 7.7 for Timer A1.1 PWM output
    // Configuring GPIO 5.6 for Timer A2.1 PWM output
    // Configuring GPIO 10.5 as peripheral output TIMER A3.1 for PWM output
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2, GPIO_PIN4,GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P7, GPIO_PIN7,GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P5, GPIO_PIN6,GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P10, GPIO_PIN5,GPIO_PRIMARY_MODULE_FUNCTION);
*/

    // Set P1.0 to output direction (LED)
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P1,GPIO_PIN0);

    // Configuring Timer_A to have a period of approximately 20ms and an initial duty cycle of 5% of that (64 ticks)
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_1);
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_2);
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_3);
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_4);



/*
    // OG Configuring Timer_A to have a period of approximately 500ms and an initial duty cycle of 10% of that (3200 ticks)
    // Configuring Timer_A to have a period of approximately 20ms and an initial duty cycle of 5% of that (64 ticks)
    MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig0);
    MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfig1);
    MAP_Timer_A_generatePWM(TIMER_A2_BASE, &pwmConfig2);
    MAP_Timer_A_generatePWM(TIMER_A3_BASE, &pwmConfig3);
*/

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
/*
    if (status & GPIO_PIN1) // if button 1.1 is pressed
        {
            // TimerA1.1 pin 7.7 Motor 1 CCW
            if(pwmConfigA1_1.dutyCycle == clockDutyCycle*0.1) //   10% cycle at 2ms
            {
                speedChange = -clockDutyCycle*0.0125;
            }
            if(pwmConfigA1_1.dutyCycle == clockDutyCycle*0.05) //   5% cycle, 1ms
            {
                speedChange = clockDutyCycle*0.0125;
            }
            pwmConfigA1_1.dutyCycle += speedChange; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms
            MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_1);

            // TimerA1.2 pin 7.6 Motor 2 CCW
            if(pwmConfigA1_2.dutyCycle == clockDutyCycle*0.1) //   10% cycle at 2ms
            {
                speedChange = -clockDutyCycle*0.0125;
            }
            if(pwmConfigA1_2.dutyCycle == clockDutyCycle*0.05) //   5% cycle, 1ms
            {
                speedChange = clockDutyCycle*0.0125;
            }
            pwmConfigA1_2.dutyCycle += speedChange; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms
            MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_2);

            // Toggle P1.0 output - Button Press debug purposes
            MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1,GPIO_PIN0);
        }
        if (status & GPIO_PIN4) // if button 1.4 is pressed
        {
            // TimerA1.3 pin 7.5 Motor 3 CW
            if(pwmConfigA1_3.dutyCycle == clockDutyCycle*0.1) //   10% cycle at 2ms
            {
                speedChange = -clockDutyCycle*0.0125;
            }
            if(pwmConfigA1_3.dutyCycle == clockDutyCycle*0.05) //   5% cycle, 1ms
            {
                speedChange = clockDutyCycle*0.0125;
            }
            pwmConfigA1_3.dutyCycle += speedChange; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms
            MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_3);

            // TimerA1.4 pin 7.4 Motor 4 CW
            if(pwmConfigA1_4.dutyCycle == clockDutyCycle*0.1) //   10% cycle at 2ms,
            {
                speedChange = -clockDutyCycle*0.0125;
            }
            if(pwmConfigA1_4.dutyCycle == clockDutyCycle*0.05) //   5% cycle, 1ms
            {
                speedChange = clockDutyCycle*0.0125;
            }
            pwmConfigA1_4.dutyCycle += speedChange; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms
            MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfigA1_4);

            // Toggle P1.0 output - Button Press debug purposes
            MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1,GPIO_PIN0);
        }
        // Delay for switch debounce
        for(i=5000; i>0; i--); // debounce
*/

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
    for(i=10000; i>0; i--); // debounce

/*
    uint32_t status = MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P1);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, status);
    if (status & GPIO_PIN1)
    {
        // TimerA0.1 pin 2.4 Motor 1 CCW
        if(pwmConfig0.dutyCycle == 128) //   10% cycle at 128,           OG 28800 90%
        {
            speedChange = -16;
//            pwmConfig.dutyCycle += speedChange;
        }
        if(pwmConfig0.dutyCycle == 64) //   5% cycle, 1ms          OG 28800 90%
        {
            speedChange = 16;
//            pwmConfig.dutyCycle += speedChange; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms     OG 3200 10%
        }
//            pwmConfig.dutyCycle = 64;  //  reset to 5% or 1ms         3200 10%
//        else
        pwmConfig0.dutyCycle += speedChange; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms     OG 3200 10%

        MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig0);



        // TimerA1.1 pin 7.7 Motor 2 CCW
         if(pwmConfig1.dutyCycle == 128) //   10% cycle at 128,           OG 28800 90%
         {
             speedChange = -16;
         }
         if(pwmConfig1.dutyCycle == 64) //   5% cycle, 1ms          OG 28800 90%
         {
             speedChange = 16;
         }

         pwmConfig1.dutyCycle += speedChange; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms     OG 3200 10%

         MAP_Timer_A_generatePWM(TIMER_A1_BASE, &pwmConfig1);


        // Button Press debug
        // Toggle P1.0 output debug button press
        MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1,GPIO_PIN0);
        // Delay
        for(i=1000; i>0; i--);
    }

    if (status & GPIO_PIN4)
    {
        // TimerA2.1 pin 5.6 Motor 3 CW
        if(pwmConfig2.dutyCycle == 128) //   10% cycle at 128,           OG 28800 90%
        {
            speedChange = -16;
        }
        if(pwmConfig2.dutyCycle == 64) //   5% cycle, 1ms          OG 28800 90%
        {
            speedChange = 16;
        }

        pwmConfig2.dutyCycle += speedChange; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms     OG 3200 10%

        MAP_Timer_A_generatePWM(TIMER_A2_BASE, &pwmConfig2);

        // TimerA3.1 pin 10.5 Motor 4 CW
        if(pwmConfig3.dutyCycle == 128) //   10% cycle at 128,           OG 28800 90%
        {
            speedChange = -16;
        }
        if(pwmConfig3.dutyCycle == 64) //   5% cycle, 1ms          OG 28800 90%
        {
            speedChange = 16;
        }

        pwmConfig3.dutyCycle += speedChange; //  1.25% increase or 0.25ms 32 for 2.5% or .5ms     OG 3200 10%

        MAP_Timer_A_generatePWM(TIMER_A3_BASE, &pwmConfig3);



        // Button Press debug
        // Toggle P1.0 output debug button press
        MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1,GPIO_PIN0);
     }
*/
}
