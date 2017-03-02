//============================================================================
// Name        : reset_pins.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>

#include "../lib/wiringPi/wiringPi/wiringPi.h"

#include "common.h"

using namespace std;

int main(void) {
	set_working_pins_to_low();
	return -1;
}

void set_working_pins_to_low(void) {
	if (wiringPiSetup() == -1) {
		cout << "error init wiring pi" << endl;
	} else {
		cout << "init wiring pi ok" << endl;
	}
	cout << "set all pins to input" << endl;

	pinMode(8, INPUT);
	pinMode(9, INPUT);
	pinMode(7, INPUT);
	pinMode(0, INPUT);
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	pinMode(26, INPUT);
	pinMode(27, INPUT);
	pinMode(28, INPUT);
	pinMode(29, INPUT);

	cout << "set all pins to low" << endl;

	digitalWrite(8, LOW);
	digitalWrite(9, LOW);
	digitalWrite(7, LOW);
	digitalWrite(0, LOW);
	digitalWrite(2, LOW);
	digitalWrite(3, LOW);
	digitalWrite(26, LOW);
	digitalWrite(27, LOW);
	digitalWrite(28, LOW);
	digitalWrite(29, LOW);

	cout << "Done" << endl;
}
