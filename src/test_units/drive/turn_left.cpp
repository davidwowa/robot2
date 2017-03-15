//============================================================================
// Name        : drive_left.cpp
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

	turn_left(200);

	return 1;
}
