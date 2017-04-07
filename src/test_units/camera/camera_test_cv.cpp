/*
 * camera_test_cv.cpp
 *
 *  Created on: 06.04.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include <ctime>
#include <unistd.h>
#include <iostream>
#include <raspicam/raspicam_cv.h>

#include "../../display/display.h"

using namespace std;

int main(int argc, char **argv) {

	init_display();

	draw_text("take pic cv...", 0, true);

	time_t timer_begin, timer_end;
	raspicam::RaspiCam_Cv Camera;
	cv::Mat image;
	int nCount = 100;
	//set camera params
	Camera.set(CV_CAP_PROP_FORMAT, CV_8UC1);
	//Open camera
	draw_text("open cam", 1, false);
	cout << "Opening Camera..." << endl;
	if (!Camera.open()) {
		cerr << "Error opening the camera" << endl;
		draw_text("ERROR", 2, true);
		draw_text("cam not open", 3, true);
		return -1;
	}
	//Start capture
	draw_text("start capture", 2, false);
	cout << "Capturing " << nCount << " frames ...." << endl;
	time(&timer_begin);
	for (int i = 0; i < nCount; i++) {
		Camera.grab();
		Camera.retrieve(image);
		if (i % 5 == 0)
			cout << "\r captured " << i << " images" << std::flush;
	}
	draw_text("stop cam", 3, false);
	cout << "Stop camera..." << endl;
	Camera.release();
	//show time statistics
	time(&timer_end); /* get current time; same as: timer = time(NULL)  */
	double secondsElapsed = difftime(timer_end, timer_begin);
	cout << secondsElapsed << " seconds for " << nCount << "  frames : FPS = "
			<< (float) ((float) (nCount) / secondsElapsed) << endl;
	//save image
	draw_text("save image", 4, false);
	cv::imwrite("raspicam_cv_image.jpg", image);
	cout << "Image saved at raspicam_cv_image.jpg" << endl;
}
