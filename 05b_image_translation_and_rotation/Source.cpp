/*
 * Making a point of rotation
 * In order to rotate an image, we need to create a matrix for the rotation. If we want to rotate an image by an
 * angle of x, then rotation matrix would be:
 * | cosx -sinx |
 * | sinx  cosx |
 * OpenCV can be used to create a matrix defining the center of rotation and the scale factor.
 * Before we rotate an image, we need to define the point through which we want to rotate ir. The point of
 * rotation will determine the rotation of different areas inside the image. That point can be anywhere on the
 * image. For now, we'll keep the image's center as the point of rotation. To get the center of the image, we'll
 * get its width and height and divide them by two:
 *	cv::Point2f center((image.cols) / 2.0, (image.rows) / 2.0);
 * Here, we're getting the width using the image.cols function and the height using image.rows.
 *
 * Creating a rotation matrix
 * We can use the getRotationMatrix2D() function to create a rotation matrix. We'll use the following code to
 * create a rotation matrix:
 *  angle = 60
 *	scale = 0.5
 *	cv::Point2f center((image.cols) / 2.0, (image.rows) / 2.0)
 *	cv::Mat rotationMatrix = getRotationMatrix2D(center, angle, scale)
 * Here, we already have center, which is the center of rotation. The angle is the rotation angle is degrees at
 * which the image will rotate. The scale is a decimal value by which the image's size increases or decreases.
 *
 * Rotating the image
 * Now, rotate the image also, we'll use the warpAffine() function of the OpenCV library. We'll need four
 * parameters inside the function:
 *	1. Original image.
 *	2. Rotated image.
 *	3. Rotation matrix.
 *	4. Dimensions of the image.
 */
#include <opencv2/opencv.hpp>

int main()
{
	// Read image from disk
	cv::Mat img{ cv::imread("../img/chile.jpg") };

	// Resize for display purpose
	cv::resize(img, img, cv::Size(), 0.7, 0.55);

	// Create rotation matrix
	float angle = 60;
	float scale = 0.5f;
	cv::Point2f center{ (img.cols) / 2.0f, (img.rows) / 2.0f };
	cv::Mat rotationMatrix{ cv::getRotationMatrix2D(center, angle, scale) };

	// Rotating the image
	cv::Mat rotatedImage;
	cv::warpAffine(img, rotatedImage, rotationMatrix, img.size());

	// Display
	cv::imshow("Original Image", img);
	cv::imshow("Rotated Image", rotatedImage);
	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}