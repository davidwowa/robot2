//============================================================================
// Name        : drive_forward.cpp
// Author      : Zakrevskyy Wladimir David
// Version     : v.0.1
// Copyright   :
// Description :
//============================================================================

#include "analytics.h"
#include "gpio.h"
#include "config.h"
#include "common.h"
#include "wiring_pi.h"
#include "drive.h"

using namespace std;

int main(void) {

	init_drive();

	drive_forward();

	return 1;
}
