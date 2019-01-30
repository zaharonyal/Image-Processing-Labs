#include <stdio.h> // for printf
#include <conio.h> // for getch
#include <iostream> // for cin cout
#include <fstream>  // For file IO
using namespace std; // Explain some day 
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
// BMP Library
#include "ImProcInPlainC.h"

	unsigned char GrayImage[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
	unsigned char GrayImage1[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
	unsigned char GrayImage2[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
	unsigned char GrayImage3[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
	unsigned char test[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
	unsigned char test12[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
void main()
{
	//lab 1
	// Declare Gray Image
	//unsigned char ColorImage[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS][3];

	//CreateColorRectangle(ColorImage);
	////StoreGrayImageAsGrayBmpFile(GrayImage, "GrayRectangle.bmp");
	//StoreBgrImageAsTrueColorBmpFile(ColorImage, "ColorRectangle.bmp");

	//lab 2
	//CreateColorRamp(ColorImage);
	//StoreBgrImageAsTrueColorBmpFile(ColorImage, "ColorRamp.bmp");
	//
	//DigitalCreateGrayRamp(GrayImage);
	/*CreateBWStrips(GrayImage, 14);
	StoreGrayImageAsGrayBmpFile(GrayImage, "A12.bmp");
	CreateGrayREctImage(GrayImage, 13, 7);
	StoreGrayImageAsGrayBmpFile(GrayImage, "A12.bmp");*/

	/*SpiralImage(GrayImage, 9);
	StoreGrayImageAsGrayBmpFile(GrayImage, "A13.bmp");*/

	/*DegradedSinAndSquare(GrayImage, 2, 16);
	StoreGrayImageAsGrayBmpFile(GrayImage, "A21.bmp");*/

	////lab 3
	//LoadGrayImageFromTrueColorBmpFile(GrayImage,"A30.bmp");
	//StoreGrayImageAsGrayBmpFile(GrayImage, "A30gray.bmp");
	//DestroyImage(GrayImage, GrayImage1, 0.314, 64);
	//StoreGrayImageAsGrayBmpFile(GrayImage1, "A31.bmp");
	//DoImageWithCandB(GrayImage2, GrayImage1);
	//StoreGrayImageAsGrayBmpFile(GrayImage2, "A32.bmp");
	//int Hist[myMAXCOLORS],Hist1[myMAXCOLORS],Hist2[myMAXCOLORS], Hist3[myMAXCOLORS];
	//float HistNew[myMAXCOLORS], Hist1New[myMAXCOLORS], Hist2New[myMAXCOLORS], Hist3New[myMAXCOLORS];
	//DoGrayHist(GrayImage, Hist);//do histogram from image A30Gray
	//DoGrayHist(GrayImage1, Hist1);//do histogram from image A31
	//DoGrayHist(GrayImage2, Hist2);//do histogram from image A32
	//DoHistogramEqualization(Hist1, Hist1New, 0, 255, "A342.csv");
	//double c = 0.2, v = 0.8;
	//DoImageWithCandBWithLimit(GrayImage3, GrayImage1,Hist1, c,v);
	//StoreGrayImageAsGrayBmpFile(GrayImage3, "A33.bmp");
	//DoGrayHist(GrayImage, Hist3);//do histogram from image A33
	//DoHistogramEqualization(Hist, HistNew, 0, 255,"A341.csv");
	//DoHistogramEqualization(Hist2, Hist2New, 0, 255,"A343.csv");
	//DoHistogramEqualization(Hist1, Hist3New, 0, 255,"A344.csv");
	//DoImageFromHist(GrayImage, test, HistNew);
	//StoreGrayImageAsGrayBmpFile(test, "A341.bmp");//Do Histogram Equalization from image A30Gray
	//DoImageFromHist(GrayImage1, test, Hist1New);
	//StoreGrayImageAsGrayBmpFile(test, "A342.bmp");//Do Histogram Equalization from image A31
	//DoImageFromHist(GrayImage2, test, Hist2New);
	//StoreGrayImageAsGrayBmpFile(test, "A343.bmp");//Do Histogram Equalization from image A32
	//DoImageFromHist(GrayImage3, test, Hist3New);
	//StoreGrayImageAsGrayBmpFile(test, "A344.bmp");//Do Histogram Equalization from image A33
	//int thresh= FindThreshold(GrayImage);
	//DoBinaryImage(GrayImage, test, thresh);
	//StoreGrayImageAsGrayBmpFile(test, "3411.bmp");
	//DoBinaryImage(GrayImage, test, 50);
	//StoreGrayImageAsGrayBmpFile(test, "3412.bmp");
	//DoBinaryImage(GrayImage, test, 70);
	//StoreGrayImageAsGrayBmpFile(test, "3413.bmp");
	//DoBinaryImage(GrayImage, test, 150);
	//StoreGrayImageAsGrayBmpFile(test, "3414.bmp");
	//DoBinaryImage(GrayImage, test, 200);
	//StoreGrayImageAsGrayBmpFile(test, "3415.bmp");
	//int how = CountFlower(GrayImage1, test12, 44, 91, 44, 40);
	//cout << "num of flower is: " << how << endl;
	//WaitForUserPressKey();

	////lab4
	//LoadGrayImageFromTrueColorBmpFile(GrayImage, "A30.bmp");
	//StoreGrayImageAsGrayBmpFile(GrayImage, "A12.bmp");
	//RotateImage(GrayImage, GrayImage1, 16, 341, 267);
	//StoreGrayImageAsGrayBmpFile(GrayImage1, "A41.bmp");
	//RotateImageBilinear(GrayImage, GrayImage2, 16, 341, 267);
	//StoreGrayImageAsGrayBmpFile(GrayImage2, "A42.bmp");
	//StoreGrayImageAsGrayBmpFile(GrayImage3, "A341.bmp");
	//RotateImage(GrayImage, GrayImage1, 11, 367, 159);
	//StoreGrayImageAsGrayBmpFile(GrayImage1, "A43.bmp");
	//RotateImageBilinear(GrayImage3, test, 11, 367, 159);
	//StoreGrayImageAsGrayBmpFile(GrayImage1, "A44.bmp");
	//WaitForUserPressKey();

	//lab5
	//LoadGrayImageFromGrayBmpFile(GrayImage, "A12.bmp");
	LoadGrayImageFromTrueColorBmpFile(GrayImage, "A30.bmp");
	AddSaltAndPepperNoise(GrayImage, GrayImage1, 250, 286);
	AddLineNoise(GrayImage1, GrayImage2, 41, 50, 3);
	StoreGrayImageAsGrayBmpFile(GrayImage2, "A51.bmp");
	#define MAX_BUFFER_SIZE (150) // i dont know way max value is 150
	unsigned char MedianBuffer[MAX_BUFFER_SIZE];
	MedianFilter(GrayImage2, GrayImage3, MedianBuffer, 1, 1);
	StoreGrayImageAsGrayBmpFile(GrayImage3, "A52.bmp");
	#define FILTER_HALF_SIZE (100) // i dont know way max value is 150
	double filter[FILTER_HALF_SIZE];
	PrepareGausssianFilter(filter, 5.0);
	DoGaussianFiltration(GrayImage2, test, filter);
	StoreGrayImageAsGrayBmpFile(test, "A53.bmp");
	WaitForUserPressKey();
}