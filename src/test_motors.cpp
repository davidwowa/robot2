//============================================================================
// Name        : test_motors.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
#include <wiringPi.h>
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
		cout << "prepare gpio for motors" << endl;
	}

	// prepare GPIOs for motors
	pinMode(motor_l_u, PWM_OUTPUT);
	pinMode(motor_l_v, PWM_OUTPUT);

	pinMode(motor_r_u, PWM_OUTPUT);
	pinMode(motor_r_v, PWM_OUTPUT);

	pwmWrite(motor_l_u, pwmValueInit); // at start turn off the GPIO
	pwmWrite(motor_l_v, pwmValueInit); // at start turn off the GPIO

	pwmWrite(motor_r_u, pwmValueInit); // at start turn off the GPIO
	pwmWrite(motor_r_v, pwmValueInit); // at start turn off the GPIO

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
		pwmWrite(motor_r_u, pwmValueInit);
		pwmWrite(motor_r_v, var);

		pwmWrite(motor_l_u, pwmValueInit);
		pwmWrite(motor_l_v, var);
		delay(100);
	}
	// acceleration backward
	if (debug == 1) {
		cout << "acceleration backward" << endl;
	}
	for (int var = 0; var < 1023; ++var) {
		pwmWrite(motor_r_u, var);
		pwmWrite(motor_r_v, pwmValueInit);

		pwmWrite(motor_l_u, var);
		pwmWrite(motor_l_v, pwmValueInit);
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
	pwmWrite(motor_r_u, pwmValueInit);
	pwmWrite(motor_r_v, pwmValue);

	pwmWrite(motor_l_u, pwmValueInit);
	pwmWrite(motor_l_v, pwmValue);
}

void backward(void) {
	if (debug == 1) {
		cout << "backward" << endl;
	}
	pwmWrite(motor_r_u, pwmValue);
	pwmWrite(motor_r_v, pwmValueInit);

	pwmWrite(motor_l_u, pwmValue);
	pwmWrite(motor_l_v, pwmValueInit);
}

void left(void) {
	if (debug == 1) {
		cout << "left" << endl;
	}
	pwmWrite(motor_r_u, pwmValueInit);
	pwmWrite(motor_r_v, pwmValue);

	pwmWrite(motor_l_u, pwmValue);
	pwmWrite(motor_l_v, pwmValueInit);
}

void right(void) {
	if (debug == 1) {
		cout << "right" << endl;
	}
	pwmWrite(motor_r_u, pwmValue);
	pwmWrite(motor_r_v, pwmValueInit);

	pwmWrite(motor_l_u, pwmValueInit);
	pwmWrite(motor_l_v, pwmValue);
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

void off(void) {
	if (debug == 1) {
		cout << "off" << endl;
	}
	pwmWrite(motor_r_u, pwmValueInit); // at start turn off the GPIO
	pwmWrite(motor_r_v, pwmValueInit); // at start turn off the GPIO

	pwmWrite(motor_l_u, pwmValueInit); // at start turn off the GPIO
	pwmWrite(motor_l_v, pwmValueInit); // at start turn off the GPIO

	pinMode(motor_r_u, INPUT);
	pinMode(motor_r_v, INPUT);
	pinMode(motor_l_u, INPUT);
	pinMode(motor_r_v, INPUT);
}
