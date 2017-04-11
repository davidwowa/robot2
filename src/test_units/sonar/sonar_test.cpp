/*
 * sonar_test.cpp
 *
 *  Created on: 11.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>

#include "../../sonar/sonar.h"
#include "../../display/display.h"

#include "../../../lib/WiringPi/wiringPi/wiringPi.h"

using namespace std;

int main(void) {

	system("sudo kill $(pidof omxplayer)");
	system("omxplayer /home/pi/robot2/sounds/funny-voices.mp3 &");

	cout << "display show" << endl;
	init_sonar();

	init_display();
	int i = 100;
	int counter = 0;

	while (counter <= i) {

		int distance_m = get_distance_m();
		int distance_r = get_distance_r();
		int distance_l = get_distance_l();
		int distance_b = get_distance_b();

		cout << "Distance on middle sensor is " << distance_m << " cm." << endl;
		cout << "Distance on right  sensor is " << distance_r << " cm." << endl;
		cout << "Distance on left   sensor is " << distance_l << " cm." << endl;
		cout << "Distance on back   sensor is " << distance_b << " cm." << endl;
		cout << "---" << endl;
		counter++;
		display_data(0, 0, distance_m, distance_r, distance_l, distance_b);
	}
	return -1;
}
