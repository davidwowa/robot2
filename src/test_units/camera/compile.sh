#!/bin/bash
g++ camera_test.cpp -o camera_test -I/usr/local/include ../../../raspicam/src/raspicam.cpp -lmmal -lmmal_core -lmmal_util
# -lraspicam