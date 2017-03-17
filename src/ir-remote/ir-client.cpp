/*
 * ir-client.cpp
 *
 *  Created on: 17.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include "../../lib/WiringPi/wiringPi/wiringPi.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lirc/lirc_client.h>
#include <time.h>

int main() {
	struct lirc_config *config;

	//Timer for our buttons
	int buttonTimer = millis();

	char *code;
	char *c;

	//Initiate WiringPi and set WiringPi pins 4, 5 & 6 (GPIO 23, 24 & 25) to output. These are the pins the LEDs are connected to.
	if (wiringPiSetup() == -1)
		exit(1);

	//Initiate LIRC. Exit on failure
	if (lirc_init("lirc", 1) == -1)
		exit(EXIT_FAILURE);

	//Read the default LIRC config at /etc/lirc/lircd.conf  This is the config for your remote.
	if (lirc_readconfig(NULL, &config, NULL) == 0) {
		//Do stuff while LIRC socket is open  0=open  -1=closed.
		while (lirc_nextcode(&code) == 0) {
			//If code = NULL, meaning nothing was returned from LIRC socket,
			//then skip lines below and start while loop again.
			if (code == NULL)
				continue;
			{
				//Make sure there is a 400ms gap before detecting button presses.
				if (millis() - buttonTimer > 400) {
					//Check to see if the string "KEY_1" appears anywhere within the string 'code'.
					if (strstr(code, "KEY_2")) {
						printf("MATCH on KEY_2\n");
						buttonTimer = millis();
					} else if (strstr(code, "KEY_3")) {
						printf("MATCH on KEY_3\n");
						buttonTimer = millis();
					} else if (strstr(code, "KEY_4")) {
						printf("MATCH on KEY_4\n");
						buttonTimer = millis();
					}
				}
			}
			//Need to free up code before the next loop
			free(code);
		}
		//Frees the data structures associated with config.
		lirc_freeconfig(config);
	}
	//lirc_deinit() closes the connection to lircd and does some internal clean-up stuff.
	lirc_deinit();
	exit(EXIT_SUCCESS);
}
