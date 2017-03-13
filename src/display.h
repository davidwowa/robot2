/*
 * display.h
 *
 *  Created on: 09.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "common.h"

#include "../lib/ArduiPi_OLED/ArduiPi_OLED_lib.h"
#include "../lib/ArduiPi_OLED/Adafruit_GFX.h"
#include "../lib/ArduiPi_OLED/ArduiPi_OLED.h"

extern void init_display(void);

extern void display_common_data(void);
extern void display_data(int direction, int speed, int m, int r, int l,
		int b);
extern void display_manual_drive_data();

extern double get_cpu_usage_data(void);
extern double get_hdd_usage_data(void);
extern std::string get_ip_address(void);

extern void draw_text(std::string text, int line_number);

#endif /* DISPLAY_H_ */
