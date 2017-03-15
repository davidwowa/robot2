/*
 * sonar_test.cpp
 *
 *  Created on: 11.03.2017
 *      Author: Wladimir David Zakrevskyy
 */
#include <iostream>

#include "../../sonar/sonar.h"
#include "../../display/display.h"

#include "../../../lib/HC-SR04-Raspberry-Pi-C-/libSonar.h"

#include "../../../lib/wiringPi/wiringPi/wiringPi.h"
#include "../../../lib/wiringPi/wiringPi/softPwm.h"

using namespace std;

Sonar sonar_m_t;
Sonar sonar_r_t;
Sonar sonar_l_t;
Sonar sonar_b_t;

int DEBUG_t = 1;

int main(void) {
	if (DEBUG_t == 1) {
		cout << "display show" << endl;
	}
	init_sonar();

	init_display();
	while (1) {

		int distance_m = sonar_m_t.distance(30000);
		int distance_r = sonar_r_t.distance(30000);
		int distance_l = sonar_l_t.distance(30000);
		int distance_b = sonar_b_t.distance(30000);

		if (DEBUG_t == 1) {
			cout << "Distance on middle sensor is " << distance_m << " cm."
					<< endl;
			cout << "Distance on right  sensor is " << distance_r << " cm."
					<< endl;
			cout << "Distance on left   sensor is " << distance_l << " cm."
					<< endl;
			cout << "Distance on back   sensor is " << distance_b << " cm."
					<< endl;
			cout << "---" << endl;
		}

		display_data(0, 0, distance_m, distance_r, distance_l, distance_b);
	}
	return -1;
}
