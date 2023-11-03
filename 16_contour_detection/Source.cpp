/*
 * Detect contours will help us find different types of shapes in our image. This can be used for motion detection,
 * object detection, and background removal, among other things.
 *
 * First, we need to convert our image to grayscale. This is really important because it help us correctly find the
 * edges. It also helps in simplifying algorithms and eliminates the complexity of the computational requirements. We
 * use the edge detection algorithm to detect edges and the retrieval algorithm  to detect shapes:
 *	cv::cvtColor(img, srcGray, COLOR_BGR2GRAY);
 * To convert an image to a Canny image, we use the Canny() function of the OpenCV library. This function requires
 * four parameters:
 *	1. The first parameter is the input image.
 *	2. The second parameter is the output image.
 *	3. The third parameter is the maximum value of the intensity gradient.
 *	4. The fourth parameter is the maximum value of the intensity gradient.
 * This function converts the image to black and white, highlighting the edges of the contours. It makes the work of the
 * contour retrieval algorithm easier.
 *	cv::Canny(srcGray, cannyImg, 50, 50);
 *
 * Detect shapes
 * To detect shapes, we use the findContours() function of the OpenCV library. This function requires five parameters:
 *	1. The first parameter is the Canny image.'
 *	2. The second parameter is the variable contours, which will store shapes detected. We use this value to draw on
 *	   those shapes later on.
 *	3. The third is the variable hierarchy that stores the hierarchy of the shapes detected.
 *	4. The fourth parameter is the mode to find contours. We use RETR_EXTERNAL to find the external contours. It's one
 *	   of the modes of the contour retrieval algorithm and is used ro retrieve only outer contours.
 *	5. The fifth parameter is the contour approximation method. For this, we use CHAIN_APPROX_NONE. It stores all the
 *	   contours found by our retrieval algorithm.
 *	std::vector<std::vector<cv::Point>> contours;
 *	std::vector<cv::Vec4i> hierarchy;
 *	cv::findContours(cannyImg, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
 * We've initialized the variable, such as contours and hierarchy, that we're going to use. We've initialized contours
 * as an array of Point, a point is 2D space. We've also initialized hierarchy as an array of Vec4i, a vector with four
 * dimensions. Then we'll use the findContour() function.
 *
 * Draw contours
 * To draw the contours, we use the drawContours()  function of the OpenCV library. The syntax of this function is:
 *	cv::drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
 * We need to give five parameters to the function:
 *	1. img is the image on which we want to draw contours.
 *	2. contours are the contours that we detected using the findContours() function.
 *	3. -1 is the contour index. It's the number of contours we want to draw. For example, if we only want to draw
 *	   the third contour, we give the value 2. In this example, we enter the value -1 because we want to draw all the
 *	   contours.
 *	4. The fourth parameter is the scalar value of the color to be given while drawing.
 *	5. The fifth parameter is the thickness of the drawing. 
 */
#include <vector>
#include <opencv2/opencv.hpp>

int main()
{
	// Load image from disk
	cv::Mat img{ cv::imread("../img/redbloodcells.jpg") };

	// Convert image to grayscale
	cv::Mat grayImg;
	cv::cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);

	// Canny edge detection
	cv::Mat canny;
	cv::Canny(grayImg, canny, 50, 50);

	// show Canny image
	cv::imshow("Canny Image", canny);

	// Create vector for contours
	std::vector<std::vector<cv::Point>> contours;

	// Create vector for contours hierarchy
	std::vector<cv::Vec4i> hierarchy;

	// Find contours
	cv::findContours(canny, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	// Draw contour on the original image
	cv::drawContours(img, contours, -1, cv::Scalar(255, 0, 255), 2);

	// Show image with contours
	cv::imshow("Contoured Image", img);
	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}