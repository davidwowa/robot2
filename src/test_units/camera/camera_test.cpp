/*
 * camera.cpp
 *
 *  Created on: 06.04.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include <stdio.h>
#include <string.h>

#include <ctime>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <raspicam/raspicam.h>

#include "../../display/display.h"

using namespace std;

int main(int argc, char **argv) {

	system("sudo kill $(pidof omxplayer)");
	system("omxplayer /home/pi/robot2/sounds/belch-kevan.mp3 &");

	init_display();

	draw_text("take pic...", 0, true);

	raspicam::RaspiCam Camera; //Cmaera object

	draw_text("open cam", 1, false);
	//Open camera
	cout << "Opening Camera..." << endl;
	if (!Camera.open()) {
		draw_text("ERROR", 2, true);
		draw_text("cam not open", 3, true);
		cerr << "Error opening camera" << endl;
		return -1;
	}

	draw_text("sleep(3)", 2, false);
	//wait a while until camera stabilizes
	cout << "Sleeping for 3 secs" << endl;
	sleep(3);
	draw_text("capture", 3, false);
	//capture
	Camera.grab();
	//allocate memory
	unsigned char *data = new unsigned char[Camera.getImageTypeSize(
			raspicam::RASPICAM_FORMAT_RGB)];
	//extract the image in rgb format
	Camera.retrieve(data, raspicam::RASPICAM_FORMAT_RGB);	//get camera image
	//save
	draw_text("save image", 4, false);
	std::ofstream outFile("raspicam_image.ppm", std::ios::binary);
	outFile << "P6\n" << Camera.getWidth() << " " << Camera.getHeight()
			<< " 255\n";
	outFile.write((char*) data,
			Camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB));
	cout << "Image saved at raspicam_image.ppm" << endl;
	//free resrources
	delete data;
	draw_text("ok", 5, false);
	return 0;
}
