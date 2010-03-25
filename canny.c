#include "stdlib.h"
#include "stdio.h"
#include "cv.h"
#include "highgui.h"

IplImage* orig;
IplImage* canny;

int hi = 300;
int lo = 200;
int aperture = 3;

void doFiltering(){
    cvCanny(orig, canny, lo, hi, aperture);
    cvShowImage("Original", orig);
    cvShowImage("Canny", canny);
}

void onHi(int pos) {
    hi = pos;
    doFiltering();
}
void onLo(int pos) {
    lo = pos;
    doFiltering();
}
void onAperture(int pos) {
    if (pos%2!=0 && pos > 1) {
        aperture = pos;
        doFiltering();
    }
}

int main(int argc, char** argv) {
    orig = cvLoadImage(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    canny = cvCreateImage(cvSize(orig->width, orig->height), IPL_DEPTH_8U, 1);
    
    doFiltering();

    cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Canny", CV_WINDOW_AUTOSIZE);

    cvShowImage("Original", orig);
    cvShowImage("Canny", canny);

    cvCreateTrackbar("High Threshold","Canny",0,255,onHi);
    cvSetTrackbarPos("High Threshold","Canny",hi);

    cvCreateTrackbar("Low Threshold","Canny",0,255,onLo);
    cvSetTrackbarPos("Low Threshold","Canny",lo);

    cvCreateTrackbar("Aperture Size","Canny",0,7,onAperture);
    cvSetTrackbarPos("Aperture Size","Canny",aperture);

    while(cvWaitKey(0) != 27);

    cvDestroyWindow("Original");
    cvDestroyWindow("Canny");
    cvReleaseImage(&orig);
    cvReleaseImage(&canny);
    
    return 0;
}
