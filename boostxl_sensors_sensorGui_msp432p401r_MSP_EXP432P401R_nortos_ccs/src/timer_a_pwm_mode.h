/*
 * timer_a_pwm_mode.h
 *
 *  Created on: Apr 25, 2017
 *      Author: Robert-temp
 */

#ifndef SRC_TIMER_A_PWM_MODE_H_
#define SRC_TIMER_A_PWM_MODE_H_





// Exported function prototypes
extern void pwmInit(void);
extern void enableButtons(void);


extern int32_t getNewThrottle1(void);
extern int32_t getNewThrottle2(void);
extern int32_t getNewThrottle3(void);
extern int32_t getNewThrottle4(void);

extern void throttleMotor1(int32_t throttle);
extern void throttleMotor2(int32_t throttle);
extern void throttleMotor3(int32_t throttle);
extern void throttleMotor4(int32_t throttle);





#endif /* SRC_TIMER_A_PWM_MODE_H_ */
