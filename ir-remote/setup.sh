#!/bin/bash
echo "run ir setup"
chmod +x *.sh
echo "copy lircrc file"
sudo lircrc /etc/lirc
echo "end lirc setup"
# irexec /etc/lirc/lircrc