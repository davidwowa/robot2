/*
 * sonar.h
 *
 *  Created on: 11.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#ifndef SONAR_H_
#define SONAR_H_

#include "../lib/HC-SR04-Raspberry-Pi-C-/libSonar.h"

extern void init_sonar(void);
extern int get_distance_m();
extern int get_distance_r();
extern int get_distance_l();
extern int get_distance_b();

extern void init_sonar(void);
extern int get_minimal_distance(int m, int r, int l);

using namespace std;

#endif /* SONAR_H_ */
