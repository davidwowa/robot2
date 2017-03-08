/*
 * display.cpp
 *
 *  Created on: 08.03.2017
 *      Author: David
 */

#include "../lib/wiringPi/wiringPi/wiringPiI2C.h"

int main() {
	wiringPiI2CSetup(1);
	wiringPiI2CWrite (1, 23);
}
