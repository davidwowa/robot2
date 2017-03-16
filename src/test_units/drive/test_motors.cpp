//============================================================================
// Name        : test_motors.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================
#include "iostream"

#include "../../drive/drive.h"

#include "../../sonar/sonar.h"
#include "../../display/display.h"

#include "../../../lib/WiringPi/wiringPi/wiringPi.h"
#include "../../../lib/WiringPi/wiringPi/softPwm.h"

using namespace std;

int main(void) {
	init_drive();
	init_display();

	// acceleration forward
	cout << "acceleration forward" << endl;
	draw_text("acceleration forward", 1, false);
	for (int var = 0; var < 200; ++var) {
		cout << "set speed to " << var << endl;
		draw_text("acceleration forward", 1, true);
		std::string text_on_display = "acc for " + std::to_string(var);
		draw_text(text_on_display, 0, false);
		drive_forward(var);
		delay(100);
	}
	// acceleration backward
	cout << "acceleration backward" << endl;
	draw_text("acceleration backward", 1, false);
	for (int var = 0; var < 200; ++var) {
		cout << "set speed to " << var << endl;
		draw_text("acceleration backward", 1, true);
		std::string text_on_display = "back for " + std::to_string(var);
		draw_text(text_on_display, 0, false);
		drive_backward(var);
		delay(100);
	}

	cout << "drive forward" << endl;
	draw_text("FORWARD", 0, true);
	drive_forward();
	delay(3000);
	cout << "drive backward" << endl;
	draw_text("BACKWARD", 0, true);
	drive_backward();
	delay(3000);
	cout << "drive right" << endl;
	draw_text("TURN_RIGHT", 0, true);
	turn_right();
	delay(3000);
	cout << "drive left" << endl;
	draw_text("TURN_LEFT", 0, true);
	turn_left();
	delay(3000);

	cout << "stop" << endl;
	draw_text("STOP", 0, true);
	drive_backward(0);
	return -1;
}
