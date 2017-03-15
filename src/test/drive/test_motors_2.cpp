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
	stop_motors();
	if (DEBUG == 1) {
		cout << "off" << endl;
	}
	return -1;
}