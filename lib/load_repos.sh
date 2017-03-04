#!/bin/bash
echo "load sonar library"
git clone https://github.com/omaflak/HC-SR04-Raspberry-Pi-C-.git
echo "load wiringPi library"
git clone git://git.drogon.net/wiringPi
#echo "install wiringPi"
# only first time
#cd wiringPi
#git pull origin
#cd wiringPi
#./build
#cd ../..
echo "load open cv library"
git clone https://github.com/opencv/opencv.git
echo "get raspicam library for opencv"
git clone https://github.com/cedricve/raspicam
#cd raspicam
#mkdir build
#cd build
#cmake ..