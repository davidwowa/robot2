//============================================================================
// Name        : drive_right.cpp
// Author      : Zakrevskyy Wladimir David
// Version     : v.0.1
// Copyright   :
// Description :
//============================================================================

#include "common.h"
#include "gpio.h"
#include "analytics.h"
#include "drive.h"

using namespace std;

int main(void) {

	init_drive();

	turn_right();

	return 1;
}
