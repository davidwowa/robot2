/*
 * drive.cpp
 *
 *  Created on: 11.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include <iostream>

#include "../../lib/WiringPi/wiringPi/wiringPi.h"
#include "../../lib/WiringPi/wiringPi/softPwm.h"

#include "drive.h"
#include "gpio_drive.h"

using namespace std;

void init_drive(void) {
	init_wiringPi();
	init_PWM();
}

void init_wiringPi(void) {
	cout << "init wiring pi" << endl;

	if (wiringPiSetup() == -1) {
		cout << "error on wiring pi setup" << endl;
	} else {
		cout << "wiring pi setup OK" << endl;
	}
}

void init_PWM(void) {
	cout << "prepare pwm gpio for motors" << endl;
	// prepare GPIOs for motors
	softPwmCreate(MOTOR_L_U, PWM_MIN, PWM_MAX);
	softPwmCreate(MOTOR_L_V, PWM_MIN, PWM_MAX);

	softPwmCreate(MOTOR_R_U, PWM_MIN, PWM_MAX);
	softPwmCreate(MOTOR_R_V, PWM_MIN, PWM_MAX);
}

void set_working_pins_to_low(void) {
	cout << "set all pins to INPUT" << endl;

	pinMode(MOTOR_L_U, INPUT);
	pinMode(MOTOR_L_V, INPUT);

	pinMode(MOTOR_R_U, INPUT);
	pinMode(MOTOR_R_V, INPUT);

	cout << "set all pins to LOW" << endl;

	digitalWrite(MOTOR_L_U, LOW);
	digitalWrite(MOTOR_L_V, LOW);

	digitalWrite(MOTOR_R_U, LOW);
	digitalWrite(MOTOR_R_V, LOW);

	cout << "Done" << endl;
}

void drive_forward(void) {
	cout << "forward" << endl;
	softPwmWrite(MOTOR_R_U, PWM_MIN);
	softPwmWrite(MOTOR_R_V, PWM_MAX);

	softPwmWrite(MOTOR_L_U, PWM_MAX);
	softPwmWrite(MOTOR_L_V, PWM_MIN);
}

void drive_backward(void) {
	cout << "backward" << endl;
	softPwmWrite(MOTOR_R_U, PWM_MAX);
	softPwmWrite(MOTOR_R_V, PWM_MIN);

	softPwmWrite(MOTOR_L_U, PWM_MIN);
	softPwmWrite(MOTOR_L_V, PWM_MAX);
}

void turn_left(void) {
	cout << "left" << endl;
	softPwmWrite(MOTOR_R_U, PWM_MAX);
	softPwmWrite(MOTOR_R_V, PWM_MIN);

	softPwmWrite(MOTOR_L_U, PWM_MAX);
	softPwmWrite(MOTOR_L_V, PWM_MIN);
}

void turn_right(void) {
	cout << "right" << endl;
	softPwmWrite(MOTOR_R_U, PWM_MIN);
	softPwmWrite(MOTOR_R_V, PWM_MAX);

	softPwmWrite(MOTOR_L_U, PWM_MIN);
	softPwmWrite(MOTOR_L_V, PWM_MAX);
}

void stop(void) {
	cout << "stop" << endl;
	softPwmWrite(MOTOR_R_U, PWM_MIN);
	softPwmWrite(MOTOR_R_V, PWM_MIN);

	softPwmWrite(MOTOR_L_U, PWM_MIN);
	softPwmWrite(MOTOR_L_V, PWM_MIN);
}

void drive_forward(int pwm) {
	cout << "forward pwm " << pwm << endl;
	softPwmWrite(MOTOR_R_U, pwm);
	softPwmWrite(MOTOR_R_V, PWM_MAX);

	softPwmWrite(MOTOR_L_U, PWM_MAX);
	softPwmWrite(MOTOR_L_V, pwm);
}

void drive_backward(int pwm) {
	cout << "backward pwm " << pwm << endl;
	softPwmWrite(MOTOR_R_U, PWM_MAX);
	softPwmWrite(MOTOR_R_V, pwm);

	softPwmWrite(MOTOR_L_U, pwm);
	softPwmWrite(MOTOR_L_V, PWM_MAX);
}

void turn_left(int pwm) {
	cout << "left pwm " << pwm << endl;
	softPwmWrite(MOTOR_R_U, PWM_MAX);
	softPwmWrite(MOTOR_R_V, pwm);

	softPwmWrite(MOTOR_L_U, PWM_MAX);
	softPwmWrite(MOTOR_L_V, pwm);
}

void turn_right(int pwm) {
	cout << "right pwm " << pwm << endl;
	softPwmWrite(MOTOR_R_U, pwm);
	softPwmWrite(MOTOR_R_V, PWM_MAX);

	softPwmWrite(MOTOR_L_U, pwm);
	softPwmWrite(MOTOR_L_V, PWM_MAX);
}

void stop_motors(void) {
	cout << "stop" << endl;
	softPwmWrite(MOTOR_R_U, PWM_MIN);
	softPwmWrite(MOTOR_R_V, PWM_MIN);

	softPwmWrite(MOTOR_L_U, PWM_MIN);
	softPwmWrite(MOTOR_L_V, PWM_MIN);

	set_working_pins_to_low();
}

void drive_backward(int pin, int pwm) {
	// TODO
}

void drive_forward(int pin, int pwm) {
	// TODO
}
void turn_left(int pin, int pwm) {
	// TODO
}

void turn_right(int pin, int pwm) {
	// TODO
}
