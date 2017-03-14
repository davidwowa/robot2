CC=g++
CFLAGS=-c -Wall
LIBFLAGS=-lwiringPi ../lib/HC-SR04-Raspberry-Pi-C-/libSonar.cpp -lpthread -lArduiPi_OLED

base: display.o wiring_pi.o drive.o sonar.o
drive: drive_backward drive_forward turn_left turn_right stop

drive_backward:
	$(CC) drive_backward.cpp wiring_pi.cpp drive.cpp -o drive_backward -lwiringPi

drive_forward:
	$(CC) drive_forward.cpp wiring_pi.cpp drive.cpp -o drive_forward -lwiringPi

turn_left:
	$(CC) turn_left.cpp wiring_pi.cpp drive.cpp -o turn_left -lwiringPi

turn_right:
	$(CC) turn_right.cpp wiring_pi.cpp drive.cpp -o turn_right -lwiringPi

stop:
	$(CC) stop.cpp wiring_pi.cpp drive.cpp -o stop -lwiringPi

display.o: display.cpp 
	$(CC) $(CFLAGS) display.cpp -lArduiPi_OLED

wiring_pi.o: wiring_pi.cpp
	$(CC) $(CFLAGS) wiring_pi.cpp -lwiringPi

drive.o: drive.cpp
	$(CC) $(CFLAGS) drive.cpp -lpthread -lwiringPi
	
sonar.o: sonar.cpp
	$(CC) $(CFLAGS) sonar.cpp ../lib/HC-SR04-Raspberry-Pi-C-/libSonar.cpp

clean:
	rm *.o