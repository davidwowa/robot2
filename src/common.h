/*
 * common.h
 *
 *  Created on: 02.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#ifndef COMMON_H_
#define COMMON_H_

int MAX_WALL_DISTANCE_3 = 30;
int MAX_WALL_DISTANCE_2 = 20;
int MAX_WALL_DISTANCE_1 = 10;

int SPEED_3 = 200;
int SPEED_2 = 175;
int SPEED_1 = 150;

int FORWARD = 1;
int TURN_LEFT = 2;
int BACKWARD = 3;
int TURN_RIGHT = 4;

int INTERVAL = 600;

void set_working_pins_to_low(void);

#endif /* COMMON_H_ */
