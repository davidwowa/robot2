#!/bin/bash
echo "load sonar library"
git clone https://github.com/omaflak/HC-SR04-Raspberry-Pi-C-.git
echo "load wiringPi library"
git clone git://git.drogon.net/wiringPi
echo "install wiringPi"
# only first time
#cd wiringPi
#git pull origin
#cd wiringPi
#./build