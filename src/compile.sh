#!/bin/bash
echo "compile core"
cd /home/pi/robot2/src/core/
./compile.sh

echo "compile display test"
cd /home/pi/robot2/src/core/test/display/
./compile.sh

echo "compile sonar test"
cd /home/pi/robot2/src/core/test/sonar/
./compile.sh

echo "compile drive test"
cd /home/pi/robot2/src/core/test/drive/
./compile.sh

echo "ready"