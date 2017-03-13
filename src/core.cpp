//============================================================================
// Name        : core.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

#include "gpio.h"
#include "analytics.h"
#include "wiring_pi.h"
#include "display.h"
#include "sonar.h"
#include "drive.h"
#include "common.h"

void display_data(int direction, int speed, int m, int r, int l, int b);
void init(void);

using namespace std;

Sonar sonar_m;
Sonar sonar_r;
Sonar sonar_l;
Sonar sonar_b;

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

int get_minimal_distance(int m, int r, int l) {
	int result = m;
	if (r < result) {
		result = r;
	}
	if (l < result) {
		result = l;
	}
	if (DEBUG == 1) {
		cout << "minimal distance is " << result << endl;
	}
	return result;
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
	if (DEBUG == 1) {
		cout << "current speed is " << result << endl;
	}
	return result;
}

int main(void) {
	init();

	if (DEBUG == 1) {
		cout << "allone drive" << endl;
	}

	int current_pointer = FORWARD;
	while (1) {

		int distance_m = sonar_m.distance(30000);
		int distance_r = sonar_r.distance(30000);
		int distance_l = sonar_l.distance(30000);
		int distance_b = sonar_b.distance(30000);

		if (DEBUG == 1) {
			cout << "Distance on middle sensor is " << distance_m << " cm."
					<< endl;
			cout << "Distance on right  sensor is " << distance_r << " cm."
					<< endl;
			cout << "Distance on left   sensor is " << distance_l << " cm."
					<< endl;
			cout << "Distance on back   sensor is " << distance_b << " cm."
					<< endl;
			cout << "---" << endl;
		}
		// set speed depend from minimal distance to wall or object what see sonar
		int current_minmal_distance = get_minimal_distance(distance_m,
				distance_r, distance_l);
		int current_speed = get_speed(current_minmal_distance);

		display_data(current_pointer, current_speed, distance_m, distance_r,
				distance_l, distance_b);

		if (FORWARD == current_pointer) {
			if (distance_m < MAX_WALL_DISTANCE_1) {
				if (distance_m < MAX_WALL_DISTANCE_1
						&& distance_l < MAX_WALL_DISTANCE_1
						&& distance_r < MAX_WALL_DISTANCE_1) {
					drive_backward(current_speed);
					current_pointer = BACKWARD;
				} else if (distance_l > distance_r) {
					turn_left(current_speed);
					current_pointer = TURN_LEFT;
				} else {
					turn_right(current_speed);
					current_pointer = TURN_RIGHT;
				}
			} else {
				drive_forward(current_speed);
				current_pointer = FORWARD;
			}
		}

		if (BACKWARD == current_pointer) {
			int backward_speed = get_speed(distance_b);
			if (distance_b < MAX_WALL_DISTANCE_1
					|| distance_b < MAX_WALL_DISTANCE_2
					|| distance_b < MAX_WALL_DISTANCE_3) {
				if (distance_l > distance_r) {
					turn_left(current_speed);
					current_pointer = TURN_LEFT;
				} else {
					turn_right(current_speed);
					current_pointer = TURN_RIGHT;
				}
			} else {
				drive_backward(backward_speed);
				current_pointer = BACKWARD;
			}
		}

		if (TURN_LEFT == current_pointer) {
			if (distance_l < MAX_WALL_DISTANCE_1
					&& distance_r < MAX_WALL_DISTANCE_1) {
				turn_left(current_speed);
				current_pointer = TURN_LEFT;
			} else {
				drive_forward(current_speed);
				current_pointer = FORWARD;
			}
		}

		if (TURN_RIGHT == current_pointer) {
			if (distance_r < MAX_WALL_DISTANCE_1
					&& distance_l < MAX_WALL_DISTANCE_1) {
				turn_right(current_speed);
				current_pointer = TURN_RIGHT;
			} else {
				drive_forward(current_speed);
				current_pointer = FORWARD;
			}
		}

		delay(INTERVAL);
	}
	return -1;
}

