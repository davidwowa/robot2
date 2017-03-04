#!/bin/bash
echo "kill core"
sudo kill $(pidof core)
echo "start core"
/home/pi/robot2/src/core