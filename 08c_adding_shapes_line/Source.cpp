/*
 * Drawing a line
 * To draw a line, we'll use the line() function of the OpenCV library. We have four parameter inside this
 * function:
 *	1. startPoint is the starting point of the line. In this case, it's the top left corner of the image.
 *	2. endPoint is the end point of the line. In this example, it's the bottom right corner of the  image.
 *	3. color is a color of the line.
 *	4. thickness is the thickness of the line.
 */
#include <string>
#include <valarray>
#include <opencv2/opencv.hpp>

int main()
{
	// Read image from disk
	cv::Mat img{ cv::imread("../img/chile.jpg") };

	// Set starting point
	cv::Point2f startPoint{ cv::Point(0, 0) };

	// Set ending point
	cv::Point2f endPoit{ cv::Point(img.cols, img.rows) };

	// Set color
	cv::Scalar whiteColor{ cv::Scalar(255, 255, 255) };

	// Set thickness
	int lineThickness{ 2 };

	// Draw the line
	cv::line(img, startPoint, endPoit, whiteColor, lineThickness, cv::LINE_AA);

	// Display image
	std::string windowName{ "Image" };
	cv::namedWindow(windowName, cv::WINDOW_NORMAL);

	cv::imshow(windowName, img);
	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}