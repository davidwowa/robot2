//============================================================================
// Name        : reset_pins.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

/*
 +-----+-----+---------+------+---+---Pi 2---+---+------+---------+-----+-----+
 | USD | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 |     |     |    3.3v |      |   |  1 || 2  |   |      | 5v      |     |     |
 |   X |   8 |   SDA.1 |   IN | 0 |  3 || 4  |   |      | 5v      |     |     |
 |   X |   9 |   SCL.1 |  OUT | 0 |  5 || 6  |   |      | 0v      |     |     |
 |   X |   7 | GPIO. 7 |   IN | 1 |  7 || 8  | 1 | ALT0 | TxD     | 15  | 14  |
 |     |     |      0v |      |   |  9 || 10 | 1 | ALT0 | RxD     | 16  | 15  |
 |   X |   0 | GPIO. 0 |   IN | 0 | 11 || 12 | 0 | OUT  | GPIO. 1 | 1   | 18  |
 |   X |   2 | GPIO. 2 |   IN | 0 | 13 || 14 |   |      | 0v      |     |     |
 |   X |   3 | GPIO. 3 |   IN | 0 | 15 || 16 | 0 | IN   | GPIO. 4 | 4   | 23  |
 |     |     |    3.3v |      |   | 17 || 18 | 0 | OUT  | GPIO. 5 | 5   | 24  |
 |   X |  12 |    MOSI |   IN | 0 | 19 || 20 |   |      | 0v      |     |     |
 |   - |  13 |    MISO |   IN | 0 | 21 || 22 | 0 | IN   | GPIO. 6 | 6   | 25  |
 |   - |  14 |    SCLK |   IN | 0 | 23 || 24 | 1 | IN   | CE0     | 10  | 8   |
 |     |     |      0v |      |   | 25 || 26 | 1 | IN   | CE1     | 11  | 7   |
 |   - |  30 |   SDA.0 |   IN | 1 | 27 || 28 | 1 | IN   | SCL.0   | 31  | 1   |
 |   - |  21 | GPIO.21 |   IN | 1 | 29 || 30 |   |      | 0v      |     |     |
 |   6 |  22 | GPIO.22 |   IN | 1 | 31 || 32 | 0 | IN   | GPIO.26 | 26  | X   |
 |  13 |  23 | GPIO.23 |   IN | 0 | 33 || 34 |   |      | 0v      |     |     |
 |  19 |  24 | GPIO.24 |   IN | 0 | 35 || 36 | 0 | IN   | GPIO.27 | 27  | X   |
 |  26 |  25 | GPIO.25 |   IN | 0 | 37 || 38 | 0 | IN   | GPIO.28 | 28  | X   |
 |     |     |      0v |      |   | 39 || 40 | 0 | IN   | GPIO.29 | 29  | X   |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+---Pi 2---+---+------+---------+-----+-----+
 */

#include <iostream>
#include <wiringPi.h>
//#include "../lib/wiringPi/wiringPi/wiringPi.h"

using namespace std;

int main(void) {

	if (wiringPiSetup() == -1)
		return -1;

	cout << "set all pins to input" << endl;

	pinMode(8, INPUT);
	pinMode(9, INPUT);
	pinMode(7, INPUT);
	pinMode(0, INPUT);
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	pinMode(26, INPUT);
	pinMode(27, INPUT);
	pinMode(28, INPUT);
	pinMode(29, INPUT);

	cout << "set all pins to low" << endl;

	digitalWrite(8, LOW);
	digitalWrite(9, LOW);
	digitalWrite(7, LOW);
	digitalWrite(0, LOW);
	digitalWrite(2, LOW);
	digitalWrite(3, LOW);
	digitalWrite(26, LOW);
	digitalWrite(27, LOW);
	digitalWrite(28, LOW);
	digitalWrite(29, LOW);

	cout << "Done" << endl;

	return -1;
}
