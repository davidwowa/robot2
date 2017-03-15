#!/bin/bash
echo "compile core"
/home/pi/robot2/src/core/compile.sh

echo "compile display test"
/home/pi/robot2/src/core/test/display/compile.sh

echo "compile sonar test"
/home/pi/robot2/src/core/test/sonar/compile.sh

echo "compile drive test"
/home/pi/robot2/src/core/test/drive/compile.sh

echo "ready"