/*
 * common.h
 *
 *  Created on: 02.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

//#ifndef COMMON_H_
//#define COMMON_H_

#include <iostream>
#include <getopt.h>
#include <math.h>

#include <stdio.h>
#include <string.h>
#include <string>

#include <sys/types.h>
#include <sys/statvfs.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <ifaddrs.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

extern const int MAX_WALL_DISTANCE_3 = 30;
extern const int MAX_WALL_DISTANCE_2 = 20;
extern const int MAX_WALL_DISTANCE_1 = 10;

extern const int SPEED_3 = 200;
extern const int SPEED_2 = 165;
extern const int SPEED_1 = 125;

extern const int FORWARD = 1;
extern const int TURN_LEFT = 2;
extern const int BACKWARD = 3;
extern const int TURN_RIGHT = 4;

extern const int INTERVAL = 600;

extern void init_wiringPi(void);
extern void init_PWM(void);

extern void set_working_pins_to_low(void);

extern int is_running(std::string file_path);

//#endif /* COMMON_H_ */
