/*
 * drive.cpp
 *
 *  Created on: 11.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include "drive.h"
#include "common.h"

void init_drive(void) {
	init_wiringPi();
	init_PWM();
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

void drive_forward(int pwm) {
	if (DEBUG == 1) {
		cout << "forward pwm " << pwm << endl;
	}
	softPwmWrite(MOTOR_R_U, pwm);
	softPwmWrite(MOTOR_R_V, PWM_MIN);

	softPwmWrite(MOTOR_L_U, PWM_MIN);
	softPwmWrite(MOTOR_L_V, pwm);
}

void drive_backward(int pwm) {
	if (DEBUG == 1) {
		cout << "backward pwm " << pwm << endl;
	}
	softPwmWrite(MOTOR_R_U, PWM_MIN);
	softPwmWrite(MOTOR_R_V, pwm);

	softPwmWrite(MOTOR_L_U, pwm);
	softPwmWrite(MOTOR_L_V, PWM_MIN);
}

void turn_left(int pwm) {
	if (DEBUG == 1) {
		cout << "left pwm " << pwm << endl;
	}
	softPwmWrite(MOTOR_R_U, PWM_MIN);
	softPwmWrite(MOTOR_R_V, pwm);

	softPwmWrite(MOTOR_L_U, PWM_MIN);
	softPwmWrite(MOTOR_L_V, pwm);
}

void turn_right(int pwm) {
	if (DEBUG == 1) {
		cout << "right pwm " << pwm << endl;
	}
	softPwmWrite(MOTOR_R_U, pwm);
	softPwmWrite(MOTOR_R_V, PWM_MIN);

	softPwmWrite(MOTOR_L_U, pwm);
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
