//============================================================================
// Name        : test_motors.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================
#include "iostream"

#include "../../drive/drive.h"
#include "../../drive/gpio_drive.h"

#include "../../../lib/wiringPi/wiringPi/wiringPi.h"
#include "../../../lib/wiringPi/wiringPi/softPwm.h"

using namespace std;

int DEBUG = 1;

int main(void) {
	init_wiringPi();
	init_PWM();
	init_drive();

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
	stop_motors();
	return -1;
}
