/*
 * core.cpp
 *
 *  Created on: 15.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include "iostream"
#include <stdio.h>

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <lirc/lirc_client.h>
#include <time.h>

#include "../display/display.h"
#include "../drive/drive.h"
#include "../sonar/sonar.h"
#include "../config/config.h"

#include "../../lib/WiringPi/wiringPi/wiringPi.h"
#include "../../lib/WiringPi/wiringPi/softPwm.h"

#include "../../lib/ArduiPi_OLED/ArduiPi_OLED_lib.h"
#include "../../lib/ArduiPi_OLED/Adafruit_GFX.h"
#include "../../lib/ArduiPi_OLED/ArduiPi_OLED.h"

#include "../../lib/HC-SR04-Raspberry-Pi-C-/libSonar.h"

using namespace std;

void init(void);
void run(void);
int get_speed(int minimal_distance);
int is_running();

int current_pointer = FORWARD;

void init() {
	init_display();
	draw_text("ROBOT_2", 0, false);
	draw_text("display ready", 1, false);
	init_drive();
	draw_text("motor/pwm ready", 2, false);
	init_sonar();
	draw_text("sonar ready", 3, false);
	draw_text("ready to drive...", 4, false);
}

void run() {

	int distance_m = get_distance_m();
	int distance_r = get_distance_r();
	int distance_l = get_distance_l();
	int distance_b = get_distance_b();

	cout << "Distance on middle sensor is " << distance_m << " cm." << endl;
	cout << "Distance on right  sensor is " << distance_r << " cm." << endl;
	cout << "Distance on left   sensor is " << distance_l << " cm." << endl;
	cout << "Distance on back   sensor is " << distance_b << " cm." << endl;
	cout << "---" << endl;

	int current_minmal_distance = get_minimal_distance(distance_m, distance_r,
			distance_l);

	int current_speed = get_speed(current_minmal_distance);

	if (FORWARD == current_pointer) {
		if (distance_m > MAX_WALL_DISTANCE_1) {
			if (distance_l < MAX_WALL_DISTANCE_1) {
				turn_right(current_speed);
				current_pointer = TURN_RIGHT;
			}
			if (distance_r < MAX_WALL_DISTANCE_1) {
				turn_left(current_speed);
				current_pointer = TURN_LEFT;
			}
		} else {
			current_pointer = BACKWARD;
		}
	}

	if (BACKWARD == current_pointer) {
		if (distance_b > MAX_WALL_DISTANCE_1) {
			if (distance_l < MAX_WALL_DISTANCE_1) {
				turn_left(current_speed);
				current_pointer = TURN_LEFT;
			}
			if (distance_r < MAX_WALL_DISTANCE_1) {
				turn_right(current_speed);
				current_pointer = TURN_RIGHT;
			}
		} else {
			current_pointer = BACKWARD;
		}
	}

	if (FORWARD == current_pointer) {
		if (distance_m > MAX_WALL_DISTANCE_1 && distance_l > MAX_WALL_DISTANCE_1
				&& distance_r > MAX_WALL_DISTANCE_1) {
			drive_forward(current_speed);
			current_pointer = FORWARD;
		}
		if (distance_m < MAX_WALL_DISTANCE_1 && distance_l > MAX_WALL_DISTANCE_1
				&& distance_r < MAX_WALL_DISTANCE_1) {
			turn_left(current_speed);
			current_pointer = TURN_LEFT;
		}
		if (distance_m < MAX_WALL_DISTANCE_1 && distance_l < MAX_WALL_DISTANCE_1
				&& distance_r > MAX_WALL_DISTANCE_1) {
			turn_right(current_speed);
			current_pointer = TURN_RIGHT;
		}
		if (distance_m < MAX_WALL_DISTANCE_1 && distance_l < MAX_WALL_DISTANCE_1
				&& distance_r < MAX_WALL_DISTANCE_1) {
			drive_backward(current_speed);
			current_pointer = BACKWARD;
		}
	}

	if (BACKWARD == current_pointer) {
		if (distance_m < MAX_WALL_DISTANCE_1 && distance_l > MAX_WALL_DISTANCE_1
				&& distance_r < MAX_WALL_DISTANCE_1) {
			turn_left(current_speed);
			current_pointer = TURN_LEFT;
		}
		if (distance_m < MAX_WALL_DISTANCE_1 && distance_l < MAX_WALL_DISTANCE_1
				&& distance_r > MAX_WALL_DISTANCE_1) {
			turn_right(current_speed);
			current_pointer = TURN_RIGHT;
		}
		if (distance_m > MAX_WALL_DISTANCE_1 && distance_l > MAX_WALL_DISTANCE_1
				&& distance_r < MAX_WALL_DISTANCE_1) {
			turn_left(current_speed);
			current_pointer = TURN_LEFT;
		}
		if (distance_m > MAX_WALL_DISTANCE_1 && distance_l < MAX_WALL_DISTANCE_1
				&& distance_r > MAX_WALL_DISTANCE_1) {
			turn_right(current_speed);
			current_pointer = TURN_RIGHT;
		}
	}

	if (TURN_LEFT == current_pointer) {
		if (distance_m > MAX_WALL_DISTANCE_1 && distance_l > MAX_WALL_DISTANCE_1
				&& distance_r > MAX_WALL_DISTANCE_1) {
			drive_forward(current_speed);
			current_pointer = FORWARD;
		}
	}

	if (TURN_RIGHT == current_pointer) {
		if (distance_m > MAX_WALL_DISTANCE_1 && distance_l > MAX_WALL_DISTANCE_1
				&& distance_r > MAX_WALL_DISTANCE_1) {
			drive_forward(current_speed);
			current_pointer = FORWARD;
		}
	}

	display_data(current_pointer, current_speed, distance_m, distance_r,
			distance_l, distance_b);
}

int main(void) {
	init();

	run();

	struct lirc_config *config;

	//Timer for our buttons
	int buttonTimer = millis();

	char *code;
	char *c;

	//Initiate WiringPi and set WiringPi pins 4, 5 & 6 (GPIO 23, 24 & 25) to output. These are the pins the LEDs are connected to.
//	if (wiringPiSetup() == -1)
//		exit(1);

//Initiate LIRC. Exit on failure
	if (lirc_init("lirc", 1) == -1)
		exit(EXIT_FAILURE);

	//Read the default LIRC config at /etc/lirc/lircd.conf  This is the config for your remote.
	if (lirc_readconfig(NULL, &config, NULL) == 0) {
		//Do stuff while LIRC socket is open  0=open  -1=closed.
		while (true) {
			run();
			//		while (lirc_nextcode(&code) == 0) {
			lirc_nextcode(&code);
			//If code = NULL, meaning nothing was returned from LIRC socket,
			//then skip lines below and start while loop again.
			if (code == NULL)
				continue;
			{
				//Make sure there is a 400ms gap before detecting button presses.
				if (millis() - buttonTimer > 400) {
					//Check to see if the string "KEY_1" appears anywhere within the string 'code'.
					if (strstr(code, "KEY_STOP")) {
						printf("MATCH on KEY_STOP\n");
						draw_text("ROBOT_2", 0, true);
						draw_text("terminated", 1, false);
						drive_backward(0);
						draw_text("ok", 2, false);
						exit(EXIT_SUCCESS);
					} else {
						buttonTimer = millis();
					}
				}
			}
			//Need to free up code before the next loop
			free(code);
//		}
		}
		//Frees the data structures associated with config.
		lirc_freeconfig(config);
	}
	//lirc_deinit() closes the connection to lircd and does some internal clean-up stuff.
	lirc_deinit();
	exit(EXIT_SUCCESS);
	return -1;
}

int get_speed(int minimal_distance) {
	int result = SPEED_1;
	if (minimal_distance >= MAX_WALL_DISTANCE_3) {
		result = SPEED_3;
	}
	if (minimal_distance >= MAX_WALL_DISTANCE_2
			&& minimal_distance < MAX_WALL_DISTANCE_3) {
		result = SPEED_2;
	}
	if (minimal_distance >= 0 && minimal_distance < MAX_WALL_DISTANCE_1) {
		result = SPEED_1;
	}
	cout << "current speed is " << result << endl;
	return result;
}

int is_running() {
	FILE *run_config;
	int is_run = 0;

	run_config = fopen("/home/pi/robot2/config/core", "r");
	if (run_config) {
		fscanf(run_config, "%d", &is_run);
		fclose(run_config);
	}
	return is_run;
}
