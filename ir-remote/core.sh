#!/bin/bash
echo "kill core"
sudo kill $(pidof core)
echo "start core"
sudo /home/pi/robot2/src/core