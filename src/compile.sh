#!/bin/bash
echo "compile core old"
g++ core_old.cpp -o core_old -lwiringPi ../lib/HC-SR04-Raspberry-Pi-C-/libSonar.cpp

echo "compile core 2"
g++ core.cpp -o core -lwiringPi ../lib/HC-SR04-Raspberry-Pi-C-/libSonar.cpp -lArduiPi_OLED

echo "compile commons"
g++ reset_pins.cpp -o reset_pins -lwiringPi
echo "compile motor test"
g++ test_motors.cpp -o test_motors -lwiringPi -lpthread
echo "compile motor test 2"
g++ test_motors_2.cpp -o test_motors_2 -lwiringPi -lpthread

echo "compile motor test backward"
g++ drive_backward.cpp -o drive_backward -lwiringPi
echo "compile motor test forward"
g++ drive_forward.cpp -o drive_forward -lwiringPi
echo "compile motor test left"
g++ turn_left.cpp -o turn_left -lwiringPi
echo "compile motor test right"
g++ turn_right.cpp -o turn_right -lwiringPi
echo "compile motor test stop"
g++ stop.cpp -o stop -lwiringPi

#echo "compile playMP3"
#gcc -O2 -o playMP3 playMP3.c -lmpg123 -lao

echo "compile test display"
g++ display.cpp -o display -lArduiPi_OLED

echo "compile test display"
g++ display_test.cpp -o display_test -lArduiPi_OLED

echo "compile ip adress modul"
g++ ip_address.cpp -o ip_address

echo "ready"