void init(void) {
	if (DEBUG == 1) {
		cout << "init wiring pi" << endl;
	}

	if (wiringPiSetup() == -1) {
		if (DEBUG == 1) {
			cout << "error on wiring pi setup" << endl;
		}
	} else {
		if (DEBUG == 1) {
			cout << "wiring pi setup OK" << endl;
		}
	}

	if (!display.init(OLED_I2C_RESET, opts.oled))
		exit(EXIT_FAILURE);

	display.begin();
	// init done
	display.clearDisplay();   // clears the screen  buffer
	display.display();   	// display it (clear display)

	if (DEBUG == 1) {
		cout << "start sonars" << endl;
	}

	sonar_m.init(TRIGGER_M, ECHO_M);

	sonar_r.init(TRIGGER_R, ECHO_R);

	sonar_l.init(TRIGGER_L, ECHO_L);

	sonar_b.init(TRIGGER_B, ECHO_B);

	if (DEBUG == 1) {
		cout << "drive inital forward" << endl;
	}

	if (DEBUG == 1) {
		cout << "prepare pwm gpio for motors" << endl;
	}
	// prepare GPIOs for motors
	softPwmCreate(MOTOR_L_U, PWM_MIN, PWM_MAX);
	softPwmCreate(MOTOR_L_V, PWM_MIN, PWM_MAX);

	softPwmCreate(MOTOR_R_U, PWM_MIN, PWM_MAX);
	softPwmCreate(MOTOR_R_V, PWM_MIN, PWM_MAX);
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

	FILE *temperatureFile;
	double T = 0.0;

	temperatureFile = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
	if (temperatureFile) {
		fscanf(temperatureFile, "%lf", &T);
		fclose(temperatureFile);
	}
	T = T / 1000.0;
	display.setCursor(30, 53);
	display.printf("CPU:%.0fC", T);

	struct statvfs buf;
	double usage = 0.0;

	if (!statvfs("/etc/rc.local", &buf)) {
		unsigned long hd_used;
		hd_used = buf.f_blocks - buf.f_bfree;
		usage = ((double) hd_used) / ((double) buf.f_blocks) * 100;
	}

	display.setCursor(86, 53);
	display.printf("HD:%.0f%%", round(usage));

	display.display();
}

void drive_forward(void) {
	if (DEBUG == 1) {
		cout << "forward" << endl;
	}
	softPwmWrite(MOTOR_R_U, PWM_MAX);
	softPwmWrite(MOTOR_R_V, PWM_MIN);

	softPwmWrite(MOTOR_L_U, PWM_MIN);
	softPwmWrite(MOTOR_L_V, PWM_MAX);
}
void drive_backward(void) {
	if (DEBUG == 1) {
		cout << "backward" << endl;
	}
	softPwmWrite(MOTOR_R_U, PWM_MIN);
	softPwmWrite(MOTOR_R_V, PWM_MAX);

	softPwmWrite(MOTOR_L_U, PWM_MAX);
	softPwmWrite(MOTOR_L_V, PWM_MIN);
}
void turn_left(void) {
	if (DEBUG == 1) {
		cout << "left" << endl;
	}
	softPwmWrite(MOTOR_R_U, PWM_MIN);
	softPwmWrite(MOTOR_R_V, PWM_MAX);

	softPwmWrite(MOTOR_L_U, PWM_MIN);
	softPwmWrite(MOTOR_L_V, PWM_MAX);
}
void turn_right(void) {
	if (DEBUG == 1) {
		cout << "right" << endl;
	}
	softPwmWrite(MOTOR_R_U, PWM_MAX);
	softPwmWrite(MOTOR_R_V, PWM_MIN);

	softPwmWrite(MOTOR_L_U, PWM_MAX);
	softPwmWrite(MOTOR_L_V, PWM_MIN);
}
void stop(void) {
	if (DEBUG == 1) {
		cout << "stop" << endl;
	}
	softPwmWrite(MOTOR_R_U, PWM_MIN);
	softPwmWrite(MOTOR_R_V, PWM_MIN);

	softPwmWrite(MOTOR_L_U, PWM_MIN);
	softPwmWrite(MOTOR_L_V, PWM_MIN);
}

void drive_forward(int pwm) {
	if (DEBUG == 1) {
		cout << "forward pwm " << pwm << endl;
	}
	softPwmWrite(MOTOR_R_U, pwm);
	softPwmWrite(MOTOR_R_V, PWM_MIN);

	softPwmWrite(MOTOR_L_U, PWM_MIN);
	softPwmWrite(MOTOR_L_V, pwm);
}
void drive_backward(int pwm) {
	if (DEBUG == 1) {
		cout << "backward pwm " << pwm << endl;
	}
	softPwmWrite(MOTOR_R_U, PWM_MIN);
	softPwmWrite(MOTOR_R_V, pwm);

	softPwmWrite(MOTOR_L_U, pwm);
	softPwmWrite(MOTOR_L_V, PWM_MIN);
}
void turn_left(int pwm) {
	if (DEBUG == 1) {
		cout << "left pwm " << pwm << endl;
	}
	softPwmWrite(MOTOR_R_U, PWM_MIN);
	softPwmWrite(MOTOR_R_V, pwm);

	softPwmWrite(MOTOR_L_U, PWM_MIN);
	softPwmWrite(MOTOR_L_V, pwm);
}
void turn_right(int pwm) {
	if (DEBUG == 1) {
		cout << "right pwm " << pwm << endl;
	}
	softPwmWrite(MOTOR_R_U, pwm);
	softPwmWrite(MOTOR_R_V, PWM_MIN);

	softPwmWrite(MOTOR_L_U, pwm);
	softPwmWrite(MOTOR_L_V, PWM_MIN);
}
