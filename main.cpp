#include <iostream>
#include <opencv2/core/types_c.h>
#include <cv.h>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
void m();
int main() {
    m();
    return 0;
}


void m(){
    IplImage* img = cvLoadImage("/home/gesandte/Downloads/123.png",1);
    IplImage* resImg = cvCreateImage(cvSize(img->width*3, img->height*3),8,3);
    Mat matImg = cvarrToMat(img);
    cvtColor(matImg, matImg, CV_RGB2GRAY );
    Mat resMat = cvarrToMat(resImg);
    cvtColor(resMat, resMat, CV_RGB2GRAY );
    int x = 0;
    int y = 0;
    for(int i = 0; i < matImg.rows; i++) {
        for (int k = 0; k < matImg.cols; k++) {
            for (int j = 0; j < 3; j++) {
                resMat.at<uchar>((i+x), y) = matImg.at<uchar>(i, k);
                if (x == 0) {
                    resMat.at<uchar>((i + x + 1), y) = matImg.at<uchar>(i, k);
                    resMat.at<uchar>((i + x + 2), y) = matImg.at<uchar>(i, k);
                }else{
                    resMat.at<uchar>((i + x - 1), y) = matImg.at<uchar>(i, k);
                    resMat.at<uchar>((i + x - 2), y) = matImg.at<uchar>(i, k);
                }
                    y++;
            }

        }


        x+=2;
        y = 0;
    }
    cvNamedWindow("1",1);
    cvNamedWindow("2",1);
    imshow("1", resMat);
    imshow("2", matImg);
    waitKey(0);


}