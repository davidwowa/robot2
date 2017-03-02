//============================================================================
// Name        : drive_stop.cpp
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

	if (debug == 1) {
		cout << "init wiring pi" << endl;
	}

	if (wiringPiSetup() == -1)
		return -1;

	if (debug == 1) {
		cout << "prepare gpio for motors" << endl;
	}

	// prepare GPIOs for motors
	pinMode(motor_l_u, OUTPUT);
	pinMode(motor_l_v, OUTPUT);

	pinMode(motor_r_u, OUTPUT);
	pinMode(motor_r_v, OUTPUT);

	digitalWrite(motor_l_u, pwmValueInit); // at start turn off the GPIO
	digitalWrite(motor_l_v, pwmValueInit); // at start turn off the GPIO

	digitalWrite(motor_r_u, pwmValueInit); // at start turn off the GPIO
	digitalWrite(motor_r_v, pwmValueInit); // at start turn off the GPIO

	stop();

	return -1;
}

void stop(void) {
	if (debug == 1) {
		cout << "stop" << endl;
	}
	digitalWrite(motor_r_u, pwmValueInit);
	digitalWrite(motor_r_v, pwmValueInit);

	digitalWrite(motor_l_u, pwmValueInit);
	digitalWrite(motor_l_v, pwmValueInit);
}
