#include <opencv2/opencv.hpp>

int main()
{
	// Capture from web-cam. Zero represents the default camera being used to capture the video. 
	cv::VideoCapture cap(0);
	cv::Mat frame;
	
	while(true)
	{
		// Get frame from video stream.
		cap.read(frame);

		// Display frames.
		cv::imshow("Frame", frame);

		// Use waitKey(1) so that we can display the frames continuously and get a smooth display. 
		int key{ cv::waitKey(1) };
		if(key == 'q')
			break;
	}

	cap.release();
	cv::destroyAllWindows();
	return 0;
}