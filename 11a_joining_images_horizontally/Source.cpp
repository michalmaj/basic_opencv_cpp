/*
 * While editing, we may want to join images to display more of the images at once, perhaps to make them more visually
 * appealing.
 *
 * Joining images horizontally
 * To join images horizontally, we use the hconcat() method of the OpenCV library.  The parameters of this function are
 * all the images we want to stack horizontally, and we have to add the variable of the image that it'll store the final
 * joined image.
 * hconcat(img1, img2, finalImg)
 * There are two different images, img1 and img2, they'll be joined horizontally and stored in the variable finalImg.
 * Note: All the images to be stacked should be the same size.
 */
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
	// Read original image and image in grayscale
	cv::Mat img1{ cv::imread("../img/manchester.jpg") };
	cv::Mat img2{ cv::imread("../img/manchester.jpg", cv::IMREAD_GRAYSCALE) };

	// Convert img2
	cv::cvtColor(img2, img2, cv::COLOR_GRAY2BGR);

	// Create Mat object to store horizontally concatenated images
	cv::Mat finalImg;

	// Join images horizontally
	cv::hconcat(img1, img2, finalImg);

	// Display final image
	std::string windowName{ "Final Image" };
	cv::namedWindow(windowName, cv::WINDOW_NORMAL);
	cv::imshow(windowName, finalImg);
	cv::waitKey(0);

	cv::destroyAllWindows();


	return 0;
}