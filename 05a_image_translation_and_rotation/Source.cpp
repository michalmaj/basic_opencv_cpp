/*
 * Sometimes we want to change the position of an image or rotate it while doing graphic design. We might use
 * photo editing tools when we have just a few images to edit. However, if we have thousands of images to edit,
 * it'll take hours to edit them all. So the solution is to use image translation and rotation in the OpenCV
 * library. Image translation and rotation fall under the class of affine transformation.
 *
 * Create a translation matrix
 * The translation of an image in OpenCV is shifting the image by certain pixels in the horizontal and vertical
 * direction. We need to specify the translation matrix through which the translation of the image is to occur.
 * If we want to shift the image x pixels along the horizontal and y pixels along the vertical, the translation
 * matrix would be:
 * | 1 0 x |
 * | 0 1 y |
 * First, we'll list the numbers to be used inside the matrix as an array of float numbers. We can use any number
 * in place of the variables x and y that determine the translation of the image. In this case, we're finding the
 * height and width of the image and using one-third of that value to translate the image.
 * Then we'll simply use the property of the Mat to create the matrix from the array. We'll use the Mat() function,
 * which has four parameters:
 *  1. Number of rows.
 *  2. Number of columns.
 *  3. Type of data used in the matrix. For example, CV_32F means we're using the float data type.
 *  4. Array of numbers.
 *
 * Translating the image
 * To translate the images, we'll use the wrapAffine() function of the OpenCV library. We need four parameters
 * inside the function:
 *  1. The original image.
 *  2. The translated image.
 *  3. The translation matrix.
 *  4. The dimensions.
 */
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

int main()
{
    // Read the image from the path
    cv::Mat img{ cv::imread("../img/chile.jpg") };

    // Resize image for displaying purpose
    cv::resize(img, img, cv::Size(), 0.7, 0.55);

    // Create placeholders for translated image
    cv::Mat translatedImage;

    // Get width and height of the image, we can use C++17 structured binding
    auto [width, height] = img.size();

    // Create x and y from width and height
    float x = static_cast<float>(width) / 3;
    float y = static_cast<float>(height) / 3;

    // Create translation matrix
    std::vector<float> warp_values {1.0, 0.0, x, 0.0, 1.0, y};
    cv::Mat translationMatrix{ cv::Mat(2, 3, CV_32F, warp_values.data()) };

    // Translating image
    cv::warpAffine(img, translatedImage, translationMatrix, img.size());

    // Display images
    cv::imshow("Original Image", img);
    cv::imshow("Translated Image", translatedImage);
    cv::waitKey(0);

    cv::destroyAllWindows();
   
    return 0;
}