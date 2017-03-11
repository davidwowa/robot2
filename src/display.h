/*
 * display.h
 *
 *  Created on: 09.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdio.h>
#include <math.h>
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

#include <getopt.h>

#include "../lib/ArduiPi_OLED/ArduiPi_OLED_lib.h"
#include "../lib/ArduiPi_OLED/Adafruit_GFX.h"
#include "../lib/ArduiPi_OLED/ArduiPi_OLED.h"

using namespace std;

extern void init_display(void);

extern void display_common_data(void);
extern void display_drive_data(int direction, int speed, int m, int r, int l,
		int b);
extern void display_manual_drive_data();

extern double get_cpu_usage_data(void);
extern double get_hdd_usage_data(void);
extern std::string get_ip_address(void);

#endif /* DISPLAY_H_ */
