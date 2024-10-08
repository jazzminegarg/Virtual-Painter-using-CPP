#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////////  Project 1 - Virtual Painter //////////////////////

Mat img;
VideoCapture cap(0);
vector<vector<int>> newPoints;  // to store all points

/////////////////////  COLOR VALUES ////////////////////////////////
// hmin, smin, vmin, hmax, smax, vmax
vector<vector<int>> myColors{
     {100, 50, 50, 160, 255, 255},// Purple (extended range to include all shades)

    {35, 50, 50, 85, 255, 255}    // Green (extended range to include all shades)
};

vector<Scalar> myColorValues{
      {255, 0, 255}, // Purple
    {0, 255, 0}      // Green
};
////////////////////////////////////////////////////////////////////

Point getContours(Mat image) {
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());

    Point myPoint(0, 0);

    for (int i = 0; i < contours.size(); i++) {
        int area = contourArea(contours[i]);
        cout << area << endl;

        if (area > 1000) {
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

            boundRect[i] = boundingRect(conPoly[i]);
            myPoint.x = boundRect[i].x + boundRect[i].width / 2;
            myPoint.y = boundRect[i].y;
        }
    }
    return myPoint;
}

vector<vector<int>> findColor(Mat img) {
    Mat imgHSV;
    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    for (int i = 0; i < myColors.size(); i++) {
        Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
        Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
        Mat mask;
        inRange(imgHSV, lower, upper, mask);
        Point myPoint = getContours(mask);
        if (myPoint.x != 0) {
            newPoints.push_back({myPoint.x, myPoint.y, i});
        }
    }
    return newPoints;
}

void drawOnCanvas(vector<vector<int>> newPoints, vector<Scalar> myColorValues) {
    for (int i = 0; i < newPoints.size(); i++) {
        circle(img, Point(newPoints[i][0], newPoints[i][1]), 10, myColorValues[newPoints[i][2]], FILLED);
    }
}

int main() {
    while (true) {
        cap.read(img);

        // Flip the image horizontally to avoid mirror effect
        flip(img, img, 1);

        newPoints = findColor(img);
        drawOnCanvas(newPoints, myColorValues);

        imshow("Image", img);
        waitKey(1);
    }
}
