/*
 * display.cpp
 *
 *  Created on: 08.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include "../lib/ArduiPi_OLED/ArduiPi_OLED_lib.h"
#include "../lib/ArduiPi_OLED/Adafruit_GFX.h"
#include "../lib/ArduiPi_OLED/ArduiPi_OLED.h"

#include <getopt.h>

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

int main() {
	if (!display.init(OLED_I2C_RESET, opts.oled))
		exit(EXIT_FAILURE);

	display.begin();
	// init done
	display.clearDisplay();   // clears the screen  buffer
	display.display();   	// display it (clear display)

	// text display tests
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0, 0);
	display.print("Hello, world!\n");
	display.setTextColor(BLACK, WHITE); // 'inverted' text
	display.printf("%f\n", 3.141592);
	display.setTextSize(2);
	display.setTextColor(WHITE);
	display.printf("0x%8X\n", 0xDEADBEEF);
	display.display();
	sleep(2);

	// showing on this display is very slow (the driver need to be optimized)
	int sleep_divisor = 4;

	// horizontal bargraph tests
	display.clearDisplay();
	display.setTextSize(2);
	display.setTextColor(WHITE);
	for (int i = 0; i <= 100; i++) {
		display.clearDisplay();
		display.setCursor(0, 0);
//		display.print("Gauge Graph!\n");
		display.printf("  %03d %%", i);

		display.drawHorizontalBargraph(0, 16, (int16_t) display.width(), 8, 1,
				i);
		display.drawHorizontalBargraph(0, 25, (int16_t) display.width(), 8, 1,
				i);
		display.drawHorizontalBargraph(0, 34, (int16_t) display.width(), 8, 1,
				i);
		display.drawHorizontalBargraph(0, 43, (int16_t) display.width(), 8, 1,
				i);

		display.display();
		usleep(25000 / sleep_divisor);
	}
}
