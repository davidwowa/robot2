#!/bin/bash
echo "compile core"
cd /home/pi/robot2/src/core/
./compile.sh

echo "compile display test"
cd /home/pi/robot2/src/core/test_units/display/
./compile.sh

echo "compile sonar test"
cd /home/pi/robot2/src/core/test_units/sonar/
./compile.sh

echo "compile drive test"
cd /home/pi/robot2/src/core/test_units/drive/
./compile.sh

echo "compile file io test"
cd /home/pi/robot2/src/test_units/io/
./compile.sh

echo "compile ip address test"
cd /home/pi/robot2/src/test_units/net/
./compile.sh

echo "ready"