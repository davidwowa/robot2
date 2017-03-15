//============================================================================
// Name        : drive_stop.cpp
// Author      : Zakrevskyy Wladimir David
// Version     : v.0.1
// Copyright   :
// Description :
//============================================================================

#include "../../drive/drive.h"

#include "../../lib/wiringPi/wiringPi/wiringPi.h"
#include "../../lib/wiringPi/wiringPi/softPwm.h"

int main(void) {

	init_drive();

//	stop_motors();
	drive_backward(0);

	return 1;
}
