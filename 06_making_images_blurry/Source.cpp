/*
 * We might have used different features in our cameras or photo editing tools, such sa making the images blurry.
 * These features make our images more suitable for different contexts.
 *
 * Making an image blurry
 * We have to use the GaussianBlur() method to make an image blurry. We need to give four parameters to this
 * function:
 *	1. The original image.
 *	2. The blurred image.
 *	3. Kernel size.
 *	4. SigmaX.
 * cv::Size kernelSize = Size(7,7);
 * int sigmaX = 0;
 * cv::GaussianBlur(img, blurredImg, kernelSize, sigmaX);
 * In the code above, sigmaX represents the kernel's standard deviation in the x-direction.
 *
 * Kernel size
 * Here, the kernelSize is the size of the window where the blur is applied. It should be in odd numbers. This
 * will make the previous layer's pixels similar to the output pixel.If we use even numbers, we might suffer
 * from aliasing errors. Increasing the number will increase the blurriness of teh image
 */
#include <opencv2/opencv.hpp>

int main()
{
	// Read an image from disk
	cv::Mat img{ cv::imread("../img/chile.jpg") };

	// Resize for displaying purpose
	cv::resize(img, img, cv::Size(), 0.7, 0.55);

	// Blur the image
	cv::Mat blurredImg;
	cv::Size kernel{ cv::Size(7, 7) };
	int sigmaX = 0;
	cv::GaussianBlur(img, blurredImg, kernel, sigmaX);

	// Show images
	cv::imshow("Original Image", img);
	cv::imshow("Blurred Image", blurredImg);
	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}