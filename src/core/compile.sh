#!/bin/bash
g++ core.cpp ../display/display.cpp ../drive/drive.cpp ../sonar/sonar.cpp -o core -lwiringPi -lpthread -lArduiPi_OLED ../../lib/HC-SR04-Raspberry-Pi-C-/libSonar.cpp -llirc_client
