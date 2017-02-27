//============================================================================
// Name        : test_motors.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

/*
 +-----+-----+---------+------+---+---Pi 2---+---+------+---------+-----+-----+
 | USD | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 |     |     |    3.3v |      |   |  1 || 2  |   |      | 5v      |     |     |
 |   X |   8 |   SDA.1 |   IN | 0 |  3 || 4  |   |      | 5v      |     |     |
 |   X |   9 |   SCL.1 |  OUT | 0 |  5 || 6  |   |      | 0v      |     |     |
 |   X |   7 | GPIO. 7 |   IN | 1 |  7 || 8  | 1 | ALT0 | TxD     | 15  | 14  |
 |     |     |      0v |      |   |  9 || 10 | 1 | ALT0 | RxD     | 16  | 15  |
 |   X |   0 | GPIO. 0 |   IN | 0 | 11 || 12 | 0 | OUT  | GPIO. 1 | 1   | 18  |
 |   X |   2 | GPIO. 2 |   IN | 0 | 13 || 14 |   |      | 0v      |     |     |
 |   X |   3 | GPIO. 3 |   IN | 0 | 15 || 16 | 0 | IN   | GPIO. 4 | 4   | 23  |
 |     |     |    3.3v |      |   | 17 || 18 | 0 | OUT  | GPIO. 5 | 5   | 24  |
 |   X |  12 |    MOSI |   IN | 0 | 19 || 20 |   |      | 0v      |     |     |
 |   X |  13 |    MISO |   IN | 0 | 21 || 22 | 0 | IN   | GPIO. 6 | 6   | 25  |
 |   X |  14 |    SCLK |   IN | 0 | 23 || 24 | 1 | IN   | CE0     | 10  | 8   |
 |     |     |      0v |      |   | 25 || 26 | 1 | IN   | CE1     | 11  | 7   |
 |   X |  30 |   SDA.0 |   IN | 1 | 27 || 28 | 1 | IN   | SCL.0   | 31  | 1   |
 |   X |  21 | GPIO.21 |   IN | 1 | 29 || 30 |   |      | 0v      |     |     |
 |   6 |  22 | GPIO.22 |   IN | 1 | 31 || 32 | 0 | IN   | GPIO.26 | 26  | 12  |
 |  13 |  23 | GPIO.23 |   IN | 0 | 33 || 34 |   |      | 0v      |     |     |
 |  19 |  24 | GPIO.24 |   IN | 0 | 35 || 36 | 0 | IN   | GPIO.27 | 27  | 16  |
 |  26 |  25 | GPIO.25 |   IN | 0 | 37 || 38 | 0 | IN   | GPIO.28 | 28  | 20  |
 |     |     |      0v |      |   | 39 || 40 | 0 | IN   | GPIO.29 | 29  | 21  |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+---Pi 2---+---+------+---------+-----+-----+
 */

#include <lib/wiringPi/wiringPi/wiringPi.h>
#include <iostream>

using namespace std;

void forward();
void backward();
void right();
void left();
void stop();
void off();

int debug = 1;

int maxWallDisntance = 15;

// motor pins (pwm)
// motor left
int motor_l_u = 14;
int motor_l_v = 30;

// motor right
int motor_r_u = 12;
int motor_r_v = 13;

// pwm
int pwmValue = HIGH;
int pwmValueInit = LOW;

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
	pinMode(motor_l_u, OUTPUT);
	pinMode(motor_l_v, OUTPUT);

	pinMode(motor_r_u, OUTPUT);
	pinMode(motor_r_v, OUTPUT);

	digitalWrite(motor_l_u, pwmValueInit); // at start turn off the GPIO
	digitalWrite(motor_l_v, pwmValueInit); // at start turn off the GPIO

	digitalWrite(motor_r_u, pwmValueInit); // at start turn off the GPIO
	digitalWrite(motor_r_v, pwmValueInit); // at start turn off the GPIO

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
		digitalWrite(motor_r_u, pwmValueInit);
		digitalWrite(motor_r_v, var);

		digitalWrite(motor_l_u, pwmValueInit);
		digitalWrite(motor_l_v, var);
		delay(100);
	}
	// acceleration backward
	if (debug == 1) {
		cout << "acceleration backward" << endl;
	}
	for (int var = 0; var < 1023; ++var) {
		digitalWrite(motor_r_u, var);
		digitalWrite(motor_r_v, pwmValueInit);

		digitalWrite(motor_l_u, var);
		digitalWrite(motor_l_v, pwmValueInit);
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
	digitalWrite(motor_r_u, pwmValueInit);
	digitalWrite(motor_r_v, pwmValue);

	digitalWrite(motor_l_u, pwmValueInit);
	digitalWrite(motor_l_v, pwmValue);
}

void backward(void) {
	if (debug == 1) {
		cout << "backward" << endl;
	}
	digitalWrite(motor_r_u, pwmValue);
	digitalWrite(motor_r_v, pwmValueInit);

	digitalWrite(motor_l_u, pwmValue);
	digitalWrite(motor_l_v, pwmValueInit);
}

void left(void) {
	if (debug == 1) {
		cout << "left" << endl;
	}
	digitalWrite(motor_r_u, pwmValueInit);
	digitalWrite(motor_r_v, pwmValue);

	digitalWrite(motor_l_u, pwmValue);
	digitalWrite(motor_l_v, pwmValueInit);
}

void right(void) {
	if (debug == 1) {
		cout << "right" << endl;
	}
	digitalWrite(motor_r_u, pwmValue);
	digitalWrite(motor_r_v, pwmValueInit);

	digitalWrite(motor_l_u, pwmValueInit);
	digitalWrite(motor_l_v, pwmValue);
}

void stop(void) {
	if (debug == 1) {
		cout << "stop" << endl;
	}
	digitalWrite(motor_r_u, pwmValueInit);
	digitalWrite(motor_r_v, pwmValueInit);

	digitalWrite(motor_l_u, pwmValueInit);
	digitalWrite(motor_l_v, pwmValueInit);
}

void off(void) {
	if (debug == 1) {
		cout << "off" << endl;
	}
	digitalWrite(motor_r_u, pwmValueInit); // at start turn off the GPIO
	digitalWrite(motor_r_v, pwmValueInit); // at start turn off the GPIO

	digitalWrite(motor_l_u, pwmValueInit); // at start turn off the GPIO
	digitalWrite(motor_l_v, pwmValueInit); // at start turn off the GPIO

	pinMode(motor_r_u, INPUT);
	pinMode(motor_r_v, INPUT);
	pinMode(motor_l_u, INPUT);
	pinMode(motor_r_v, INPUT);
}
