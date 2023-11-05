/*
 * Corners are one of the most essential features in an image. Corners are points in an image where the directions of
 * the intensity gradient changes abruptly. This means that the gradient vectors around a corner point have different
 * orientations. These regions are often distinctive and can be used as landmarks or reference points for various
 * computer vision tasks. Corners detection is very important for patch mapping, which is used to produce texture
 * maps for geometric models of real-world objects.
 * We'll use Harris corner detection to detect corners. This algorithm, created be Chris Harris and Mike Stephens,
 * works by taking the horizontal and vertical derivatives of image pixel values and looking for areas these values
 * are high. But first, we need to convert our image to grayscale. As mentioned previously, this helps in simplifying
 * algorithms and eliminates the complexity of the computational requirements of the Harris corner detection algorithm.
 *
 * Corner detection
 * For corner detection, we use the cornerHarris() function of the OpenCV library. The syntax of the code is:
 *	cv::cornerHarris(gray, output, blockSize, apertureSize, k)
 * The function five parameters:
 *	1. gray is the input image in which corners are to be detected. It should be a single channel 8-bit or floating-
 *	   point image.
 *	2. output is the output image that will contain the corner strength values for each pixel. The image should be a
 *	   single channel 32-bit floating-point image.
 *	3. blockSize - is the size of the neighborhood used for corner detection. It's typically set to a small odd value,
 *	   such as 3 or 5.
 *	4. apertureSize is the aperture parameter for the Sobel operator, which is used to calculate the gradient of the
 *	   image. It;s typically set to 3.
 *	5. k is the Harris corner detector free parameter, which is used to adjust the sensitivity of the detector.
 *	   Larger values will result in fewer corners being detected.
 * This function applies the Harris corner detection algorithm to the input image, and the resulting corner strength
 * values are stored in the output image. The higher the corner strength value, the more likely it is that the pixel
 * is a corner. The output of the Harris detector is not thresholded; it's just a 32-bit float matrix with the
 * corner strength at each pixel. After this, we use normalize and convertScaleAbs() to get a thresholded image.
 *
 * The normalize() function
 * After applying the cornerHarris() function, the normalize() function is applied to the corner strength image to
 * scale the corner strength value between 0 and 255. The syntax of the function is:
 *	cv::normalize(input, output_norm, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
 * It has seven arguments:
 *	1. input is the input image.
 *	2. output_nor is the output image.
 *	3. 0 is the lower bound og the output.
 *	4. 255 is the upper bound of the output.
 *	5 NORM_MINMAX is the normalization type.
 *	6. CV_32FC1 is the output image type.
 *	7. Mat() is the mask.
 * After applying the normalize() function, the convertScaleAbs() function is applied to the corner strength image to
 * get an 8-bit image containing the corners. The syntax of the function is:
 *	convertScaleAbs(output_norm, output_norm_scaled);
 * It has two arguments:
 *	1. output_norm is the input image.
 *	2. output_norm_scaled is the output image.
 * Now we've received a thresholded image that can be used to compare with certain maximum pixel intensity to figure
 * out the corner points.
 *
 * Pointing to corners
 * First, we use the nested for loop to iterate through each pixel in the image. Then we compare the pixel to a
 * certain value to find the corner.
 *
 * Note: The cornerHarris() function can be sensitive to noise and might produce false positive, so we recommend
 * using additional techniques to verify the detected corners, such non-maximum suppression.
*/
#include <string>
#include <opencv2/opencv.hpp>

int main()
{
	// Declaring necessary matrices
	cv::Mat image, gray;
	cv::Mat output, output_norm, output_norm_scaled;

	// Reading image
	image = cv::imread("../img/house.jpg");

	// Convert color to grayscale
	cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

	// Detecting corners
	cv::cornerHarris(gray, output, 6, 3, 0.1);

	// Normalize the values
	cv::normalize(output, output_norm, 0, 255, cv::NORM_MINMAX, CV_32FC1, cv::Mat());
	cv::convertScaleAbs(output_norm, output_norm_scaled);

	// Drawing a circle around corners
	for(int j{0}; j <output_norm.rows; ++j)
	{
		for(int i{0}; i < output.cols; ++i)
		{
			if (static_cast<int>(output_norm.at<float>(j, i)) > 100)
				cv::circle(image, cv::Point(i, j), 4, cv::Scalar(0, 0, 255), 2);
		}
	}

	// Display image
	std::string name{ "Output Harris" };
	cv::namedWindow(name, cv::WINDOW_NORMAL);
	cv::imshow(name, image);
	cv::waitKey(0);

	cv::destroyAllWindows();


	return 0;
}