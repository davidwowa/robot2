//============================================================================
// Name        : test_motors.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
//#include "../lib/wiringPi/wiringPi/wiringPi.h"

using namespace std;

void forward();
void backward();
void right();
void left();
void stop();
void off();

int debug = 1;

// motor pins (pwm)
// motor left
int motor_l_u = 26;
int motor_l_v = 27;

// motor right
int motor_r_u = 28;
int motor_r_v = 29;

// pwm
int pwmValue = 1023;
int pwmValueInit = 0;

int main(void) {

	if (debug == 1) {
		cout << "init wiring pi" << endl;
	}

	if (wiringPiSetup() == -1)
		return -1;

	if (debug == 1) {
		cout << "init wiring pi setup gpio (for PWM)" << endl;
	}
	if (wiringPiSetupGpio() == -1)
		return -1;

	if (debug == 1) {
		cout << "prepare gpio for motors" << endl;
	}

	// prepare GPIOs for motors
	softPwmCreate(motor_l_u, pwmValueInit, pwmValue);
	softPwmCreate(motor_l_v, pwmValueInit, pwmValue);

	softPwmCreate(motor_r_u, pwmValueInit, pwmValue);
	softPwmCreate(motor_r_v, pwmValueInit, pwmValue);

	if (debug == 1) {
		cout << "drive forward" << endl;
	}
	forward();
	delay(2000);
	if (debug == 1) {
		cout << "drive backward" << endl;
	}
	backward();
	delay(2000);
	if (debug == 1) {
		cout << "drive right" << endl;
	}
	right();
	delay(2000);
	if (debug == 1) {
		cout << "drive left" << endl;
	}
	left();
	delay(2000);

	// acceleration forward
	if (debug == 1) {
		cout << "acceleration forward" << endl;
	}
	for (int var = 0; var < 1023; ++var) {
		softPwmWrite(motor_r_u, pwmValueInit);
		softPwmWrite(motor_r_v, var);

		softPwmWrite(motor_l_u, pwmValueInit);
		softPwmWrite(motor_l_v, var);
		delay(100);
	}
	// acceleration backward
	if (debug == 1) {
		cout << "acceleration backward" << endl;
	}
	for (int var = 0; var < 1023; ++var) {
		softPwmWrite(motor_r_u, var);
		softPwmWrite(motor_r_v, pwmValueInit);

		softPwmWrite(motor_l_u, var);
		softPwmWrite(motor_l_v, pwmValueInit);
		delay(100);
	}
	if (debug == 1) {
		cout << "stop" << endl;
	}
	stop();
	if (debug == 1) {
		cout << "off" << endl;
	}
	off();
	return -1;
}

void forward(void) {
	if (debug == 1) {
		cout << "forward" << endl;
	}
	softPwmWrite(motor_r_u, pwmValueInit);
	softPwmWrite(motor_r_v, pwmValue);

	softPwmWrite(motor_l_u, pwmValueInit);
	softPwmWrite(motor_l_v, pwmValue);
}

void backward(void) {
	if (debug == 1) {
		cout << "backward" << endl;
	}
	softPwmWrite(motor_r_u, pwmValue);
	softPwmWrite(motor_r_v, pwmValueInit);

	softPwmWrite(motor_l_u, pwmValue);
	softPwmWrite(motor_l_v, pwmValueInit);
}

void left(void) {
	if (debug == 1) {
		cout << "left" << endl;
	}
	softPwmWrite(motor_r_u, pwmValueInit);
	softPwmWrite(motor_r_v, pwmValue);

	softPwmWrite(motor_l_u, pwmValue);
	softPwmWrite(motor_l_v, pwmValueInit);
}

void right(void) {
	if (debug == 1) {
		cout << "right" << endl;
	}
	softPwmWrite(motor_r_u, pwmValue);
	softPwmWrite(motor_r_v, pwmValueInit);

	softPwmWrite(motor_l_u, pwmValueInit);
	softPwmWrite(motor_l_v, pwmValue);
}

void stop(void) {
	if (debug == 1) {
		cout << "stop" << endl;
	}
	softPwmWrite(motor_r_u, pwmValueInit);
	softPwmWrite(motor_r_v, pwmValueInit);

	softPwmWrite(motor_l_u, pwmValueInit);
	softPwmWrite(motor_l_v, pwmValueInit);
}

void off(void) {
	if (debug == 1) {
		cout << "off" << endl;
	}
	softPwmWrite(motor_r_u, pwmValueInit); // at start turn off the GPIO
	softPwmWrite(motor_r_v, pwmValueInit); // at start turn off the GPIO

	softPwmWrite(motor_l_u, pwmValueInit); // at start turn off the GPIO
	softPwmWrite(motor_l_v, pwmValueInit); // at start turn off the GPIO

	pinMode(motor_r_u, INPUT);
	pinMode(motor_r_v, INPUT);
	pinMode(motor_l_u, INPUT);
	pinMode(motor_r_v, INPUT);
}
