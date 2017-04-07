#!/bin/bash
g++ camera_test.cpp -o camera_test -I/usr/local/include -L/opt/vc/lib -lraspicam -lmmal -lmmal_core -lmmal_util ../../display/display.cpp -lwiringPi -lpthread -lArduiPi_OLED
g++ camera_test_cv.cpp -o camera_test_cv -I/usr/local/include/ -L/opt/vc/lib -lraspicam -lraspicam_cv -lmmal -lmmal_core -lmmal_util -lopencv_core -lopencv_highgui -lopencv_imgcodecs ../../display/display.cpp -lArduiPi_OLED
