//Takes one argument which is name of the file and uses hough transforms
//Used to see how well hough identifieds shapes for Rock Band term project

#include <cv.h>
#include <highgui.h>

int main(int argc, char *argv[]){
	//Load and create images
	IplImage* srcImg = cvLoadImage(argv[1],1);
	
	IplImage* grayImg = cvCreateImage(cvSize(srcImg->width, srcImg->height),IPL_DEPTH_8U,1);
	cvCvtColor(srcImg,grayImg,CV_BGR2GRAY);

	IplImage* sobelImg =  cvCreateImage(cvSize(srcImg->width, srcImg->height),IPL_DEPTH_8U,1);
	cvCanny(grayImg,sobelImg,atoi(argv[2]),atoi(argv[3]),3);
	
	//Display Images
	cvNamedWindow("Source", 1);
	cvShowImage("Source",srcImg);

	cvNamedWindow("Gray Image",1);
	cvShowImage("Gray Image",grayImg);

	cvNamedWindow("Sobel Image",1);
	cvShowImage("Sobel Image",sobelImg);

	cvWaitKey(0);

	cvSaveImage(argv[4],sobelImg);
	
	//Release images and destroy windows
	cvDestroyWindow("Source");
	cvReleaseImage(&srcImg);
	
	cvDestroyWindow("Gray Image");
	cvReleaseImage(&grayImg);

	cvDestroyWindow("Sobel Image");
	cvReleaseImage(&sobelImg);
}
