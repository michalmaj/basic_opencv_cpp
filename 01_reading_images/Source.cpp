#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat img{ cv::imread("../img/Mount_Everest.jpg") };

	cv::imshow("Image", img);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}