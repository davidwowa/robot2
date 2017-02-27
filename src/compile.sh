#!/bin/bash
echo "compile core"
g++ core.cpp -o core -lwiringPi ../lib/HC-SR04-Raspberry-Pi-C-/libSonar.cpp
echo "compile commons"
g++ reset_pins.cpp -o reset_pins -lwiringPi
echo "compile photoresistor"
g++ photoresistor.cpp -o photoresistor -lwiringPi
echo "compile motor test"
g++ test_motors.cpp -o test_motors -lwiringPi