//============================================================================
// Name        : test_motors.cpp
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

	// acceleration forward
	if (DEBUG == 1) {
		cout << "acceleration forward" << endl;
	}
	for (int var = 0; var < PWM_MAX; ++var) {
		if (DEBUG == 1) {
			cout << "set speed to " << var << endl;
		}
		softPwmWrite(MOTOR_R_U, (PWM_MAX - var));
		softPwmWrite(MOTOR_R_V, var);

		softPwmWrite(MOTOR_L_U, var);
		softPwmWrite(MOTOR_L_V, (PWM_MAX - var));
		delay(100);
	}
	// acceleration backward
	if (DEBUG == 1) {
		cout << "acceleration backward" << endl;
	}
	for (int var = 0; var < PWM_MAX; ++var) {
		if (DEBUG == 1) {
			cout << "set speed to " << var << endl;
		}
		softPwmWrite(MOTOR_R_U, var);
		softPwmWrite(MOTOR_R_V, (PWM_MAX - var));

		softPwmWrite(MOTOR_L_U, (PWM_MAX - var));
		softPwmWrite(MOTOR_L_V, var);
		delay(100);
	}

	if (DEBUG == 1) {
		cout << "drive forward" << endl;
	}
	drive_forward();
	delay(3000);
	if (DEBUG == 1) {
		cout << "drive backward" << endl;
	}
	drive_backward();
	delay(3000);
	if (DEBUG == 1) {
		cout << "drive right" << endl;
	}
	turn_right();
	delay(3000);
	if (DEBUG == 1) {
		cout << "drive left" << endl;
	}
	turn_left();
	delay(3000);

	if (DEBUG == 1) {
		cout << "stop" << endl;
	}
	stop();
	return -1;
}

void init(void) {
	if (DEBUG == 1) {
		cout << "init wiring pi" << endl;
	}

	if (wiringPiSetup() == -1) {
		cout << "error on wiring pi setup" << endl;
	} else {
		cout << "wiring pi setup OK" << endl;
	}

	if (DEBUG == 1) {
		cout << "prepare pwm gpio for motors" << endl;
	}
	// prepare GPIOs for motors
	softPwmCreate(MOTOR_L_U, PWM_MIN, PWM_MAX);
	softPwmCreate(MOTOR_L_V, PWM_MIN, PWM_MAX);

	softPwmCreate(MOTOR_R_U, PWM_MIN, PWM_MAX);
	softPwmCreate(MOTOR_R_V, PWM_MIN, PWM_MAX);
}

void drive_forward(void) {
	if (DEBUG == 1) {
		cout << "forward" << endl;
	}
	softPwmWrite(MOTOR_R_U, PWM_MAX);
	softPwmWrite(MOTOR_R_V, PWM_MIN);

	softPwmWrite(MOTOR_L_U, PWM_MIN);
	softPwmWrite(MOTOR_L_V, PWM_MAX);
}
void drive_backward(void) {
	if (DEBUG == 1) {
		cout << "backward" << endl;
	}
	softPwmWrite(MOTOR_R_U, PWM_MIN);
	softPwmWrite(MOTOR_R_V, PWM_MAX);

	softPwmWrite(MOTOR_L_U, PWM_MAX);
	softPwmWrite(MOTOR_L_V, PWM_MIN);
}
void turn_left(void) {
	if (DEBUG == 1) {
		cout << "left" << endl;
	}
	softPwmWrite(MOTOR_R_U, PWM_MIN);
	softPwmWrite(MOTOR_R_V, PWM_MAX);

	softPwmWrite(MOTOR_L_U, PWM_MIN);
	softPwmWrite(MOTOR_L_V, PWM_MAX);
}
void turn_right(void) {
	if (DEBUG == 1) {
		cout << "right" << endl;
	}
	softPwmWrite(MOTOR_R_U, PWM_MAX);
	softPwmWrite(MOTOR_R_V, PWM_MIN);

	softPwmWrite(MOTOR_L_U, PWM_MAX);
	softPwmWrite(MOTOR_L_V, PWM_MIN);
}
void stop(void) {
	if (DEBUG == 1) {
		cout << "stop" << endl;
	}
	softPwmWrite(MOTOR_R_U, PWM_MIN);
	softPwmWrite(MOTOR_R_V, PWM_MIN);

	softPwmWrite(MOTOR_L_U, PWM_MIN);
	softPwmWrite(MOTOR_L_V, PWM_MIN);
}
