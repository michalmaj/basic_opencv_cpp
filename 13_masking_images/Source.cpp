/*
 * Masking is another essential tool used to edit images in OpenCV. Masking is an image editing technique used to
 * highlight a specific part of an image. It's used to combine different images, as as highlight the required portion
 * in the combined images. We can use bitwise operators to mask images.
 * To start off, we create a blank image using the Mat::zeros() function of the OpenCV library. We'll create the
 * mask in a blank image and later use ot to mask image.
 * Note: While masking, the size of the mask image should be the same as the image being masked. We need to read an
 * image as img before creating the blank image.
 *
 * Apply the mask to the image
 * To apply a mask to the image, we use the bitwise_and() function of the OpenCV library. This function requires
 * three parameters:
 *	1. The first parameter is the crescent-shaped mask we created.
 *	2. The second parameter consists of the image on which we'll apply the AND bitwise operation.
 *	3. The third parameter is the output image after applying the mask.
 */
#include <opencv2/opencv.hpp>

int main()
{
	// Read the image from disk
	cv::Mat img{ cv::imread("../img/manchester.jpg") };
	cv::imshow("Image", img);

	// Creating two blank images
	cv::Mat circleA{ cv::Mat::zeros(img.size(), img.type()) };
	cv::Mat rectangleA{ cv::Mat::zeros(img.size(), img.type()) };

	// Draw rectangle and circle on blank images
	cv::rectangle(rectangleA, cv::Point(30, 30), cv::Point(200, 400), cv::Scalar(255, 255, 255), -1);
	cv::circle(circleA, cv::Point(250, 166), 100, cv::Scalar(255, 255, 255), -1);

	// Show shapes
	cv::imshow("Rectangle", rectangleA);
	cv::imshow("Circle", circleA);

	// Using bitwise operator 'AND'
	cv::Mat crescent_shape;
	cv::bitwise_and(rectangleA, circleA, crescent_shape);
	cv::imshow("Bitwise AND", crescent_shape);

	// Masking the image
	cv::Mat maskedImg;
	cv::bitwise_and(crescent_shape, img, maskedImg);
	cv::imshow("Masked Image", maskedImg);

	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}