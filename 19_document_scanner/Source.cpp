#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat origImg, grayImg, blurImg, cannyImg, threImg, dilImg, warpImg, cropImg;
std::vector<cv::Point> initPoints, finalPoints;
float w = 420, h = 600;

cv::Mat preProcessing(cv::Mat img)
{
	cv::cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(grayImg, blurImg, cv::Size(3, 3), 3, 0);
	cv::Canny(blurImg, cannyImg, 25, 75);
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::dilate(cannyImg, dilImg, kernel);
	return dilImg;
}

std::vector<cv::Point> getContours(cv::Mat image) {

	std::vector<std::vector<cv::Point>> contourPoints;
	std::vector<cv::Vec4i> hierarchyVec;

	cv::findContours(image, contourPoints, hierarchyVec, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	std::vector<std::vector<cv::Point>> conPoly(contourPoints.size());
	std::vector<cv::Rect> boundRect(contourPoints.size());

	std::vector<cv::Point> biggestPoint;
	int maxArea = 0;

	for (int i = 0; i < contourPoints.size(); i++)
	{
		int contArea = cv::contourArea(contourPoints[i]);
		std::string objectType;

		if (contArea > 1000)
		{
			float perimeter = cv::arcLength(contourPoints[i], true);
			cv::approxPolyDP(contourPoints[i], conPoly[i], 0.02 * perimeter, true);

			if (contArea > maxArea && conPoly[i].size() == 4) {

				biggestPoint = { conPoly[i][0],conPoly[i][1] ,conPoly[i][2] ,conPoly[i][3] };
				maxArea = contArea;
			}
		}
	}
	return biggestPoint;
}

std::vector<cv::Point> reorder(std::vector<cv::Point> points)
{
	std::vector<cv::Point> finPoints;
	std::vector<int>  addPoints, subPoints;

	for (int i = 0; i < 4; i++)
	{
		addPoints.push_back(points[i].x + points[i].y);
		subPoints.push_back(points[i].x - points[i].y);
	}

	finPoints.push_back(points[std::min_element(addPoints.begin(), addPoints.end()) - addPoints.begin()]);
	finPoints.push_back(points[std::max_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]);
	finPoints.push_back(points[std::min_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]);
	finPoints.push_back(points[std::max_element(addPoints.begin(), addPoints.end()) - addPoints.begin()]);
	return finPoints;
}

cv::Mat getWarp(cv::Mat img, std::vector<cv::Point> points, float w, float h)
{
	cv::Point2f init[4] = { points[0],points[1],points[2],points[3] };
	cv::Point2f final[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };
	cv::Mat finalMatrix = cv::getPerspectiveTransform(init, final);
	cv::warpPerspective(img, warpImg, finalMatrix, cv::Point(w, h));
	return warpImg;
}

int main()
{
	std::string path = "../img/doc.png";
	cv::Mat origImg = cv::imread(path);
	cv::Mat threImg = preProcessing(origImg);
	std::vector<cv::Point> initPoints = getContours(threImg);
	std::vector<cv::Point> finalPoints = reorder(initPoints);
	cv::Mat warpImg = getWarp(origImg, finalPoints, w, h);
	cv::imshow("Image", origImg);
	cv::imshow("Final Document", warpImg);
	cv::waitKey(0);
	return 0;
}