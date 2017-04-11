/*
 * display_test_2.cpp
 *
 *  Created on: 13.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include <stdio.h>
#include <string.h>

#include "../../config/config.h"
#include "../../display/display.h"

using namespace std;

int main(void) {
	init_display();

	system("sudo kill $(pidof omxplayer)");
	system("omxplayer /home/pi/robot2/sounds/belch-kevan.mp3 &");

	draw_text("line 0", 0, false);

	draw_text("line 1", 1, false);
	draw_text("line 2", 2, false);
	draw_text("line 3", 3, false);
	draw_text("line 4", 4, false);
	draw_text("line 5", 5, false);
	draw_text("line 6", 6, false);

	return 1;
}
