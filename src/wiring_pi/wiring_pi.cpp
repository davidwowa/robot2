/*
 * wiring_pi.cpp
 *
 *  Created on: 13.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include <iostream>

#include "gpio.h"
#include "wiring_pi.h"

using namespace std;

int DEBUG = 1;

void init_wiringPi(void) {
	if (DEBUG == 1) {
		cout << "init wiring pi" << endl;
	}

	if (wiringPiSetup() == -1) {
		if (DEBUG == 1) {
			cout << "error on wiring pi setup" << endl;
		}
	} else {
		if (DEBUG == 1) {
			cout << "wiring pi setup OK" << endl;
		}
	}
}

void init_PWM(void) {
	if (DEBUG == 1) {
		cout << "prepare pwm gpio for motors" << endl;
	}
	// prepare GPIOs for motors
	softPwmCreate(MOTOR_L_U, PWM_MIN, PWM_MAX);
	softPwmCreate(MOTOR_L_V, PWM_MIN, PWM_MAX);

	softPwmCreate(MOTOR_R_U, PWM_MIN, PWM_MAX);
	softPwmCreate(MOTOR_R_V, PWM_MIN, PWM_MAX);
}

void set_working_pins_to_low(void) {
	cout << "set all pins to INPUT" << endl;

	pinMode(ECHO_M, INPUT);
	pinMode(TRIGGER_M, INPUT);
	pinMode(ECHO_R, INPUT);
	pinMode(TRIGGER_R, INPUT);
	pinMode(ECHO_L, INPUT);
	pinMode(TRIGGER_L, INPUT);
	pinMode(ECHO_B, INPUT);
	pinMode(TRIGGER_B, INPUT);

	pinMode(MOTOR_L_U, INPUT);
	pinMode(MOTOR_L_V, INPUT);

	pinMode(MOTOR_R_U, INPUT);
	pinMode(MOTOR_R_V, INPUT);

	cout << "set all pins to LOW" << endl;

	digitalWrite(ECHO_M, LOW);
	digitalWrite(TRIGGER_M, LOW);
	digitalWrite(ECHO_R, LOW);
	digitalWrite(TRIGGER_R, LOW);
	digitalWrite(ECHO_L, LOW);
	digitalWrite(TRIGGER_L, LOW);
	digitalWrite(ECHO_B, LOW);
	digitalWrite(TRIGGER_B, LOW);

	digitalWrite(MOTOR_L_U, LOW);
	digitalWrite(MOTOR_L_V, LOW);

	digitalWrite(MOTOR_R_U, LOW);
	digitalWrite(MOTOR_R_V, LOW);

	cout << "Done" << endl;
}
