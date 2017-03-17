#!/bin/bash
echo "kill core"
sudo kill $(pidof core)
echo "start core"
sudo cat > /home/pi/robot2/config/core << EOF 1 EOF
#sudo echo "1" > /home/pi/robot2/config/core
sudo /home/pi/robot2/src/core/core