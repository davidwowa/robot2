#!/bin/bash
g++ test_motors.cpp ../../drive/drive.cpp -o test_motors -lwiringPi -lpthread
g++ test_motors_2.cpp ../../drive/drive.cpp -o test_motors_2 -lwiringPi -lpthread
g++ drive_backward.cpp ../../drive/drive.cpp -o drive_backward -lwiringPi -lpthread
g++ drive_forward.cpp ../../drive/drive.cpp -o drive_forward -lwiringPi -lpthread
g++ turn_left.cpp ../../drive/drive.cpp -o turn_left -lwiringPi -lpthread
g++ turn_right.cpp ../../drive/drive.cpp -o turn_right -lwiringPi -lpthread
g++ stop.cpp ../../drive/drive.cpp -o stop -lwiringPi -lpthread