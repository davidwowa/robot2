//============================================================================
// Name        : drive_backward.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
#include "../lib/wiringPi/wiringPi/wiringPi.h"

#include "drive_backward.h"

using namespace std;

int debug = 1;

// motor pins (pwm)
// motor left
int motor_l_u = 26;
int motor_l_v = 27;

// motor right
int motor_r_u = 28;
int motor_r_v = 29;

// pwm
int pwmValue = HIGH;
int pwmValueInit = LOW;

int main(void) {

	if (debug == 1) {
		cout << "init wiring pi" << endl;
	}

	if (wiringPiSetup() == -1)
		return -1;

	if (debug == 1) {
		cout << "prepare gpio for motors" << endl;
	}

	backward();
	delay(1000);

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

void backward(void) {
	if (debug == 1) {
		cout << "backward" << endl;
	}
	digitalWrite(motor_r_u, pwmValueInit);
	digitalWrite(motor_r_v, pwmValue);

	digitalWrite(motor_l_u, pwmValue);
	digitalWrite(motor_l_v, pwmValueInit);
}
