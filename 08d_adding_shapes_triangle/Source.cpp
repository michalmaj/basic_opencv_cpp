/*
 * Drawing triangle
 * To draw a triangle in OpenCV we need to use a polylines function.This function is also used to draw one or
 * more polygons on an image. cv::polylines has seven parameters:
 *	1. img - this is the input/output image where the polygons will be drawn.
 *	2. pts - this is an input array of polygonal curves. It can be a single curve represented as a cv::Point or
 *	   multiple curves represented as a vector of vectors of cv::Point. Each cv::Point represents a vertex of
 *	   the polygon.
 *	3. is Closed - a boolean parameter that indicates whether the drawn shape is closed (true) or open (false).
 *	   If set to true, the last point in each curve is connected to the first point, forming a closed shape.
 *	4. color - the color of the polygon.
 *	5. thickness - the thickness of the polygon edges. If we set to -1 the polygon will be filled.
 *	6. lineType - it represents the connectivity of the points.
 *	7. shift is number of fractional bits in the point coordinates. The default value is 0, indicating integer
 *	   pixels coordinates.
 */
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

int main()
{
	// Load the image from disk
	cv::Mat img{ cv::imread("../img/chile.jpg") };

	// Define the vertices for the triangle
	std::vector<cv::Point> pts{ {250, 50}, {50, 450}, {450, 450} };

	// Set color
	cv::Scalar color{ cv::Scalar(255, 0, 255) };

	// Set thickness
	int thickness{ 3 };

	// Draw the triangle
	cv::polylines(img, pts, true, color, thickness, cv::LINE_AA);

	// Show the image
	std::string windowName{ "Image" };
	cv::namedWindow(windowName, cv::WINDOW_NORMAL);

	cv::imshow(windowName, img);
	cv::waitKey(0);

	cv::destroyAllWindows();


	return 0;
}