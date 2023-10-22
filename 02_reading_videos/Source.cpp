#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	// Capture video
	// Now, we have to capture the video, and we use the VideoCapture capture(videoPath) method of the OpenCV
	// library. The videoPath stores the complete path of the video.
	std::string videoPath{ "../vid/driving_car.mp4" };
	// Here, we're going to read the individual frames of the video. First, we declare the variable for the
	// image. Then, we use the cap.read(img) function to read the image and store it in the img variable.
	cv::VideoCapture cap{ videoPath }; // Variable in which the video is stored.
	cv::Mat img; // Object of the Mat class. It's used for storing the individual frames of the video.

	while (true)
	{
		cap.read(img);

		// Check if we still have frames
		if(img.empty())
			break;

		// Displaying the frames continuously
		cv::imshow("Frame", img);
		int key{ cv::waitKey(20) };

		// Check if the user pressed the 'q' key.
		if(key == 'q')
			break;
	}

	cap.release();
	cv::destroyAllWindows();

	return 0;
}