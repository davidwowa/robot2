//============================================================================
// Name        : test_motors.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>

#include "../lib/wiringPi/wiringPi/wiringPi.h"

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
		cout << "init wiring pi setup gpio (for PWM)" << endl;
	}
	if (wiringPiSetupSys() == -1)
		return -1;

	if (debug == 1) {
		cout << "prepare gpio for motors" << endl;
	}

	pinMode(motor_l_u, PWM_OUTPUT);
	pinMode(motor_l_v, PWM_OUTPUT);
	pinMode(motor_r_u, PWM_OUTPUT);
	pinMode(motor_r_v, PWM_OUTPUT);

	digitalWrite(motor_l_u, LOW); // at start turn off the GPIO
	digitalWrite(motor_l_v, LOW); // at start turn off the GPIO
	digitalWrite(motor_r_u, LOW); // at start turn off the GPIO
	digitalWrite(motor_r_v, LOW); // at start turn off the GPIO

	// prepare GPIOs for motors
	pwmWrite(motor_l_u, pwmValueInit);
	pwmWrite(motor_l_v, pwmValueInit);

	pwmWrite(motor_r_u, pwmValueInit);
	pwmWrite(motor_r_v, pwmValueInit);

	// acceleration forward
	if (debug == 1) {
		cout << "acceleration forward" << endl;
	}
	for (int var = 0; var < pwmValue; ++var) {
		if (debug == 1) {
			cout << "set speed to " << var << endl;
		}
		pwmWrite(motor_r_u, (pwmValue - var));
		pwmWrite(motor_r_v, var);

		pwmWrite(motor_l_u, var);
		pwmWrite(motor_l_v, (pwmValue - var));
		delay(10);
	}
	// acceleration backward
	if (debug == 1) {
		cout << "acceleration backward" << endl;
	}
	for (int var = 0; var < pwmValue; ++var) {
		if (debug == 1) {
			cout << "set speed to " << var << endl;
		}
		pwmWrite(motor_r_u, var);
		pwmWrite(motor_r_v, (pwmValue - var));

		pwmWrite(motor_l_u, (pwmValue - var));
		pwmWrite(motor_l_v, var);
		delay(10);
	}

	if (debug == 1) {
		cout << "drive forward" << endl;
	}
	drive_forward();
	delay(2000);
	if (debug == 1) {
		cout << "drive backward" << endl;
	}
	drive_backward();
	delay(2000);
	if (debug == 1) {
		cout << "drive right" << endl;
	}
	drive_right();
	delay(2000);
	if (debug == 1) {
		cout << "drive left" << endl;
	}
	drive_left();
	delay(2000);

	if (debug == 1) {
		cout << "stop" << endl;
	}
	stop();
	if (debug == 1) {
		cout << "off" << endl;
	}
	return -1;
}

void drive_forward(void) {
	if (debug == 1) {
		cout << "forward" << endl;
	}
	pwmWrite(motor_r_u, pwmValue);
	pwmWrite(motor_r_v, pwmValueInit);

	pwmWrite(motor_l_u, pwmValueInit);
	pwmWrite(motor_l_v, pwmValue);
}
void drive_backward(void) {
	if (debug == 1) {
		cout << "backward" << endl;
	}
	pwmWrite(motor_r_u, pwmValueInit);
	pwmWrite(motor_r_v, pwmValue);

	pwmWrite(motor_l_u, pwmValue);
	pwmWrite(motor_l_v, pwmValueInit);
}
void drive_left(void) {
	if (debug == 1) {
		cout << "left" << endl;
	}
	pwmWrite(motor_r_u, pwmValueInit);
	pwmWrite(motor_r_v, pwmValue);

	pwmWrite(motor_l_u, pwmValueInit);
	pwmWrite(motor_l_v, pwmValue);
}
void drive_right(void) {
	if (debug == 1) {
		cout << "right" << endl;
	}
	pwmWrite(motor_r_u, pwmValue);
	pwmWrite(motor_r_v, pwmValueInit);

	pwmWrite(motor_l_u, pwmValue);
	pwmWrite(motor_l_v, pwmValueInit);
}
void stop(void) {
	if (debug == 1) {
		cout << "stop" << endl;
	}
	pwmWrite(motor_r_u, pwmValueInit);
	pwmWrite(motor_r_v, pwmValueInit);

	pwmWrite(motor_l_u, pwmValueInit);
	pwmWrite(motor_l_v, pwmValueInit);
}
