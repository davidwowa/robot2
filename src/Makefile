CC=g++
CFLAGS=-c -Wall
LIBFLAGS=-lwiringPi ../lib/HC-SR04-Raspberry-Pi-C-/libSonar.cpp -lpthread -lArduiPi_OLED

wiring_pi.o: wiring_pi.cpp
	$(CC) $(CFLAGS) wiring_pi.cpp -lwiringPi

display.o: display.cpp 
	$(CC) $(CFLAGS) display.cpp -lArduiPi_OLED

drive.o: drive.cpp
	$(CC) $(CFLAGS) drive.cpp -lpthread -lwiringPi
	
sonar.o: sonar.cpp
	$(CC) $(CFLAGS) sonar.cpp ../lib/HC-SR04-Raspberry-Pi-C-/libSonar.cpp

clean:
	rm *.o