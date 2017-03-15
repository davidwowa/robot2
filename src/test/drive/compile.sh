#!/bin/bash
g++ test_motors.cpp ../../drive/drive.cpp -o test_motors -lwiringPi -lpthread
g++ test_motors_2.cpp ../../drive/drive.cpp -o test_motors_2 -lwiringPi -lpthread
