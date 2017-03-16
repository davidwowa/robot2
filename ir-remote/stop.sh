#!/bin/bash
echo "stop"
sudo echo "0" > /home/pi/robot2/src/config/run
sudo /home/pi/robot2/src/test_units/drive/stop