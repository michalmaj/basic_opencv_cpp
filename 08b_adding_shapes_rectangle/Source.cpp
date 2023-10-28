/*
 * Drawing a rectangle
 * To draw a rectangle, we'll use the rectangle function of the OpenCV library. We have five parameters inside
 * this function:
 *	1. img - is the original image.
 *	2. leftTopCorner - is the top left corner point of where we want to draw the rectangle on the image.
 *	3. right Bottom Corner - is the bottom right corner point of where we want to draw the rectangle on the image.
 *	4. color - is the color of rectangle.
 *	5. thickness - is the thickness of the rectangle. We can use a -1 to fill the circle with the same color.
 */
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
	// Read an image from disk
	cv::Mat img{ cv::imread("../img/chile.jpg") };

	// Set left top corner and bottom right corner
	cv::Point2f leftTopCorner{ cv::Point(200, 100) };
	cv::Point2f bottomRightCorner{ cv::Point(450, 300) };

	// Set color of our rectangle (yellow in this case)
	cv::Scalar yellowColor{ cv::Scalar(0, 255, 255) };

	// Set thickness of the rectangle
	int rectangleThickness{ 2 };

	cv::rectangle(img, leftTopCorner, bottomRightCorner, yellowColor, rectangleThickness);

	// Drawing image
	std::string windowName{ "Image" };
	cv::namedWindow(windowName, cv::WINDOW_NORMAL);

	cv::imshow(windowName, img);
	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}