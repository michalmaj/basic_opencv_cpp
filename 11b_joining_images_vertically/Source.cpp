/*
 * Join images vertically
 * To join images vertically, we use the vconcat() method of the OpenCV library. The parameters of this function are
 * the images we want to stack vertically. At the end of the list, we have to introduce the variable of the image
 * that will store the final joined image.
 * cv::vconcat(img1, img2, finalImg)
 * Note: All images to be stacked should be the same size.
 */
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
	// Load images from disk (in color and in grayscale)
	cv::Mat img1{ cv::imread("../img/manchester.jpg") };
	cv::Mat img2{ cv::imread("../img/manchester.jpg", cv::IMREAD_GRAYSCALE) };

	// Convert grayscale to 3D
	cv::cvtColor(img2, img2, cv::COLOR_GRAY2BGR);

	// Create Mat object to store vertically stacked images
	cv::Mat finalImg;

	// Join image vertically
	cv::vconcat(img1, img2, finalImg);

	// Show the image
	std::string windowName{ "Final Image" };
	cv::namedWindow(windowName, cv::WINDOW_NORMAL);
	cv::imshow(windowName, finalImg);
	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}