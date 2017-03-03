//============================================================================
// Name        : core.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>

#include "../lib/wiringPi/wiringPi/wiringPi.h"
#include "../lib/wiringPi/wiringPi/softPwm.h"
#include "../lib/HC-SR04-Raspberry-Pi-C-/libSonar.h"

#include "gpio.h"
#include "analytics.h"
#include "drive.h"
#include "common.h"

using namespace std;

Sonar sonar_m;
Sonar sonar_r;
Sonar sonar_l;

int get_minimal_distance(int m, int r, int l) {
	int result = m;
	if (r < result) {
		result = r;
	}
	if (l < result) {
		result = l;
	}
	if (debug == 1) {
		cout << "minimal distance is " << result << endl;
	}
	return result;
}

int get_speed(int minimal_distance) {
	int result = speed_1;
	if (minimal_distance >= maxWallDisntance_3) {
		result = speed_3;
	}
	if (minimal_distance >= maxWallDisntance_2
			&& minimal_distance < maxWallDisntance_3) {
		result = speed_2;
	}
	if (minimal_distance >= 0 && minimal_distance < maxWallDisntance_1) {
		result = speed_1;
	}
	if (debug == 1) {
		cout << "current speed is " << result << endl;
	}
	return result;
}

int main(void) {
	init();

	if (debug == 1) {
		cout << "allone drive" << endl;
	}
	while (1) {

		int distance_m = sonar_m.distance(30000);
		int distance_r = sonar_r.distance(30000);
		int distance_l = sonar_l.distance(30000);

		if (debug == 1) {
			cout << "Distance on middle sensor is " << distance_m << " cm."
					<< endl;
			cout << "Distance on right  sensor is " << distance_r << " cm."
					<< endl;
			cout << "Distance on left   sensor is " << distance_l << " cm."
					<< endl;
			cout << "---" << endl;
		}
		// set speed depend from minimal distance to wall or object what see sonar
		int current_minmal_distance = get_minimal_distance(distance_m,
				distance_r, distance_l);
		int current_speed = get_speed(current_minmal_distance);

		if (distance_l >= maxWallDisntance_3) {
			drive_forward(current_speed);
		} else if (distance_l >= maxWallDisntance_2
				&& distance_l < maxWallDisntance_3) {
			drive_forward(current_speed);
		} else if (distance_l >= 0 && distance_l < maxWallDisntance_1) {
			drive_right(current_speed);
		} else {
			drive_forward(current_speed);
		}

		delay(interval);

		if (distance_m >= maxWallDisntance_3) {
			drive_forward(current_speed);
		} else if (distance_m >= maxWallDisntance_2
				&& distance_m < maxWallDisntance_3) {
			drive_forward(current_speed);
		} else if (distance_m >= 0 && distance_m < maxWallDisntance_1) {

			int randomBit = rand() & 1;

			if (debug == 1) {
				cout << "decision bit (0 = right) " << randomBit << endl;
			}

			if (randomBit == 0) {
				drive_right(current_speed);
			} else {
				drive_left(current_speed);
			}

		} else {
			drive_forward(current_speed);
		}

		delay(interval);

		if (distance_r >= maxWallDisntance_3) {
			drive_forward(current_speed);
		} else if (distance_r >= maxWallDisntance_2
				&& distance_r < maxWallDisntance_3) {
			drive_forward(current_speed);
		} else if (distance_r >= 0 && distance_r < maxWallDisntance_1) {
			drive_left(current_speed);
		} else {
			drive_forward(current_speed);
		}

		delay(interval);
	}
	return -1;
}

void init(void) {
	if (debug == 1) {
		cout << "init wiring pi" << endl;
	}

	if (wiringPiSetup() == -1) {
		cout << "error on wiring pi setup" << endl;
	} else {
		cout << "wiring pi setup OK" << endl;
	}

	if (debug == 1) {
		cout << "start sonars" << endl;
	}

	sonar_m.init(trigger_m, echo_m);

	sonar_r.init(trigger_r, echo_r);

	sonar_l.init(trigger_l, echo_l);

	if (debug == 1) {
		cout << "drive inital forward" << endl;
	}

	if (debug == 1) {
		cout << "prepare pwm gpio for motors" << endl;
	}
	// prepare GPIOs for motors
	softPwmCreate(motor_l_u, pwmValueInit, pwmValue);
	softPwmCreate(motor_l_v, pwmValueInit, pwmValue);

	softPwmCreate(motor_r_u, pwmValueInit, pwmValue);
	softPwmCreate(motor_r_v, pwmValueInit, pwmValue);
}

void drive_forward(void) {
	if (debug == 1) {
		cout << "forward" << endl;
	}
	softPwmWrite(motor_r_u, pwmValue);
	softPwmWrite(motor_r_v, pwmValueInit);

	softPwmWrite(motor_l_u, pwmValueInit);
	softPwmWrite(motor_l_v, pwmValue);
}
void drive_backward(void) {
	if (debug == 1) {
		cout << "backward" << endl;
	}
	softPwmWrite(motor_r_u, pwmValueInit);
	softPwmWrite(motor_r_v, pwmValue);

	softPwmWrite(motor_l_u, pwmValue);
	softPwmWrite(motor_l_v, pwmValueInit);
}
void drive_left(void) {
	if (debug == 1) {
		cout << "left" << endl;
	}
	softPwmWrite(motor_r_u, pwmValueInit);
	softPwmWrite(motor_r_v, pwmValue);

	softPwmWrite(motor_l_u, pwmValueInit);
	softPwmWrite(motor_l_v, pwmValue);
}
void drive_right(void) {
	if (debug == 1) {
		cout << "right" << endl;
	}
	softPwmWrite(motor_r_u, pwmValue);
	softPwmWrite(motor_r_v, pwmValueInit);

	softPwmWrite(motor_l_u, pwmValue);
	softPwmWrite(motor_l_v, pwmValueInit);
}
void stop(void) {
	if (debug == 1) {
		cout << "stop" << endl;
	}
	softPwmWrite(motor_r_u, pwmValueInit);
	softPwmWrite(motor_r_v, pwmValueInit);

	softPwmWrite(motor_l_u, pwmValueInit);
	softPwmWrite(motor_l_v, pwmValueInit);
}

void drive_forward(int pwm) {
	if (debug == 1) {
		cout << "forward pwm " << pwm << endl;
	}
	softPwmWrite(motor_r_u, pwm);
	softPwmWrite(motor_r_v, pwmValueInit);

	softPwmWrite(motor_l_u, pwmValueInit);
	softPwmWrite(motor_l_v, pwm);
}
void drive_backward(int pwm) {
	if (debug == 1) {
		cout << "backward pwm " << pwm << endl;
	}
	softPwmWrite(motor_r_u, pwmValueInit);
	softPwmWrite(motor_r_v, pwm);

	softPwmWrite(motor_l_u, pwm);
	softPwmWrite(motor_l_v, pwmValueInit);
}
void drive_left(int pwm) {
	if (debug == 1) {
		cout << "left pwm " << pwm << endl;
	}
	softPwmWrite(motor_r_u, pwmValueInit);
	softPwmWrite(motor_r_v, pwm);

	softPwmWrite(motor_l_u, pwmValueInit);
	softPwmWrite(motor_l_v, pwm);
}
void drive_right(int pwm) {
	if (debug == 1) {
		cout << "right pwm " << pwm << endl;
	}
	softPwmWrite(motor_r_u, pwm);
	softPwmWrite(motor_r_v, pwmValueInit);

	softPwmWrite(motor_l_u, pwm);
	softPwmWrite(motor_l_v, pwmValueInit);
}
