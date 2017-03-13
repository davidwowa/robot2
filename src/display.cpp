/*
 * display.cpp
 *
 *  Created on: 09.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include <getopt.h>
#include <sys/statvfs.h>
#include <math.h>

#include "display.h"
#include "common.h"

using namespace std;

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

// 0-16 -> 0
// 16-24 -> 1
// 25-33 -> 2
// 34-42 -> 3
// 43-51 -> 4
// 52-60 -> 5
// 61-63 -> 6
void draw_text(std::string text, int line_number) {
	const char* c_string = text.c_str();
	display.clearDisplay();
	if (0 == line_number) {
		display.setTextColor(WHITE);
		display.setCursor(0, 0);
		display.setTextSize(2);
		display.printf("%s", c_string);
	}
	if (1 == line_number) {
		display.setTextColor(WHITE);
		display.setCursor(0, 16);
		display.setTextSize(1);
		display.printf("%s", c_string);
	}
	if (2 == line_number) {
		display.setTextColor(WHITE);
		display.setCursor(0, 25);
		display.setTextSize(1);
		display.printf("%s", c_string);
	}
	if (3 == line_number) {
		display.setTextColor(WHITE);
		display.setCursor(0, 34);
		display.setTextSize(1);
		display.printf("%s", c_string);
	}
	if (4 == line_number) {
		display.setTextColor(WHITE);
		display.setCursor(0, 43);
		display.setTextSize(1);
		display.printf("%s", c_string);
	}
	if (5 == line_number) {
		display.setTextColor(WHITE);
		display.setCursor(0, 52);
		display.setTextSize(1);
		display.printf("%s", c_string);
	}
	if (6 == line_number) {
		display.setTextColor(WHITE);
		display.setCursor(0, 61);
		display.setTextSize(1);
		display.printf("%s", c_string);
	}
	display.display();
}

void display_data(int direction, int speed, int m, int r, int l, int b) {
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setCursor(0, 0);
	display.setTextSize(2);
	display.printf("d=%d", direction);

	display.setCursor(40, 0);
	display.printf("s=%d", speed);

	if (m <= 127) {
		display.drawHorizontalBargraph(0, 16, (int16_t) display.width(), 4, 1,
				m);
	} else {
		display.drawHorizontalBargraph(0, 16, (int16_t) display.width(), 4, 1,
				100);
	}
	if (r <= 127) {
		display.drawHorizontalBargraph(0, 21, (int16_t) display.width(), 4, 1,
				r);
	} else {
		display.drawHorizontalBargraph(0, 21, (int16_t) display.width(), 4, 1,
				100);
	}
	if (l <= 127) {
		display.drawHorizontalBargraph(0, 26, (int16_t) display.width(), 4, 1,
				l);
	} else {
		display.drawHorizontalBargraph(0, 26, (int16_t) display.width(), 4, 1,
				100);
	}
	if (b <= 127) {
		display.drawHorizontalBargraph(0, 31, (int16_t) display.width(), 4, 1,
				b);
	} else {
		display.drawHorizontalBargraph(0, 31, (int16_t) display.width(), 4, 1,
				100);
	}

	display.setTextSize(1);
	display.setCursor(0, 36);
	display.printf("v.%d", 2);

	double cpu_temp = get_cpu_usage_data();

	display.setCursor(30, 36);
	display.printf("CPU:%.0fC", cpu_temp);

	double usage = get_hdd_usage_data();

	display.setCursor(86, 36);
	display.printf("HD:%.0f%%", usage);

	std::string ip = get_ip_address();
	display.setCursor(0, 44);

	const char* arr = ip.c_str();

	display.print(arr);
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

std::string get_ip_address() {
	int fd;
	struct ifreq ifr;

	fd = socket(AF_INET, SOCK_DGRAM, 0);

	/* I want to get an IPv4 IP address */
	ifr.ifr_addr.sa_family = AF_INET;

	/* I want IP address attached to "wlan0" */
	strncpy(ifr.ifr_name, "wlan0", IFNAMSIZ - 1);

	ioctl(fd, SIOCGIFADDR, &ifr);

	close(fd);

	char* out = inet_ntoa(((struct sockaddr_in *) &ifr.ifr_addr)->sin_addr);

	/* display result */
	//printf("IP:%s\n", out);
	std::string str(out);

	return str;
}

//int main() {
//	init_display();
//	display_data(1, 123, 20, 50, 80, 90);
//}
