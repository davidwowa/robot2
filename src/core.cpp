//============================================================================
// Name        : core.cpp
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
 |   S |   8 |   SDA.1 |   IN | 0 |  3 || 4  |   |      | 5v      |     |     |
 |   S |   9 |   SCL.1 |  OUT | 0 |  5 || 6  |   |      | 0v      |     |     |
 |   S |   7 | GPIO. 7 |   IN | 1 |  7 || 8  | 1 | ALT0 | TxD     | 15  | 14  |
 |     |     |      0v |      |   |  9 || 10 | 1 | ALT0 | RxD     | 16  | 15  |
 |   S |   0 | GPIO. 0 |   IN | 0 | 11 || 12 | 0 | OUT  | GPIO. 1 | 1   | 18  |
 |   S |   2 | GPIO. 2 |   IN | 0 | 13 || 14 |   |      | 0v      |     |     |
 |   S |   3 | GPIO. 3 |   IN | 0 | 15 || 16 | 0 | IN   | GPIO. 4 | 4   | 23  |
 |     |     |    3.3v |      |   | 17 || 18 | 0 | OUT  | GPIO. 5 | 5   | 24  |
 |   - |  12 |    MOSI |   IN | 0 | 19 || 20 |   |      | 0v      |     |     |
 |   - |  13 |    MISO |   IN | 0 | 21 || 22 | 0 | IN   | GPIO. 6 | 6   | 25  |
 |   - |  14 |    SCLK |   IN | 0 | 23 || 24 | 1 | IN   | CE0     | 10  | 8   |
 |     |     |      0v |      |   | 25 || 26 | 1 | IN   | CE1     | 11  | 7   |
 |   - |  30 |   SDA.0 |   IN | 1 | 27 || 28 | 1 | IN   | SCL.0   | 31  | 1   |
 |   - |  21 | GPIO.21 |   IN | 1 | 29 || 30 |   |      | 0v      |     |     |
 |   6 |  22 | GPIO.22 |   IN | 1 | 31 || 32 | 0 | IN   | GPIO.26 | 26  | M   |
 |  13 |  23 | GPIO.23 |   IN | 0 | 33 || 34 |   |      | 0v      |     |     |
 |  19 |  24 | GPIO.24 |   IN | 0 | 35 || 36 | 0 | IN   | GPIO.27 | 27  | M   |
 |  26 |  25 | GPIO.25 |   IN | 0 | 37 || 38 | 0 | IN   | GPIO.28 | 28  | M   |
 |     |     |      0v |      |   | 39 || 40 | 0 | IN   | GPIO.29 | 29  | M   |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+---Pi 2---+---+------+---------+-----+-----+
 */

#include <iostream>
#include "../lib/wiringPi/wiringPi/wiringPi.h"
#include "../lib/HC-SR04-Raspberry-Pi-C-/libSonar.h"

//#include <wiringPi.h>
//#include <libSonar.h>

using namespace std;

void forward();
void backward();
void right();
void left();
void stop();

int debug = 1;

int maxWallDisntance = 15;

// middle sonar sensor
int echo_m = 8;
int trigger_m = 9;

// right sonar sensor
int echo_r = 7;
int trigger_r = 0;

// left sonar sensor
int echo_l = 2;
int trigger_l = 3;

// motor pins (pwm)
// motor left
int motor_l_u = 26;
int motor_l_v = 27;

// motor right
int motor_r_u = 28;
int motor_r_v = 29;

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
		cout << "start sonars" << endl;
	}

	Sonar sonar_m;
	sonar_m.init(trigger_m, echo_m);

	Sonar sonar_r;
	sonar_r.init(trigger_r, echo_r);

	Sonar sonar_l;
	sonar_l.init(trigger_l, echo_l);

	if (debug == 1) {
		cout << "drive inital forward" << endl;
	}

	forward();

	if (debug == 1) {
		cout << "allone drive" << endl;
	}
	while (1) {
		int distance_m = sonar_m.distance(30000);
		int distance_r = sonar_r.distance(30000);
		int distance_l = sonar_l.distance(30000);

		if (debug == 1) {
			cout << "Distance on middle sensor is " << distance_m << " cm."
					<< endl;
			cout << "Distance on right  sensor is " << distance_r << " cm."
					<< endl;
			cout << "Distance on left   sensor is " << distance_l << " cm."
					<< endl;
			cout << "---" << endl;
		}

		if (distance_m < maxWallDisntance) {
			if (distance_m > 0) {
				if (distance_r < distance_l) {
					left();
				} else {
					right();
				}
				left();
			} else {
				backward();
				right();
			}
		}

		if (distance_r < maxWallDisntance) {
			if (distance_r > 0) {
				left();
			} else {
				right();
			}
		} else {
			left();
		}

		if (distance_l < maxWallDisntance) {
			if (distance_l > 0) {
				right();
			} else {
				backward();
				left();
			}
		} else {
			backward();
			right();
		}
		forward();
	}
	return -1;
}

void forward(void) {
	if (debug == 1) {
		cout << "forward" << endl;
	}
	digitalWrite(motor_r_u, pwmValue);
	digitalWrite(motor_r_v, pwmValueInit);

	digitalWrite(motor_l_u, pwmValueInit);
	digitalWrite(motor_l_v, pwmValue);
}
void backward(void) {
	if (debug == 1) {
		cout << "backward" << endl;
	}
	digitalWrite(motor_r_u, pwmValueInit);
	digitalWrite(motor_r_v, pwmValue);

	digitalWrite(motor_l_u, pwmValue);
	digitalWrite(motor_l_v, pwmValueInit);
}
void left(void) {
	if (debug == 1) {
		cout << "left" << endl;
	}
	digitalWrite(motor_r_u, pwmValueInit);
	digitalWrite(motor_r_v, pwmValue);

	digitalWrite(motor_l_u, pwmValueInit);
	digitalWrite(motor_l_v, pwmValue);
}
void right(void) {
	if (debug == 1) {
		cout << "right" << endl;
	}
	digitalWrite(motor_r_u, pwmValue);
	digitalWrite(motor_r_v, pwmValueInit);

	digitalWrite(motor_l_u, pwmValue);
	digitalWrite(motor_l_v, pwmValueInit);
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
