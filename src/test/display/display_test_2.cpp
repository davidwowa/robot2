/*
 * display_test_2.cpp
 *
 *  Created on: 13.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include "../../config/config.h"
#include "../../display/display.h"

using namespace std;

int main(void) {
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
