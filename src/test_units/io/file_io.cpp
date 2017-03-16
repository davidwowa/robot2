/*
 * file_io.cpp
 *
 *  Created on: 17.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include "iostream"
#include <stdio.h>

using namespace std;

int is_running();

int main() {
	int test = is_running();

	cout << "first test " << test << endl;

	while (1 == test) {
		cout << "core run" << test << endl;
		run();
		delay(510);
		test = is_running();
	}
	cout << "core stop" << test << endl;
	return -1;
}

int is_running() {
	FILE *run_config;
	int is_run = 0;

	run_config = fopen("/home/pi/robot2/src/config/run", "r");
	if (run_config) {
		fscanf(run_config, "%d", &is_run);
		fclose(run_config);
	}
	return is_run;
}
