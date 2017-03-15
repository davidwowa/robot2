/*
 * gpio.h
 *
 *  Created on: 02.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

/*
 +-----+-----+---------+------+---+---Pi 2---+---+------+---------+-----+-----+
 | USD | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 |     |     |    3.3v |      |   |  1 || 2  |   |      | 5v      |     |     |
 |   D |   8 |   SDA.1 |   IN | 0 |  3 || 4  |   |      | 5v      |     |     |
 |   D |   9 |   SCL.1 |  OUT | 0 |  5 || 6  |   |      | 0v      |     |     |
 |   E |   7 | GPIO. 7 |   IN | 1 |  7 || 8  | 1 | ALT0 | TxD     | 15  | 14  |
 |     |     |      0v |      |   |  9 || 10 | 1 | ALT0 | RxD     | 16  | 15  |
 |   T |   0 | GPIO. 0 |   IN | 0 | 11 || 12 | 0 | OUT  | GPIO. 1 | 1   | 18  |
 |   E |   2 | GPIO. 2 |   IN | 0 | 13 || 14 |   |      | 0v      |     |     |
 |   T |   3 | GPIO. 3 |   IN | 0 | 15 || 16 | 0 | IN   | GPIO. 4 | 4   | 23  |
 |     |     |    3.3v |      |   | 17 || 18 | 0 | OUT  | GPIO. 5 | 5   | 24  |
 |   E |  12 |    MOSI |   IN | 0 | 19 || 20 |   |      | 0v      |     |     |
 |   T |  13 |    MISO |   IN | 0 | 21 || 22 | 0 | IN   | GPIO. 6 | 6   | 25  |
 |   E |  14 |    SCLK |   IN | 0 | 23 || 24 | 1 | IN   | CE0     | 10  | 8   |
 |     |     |      0v |      |   | 25 || 26 | 1 | IN   | CE1     | 11  | 7   |
 |   T |  30 |   SDA.0 |   IN | 1 | 27 || 28 | 1 | IN   | SCL.0   | 31  | 1   |
 |   - |  21 | GPIO.21 |   IN | 1 | 29 || 30 |   |      | 0v      |     |     |
 |   6 |  22 | GPIO.22 |   IN | 1 | 31 || 32 | 0 | IN   | GPIO.26 | 26  | M   |
 |  13 |  23 | GPIO.23 |   IN | 0 | 33 || 34 |   |      | 0v      |     |     |
 |  19 |  24 | GPIO.24 |   IN | 0 | 35 || 36 | 0 | IN   | GPIO.27 | 27  | M   |
 |  26 |  25 | GPIO.25 |   IN | 0 | 37 || 38 | 0 | IN   | GPIO.28 | 28  | M   |
 |     |     |      0v |      |   | 39 || 40 | 0 | IN   | GPIO.29 | 29  | M   |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+---Pi 2---+---+------+---------+-----+-----+
 */

#ifndef GPIO_H_
#define GPIO_H_

// middle sonar sensor
extern const int ECHO_M = 7;
extern const int TRIGGER_M = 0;

// right sonar sensor
extern const int ECHO_R = 2;
extern const int TRIGGER_R = 3;

// left sonar sensor
extern const int ECHO_L = 12;
extern const int TRIGGER_L = 13;

// back sonar sensor
extern const int ECHO_B = 14;
extern const int TRIGGER_B = 30;

// motor pins (pwm)
// motor left
extern const int MOTOR_L_U = 26;
extern const int MOTOR_L_V = 27;

// motor right
extern const int MOTOR_R_U = 28;
extern const int MOTOR_R_V = 29;

// pwm
extern const int PWM_MAX = 200;
extern const int PWM_MIN = 0;

#endif /* GPIO_H_ */
