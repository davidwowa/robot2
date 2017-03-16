#!/bin/bash
echo "load sonar library"
git clone https://github.com/davidwowa/HC-SR04-Raspberry-Pi-C-.git

echo "load wiringPi library"
git clone https://github.com/davidwowa/WiringPi.git
#echo "install wiringPi"
# only first time
#cd wiringPi
#git pull origin
#cd wiringPi
#./build
#cd ../..

#echo "load open cv library"
#sudo apt-get install build-essential
#sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
#git clone https://github.com/opencv/opencv.git

#echo "get raspicam library for opencv"
#git clone https://github.com/cedricve/raspicam
#cd raspicam
#mkdir build
#cd build
#cmake ..
#cd ../..

#echo "load libao for play wav and so on"
#git clone https://github.com/timonwong/libao.git

#echo "load libmpg for play mp3"
#git clone https://github.com/gypified/libmpg123.git

echo "load display library"
git clone https://github.com/davidwowa/ArduiPi_OLED.git
#echo "install display library"
#cd ArduiPi_OLED
#sudo make