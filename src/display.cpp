/*
 * display.cpp
 *
 *  Created on: 08.03.2017
 *      Author: David
 */

#include "../lib/wiringPi/wiringPi/wiringPiI2C.h"

int main() {
	int display = wiringPiI2CSetup(0x3c);
	init(display);
	clear(display);
	wiringPiI2CWrite(display, 23);
}

void init(int display) {
	wiringPiI2CWriteReg8(display, 0x00, 0xae); // display off
	wiringPiI2CWriteReg8(display, 0x00, 0xd5); // clockdiv
	wiringPiI2CWriteReg8(display, 0x00, 0x80);
	wiringPiI2CWriteReg8(display, 0x00, 0xa8); // multiplex
	wiringPiI2CWriteReg8(display, 0x00, 0x3f);
	wiringPiI2CWriteReg8(display, 0x00, 0xd3); // offset
	wiringPiI2CWriteReg8(display, 0x00, 0x00);
	wiringPiI2CWriteReg8(display, 0x00, 0x40); // startline
	wiringPiI2CWriteReg8(display, 0x00, 0x8d); // charge pump
	wiringPiI2CWriteReg8(display, 0x00, 0x14);
	wiringPiI2CWriteReg8(display, 0x00, 0x20); // memory mode
	wiringPiI2CWriteReg8(display, 0x00, 0x00);
//wiringPiI2CWriteReg8(display,0x00,0x01);
	wiringPiI2CWriteReg8(display, 0x00, 0xa1); // segregmap
	wiringPiI2CWriteReg8(display, 0x00, 0xc8); // comscandec
	wiringPiI2CWriteReg8(display, 0x00, 0xda); // set com pins
	wiringPiI2CWriteReg8(display, 0x00, 0x12);
	wiringPiI2CWriteReg8(display, 0x00, 0x81); // contrast
	wiringPiI2CWriteReg8(display, 0x00, 0xcf);
	wiringPiI2CWriteReg8(display, 0x00, 0xd9); // precharge
	wiringPiI2CWriteReg8(display, 0x00, 0xf1);
	wiringPiI2CWriteReg8(display, 0x00, 0xdb); // vcom detect
	wiringPiI2CWriteReg8(display, 0x00, 0x40);
	wiringPiI2CWriteReg8(display, 0x00, 0xa4); // resume
	wiringPiI2CWriteReg8(display, 0x00, 0xa6); // normal (not inverted)
	wiringPiI2CWriteReg8(display, 0x00, 0xaf); // display on
}

void reset_pos(int display) {
	wiringPiI2CWriteReg8(display, 0x00, 0xb0);
	wiringPiI2CWriteReg8(display, 0x00, 0x00);
	wiringPiI2CWriteReg8(display, 0x00, 0x10);
}
void clear(int display) {
	reset_pos(display);
	for (int x = 0; x < 128; x++) {
		for (int y = 0; y < 64; y++) {
			wiringPiI2CWriteReg8(display, 0x40, 0x00);
		}
	}
}
