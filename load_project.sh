#!/bin/bash
sudo rm -r robot2
git clone https://bitbucket.org/wowa_/robot2
chmod +x robot2/deploy.sh
robot2/deploy.sh