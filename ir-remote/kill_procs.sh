#!/bin/bash
echo "kill all processes"
echo "kill core"
kill $(pidof core)
echo "kill drive_backward"
kill $(pidof drive_backward)
echo "kill drive_forward"
kill $(pidof drive_forward)
echo "kill drive_right"
kill $(pidof drive_right)
echo "kill drive_left"
kill $(pidof drive_left)
echo "kill drive_stop"
kill $(pidof drive_stop)
echo "kill test_motors"
kill $(pidof test_motors)
echo "kill reset_pins"
kill $(pidof reset_pins)

echo "reset_pins"
/home/pi/robot2/src/reset_pins
echo "stop driving"
/home/pi/robot2/src/drive_stop