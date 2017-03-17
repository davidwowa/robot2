#!/bin/bash
echo "compile core"
cd /home/pi/robot2/src/core/
./compile.sh

echo "compile display test"
cd /home/pi/robot2/src/core/test-units/display/
./compile.sh

echo "compile sonar test"
cd /home/pi/robot2/src/core/test-units/sonar/
./compile.sh

echo "compile drive test"
cd /home/pi/robot2/src/core/test-units/drive/
./compile.sh

echo "compile file io test"
cd /home/pi/robot2/src/core/test-units/io/
./compile.sh

echo "ready"