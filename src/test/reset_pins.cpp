//============================================================================
// Name        : reset_pins.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>

#include "../drive/gpio_drive.h"
#include "../sonar/gpio_sonar.h"

#include "../../lib/wiringPi/wiringPi/wiringPi.h"

using namespace std;

int DEBUG = 1;

void set_working_pins_to_low();

int main(void) {
	set_working_pins_to_low();
	return -1;
}

void set_working_pins_to_low(void) {
	if (wiringPiSetup() == -1) {
		if (DEBUG == 1) {
			cout << "error on wiring pi setup" << endl;
		}
	} else {
		if (DEBUG == 1) {
			cout << "wiring pi setup OK" << endl;
		}
	}
	cout << "set all pins to INPUT" << endl;

	pinMode(ECHO_M, INPUT);
	pinMode(TRIGGER_M, INPUT);
	pinMode(ECHO_R, INPUT);
	pinMode(TRIGGER_R, INPUT);
	pinMode(ECHO_L, INPUT);
	pinMode(TRIGGER_L, INPUT);
	pinMode(ECHO_B, INPUT);
	pinMode(TRIGGER_B, INPUT);

	pinMode(MOTOR_L_U, INPUT);
	pinMode(MOTOR_L_V, INPUT);

	pinMode(MOTOR_R_U, INPUT);
	pinMode(MOTOR_R_V, INPUT);

	cout << "set all pins to LOW" << endl;

	digitalWrite(ECHO_M, LOW);
	digitalWrite(TRIGGER_M, LOW);
	digitalWrite(ECHO_R, LOW);
	digitalWrite(TRIGGER_R, LOW);
	digitalWrite(ECHO_L, LOW);
	digitalWrite(TRIGGER_L, LOW);
	digitalWrite(ECHO_B, LOW);
	digitalWrite(TRIGGER_B, LOW);

	digitalWrite(MOTOR_L_U, LOW);
	digitalWrite(MOTOR_L_V, LOW);

	digitalWrite(MOTOR_R_U, LOW);
	digitalWrite(MOTOR_R_V, LOW);

	cout << "Done" << endl;
}