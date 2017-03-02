//============================================================================
// Name        : photoresistor.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description : need ad converter (TODO buy it)
//============================================================================

#include <iostream>
#include "../lib/wiringPi/wiringPi/wiringPi.h"

using namespace std;

int debug = 1;

// photoresistor
int photoresistor = 21;

int result = 0;

int main(void) {

	if (debug == 1) {
		cout << "init wiring pi" << endl;
	}

	if (wiringPiSetup() == -1)
		return -1;

	if (debug == 1) {
		cout << "prepare photoresistor" << endl;
	}

	// photoresistor
	pinMode(photoresistor, OUTPUT);
	digitalWrite(photoresistor, LOW);

	// TODO
	while (1) {
		result = analogRead(photoresistor);
		cout << result << endl;
		delay(1000);
	}
	return -1;
}
