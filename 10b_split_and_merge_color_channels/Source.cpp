/*
 * Merge color channels
 * To merge the color channels, we use the merge() method of the OpenCV library. This method requires two
 * parameters:
 *	1. An array of the image.
 *	2. The merged image.
 */
#include <opencv2/opencv.hpp>
#include <vector>

int main()
{
	// Read an image from disk
	cv::Mat img{ cv::imread("../img/chile.jpg") };

	// Set Mat object to store split image
	cv::Mat splitImg[3];

	// Set Mat object to store final image
	cv::Mat finalImg;

	// Splitting image
	cv::split(img, splitImg);

	// Merging image
	std::vector<cv::Mat> colorArray{ splitImg[0], splitImg[1], splitImg[2] };
	cv::merge(colorArray, finalImg);

	// Displaying the image
	cv::merge(colorArray, finalImg);
	cv::imshow("final", finalImg);
	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}