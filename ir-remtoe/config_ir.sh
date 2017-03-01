#!/bin/bash
# but you can use the /boot/config.txt file and declare dtoverlay=lirc-rpi,gpio_in_pin=26
echo "kill lirc deamon"
kill $(pidof lircd)
echo "remove lirc modul"
modprobe -r lirc_rpi
echo "load lirc modul with another gpio"
modprobe lirc_rpi gpio_in_pin=26
#KEY_UP
#KEY_DOWN
#KEY_LEFT
#KEY_RIGHT
#KEY_PLAY
#KEY_STOP