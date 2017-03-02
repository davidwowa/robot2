//============================================================================
// Name        : test_motors.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
//#include <wiringPi.h>
//#include <softPwm.h>
#include "../lib/wiringPi/wiringPi/softPwm.h"
#include "../lib/wiringPi/wiringPi/wiringPi.h"

using namespace std;

void init();

void forward();
void backward();
void right();
void left();
void stop();

int debug = 1;

// motor pins (pwm)
// motor left
int motor_l_u = 26;
int motor_l_v = 27;

// motor right
int motor_r_u = 28;
int motor_r_v = 29;

// pwm
int pwmValue = 500;
int pwmValueInit = 0;

int main(void) {

	init();

	// acceleration forward
	if (debug == 1) {
		cout << "acceleration forward" << endl;
	}
	for (int var = 0; var < pwmValue; ++var) {
		if (debug == 1) {
			cout << "set speed to " << var << endl;
		}
		softPwmWrite(motor_r_u, (pwmValue - var));
		softPwmWrite(motor_r_v, var);

		softPwmWrite(motor_l_u, var);
		softPwmWrite(motor_l_v, (pwmValue - var));
		delay(100);
	}
	// acceleration backward
	if (debug == 1) {
		cout << "acceleration backward" << endl;
	}
	for (int var = 0; var < pwmValue; ++var) {
		if (debug == 1) {
			cout << "set speed to " << var << endl;
		}
		softPwmWrite(motor_r_u, var);
		softPwmWrite(motor_r_v, (pwmValue - var));

		softPwmWrite(motor_l_u, (pwmValue - var));
		softPwmWrite(motor_l_v, var);
		delay(100);
	}

	if (debug == 1) {
		cout << "drive forward" << endl;
	}
	forward();
	delay(3000);
	if (debug == 1) {
		cout << "drive backward" << endl;
	}
	backward();
	delay(3000);
	if (debug == 1) {
		cout << "drive right" << endl;
	}
	right();
	delay(3000);
	if (debug == 1) {
		cout << "drive left" << endl;
	}
	left();
	delay(3000);

	if (debug == 1) {
		cout << "stop" << endl;
	}
	stop();
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
		cout << "prepare gpio for motors" << endl;
	}

	// prepare GPIOs for motors
	softPwmCreate(motor_l_u, pwmValueInit, pwmValue);
	softPwmCreate(motor_l_v, pwmValueInit, pwmValue);

	softPwmCreate(motor_r_u, pwmValueInit, pwmValue);
	softPwmCreate(motor_r_v, pwmValueInit, pwmValue);
}
void forward(void) {
	if (debug == 1) {
		cout << "forward" << endl;
	}
	softPwmWrite(motor_r_u, pwmValue);
	softPwmWrite(motor_r_v, pwmValueInit);

	softPwmWrite(motor_l_u, pwmValueInit);
	softPwmWrite(motor_l_v, pwmValue);
}
void backward(void) {
	if (debug == 1) {
		cout << "backward" << endl;
	}
	softPwmWrite(motor_r_u, pwmValueInit);
	softPwmWrite(motor_r_v, pwmValue);

	softPwmWrite(motor_l_u, pwmValue);
	softPwmWrite(motor_l_v, pwmValueInit);
}
void left(void) {
	if (debug == 1) {
		cout << "left" << endl;
	}
	softPwmWrite(motor_r_u, pwmValueInit);
	softPwmWrite(motor_r_v, pwmValue);

	softPwmWrite(motor_l_u, pwmValueInit);
	softPwmWrite(motor_l_v, pwmValue);
}
void right(void) {
	if (debug == 1) {
		cout << "right" << endl;
	}
	softPwmWrite(motor_r_u, pwmValue);
	softPwmWrite(motor_r_v, pwmValueInit);

	softPwmWrite(motor_l_u, pwmValue);
	softPwmWrite(motor_l_v, pwmValueInit);
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
