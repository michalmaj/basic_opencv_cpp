/*
 * Warp perspective
 * Sometimes we want only a portion of an image. For example, while scanning a document, we might need to get
 * only a par of the document.
 *
 * Getting the dimension of the image
 * To get the pixel points of the image's corners, we can use any image-editor tool, like MS Paint. When we move
 * the cursor to the corner, we'll get the pixel points. Through MS Paint we get four points of the image:
 * float w = 400, h = 550;
 * cv::Point2f pointA[4] = { {869, 649},{1893, 1077}, {73, 2149},{1125, 2673}};
 * cv::Point2f pointB[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };
 * Note: We'll assign the values of four points of the required portion to four different points to create the
 * image.
 *
 * Creating a warp perspective matrix
 * To create a warp perspective matrix, we have to use the getPerspectiveTransform() method of the OpenCV
 * library:
 * matrix = getPerspectiveTransform(pointA, pointB);
 *
 * Warping the image
 * To warp the image, we'll use the warpPerspective() function of the OpenCV library. We need to pass four
 * parameters to the function:
 *	1. The original image.
 *	2. The warped image.
 *	3. The warp perspective matrix.
 *	4. The dimensions of the image.
 * cv::warpPerspective(img, warpedImage, matrix, Point(w, h));
 */
#include <vector>
#include <opencv2/opencv.hpp>

int main()
{
	// Create placeholders
	cv::Mat matrix;
	cv::Mat warpedImage;

	// Reading the image from disk
	cv::Mat img{ cv::imread("../img/note.jpg") };

	float w{ 400 };
	float h{ 550 };

	// Normal way wo initialize Point2f that contains points
	//cv::Point2f pointA[4] = { {837, 537},{1925, 1077}, {13, 2109},{1133, 2689} };
	//cv::Point2f pointB[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	// Version with std::vector
	std::vector<cv::Point2f> pointA{ {837, 537},{1925, 1077}, {13, 2109},{1133, 2689} };
	std::vector<cv::Point2f> pointB{ {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };
	matrix = cv::getPerspectiveTransform(pointA, pointB);

	cv::warpPerspective(img, warpedImage, matrix, cv::Point(w, h));

	// Display images
	cv::imshow("Image", img);
	cv::imshow("Image Warp", warpedImage);
	cv::waitKey(0);

	cv::destroyAllWindows();
}