/*
 * What if we want to put a certain shape, such as a rectangle, around a specific portion of an image to draw the
 * viewer's attention? It'll take a very long time to add those borders to a large number of images. But there is
 * a better idea: we'll use OpenCV to draw the required shapes on those images.
 *
 * Drawing a circle
 * To draw a circle, we'll use the circle() function of the OpenCV library. We'll have five parameters inside
 * this function:
 *	1. center - is the center point of the circle around which the circle will be drawn.
 *	2. radius - is the radius of the circle.
 *	3. color - is the color of the circle. It's specified as a cv::Scalar object, which can represent color
 *	   in various color spaces
 *	4. thickness - is the thickness of the circle. We can use of -1 to fill the circle with the same color.
 */
#include <opencv2/opencv.hpp>
#include <string>

int main()
{
	// Reading image from disk
	cv::Mat img{ cv::imread("../img/chile.jpg") };

	// Set center of the center
	cv::Point2f center{ cv::Point(410, 170) };

	// Set radius of the circle
	int radius{ 100 };

	// Set color of the circle (in this case our color will be red)
	cv::Scalar redColor{ cv::Scalar(0, 0, 255) };

	// Set thickness of the boundary
	int circleThiskness{ 5 };

	// Draw the circle on the image
	cv::circle(img, center, radius, redColor, circleThiskness);

	// For display purpose, we can use cv::WINDOW_NORMAL in namedWindow, now we can resize like typical window
	std::string windowName{ "Image" };
	cv::namedWindow(windowName, cv::WINDOW_NORMAL);

	// Show image
	cv::imshow(windowName, img);
	cv::waitKey(0);

	cv::destroyAllWindows();


	return 0;
}