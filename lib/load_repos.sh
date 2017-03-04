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
#sudo apt-get install build-essential
#sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
git clone https://github.com/opencv/opencv.git
echo "get raspicam library for opencv"
git clone https://github.com/cedricve/raspicam
#cd raspicam
#mkdir build
#cd build
#cmake ..