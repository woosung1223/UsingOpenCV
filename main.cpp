#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;


int main(int ac, char** av) {
	Mat img = imread("labrador.jpg"); 
	vector<uchar> Pixels;
	int count = 0;
	for (int row = 0; row < img.rows; row++)
	{
		uchar* pointer_row = img.ptr<uchar>(row);
		for (int col = 0; col < img.cols; col++)
		{
			uchar b = pointer_row[col * 3 + 0];
			uchar g = pointer_row[col * 3 + 1];
			uchar r = pointer_row[col * 3 + 2];

			uchar toGray = (b + g + r) / 3;
			for (int i = 0; i < 3; i++)
				pointer_row[col * 3 + i] = toGray;
		}
		cout << "\n" << endl;
	}
	imshow("img", img);
	waitKey(0);
	return 0;
}