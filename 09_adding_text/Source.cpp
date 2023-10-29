/*
 * Let's suppose we want to add the name of a company to a large number of images. We can use the OpenCV library to
 * easily do that.
 *
 * Adding text to an image
 * To add text, we'll use the putText() function of the OpenCV library. We have seen parameters inside this
 * function:
 *	1. text - it the text that we want to display on the image.
 *	2. startingPoint - is the starting pixel point of the text.
 *	3. font - is the font type that we're using to display text.
 *	4. fontSize - is the font size.
 *	5. color - is the color of the text.
 *	6. thickness = is the thickness of the text.
 */
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
	// Read image from disk
	cv::Mat img{ cv::imread("../img/chile.jpg") };

	// Set string to display
	std::string text{ "Greetings" };

	// Set starting point
	cv::Point2f startingPoint{ cv::Point(0, 100) };

	// Set font size
	int fontSize{ 3 };

	// Set color of text
	cv::Scalar blackColor{ cv::Scalar(0, 0, 0) };

	// Set thickness
	int thickness{ 3 };

	// Put text on the image
	cv::putText(img, text, startingPoint, cv::FONT_HERSHEY_COMPLEX, fontSize, blackColor, thickness);

	// Display image
	std::string windowName{ "Image" };
	cv::namedWindow(windowName, cv::WINDOW_NORMAL);
	cv::imshow(windowName, img);
	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}