#!/bin/bash
# sudo apt-get install lirc liblircclient-dev
g++ ir-client.cpp -o ir-client -lwiringPi -llirc_client