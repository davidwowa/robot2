#!/bin/bash
g++ test_motors.cpp ../../drive/drive.cpp ../../display/display.cpp -o test_motors -lwiringPi -lpthread -lArduiPi_OLED
g++ test_motors_2.cpp ../../drive/drive.cpp ../../display/display.cpp -o test_motors_2 -lwiringPi -lpthread -lArduiPi_OLED
g++ drive_backward.cpp ../../drive/drive.cpp ../../display/display.cpp -o drive_backward -lwiringPi -lpthread -lArduiPi_OLED
g++ drive_forward.cpp ../../drive/drive.cpp ../../display/display.cpp -o drive_forward -lwiringPi -lpthread -lArduiPi_OLED
g++ turn_left.cpp ../../drive/drive.cpp ../../display/display.cpp -o turn_left -lwiringPi -lpthread -lArduiPi_OLED
g++ turn_right.cpp ../../drive/drive.cpp ../../display/display.cpp -o turn_right -lwiringPi -lpthread -lArduiPi_OLED
g++ stop.cpp ../../drive/drive.cpp ../../display/display.cpp -o stop -lwiringPi -lpthread -lArduiPi_OLED