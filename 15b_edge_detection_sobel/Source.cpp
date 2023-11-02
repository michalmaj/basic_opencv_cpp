/*
 * Sobel edge detection
 * For Sobel edge detection, we use the Sobel() function of the OpenCV library. The algorithm of Sobel edge detection
 * is based on the fact that at the edges, there's a drastic change in the pixel intensity. We can use the first
 * derivative to observe this change. A higher change in the gradient suggest a major change in the image. The
 * algorithm decides those points are edges. It also uses Gaussian smoothing for noise reduction.
 * The Sobel() function requires five parameters, which are listed below:
 *	1. The first parameter is the input image.
 *	2. The second parameter is the output image.
 *	3. The third parameter is the data depth. For this, we use CV_64F, which means we'll use 64-bit floating-point.
 *	4. The fourth parameter is the gradient's value in the x-direction.
 *	5. The fifth parameter is the gradient's value in the y-direction.
 */
#include <opencv2/opencv.hpp>

int main()
{
	// Load image from disk
	cv::Mat img{ cv::imread("../img/chile.jpg") };

	// Resize the image in sake of display
	cv::resize(img, img, cv::Size(), 0.5, 0.5);

	// Convert image into grayscale
	cv::Mat grayImg;
	cv::cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);

	// Use Sobel edge detection
	int kernelSize{ 3 }; // kernel must be odd number
	cv::Mat sobelx, sobely, sobelxy;
	cv::Sobel(grayImg, sobelx, CV_64F, 1, 0, kernelSize);
	cv::Sobel(grayImg, sobely, CV_64F, 0, 1, kernelSize);
	cv::Sobel(grayImg, sobelxy, CV_64F, 1, 1, kernelSize);

	// Display images
	cv::imshow("Original Image", img);
	cv::imshow("Gray Image", grayImg);
	cv::imshow("SobelX", sobelx);
	cv::imshow("SobelY", sobely);
	cv::imshow("SobelXY", sobelxy);
	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}