#!/bin/bash
echo "stop"
sudo cat > /home/pi/robot2/config/core << EOF 0 EOF
#sudo echo "0" > /home/pi/robot2/config/core
sudo /home/pi/robot2/src/test_units/drive/stop