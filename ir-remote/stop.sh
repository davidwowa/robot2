#!/bin/bash
echo "stop"
if true ; then
	sudo cat << EOF > /home/pi/robot2/config/core
0
EOF
fi
#sudo echo "0" > /home/pi/robot2/config/core
sudo /home/pi/robot2/src/test_units/drive/stop
