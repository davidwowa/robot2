#!/bin/bash
echo "kill all processes"
echo "kill core"
sudo kill $(pidof core)
echo "kill drive_backward"
sudo kill $(pidof drive_backward)
echo "kill drive_forward"
sudo kill $(pidof drive_forward)
echo "kill drive_right"
sudo kill $(pidof drive_right)
echo "kill drive_left"
sudo kill $(pidof drive_left)
echo "kill drive_stop"
sudo kill $(pidof drive_stop)
echo "kill test_motors"
sudo kill $(pidof test_motors)
echo "kill reset_pins"
sudo kill $(pidof reset_pins)

echo "reset_pins"
/home/pi/robot2/src/reset_pins
echo "stop driving"
/home/pi/robot2/src/drive_stop