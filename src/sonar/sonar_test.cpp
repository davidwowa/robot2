/*
 * sonar_test.cpp
 *
 *  Created on: 11.03.2017
 *      Author: Wladimir David Zakrevskyy
 */
#include <iostream>

#include "../display/display.h"
#include "sonar.h"

using namespace std;

Sonar sonar_m;
Sonar sonar_r;
Sonar sonar_l;
Sonar sonar_b;

int DEBUG = 1;

int main(void) {
	if (DEBUG == 1) {
		cout << "display show" << endl;
	}
	init_sonar();

	init_display();
	while (1) {

		int distance_m = sonar_m.distance(30000);
		int distance_r = sonar_r.distance(30000);
		int distance_l = sonar_l.distance(30000);
		int distance_b = sonar_b.distance(30000);

		if (DEBUG == 1) {
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
