#!/bin/bash
g++ sonar_test.cpp ../../sonar/sonar.cpp ../../display/display.cpp -o sonar_test -lwiringPi -lArduiPi_OLED ../../../lib/HC-SR04-Raspberry-Pi-C-/libSonar.cpp
