/*
 * In Photoshop, we crop an image by drawing a shape on it. We can't always rely on drawing shapes automatically using
 * code. We may want to work on the image manually to add the personal touch. In those cases, we can use our mouse to
 * draw shapes. OpenCV provides us the feature to detect various mouse operations, such as left-click and right-click.
 *
 * We start by declaring variable and reading the image. Then we need to create the temp image that we'll use later for
 * clearing the image after drawing shape on it.
 *
 * Create a temp image
 * To create a temp image, we need to use the clone() function. We use the namedWindow() function to create a window. We
 * need to provide only one parameter to this function. It's the name that we want to give to that window:
 *	cv::Mat tep = image.clone();
 *	cv::namedWindow("Window");
 *
 * Function to draw a rectangle
 * First, we need to detect touch on a mouse. We use the setMouseCallback() function, to which we need to pass two
 * parameters:
 *	1. The window in which we want to detect mouse events.
 *	2. The function where it'll pass the event values.
 * This function is used to call a certain function if there are any mouse events:
 *	cv::setMouseCallback("Window", drawRectangle);
 * The statement above will call the drawRectangle() function if any mouse event occurs. Since this function is called
 * using the setMouseCallback() function, it records the mouse even type, event flag, and x- and y- coordinates of
 * the point. Theses parameters are passed to the drawRectangle() function. *userdata is also passed to the function.
 * So, we'll use the following parameters:
 *	- action is the mouse event;
 *	- x is the x-coordinate of the mouse point during the mouse event;
 *	- y is the y-coordinate of the mouse point during the mouse event.
 * Similar to any other photo editing tool, we draw the rectangle by pressing at one point and dragging the mouse to
 * another point. Our first point is where we press the mouse button, and the second is the point where we release
 * the mouse. We'll use this concept to draw a rectangle using the mouse.
 * We initially check the event when the left mouse button is pressed down. This event gives us the top left point of
 * the rectangle. We compare the action with EVENT_LBUTTONDOWN, which is true if the left button is pressed down.
 * Then we'll set the point tl to the x and y coordinate.
 *	void drawRectangle(int action, int x, int y, int flags, void* userdata){
 *		if(action == cv::EVENT_LBUTTONDOWN)
 *			tl = cv::Point(x, y);
 *	}
 * Then we check the event when the left mouse button is released. This event gives us the bottom right point of the
 * rectangle. We compare the action with EVENT_LBUTTONUP, which is true if the left button is pressed down. Then we
 * set the point br to the x and y coordinate.
 * Next, we draw a rectangle using the rectangle() function of the OpenCV library. We have five parameters inside
 * this function, where:
 *	1. image is the original image.
 *	2. tl is the top left corner point of where we want to draw the rectangle.
 *	3. br is the bottom right corner point of where we want to draw the rectangle.
 *	4. Scalar(0, 255, 0) gives a green color to the rectangle. It can be changed to another color with a different
 *	   color code.
 *	5. 2 is the thickness of the rectangle. We can the value of -1 to fill the rectangle with the same color.
 *
 * Clean the image
 * After drawing many rectangles in the image, we might want to clean the image, so we add the functionality of
 * clearing the image. Here, we use the temp image that we created earlier in the chapter, replacing our image with
 * the temp image.
 * For that, we declare the integer k. We use a while loop that runs until k is equal to 113. We show the image
 * inside this loop so that it's displayed continuously. Likewise, we assign k to waitKey. So the while loop keeps
 * running until someone presses "q". The waitKey gives the value of 113 when 'q' is pressed. Similarly, the waitKey
 * gives the value of 99 when 'c' is pressed. We use an if statement and compare k to 99 If the statement is true, we
 * use the copyTo() function to copy the temp image to the origin image.
 * At the end of the while loop, we've also added the destroyAllWindows() function to destroy all the windows after
 * the while loop is stopped.
 */
#include <opencv2/opencv.hpp>
#include <string>

struct UserData
{
	cv::Mat image;
	cv::Point tl, br;
	std::string name;
};

// Function called on mouse event
void drawRectangle(int action, int x, int y, int flags, void* userdata)
{
	UserData* u = static_cast<UserData*>(userdata);

	if (action == cv::EVENT_LBUTTONDOWN)
		u->tl = cv::Point(x, y);
	else if(action == cv::EVENT_LBUTTONUP)
	{
		u->br = cv::Point(x, y);

		// Drawing rectangle
		cv::rectangle(u->image, u->tl, u->br, cv::Scalar(0, 255, 0), 2);
		cv::imshow(u->name, u->image);
	}
}

int main()
{
	// Read an image
	UserData u1;
	u1.image = cv::imread("../img/manchester.jpg");

	// Create copy of our image
	cv::Mat temp{ u1.image.clone() };

	// Create a named window
	u1.name = "Window";
	cv::namedWindow(u1.name);

	// Function called on mouse events
	cv::setMouseCallback(u1.name, drawRectangle, &u1);

	char k{ '\0' };
	while(k != 'q')
	{
		// Display an image
		cv::imshow(u1.name, u1.image);

		// Restore original image on 'c' key
		k = static_cast<char>(cv::waitKey(0));
		if (k == 'c')
			temp.copyTo(u1.image);
	}

	cv::destroyAllWindows();

	return 0;
}