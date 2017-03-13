/*
 * display_test_2.cpp
 *
 *  Created on: 13.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include "analytics.h"
#include "gpio.h"
#include "config.h"
#include "common.h"
#include "wiring_pi.h"
#include "display.h"

#include <getopt.h>
#include <sys/statvfs.h>
#include <math.h>

using namespace std;

int main(void) {
	init_wiringPi();

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
