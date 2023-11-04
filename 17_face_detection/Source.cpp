/*
 * Face detection is technique that can be used widely in attendance, surveillance, and many other fields. This is
 * particular useful in te field of security. In OpenCV, we use cascade classifiers to detect faces. Cascade classifiers
 * are created through classifier training.
 *
 * What is cascade classifier training?
 * Cascade classifier training is a machine learning approach in which a cascade function is trained with lots of
 * positive and negative images, to create a cascade file that will be used to detect other images. For example, if we
 * want to detect faces, we collect images with faces and images without faces. Then, we train the images in OpenCV and
 * create the cascade. Cascade classifiers are one of the most famous and widely used features of OpenCV.
 *
 * Import the face detection cascade
 * TO import the required cascade, we use the faceCascade.load() function. This function requires the location of the
 * cascade file as its parameter:
 *	cv::CascadeClassifier faceCascade;
 *	faceCascade.load(path_to_file);
 * For example, we need the haarcascade_frontalface_alt2.xml file to detect the faces.
 *
 * Detect faces
 * To detect faces, we use the faceCascade.detectMultiScale() function of the OpenCV library. We can access this function
 * from the cascade that we imported. The syntax of the function is:
 *	std::vector<cv::Rect> faces;
 *	faceCascade.detectMultiScale(img, faces, 1.1, 3);
 * This function requires four parameters:
 *	1. imgGray - grayscale image from which are we detect faces.
 *	2. faces - is an array of Rect. The Rect class defines a rectangle by giving the coordinates of its corner points.
 *	3. 1.1 is the scale factor. It's used to specify how much the image is reduced at each image scale.
 *	4. The fourth parameter is used to specify how many neighbors each candidate rectangle should have to retain.
 *
 * Draw contours
 * After detecting the faces, the faces variable will store the x-coordinates, y-coordinate, width, and height of the
 * image. We use the for loop for all the faces detected, get their respective parameters, and use the rectangle()
 * function to draw rectangular contours around the faces detected. The syntax of the code:
 *	for(int i = 0; i < faces.size(); ++i){
 *		cv::rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(255, 0, 255), 1);
 *	}
 * The function requires five parameters
 *	1. img is the image from which we want to detect (and then draw) faces.
 *	2. faces[i].tl() gives the top left point.
 *	3. faces[i].br() gives the bottom right point.
 *	4. The fourth parameter is the scalar value of the color to be given to the rectangle.
 *	5. The fifth parameter is the thickness of the rectangle.
 */
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

int main()
{
	// Load image from disk
	cv::Mat img{ cv::imread("../img/manchester.jpg") };

	// Convert image to grayscale
	cv::Mat imgGray;
	cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);

	// Load cascade classifier
	cv::CascadeClassifier faceCascade;
	faceCascade.load("../haarcascades/haarcascade_frontalface_alt2.xml");

	// Find faces
	std::vector<cv::Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 3);

	// Draw rectangles on detected faces (uncomment one of for loop and comment another)

	//// Old fashion for loop
	//for (int i{ 0 }; i < faces.size(); ++i)
	//	cv::rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(255, 0, 0), 2); 

	// New better loop - range-based for loop
	for (const auto& f : faces)
		cv::rectangle(img, f.tl(), f.br(), cv::Scalar(255, 0, 0), 2);

	// Show image with contours
	std::string windowName{ "FaceDetection" };
	cv::namedWindow(windowName, cv::WINDOW_NORMAL);
	cv::imshow(windowName, img);
	cv::waitKey(0);

	cv::destroyAllWindows();

	return 0;
}