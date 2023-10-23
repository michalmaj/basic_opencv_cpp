/*
 * Uses of resizing and cropping
 * Sometimes, we have to crop or resize our images. We might want to crop an image to make it more appealing.
 * Or, we might want to meet the image size and dimensions criteria for an online form we have to fill out.
 * Normally, we use editing software to edit images, However, if we have a large number of pictures to crop or
 * resize, it can be very difficult to edit them all. The solution is to use OpenCV to edit all those pictures
 * instantly. This can be very useful in photo studios, passport offices, and other governmental offices.
 *
 * Steps to follow
 * We'll adopt the following steps to resize and crop images:
 *	1. Define the header files and namespaces.
 *	2. Declare variables for the original image, img, cropped image, croppedImg, and resized image, resizedImg.
 *	3. Read the image and store it in img.
 */
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	// Reading image
	std::string imagePath{ "../img/chile.jpg" };
	cv::Mat img{ cv::imread(imagePath) };

	// Create placeholders for resized and cropped image
	cv::Mat resizedImg, croppedImg;

	// The image variable contains different values ranging from 0 to 255. Those values are the pixels intensities
	// of the image in different regions. Each channel has a size of 8 bits (2^8 = 256).
	std::cout << "Small patch from big image:\n";
	std::cout << img(cv::Rect(0, 0, 3, 3)); // print just small patch from image (3x3)
	std::cout << std::endl << std::endl;

	// Dimensions of the image
	// Before resizing an image, we need to understand how to get the dimension of an image. Dimensions are the
	// length and width of an image. We can simply use the function img.size() to get these dimensions.
	std::cout << "The dimensions of the image are: " << img.size() << std::endl;

	// Resizing the image
	// Resizing an image is increasing or decreasing the width and the height of an image. We'll use the resize()
	// function to resize an image. In this case, we are decreasing the size of the image.
	cv::resize(img, resizedImg, cv::Size(600, 400));

	// Scaling the image
	// In the code above resizes the width of the image to 600 pixels and the height to 400 pixels. We can
	// change the parameters of the width and height to increase or decrease the size of the image.
	// However, we don't want the ratio of the width and height to change in most cases. If the ratio is changed,
	// the image will be stretched in the vertical or horizontal direction. So we'll keep the ration of the
	// height and width constant. Therefore, we'll resize the height and width of our image with a constant scale.
	cv::Mat resizedScaledImg;
	cv::resize(img, resizedScaledImg, cv::Size(), 0.7, 0.55); // Scale width to 0.7 and height to 0.55

	// Cropping the image
	// The XY Cartesian plane has a positive x-axis toward the east and positive y-axis toward the north. However, while working with
	// coordinates in OpenCV, the positive x-axis is still toward the east, but the positive y-axis is towards the south, and the origin
	// is at the top left corner.
	// We use Rect class to store the dimensions. This method can crop the images only in rectangular shapes. So first, we need to declare
	// the dimension of the rectangle.
	// The Rect class holds four points: (x,y) of top left corner and width and height of the rectangle.
	// Then, we use the variable roi inside the parentheses of img to crop the image as per the specified dimension.
	cv::Rect roi(0, 0, 300, 300);
	croppedImg = img(roi);


	// Display images
	cv::imshow("Image", img);
	cv::imshow("Resized Image", resizedImg);
	cv::imshow("Resized Scaled Image", resizedScaledImg);
	cv::imshow("Cropped Image", croppedImg);
	cv::waitKey(0);


	cv::destroyAllWindows();

	return 0;
}