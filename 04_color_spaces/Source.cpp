/*
 * What is a color space?
 * A color space is a specific organization of colors. It's essentially a system of representing an array of
 * pixel colors. There are several color spaces, such as BGR, grayscale, HSV, Lab, and many more.
 */
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	// Converting from BGR to grayscale
	// OpenCV reads images in BGR format. To convert an image to grayscale, we have to use the cvtColor() method
	// of the OpenCV library. We need to give three parameters to this function: 1) Original image, 2) Mat object
	// that stores the converted images, 3) Color code, for example COLOR_BGR2GRAY changes the color space from
	// BGR to grayscale.
	cv::Mat img{ cv::imread("../img/chile.jpg") };
	// Resize image for display purpose
	cv::resize(img, img, cv::Size(), 0.7, 0.55);
	// Create Mat object to store grayscale img
	cv::Mat grayImg;

	// Convert from BGR to grayscale
	cv::cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);

	// Converting from BGR to HSV
	// To convert the image to HSV, we have to use the cvtColor() method again. In this case, we have to specify a different color
	// code. Here, the color code is COLOR_BGR2HSV.
	cv::Mat hsvImg;
	cv::cvtColor(img, hsvImg, cv::COLOR_BGR2HSV);

	// Converting from BGR to Lab
	// In this case our color code will be: COLOR_BGR2Lab
	cv::Mat labImg;
	cv::cvtColor(img, labImg, cv::COLOR_BGR2Lab);

	// Converting BGR to RGB
	// Outside of OpenCV, we use the RGB format. It's an inverse of the BGR format.
	cv::Mat rgbImg;
	cv::cvtColor(img, rgbImg, cv::COLOR_BGR2RGB);

	// Display images
	cv::imshow("Original Image", img);
	cv::imshow("Grayscale Image", grayImg);
	cv::imshow("HSV Image", hsvImg);
	cv::imshow("Lab Image", labImg);
	cv::imshow("RGB Image", rgbImg);
	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}