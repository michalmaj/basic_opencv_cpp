/*
 * Instead of just stacking images we might also want to combine images. We'll use bitwise operators to combine
 * images in OpenCV. We'll work with black and white images to better understand these operators.
 *
 * What are bitwise operators?
 * There are four basic bitwise operators - AND, OR, XOR, and NOT. These operators are frequently used to edit images,
 * especially while working with masking images.
 *
 * To see them in action, we'll first create a blank image. We'll use that blank image to draw different shapes and
 * learn how bitwise operators can be used with them.
 *
 * To create a blank image, we use the Mat::zeros() function of the OpenCV library:
 * cv::Mat circleA = cv::Mat::zeros(cv::Size(600), CV_8UC3);
 *
 * This function requires two parameters:
 *	1. The size of the blank image.
 *	2. CV_8UC3, which is an unsigned integer of 8 bits with three channels.
 * We can identify this second parameter using the identifier in the form:
 * CV_<bit-depth>{U|S|F}C(<number-of-channels>)
 * Here, U is the unsigned integer type, S is the signed integer type, and F is the float type.
 *
 * In the code below, we draw a rectangle and a circle on the blank image. We'll use these two shapes to understand
 * all the bitwise operators.
 *	cv::rectangle(rectangleA, cv::Point(30, 30), cv::Point(570, 570), cv::Scalar(255, 255, 255), -1);
 *		- Point(30, 30) is the top left corner point of where we want to draw the rectangle.
 *		- Point(570, 570) is the bottom right corner point of where we want to draw the rectangle.
 *		- Scalar(255, 255, 255) adds the white color to the rectangle.
 *		- -1 is the thickness of the rectangle. It'll fill the rectangle with the respective color.
 *	cv::circle(circleA, cv::Point(300, 300), 300, cv::Scalar(255, 255, 255), -1);
 *		- Point(300, 300) - is the center point around which the circle will be drawn.
 *		- 300 is the radius of the circle.
 *		- Scalar(255, 255, 255) adds white color in the circle.
 *		- - 1 is the thickness of the circle. It'll fill the rectangle with the respective color.
 */
#include <opencv2/opencv.hpp>

int main()
{
	// Creating two empty black images
	cv::Mat circleA{ cv::Mat::zeros(cv::Size(600, 600), CV_8UC3) };
	cv::Mat rectangleA{ cv::Mat::zeros(cv::Size(600, 600), CV_8UC3) };

	// Create Mat object to store output image
	cv::Mat outputImg;

	// Draw rectangle and circle on prepared canvas
	cv::rectangle(rectangleA, cv::Point(30, 30), cv::Point(570, 570), cv::Scalar(255, 255, 255), -1);
	cv::circle(circleA, cv::Point(300, 300), 300, cv::Scalar(255, 255, 255), -1);

	// Draw images
	cv::imshow("Rectangle", rectangleA);
	cv::imshow("Circle", circleA);
	
	// The AND operator
	// To use the AND bitwise operator, we need the bitwise_and() function of the OpenCV library. This function
	// requires three parameters: img1, img2, finalImg. The AND operator return the intersecting regions of the
	// two images.
	cv::bitwise_and(rectangleA, circleA, outputImg);
	cv::imshow("Bitwise AND", outputImg);

	// The OR operator
	// To use the OR bitwise operator, we need the bitwise_or() function of the OpenCV library. This function requires
	// three parameters: imgA, imgB, outputImg. The OR operator returns the intersecting regions as well as the
	// non-intersecting regions of both images.
	cv::bitwise_or(rectangleA, circleA, outputImg);
	cv::imshow("Bitwise OR", outputImg);

	// The XOR operator
	// To use the XOR bitwise operator, we need the bitwise_xor() function of the OpenCV library. This function
	// requires three parameters: imgA, imgB, outputImg. The XOR operator returns the non-intersecting regions of the
	// two images.
	cv::bitwise_xor(rectangleA, circleA, outputImg);
	cv::imshow("Bitwise XOR", outputImg);

	// The NOT operator
	// To use the NOT bitwise operator, we need the bitwise_not() function of the OpenCV library. This function
	// requires two parameters: img, outputImg. The NOT operator returns the region that aren't part of the white
	// pixels of the image. In our case, it inverts the black and white pixels regions. It shows white pixels in the
	// regions in the region outside the circle and black pixels in the circle area.
	cv::bitwise_not(circleA, outputImg);
	cv::imshow("Bitwise NOT", outputImg);


	cv::waitKey(0);

	cv::destroyAllWindows();


	return 0;
}