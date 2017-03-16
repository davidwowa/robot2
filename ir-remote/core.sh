#!/bin/bash
echo "kill core"
sudo kill $(pidof core)
echo "start core"
sudo echo "1" > /home/pi/robot2/src/config/run
sudo /home/pi/robot2/src/core/core