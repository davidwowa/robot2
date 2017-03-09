/*
 * display.h
 *
 *  Created on: 09.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

void init_display(void);

void display_common_data(void);
void display_drive_data(int direction, int speed, int m, int r, int l, int b);
void display_manual_drive_data();

double get_cpu_usage_data(void);
double get_hdd_usage_data(void);
char* get_ip_address(void);

#endif /* DISPLAY_H_ */
