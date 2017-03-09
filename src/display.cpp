/*
 * display.cpp
 *
 *  Created on: 09.03.2017
 *      Author: Wladimir David Zakrevskyy
 */
#include "display.h"

#include <stdio.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <getopt.h>
#include <sys/statvfs.h>
#include <math.h>
#include <string>

#include "../lib/ArduiPi_OLED/ArduiPi_OLED_lib.h"
#include "../lib/ArduiPi_OLED/Adafruit_GFX.h"
#include "../lib/ArduiPi_OLED/ArduiPi_OLED.h"

// Instantiate the display
ArduiPi_OLED display;

// Config Option
struct s_opts {
	int oled;
	int verbose;
};

// default options values
s_opts opts = {
OLED_ADAFRUIT_I2C_128x64,	// Default oled
		false				// Not verbose
		};

void init_display() {
	if (!display.init(OLED_I2C_RESET, opts.oled))
		exit(EXIT_FAILURE);

	display.begin();
	// init done
	display.clearDisplay();   // clears the screen  buffer
	display.display();   	// display it (clear display)
}

void display_data(int direction, int speed, int m, int r, int l, int b) {
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setCursor(0, 0);
	display.setTextSize(2);
	display.printf("d=%d", direction);

	display.setCursor(50, 0);
	display.printf("s=%d", speed);

	if (m <= 100) {
		display.drawHorizontalBargraph(0, 16, (int16_t) display.width(), 8, 1,
				m);
	} else {
		display.drawHorizontalBargraph(0, 16, (int16_t) display.width(), 8, 1,
				100);
	}

	if (r <= 100) {
		display.drawHorizontalBargraph(0, 25, (int16_t) display.width(), 8, 1,
				r);
	} else {
		display.drawHorizontalBargraph(0, 25, (int16_t) display.width(), 8, 1,
				100);
	}

	if (l <= 100) {
		display.drawHorizontalBargraph(0, 34, (int16_t) display.width(), 8, 1,
				l);
	} else {
		display.drawHorizontalBargraph(0, 34, (int16_t) display.width(), 8, 1,
				100);
	}
	if (b <= 100) {
		display.drawHorizontalBargraph(0, 43, (int16_t) display.width(), 8, 1,
				b);
	} else {
		display.drawHorizontalBargraph(0, 43, (int16_t) display.width(), 8, 1,
				100);
	}

	display.setTextSize(1);
	display.setCursor(0, 53);
	display.printf("v.%d", 2);

	double cpu_temp = get_cpu_usage_data();

	display.setCursor(30, 53);
	display.printf("CPU:%.0fC", cpu_temp);

	double usage = get_hdd_usage_data();

	display.setCursor(86, 53);
	display.printf("HD:%.0f%%", usage);

	// string ip = get_ip_address();
	// TODO display data

	system("date -> date.txt");

	display.display();
}

double get_cpu_usage_data() {
	FILE *temperatureFile;
	double T = 0.0;

	temperatureFile = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
	if (temperatureFile) {
		fscanf(temperatureFile, "%lf", &T);
		fclose(temperatureFile);
	}
	T = T / 1000.0;
	return T;
}

double get_hdd_usage_data() {
	struct statvfs buf;
	double usage = 0.0;

	if (!statvfs("/etc/rc.local", &buf)) {
		unsigned long hd_used;
		hd_used = buf.f_blocks - buf.f_bfree;
		usage = ((double) hd_used) / ((double) buf.f_blocks) * 100;
	}
	return round(usage);
}

void get_ip_address(char* out) {

}
