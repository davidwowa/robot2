/*
 * display_test_2.cpp
 *
 *  Created on: 13.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include "analytics.h"
#include "gpio.h"
//#include "common.h"
#include "wiring_pi.h"
#include "display.h"

using namespace std;

void init_wiringPi2(void);

int main(void) {
	init_wiringPi2();

	init_display();

	draw_text("line 0", 0);

	draw_text("line 1", 1);
	draw_text("line 2", 2);
	draw_text("line 3", 3);
	draw_text("line 4", 4);
	draw_text("line 5", 5);
	draw_text("line 6", 6);

	return 1;
}

void init_wiringPi2(void) {
	if (DEBUG == 1) {
		cout << "init wiring pi" << endl;
	}

	if (wiringPiSetup() == -1) {
		if (DEBUG == 1) {
			cout << "error on wiring pi setup" << endl;
		}
	} else {
		if (DEBUG == 1) {
			cout << "wiring pi setup OK" << endl;
		}
	}
}
