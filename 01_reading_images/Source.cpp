// Header files in C++ are used to declare functions, classes, and variables that are defined in a separate source
// file. These header file provide a way a separate the interface of a program from its implementation, making
// it easier to organize and maintain large code base. We'll use only one header file, opencv.hpp.
// To include the code, we need to use the "include" keyword and also the path to the file.
#include <iostream>
#include <opencv2/opencv.hpp>

// Namespaces are the declarations that provide scope to variables, functions, etc. In each scope, a name can
// represent only one variable. There can't be two variables with the same name in the same scope. Using namespaces
// can solve this problem. We can create two variables of functions that have the same name, in two different
// namespaces. Here, we are using two namespaces, cv and std.

int main()
{
	// Reading the image
	// To read the image, we have to first get the path to the image. We'll store the path as a string variable.
	std::string imagePath{ "../img/Mount_Everest.jpg" };
	// We read the image using imread(imagePath) function. Furthermore, we pass the imagePath as the parameter to
	// this function. Next, we store the image data in an object called image, which is an instance of the Mat class.
	// Mat is an n-dimensional array class that is used as container for images.
	cv::Mat img{ cv::imread(imagePath)};

	// Displaying the image
	// To show the image, we have to use the imshow(name, Mat) method of the OpenCV library.
	// First parameter is the name of the window where the image is to be displayed.
	// The second parameter is the name of the Mat object containing the image to be displayed in the window.
	cv::imshow("Image", img);

	// Using waitKey()
	// To display the image for a certain amount of time, we use the waitKey(int) method. It takes a parameter
	//representing time in milliseconds. If we pass 0 as the parameter, the image will be displayed indefinitely. 
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}