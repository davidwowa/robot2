//============================================================================
// Name        : drive_right.cpp
// Author      : Zakrevskyy Wladimir David
// Version     : v.0.1
// Copyright   :
// Description :
//============================================================================

#include "../../drive/drive.h"

#include "../../sonar/sonar.h"
#include "../../display/display.h"

#include "../../../lib/WiringPi/wiringPi/wiringPi.h"
#include "../../../lib/WiringPi/wiringPi/softPwm.h"

int main(void) {

	init_drive();
	init_display();

	draw_text("TURN_RIGHT", 0, true);
	turn_right(0);
	draw_text("ok", 1, false);

	return 1;
}
