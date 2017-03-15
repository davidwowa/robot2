#!/bin/bash
g++ display_test.cpp -o display_test -lArduiPi_OLED
g++ display_test_2.cpp ../../display/display.cpp -o display_test_2 -lArduiPi_OLED
