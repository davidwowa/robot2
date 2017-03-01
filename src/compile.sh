#!/bin/bash
echo "compile core"
g++ core.cpp -o core -lwiringPi ../lib/HC-SR04-Raspberry-Pi-C-/libSonar.cpp
echo "compile commons"
g++ reset_pins.cpp -o reset_pins -lwiringPi
echo "compile photoresistor"
g++ photoresistor.cpp -o photoresistor -lwiringPi
echo "compile motor test"
g++ test_motors.cpp -o test_motors -lwiringPi -lpthread
echo "compile motor tes2t"
g++ test_motors_2.cpp -o test_motors_2 -lwiringPi -lpthread

echo "compile motor test backward"
g++ drive_backward.cpp -o drive_backward -lwiringPi
echo "compile motor test forward"
g++ drive_forward.cpp -o drive_forward -lwiringPi
echo "compile motor test left"
g++ drive_left.cpp -o drive_left -lwiringPi
echo "compile motor test right"
g++ drive_right.cpp -o drive_right -lwiringPi
echo "compile motor test stop"
g++ drive_stop.cpp -o drive_stop -lwiringPi