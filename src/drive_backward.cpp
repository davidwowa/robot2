//============================================================================
// Name        : drive_backward.cpp
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

	drive_backward();

	return 1;
}
