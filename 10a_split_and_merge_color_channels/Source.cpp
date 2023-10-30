/*
 * Color channels are the main component of a color image. Learning to separate these color channels will help
 * us to understand different color intensities in the image and allows us to create monochrome images.
 *
 * What are color channels?
 * A color image consist of three color channels - blue, green, and red. We merge these three color channels to
 * create color images. OpenCV allows us to split an image into its respective color channels. Additionally, it
 * allows us to merge the color channels to from a color image.
 *
 * Split color channels
 * To split color channels, we use the split() method of the OpenCV library.
 */
#include <opencv2/opencv.hpp>

int main()
{
	// Lod image from disk
	cv::Mat img{ cv::imread("../img/chile.jpg") };

	// Create Mat object to store split image
	cv::Mat splitImg[3]; // We need three channels

	// Split image
	cv::split(img, splitImg);

	// Resize split channels
	cv::Mat resizedBlue, resizedGreen, resizedRed;
	cv::resize(splitImg[0], resizedBlue, cv::Size(), 0.5, 0.5);
	cv::resize(splitImg[1], resizedGreen, cv::Size(), 0.5, 0.5);
	cv::resize(splitImg[2], resizedRed, cv::Size(), 0.5, 0.5);

	// Display the channels
	cv::imshow("Blue", resizedBlue);
	cv::imshow("Green", resizedGreen);
	cv::imshow("Red", resizedRed);
	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}