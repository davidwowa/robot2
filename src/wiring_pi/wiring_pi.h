/*
 * wiring_pi.h
 *
 *  Created on: 13.03.2017
 *      Author: David
 */

#ifndef WIRING_PI_H_
#define WIRING_PI_H_

#include "../lib/wiringPi/wiringPi/wiringPi.h"
#include "../lib/wiringPi/wiringPi/softPwm.h"

extern void init_wiringPi(void);
extern void init_PWM(void);

extern void set_working_pins_to_low(void);

#endif /* WIRING_PI_H_ */
