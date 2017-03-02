//============================================================================
// Name        : drive_forward.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>

#include "../lib/wiringPi/wiringPi/wiringPi.h"
#include "../lib/wiringPi/wiringPi/softPwm.h"

#include "drive.h"
#include "gpio.h"
#include "analytics.h"

using namespace std;

int main(void) {

	init();

	drive_right();

	return -1;
}

void init(void) {
	if (debug == 1) {
		cout << "init wiring pi" << endl;
	}

	if (wiringPiSetup() == -1) {
		cout << "error on wiring pi setup" << endl;
	} else {
		cout << "wiring pi setup OK" << endl;
	}

	if (debug == 1) {
		cout << "prepare pwm gpio for motors" << endl;
	}
	// prepare GPIOs for motors
	softPwmCreate(motor_l_u, pwmValueInit, pwmValue);
	softPwmCreate(motor_l_v, pwmValueInit, pwmValue);

	softPwmCreate(motor_r_u, pwmValueInit, pwmValue);
	softPwmCreate(motor_r_v, pwmValueInit, pwmValue);
}

void drive_right(void) {
	if (debug == 1) {
		cout << "right" << endl;
	}
	digitalWrite(motor_r_u, pwmValue);
	digitalWrite(motor_r_v, pwmValueInit);

	digitalWrite(motor_l_u, pwmValue);
	digitalWrite(motor_l_v, pwmValueInit);
}
