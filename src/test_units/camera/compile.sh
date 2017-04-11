#!/bin/bash
g++ camera_test.cpp -o camera_test -I/usr/local/include -L/opt/vc/lib -lraspicam -lmmal -lmmal_core -lmmal_util ../../display/display.cpp -lwiringPi -lpthread -lArduiPi_OLED
g++ camera_test_cv.cpp -o camera_test_cv -I/usr/local/include/ -L/opt/vc/lib -lraspicam -lraspicam_cv -lmmal -lmmal_core -lmmal_util -lopencv_core -lopencv_highgui -lopencv_imgcodecs ../../display/display.cpp -lArduiPi_OLED
g++ opencv_face.cpp -o opencv_face -I/usr/local/include/ -L/opt/vc/lib -lraspicam -lraspicam_cv -lmmal -lmmal_core -lmmal_util -lopencv_core -lopencv_highgui -lopencv_imgcodecs ../../display/display.cpp -lArduiPi_OLED

# after compiling to use camera with opencv 
# copy 
# /home/pi/robot2/lib/raspicam/build/src/libraspicam_cv.so
# /home/pi/robot2/lib/opencv/build/lib/libopencv_core.so.3.2
# /usr/local/lib/libopencv_highgui.so.3.2
# /usr/local/lib/libopencv_imgcodecs.so.3.2
# in to 
# /usr/lib/