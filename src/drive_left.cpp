//============================================================================
// Name        : drive_left.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
#include "../lib/wiringPi/wiringPi/wiringPi.h"

//#include <wiringPi.h>

using namespace std;

void left();

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

	// prepare GPIOs for motors
	pinMode(motor_l_u, OUTPUT);
	pinMode(motor_l_v, OUTPUT);

	pinMode(motor_r_u, OUTPUT);
	pinMode(motor_r_v, OUTPUT);

	digitalWrite(motor_l_u, pwmValueInit); // at start turn off the GPIO
	digitalWrite(motor_l_v, pwmValueInit); // at start turn off the GPIO

	digitalWrite(motor_r_u, pwmValueInit); // at start turn off the GPIO
	digitalWrite(motor_r_v, pwmValueInit); // at start turn off the GPIO

	while (1) {
		left();
	}

	return -1;
}

void left(void) {
	if (debug == 1) {
		cout << "left" << endl;
	}
	digitalWrite(motor_r_u, pwmValueInit);
	digitalWrite(motor_r_v, pwmValue);

	digitalWrite(motor_l_u, pwmValueInit);
	digitalWrite(motor_l_v, pwmValue);
}
