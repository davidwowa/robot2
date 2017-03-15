//============================================================================
// Name        : test_motors.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

#include "iostream"

#include "../../drive/drive.h"

#include "../../../lib/wiringPi/wiringPi/wiringPi.h"
#include "../../../lib/wiringPi/wiringPi/softPwm.h"

using namespace std;

int main(void) {

	init_drive();

	// acceleration forward
	cout << "acceleration forward" << endl;
	for (int var = 0; var < 200; ++var) {
		cout << "set speed to " << var << endl;
		drive_backward(var);
		delay(10);
	}
	// acceleration backward
	cout << "acceleration backward" << endl;
	for (int var = 200; var < 0; --var) {
		cout << "set speed to " << var << endl;
		drive_forward(var);
		delay(10);
	}

	cout << "drive forward" << endl;
	drive_forward();
	delay(2000);
	cout << "drive backward" << endl;
	drive_backward();
	delay(2000);
	cout << "drive right" << endl;
	turn_right();
	delay(2000);
	cout << "drive left" << endl;
	turn_left();
	delay(2000);

	cout << "stop" << endl;
	stop_motors();
	return -1;
}
