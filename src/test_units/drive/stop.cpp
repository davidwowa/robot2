//============================================================================
// Name        : drive_stop.cpp
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

	draw_text("STOP", 0, true);
//	stop_motors();
	drive_backward(200);
	draw_text("ok", 1, false);

	return 1;
}
