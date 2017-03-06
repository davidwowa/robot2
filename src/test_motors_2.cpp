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

	if (DEBUG == 1) {
		cout << "init wiring pi" << endl;
	}

	if (wiringPiSetup() == -1)
		return -1;

	if (DEBUG == 1) {
		cout << "init wiring pi setup gpio (for PWM)" << endl;
	}
	if (wiringPiSetupSys() == -1)
		return -1;

	if (DEBUG == 1) {
		cout << "prepare gpio for motors" << endl;
	}

	pinMode(MOTOR_L_U, PWM_OUTPUT);
	pinMode(MOTOR_L_V, PWM_OUTPUT);
	pinMode(MOTOR_R_U, PWM_OUTPUT);
	pinMode(MOTOR_R_V, PWM_OUTPUT);

	digitalWrite(MOTOR_L_U, LOW); // at start turn off the GPIO
	digitalWrite(MOTOR_L_V, LOW); // at start turn off the GPIO
	digitalWrite(MOTOR_R_U, LOW); // at start turn off the GPIO
	digitalWrite(MOTOR_R_V, LOW); // at start turn off the GPIO

	// prepare GPIOs for motors
	pwmWrite(MOTOR_L_U, PWM_MIN);
	pwmWrite(MOTOR_L_V, PWM_MIN);

	pwmWrite(MOTOR_R_U, PWM_MIN);
	pwmWrite(MOTOR_R_V, PWM_MIN);

	// acceleration forward
	if (DEBUG == 1) {
		cout << "acceleration forward" << endl;
	}
	for (int var = 0; var < PWM_MAX; ++var) {
		if (DEBUG == 1) {
			cout << "set speed to " << var << endl;
		}
		pwmWrite(MOTOR_R_U, (PWM_MAX - var));
		pwmWrite(MOTOR_R_V, var);

		pwmWrite(MOTOR_L_U, var);
		pwmWrite(MOTOR_L_V, (PWM_MAX - var));
		delay(10);
	}
	// acceleration backward
	if (DEBUG == 1) {
		cout << "acceleration backward" << endl;
	}
	for (int var = 0; var < PWM_MAX; ++var) {
		if (DEBUG == 1) {
			cout << "set speed to " << var << endl;
		}
		pwmWrite(MOTOR_R_U, var);
		pwmWrite(MOTOR_R_V, (PWM_MAX - var));

		pwmWrite(MOTOR_L_U, (PWM_MAX - var));
		pwmWrite(MOTOR_L_V, var);
		delay(10);
	}

	if (DEBUG == 1) {
		cout << "drive forward" << endl;
	}
	drive_forward();
	delay(2000);
	if (DEBUG == 1) {
		cout << "drive backward" << endl;
	}
	drive_backward();
	delay(2000);
	if (DEBUG == 1) {
		cout << "drive right" << endl;
	}
	turn_right();
	delay(2000);
	if (DEBUG == 1) {
		cout << "drive left" << endl;
	}
	turn_left();
	delay(2000);

	if (DEBUG == 1) {
		cout << "stop" << endl;
	}
	stop();
	if (DEBUG == 1) {
		cout << "off" << endl;
	}
	return -1;
}

void drive_forward(void) {
	if (DEBUG == 1) {
		cout << "forward" << endl;
	}
	pwmWrite(MOTOR_R_U, PWM_MAX);
	pwmWrite(MOTOR_R_V, PWM_MIN);

	pwmWrite(MOTOR_L_U, PWM_MIN);
	pwmWrite(MOTOR_L_V, PWM_MAX);
}
void drive_backward(void) {
	if (DEBUG == 1) {
		cout << "backward" << endl;
	}
	pwmWrite(MOTOR_R_U, PWM_MIN);
	pwmWrite(MOTOR_R_V, PWM_MAX);

	pwmWrite(MOTOR_L_U, PWM_MAX);
	pwmWrite(MOTOR_L_V, PWM_MIN);
}
void turn_left(void) {
	if (DEBUG == 1) {
		cout << "left" << endl;
	}
	pwmWrite(MOTOR_R_U, PWM_MIN);
	pwmWrite(MOTOR_R_V, PWM_MAX);

	pwmWrite(MOTOR_L_U, PWM_MIN);
	pwmWrite(MOTOR_L_V, PWM_MAX);
}
void turn_right(void) {
	if (DEBUG == 1) {
		cout << "right" << endl;
	}
	pwmWrite(MOTOR_R_U, PWM_MAX);
	pwmWrite(MOTOR_R_V, PWM_MIN);

	pwmWrite(MOTOR_L_U, PWM_MAX);
	pwmWrite(MOTOR_L_V, PWM_MIN);
}
void stop(void) {
	if (DEBUG == 1) {
		cout << "stop" << endl;
	}
	pwmWrite(MOTOR_R_U, PWM_MIN);
	pwmWrite(MOTOR_R_V, PWM_MIN);

	pwmWrite(MOTOR_L_U, PWM_MIN);
	pwmWrite(MOTOR_L_V, PWM_MIN);
}
