#!/bin/bash
sudo rm -r robot2
git clone https://bitbucket.org/wowa_/robot2
chmod +x /home/pi/robot2/deploy.sh
cd /home/pi/robot2
/home/pi/robot2/deploy.sh