/*
 * One of the most frequent uses of OpenCV is the detection of shapes, edges faces, and various other components in
 * images.
 * Detecting edges helps us solve many practical problems. It helps us detect shapes, documents, and various other
 * components of the image. It can be used for fingerprint recognition, medical imaging, and also vehicle detection.
 * Here, we'll discuss two different methods of detecting edges:
 *	- Canny edge detection.
 *	- Sobel edge detection.
 * First, we need to convert our image to grayscale. Converting the image is really important because we use the edge
 * detection algorithm to detect edges, and grayscale images help the algorithm find the edges property. It helps in
 * simplifying algorithms and eliminates the complexity of the computational requirements.
 *
 * Canny edge detection
 * For Canny edge detection, we use the Canny() function of the OpenCV library. This function requires four
 * parameters:
 *	1. The first parameter is the input image.
 *	2. The second parameter is the output image.
 *	3. The third is the minimum value of the intensity gradient. The edges with an intensity gradient lower than the
 *	   minimum value are not considered edges. So, increasing the minimum value reduces the number of edges.
 *	4. The fourth parameter is the maximum value of intensity gradient. The edges with an intensity gradient more
 *	   than the maximum value are considered edges.
 * The values that lie between these two thresholds are classified as edges or non-edges based on their connectivity.
 * The Canny edge detection algorithm goes through four main stages:
 *	1. First, it uses Gaussian blur to reduce noise.
 *	2. The, it finds the intensity gradient of the image.
 *	3. It goes through non-maximum suppression where the image is scanned, and it removes the unwanted pixels.
 *	4. The final step is hysteresis thresholding. Here, the algorithm decides whether the edges detected are edges,
 *	   based on the minimum and maximum values of the intensities provided as parameters.
 */
#include <opencv2/opencv.hpp>
#include <string>

int main()
{
	// Read image from disk
	cv::Mat img{ cv::imread("../img/chile.jpg") };

	// Resize img for display purpose
	cv::resize(img, img, cv::Size(), 0.5, 0.5);

	// Convert to grayscale
	cv::Mat src_gray;
	cv::cvtColor(img, src_gray, cv::COLOR_BGR2GRAY);

	// Canny edge detection
	cv::Mat canny_img;
	cv::Canny(src_gray, canny_img, 150, 150);

	// Show images
	cv::imshow("Original Image", img);
	cv::imshow("Gray Image", src_gray);
	cv::imshow("Canny Image", canny_img);
	cv::waitKey(0);

	cv::destroyAllWindows();
	

	return 0;
}