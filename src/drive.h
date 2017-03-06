/*
 * drive.h
 *
 *  Created on: 02.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#ifndef DRIVE_H_
#define DRIVE_H_

void init(void);

void drive_backward(void);
void drive_forward(void);
void turn_left(void);
void turn_right(void);

void drive_backward(int pwm);
void drive_forward(int pwm);
void turn_left(int pwm);
void turn_right(int pwm);

void drive_backward(int pin, int pwm);
void drive_forward(int pin, int pwm);
void turn_left(int pin, int pwm);
void turn_right(int pin, int pwm);

void stop(void);

#endif /* DRIVE_H_ */
