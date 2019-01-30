#include "ImProcInPlainC.h"
#include <conio.h> // for getch
#include <stdio.h> // for old C-Style file operations 
#include <stdlib.h> // for exit
#include <math.h>
#define _USE_MATH_DEFINES
#include <cmath> 
#include <iostream> // for cin cout
#include <fstream>  // For file IO
using namespace std;



//this is what rafi and alon build


void CreateColorRectangle(unsigned char image[][NUMBER_OF_COLUMNS][3])
{
	for (int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		for (int column = 0; column < NUMBER_OF_COLUMNS; column++)
		{
			image[row][column][R] = 213;
			image[row][column][G] = 96;
			image[row][column][B] = 213;
		}
	}

	for (int row = NUMBER_OF_ROWS * 1 / 4; row < NUMBER_OF_ROWS * 3 / 4; row++)
	{
		for (int column = NUMBER_OF_COLUMNS * 1 / 4; column < NUMBER_OF_COLUMNS * 3 / 4; column++)
		{
			image[row][column][R] = 63;
			image[row][column][G] = 163;
			image[row][column][B] = 63;
		}
	}
}

void DigitalCreateGrayRamp(unsigned char image[][NUMBER_OF_COLUMNS])
{
	int color = 0;
	for (int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		for (int column = 0; column < NUMBER_OF_COLUMNS; column++)
		{
			image[row][column] = color;
			if (column % 13 == 0)
				color += 10;
		}
		color = 0;
	}
}
void CreateColorRamp(unsigned char image[][NUMBER_OF_COLUMNS][3])
{
	for (int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		for (int column = 0; column < NUMBER_OF_COLUMNS; column++)
		{
			image[row][column][R] = 60;
			image[row][column][G] = 163;
			image[row][column][B] = 63;
		}
	}
}

void CreateBWStrips(unsigned char image[][NUMBER_OF_COLUMNS], int NumRows)
{
	int Rows = NUMBER_OF_ROWS / NumRows, color = 0;
	for (int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		for (int column = 0; column < NUMBER_OF_COLUMNS; column++)
		{
			image[row][column] = color;
		}
		if ((row % Rows == 0) && (row != 0))
		{
			if (color == 0)
				color = 255;
			else
				color = 0;
		}

	}
}

void CreateGrayRect(unsigned char image[][NUMBER_OF_COLUMNS], int NumCol, int NumRows, int StartLine, int ColStart)
{
	int col = NUMBER_OF_COLUMNS / NumCol, color = 0, rows = NUMBER_OF_ROWS / NumRows;
	for (int row = 0; row < NUMBER_OF_ROWS; row++)
	{
		for (int column = ColStart; column < NUMBER_OF_COLUMNS; column++)
		{
			if ((StartLine % 2 == 0) && (column > ColStart) && (column < ColStart + col))
			{
				image[row][column] = 127;
			}
		}
		if ((row%rows == 0) && (row != 0))
			StartLine++;
	}
}
void CreateGrayREctImage(unsigned char image[][NUMBER_OF_COLUMNS], int NumCol, int NumRows)
{
	int num2 = NUMBER_OF_COLUMNS / NumCol;
	for (int cs = num2; cs <= NUMBER_OF_ROWS; cs += num2 * 2)
	{
		int r = 1;
		CreateGrayRect(image, NumCol, NumRows * 2, r, cs);
		cs = cs + num2 * 2;
		r++;
		CreateGrayRect(image, NumCol, NumRows * 2, r, cs);
	}
}

void CreateBWBackground(unsigned char image[][NUMBER_OF_COLUMNS], int color)
{
	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			image[i][j] = color;
		}
	}
}
void SpiralImage(unsigned char image[][NUMBER_OF_COLUMNS], int WidthSpiral)
{
	CreateBWBackground(image, 255); //create white background
	float Rad = 0, Ap = 0;
	int row = 0, col = 0;
	for (Ap; Ap < 90; Ap += 0.01)
	{
		row = Rad * cos(Ap) + NUMBER_OF_ROWS / 2;
		col = Rad * sin(Ap) + NUMBER_OF_COLUMNS / 2;
		for (int w = 0; w < WidthSpiral; w++)
		{
			for (int wi = -(WidthSpiral / 2); wi < WidthSpiral / 2; wi++)
			{
				if ((row - w) >= 0 && (row - w) < NUMBER_OF_ROWS && (col + wi) >= 0 && (col + wi) < NUMBER_OF_COLUMNS)
				{
					image[row - w][col + wi] = 0;
				}
			}
		}
		Rad += 0.1;
	}
}

void DegradedSinAndSquare(unsigned char image[][NUMBER_OF_COLUMNS])
{
	float F = 0, x = 0;
	CreateBWBackground(image, 255); //create white background
	for (int i = 0; i <= NUMBER_OF_COLUMNS; i++)
	{
		for (int j = 0; j < NUMBER_OF_ROWS; j++)
		{
			image[j][i] = 127.0 * (1 + sin(2 * M_PI*F*x));
		}
		F += 0.0005;
		x += M_PI / 4;
		for (int j = NUMBER_OF_ROWS / 2; j < NUMBER_OF_ROWS; j++)
		{
			if (image[j][i] >= 127)
				image[j][i] = 255;
			else
				image[j][i] = 0;
		}
	}
}

void DestroyImage(unsigned char image[][NUMBER_OF_COLUMNS], unsigned char dest[][NUMBER_OF_COLUMNS], float Cons, int Bra)
{
	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			dest[i][j] = image[i][j] * Cons + Bra;
		}
	}
}

int* FindMinMAx(int hist[])
{
	int n = 255, min = 255, max = 0, re[2];
	for (int i = 0; i < n; i++)
	{
		if (hist[i] > max)
			max = hist[i];
		else if (hist[i] < min)
			min = hist[i];
	}
	re[0] = min;
	re[1] = max;
	return re;
}

int* FindMinMAx(unsigned char image[][NUMBER_OF_COLUMNS])
{
	int min = 255, max = 0, re[2];
	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
			if (image[i][j] > max)
				max = image[i][j];
			else if (image[i][j] < min)
				min = image[i][j];
	}


	re[0] = min;
	re[1] = max;
	return re;
}
void DoGrayHist(unsigned char image[][NUMBER_OF_COLUMNS], int Hist[])
{
	for (int i = 0; i < myMAXCOLORS; i++)
	{
		Hist[i] = 0;
	}
	for (int i = 0; i < NUMBER_OF_COLUMNS; i++)
	{
		for (int j = 0; j < NUMBER_OF_ROWS; j++)
		{
			Hist[image[i][j]] += 1;
		}
	}
}

void DoImageWithCandB(unsigned char image[][NUMBER_OF_COLUMNS], unsigned char old[][NUMBER_OF_COLUMNS])
{

	int* minmax = FindMinMAx(old);
	double contrast = (255.0) / ((double)minmax[1] - (double)minmax[0]);
	double Brightness = -contrast * minmax[0];
	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			image[i][j] = old[i][j] * contrast + Brightness;
		}
	}
}

void DoImageWithCandBWithLimit(unsigned char image[][NUMBER_OF_COLUMNS], unsigned char old[][NUMBER_OF_COLUMNS], int Hist[], double MinPrec, double MaxPrec)
{
	int IntegralHist[myMAXCOLORS];
	int cdf = 0, MinOut = 0, MaxOut = 0;
	for (int i = 0; i < myMAXCOLORS; i++)//do intgral from histogram
	{
		cdf += Hist[i];
		IntegralHist[i] = cdf;
	}
	double contrast, Brightness;
	double min = MinPrec * cdf, max = MaxPrec * cdf;
	for (int i = 0; i < myMAXCOLORS; i++)
	{
		if (IntegralHist[i] < max)
			MinOut = i;
		if (IntegralHist[i] > min)
			MaxOut = i;
	}
	if (min == max)
	{
		contrast = 1.0;
		Brightness = 0.0;
	}
	else
	{
		contrast = (255.0) / ((double)MaxOut - (double)MinOut);
		Brightness = -contrast * MinOut;
	}
	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			image[i][j] = old[i][j] * contrast + Brightness;
		}
	}
}
void DoHistogramEqualization(int old[], float newer[], int newmin, int newmax, char* name)
{
	FILE *myfile;
	myfile = fopen(name, "t");
	fputs("value,index\n", myfile);
	int  CdfMax = 0, pmf = 0;
	float cdf = 0;
	for (int i = 0; i < myMAXCOLORS; i++)
	{
		pmf += old[i];
	}

	for (int i = 0; i < myMAXCOLORS; i++)
	{
		cdf += (float)old[i] / (float)pmf;
		newer[i] = cdf;
	}

	for (int i = 0; i < myMAXCOLORS; i++)
	{
		int y = (newer[i])*((float)(newmax - newmin));
		newer[i] = y;
		fprintf(myfile, "%d,%d\n", y, i);
	}
	fclose(myfile);
}
void DoImageFromHist(unsigned char old[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], unsigned char dest[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], float Hist[])
{
	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			dest[i][j] = (int)Hist[old[i][j]];
		}
	}
}

int FindThreshold(unsigned char old[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], int threshold)
{
	int min = 0, max = 0, countmax = 0, countmin = 0;
	if (threshold != 127)
		threshold = 127;
	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			if (old[i][j] >= threshold)//find all the pixel are big from threshold
			{
				max += old[i][j];
				countmax++;
			}
			else//find all the pixel are small from threshold
			{
				min += old[i][j];
				countmin++;
			}
		}
	}
	int averag = ((float)min / (float)countmin + (float)max / (float)countmax) / 2;//find the new threshold
	return averag;
}

void DoBinaryImage(unsigned char old[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], unsigned char dest[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], int threshold)
{
	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			if (old[i][j] >= threshold)
				dest[i][j] = 255;
			else
				dest[i][j] = 0;
		}
	}
}

int CountFlower(unsigned char old[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], unsigned char test12[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], int pixelx, int pixely, int dx, int dy)
{
	int countone = 0; //how mach white pixel have for one
	int count = 0;
	int allpixel = 0; //how mach white pixel have
	int thresh = FindThreshold(old);
	DoBinaryImage(old, test12, thresh);
	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			if (test12[i][j] == 0)
				allpixel++;
		}
	}
	for (int i = pixelx; i < pixelx + dx; i++)
	{
		for (int j = pixely; j < pixely + dy; j++)
		{
			if (test12[i][j] == 0)
			{
				countone++;
				test12[i][j] = 127;
			}
		}
	}
	StoreGrayImageAsGrayBmpFile(test12, "testcount.bmp");
	if (countone == 0)
		count = -1;
	else
		count = allpixel / countone;
	return count;
}

void RotateImage(unsigned char old[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], unsigned char dest[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], int deg, int px, int py)
{
	//Forward Afine Transform :
	// Xnew = a11*Xold + a12*Yold + b1;
	// Ynew = a21*Xold + a22*Yold + b2;
	double a11, a12, a21, a22, oldrow, oldcol;
	int newrow, newcol;
		//build the AFFINE TRANSFORMATIONS
		a11 = cos(deg*M_PI / 180);
		a12 = -sin(deg*M_PI / 180);
		a21 = sin(deg*M_PI / 180);
		a22 = cos(deg*M_PI / 180);
		for (int i = 0; i < NUMBER_OF_ROWS; i++)
		{
			for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
			{
				//calculate the new pixel
				oldrow = a11 * i + a12 * j + px * (1.0 - a22) + py * a21;
				oldcol = a21 * i + a22 * j + px * (1.0 - a11) + py * a21;
				newrow = (int)(0.5 + oldrow);
				newcol = (int)(0.5 + oldcol);
				if (oldcol < NUMBER_OF_COLUMNS && oldrow < NUMBER_OF_ROWS && oldcol >0 && oldrow >0)//check if the pixel is in the frame
				{
					dest[i][j] = old[newrow][newcol];
				}
			}
		}

}
void RotateImageBilinear(unsigned char old[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], unsigned char dest[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], int deg, int px, int py)
{
	//Forward Afine Transform :
	// Xnew = a11*Xold + a12*Yold + b1;
	// Ynew = a21*Xold + a22*Yold + b2;
	double a11, a12, a21, a22, oldrow, oldcol;
	double x, y, a, b, c, d, I, i00, i10, i01, i11;
	int newrow, newcol;
	//build the AFFINE TRANSFORMATIONS
	a11 = cos(deg*M_PI / 180);
	a12 = -sin(deg*M_PI / 180);
	a21 = sin(deg*M_PI / 180);
	a22 = cos(deg*M_PI / 180);
	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			//calculate the new pixel
			oldrow = a11 * i + a12 * j + px * (1.0 - a22) + py * a21;
			oldcol = a21 * i + a22 * j + px * (1.0 - a11) + py * a21;
			newrow = (int)(0.5 + oldrow);
			newcol = (int)(0.5 + oldcol);
			x = oldcol - (int)oldcol;
			y = oldrow - (int)oldrow;
			if (oldcol < NUMBER_OF_COLUMNS && oldrow < NUMBER_OF_ROWS && oldcol >0 && oldrow >0)//check if the pixel is in the frame
			{
				i00 = old[(int)oldrow][(int)oldcol];
				a = i00;
				i10= old[(int)oldrow][(int)oldcol+1];
				b = i10 - i00;
				i01= old[(int)oldrow+1][(int)oldcol];
				c = i01 - i00;
				i11= old[(int)oldrow+1][(int)oldcol+1];
				d = i11 - i00 - i01 - i10;
				I = a + b * x + c * y + d * x*y;
				dest[i][j] = (unsigned char)(int)(I+0.5);
			}
		}
	}

}

void AddSaltAndPepperNoise(unsigned char old[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], unsigned char dest[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], int salt, int pepper)
{
	//add white(salt) dot and
	int RandRow, RandCol;
	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			dest[i][j] = old[i][j];
		}
	}
	for (int i = 0; i < salt; i++)
	{
		RandRow = (NUMBER_OF_ROWS*rand()) / RAND_MAX;
		RandCol = (NUMBER_OF_COLUMNS*rand()) / RAND_MAX;
		dest[RandRow][RandCol] = 255;
	}
	for (int i = 0; i < pepper; i++)
	{
		RandRow = (NUMBER_OF_ROWS*rand()) / RAND_MAX;
		RandCol = (NUMBER_OF_COLUMNS*rand()) / RAND_MAX;
		dest[RandRow][RandCol] = 0;
	}
}

void AddLineNoise(unsigned char old[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], unsigned char dest[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], int lines,int dx,int dy)
{
	int RandRow, RandCol;
	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			dest[i][j] = old[i][j];
		}
	}
	for (int i = 0; i < lines; i++)
	{
		RandRow = (NUMBER_OF_ROWS*rand()) / RAND_MAX;
		RandCol = (NUMBER_OF_COLUMNS*rand()) / RAND_MAX;
		for (int row = RandRow; row < dx+ RandRow; row++)
		{
			for (int col = RandCol; col < dy+ RandCol; col++)
			{
				if (row<NUMBER_OF_ROWS && col<NUMBER_OF_COLUMNS)
					dest[row][col] = 255;
			}
		}
	}
}

int MedianValue(unsigned char medianbuffer[], int size)//find the middle value
{
	int mid = ( size + 1) / 2;
	unsigned char temp;
	for (int i = 0; i < mid; i++)
	{
		for (int j = 1; j < size-1; j++)
		{
			if (medianbuffer[j] > medianbuffer[j - 1])
			{
				temp = medianbuffer[j];
				medianbuffer[j] = medianbuffer[j - 1];
				medianbuffer[j - 1] = temp;
			}
		}
	}
	return medianbuffer[mid];
}

void MedianFilter(unsigned char old[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS], unsigned char dest[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS],
	unsigned char medianbuffer[],int filterhalfwidth,int filterhalfheight)
{
	int medianbuffersize = (2 * filterhalfwidth + 1)*(2 * filterhalfheight + 1);
	if (medianbuffersize >= MAX_BUFFER_SIZE)
	{
		cout << "Too large median size" << endl;
		return;
	}
	for (int i = 0; i < NUMBER_OF_ROWS; i++)//clear dest
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			dest[i][j] = 0;
		}
	}
	for (int i = filterhalfheight; i < NUMBER_OF_ROWS-filterhalfheight; i++)
	{
		for (int j = filterhalfwidth; j < NUMBER_OF_COLUMNS - filterhalfwidth; j++)
		{
			int count = 0;
			for (int y =-filterhalfheight; y <= filterhalfheight; y++)
			{
				for (int x = -filterhalfwidth; x <= filterhalfwidth; x++)
				{
					medianbuffer[count++] = old[i + y][j + x];
				}
			}
			dest[i][j] = MedianValue(medianbuffer, medianbuffersize);
		}
	}
}

void PrepareGausssianFilter(double filter[], double sigma)
{
	double summa = 0;
	double temp;
	for (int i = 0; i < (2 * FILTER_HALF_SIZE + 1); i++)
	{
		temp = (double)(i - FILTER_HALF_SIZE) / sigma;
		temp = exp(-temp * temp);
		filter[i] = temp;
		summa += temp;
	}
	for (int i = 0; i < (2 * FILTER_HALF_SIZE + 1); i++)
	{
		temp = (double)(i - FILTER_HALF_SIZE) / sigma;
		temp = exp(-temp * temp);
		filter[i] = filter[i] / summa;
	}
}

void DoGaussianFiltration(unsigned char old[][NUMBER_OF_COLUMNS], unsigned char dest[][NUMBER_OF_COLUMNS],double filter[])
{
	// Clear all pixels of dest
	for (int i = 0; i < NUMBER_OF_ROWS; i++) 
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			dest[i][j] = 0;
		}
	}
	double summa;
	// x direction
	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = FILTER_HALF_SIZE; j < NUMBER_OF_COLUMNS - FILTER_HALF_SIZE; j++)
		{
			summa = 0;
			for (int x = -FILTER_HALF_SIZE; x <= FILTER_HALF_SIZE; x++)
			{
				summa = summa + filter[FILTER_HALF_SIZE + x] * (double)old[i][j + x];
			} // of x
			if (summa < 0) summa = 0;
			if (summa > 255) summa = 255;
				dest[i][j] = (unsigned char)summa;
		} // of column
	} // of row
	for (int i = 0; i < NUMBER_OF_COLUMNS; i++)
	{ 
		// y direction
			for (int j = FILTER_HALF_SIZE; j < NUMBER_OF_ROWS - FILTER_HALF_SIZE; j++)
			{
					summa = 0;
					for (int y = -FILTER_HALF_SIZE; y <= FILTER_HALF_SIZE; y++)
					{
						summa += filter[FILTER_HALF_SIZE + y] * dest[j + y][i];
					} // of y
					if (summa < 0) summa = 0;
					if (summa > 255) summa = 255;
						dest[j][i] = (unsigned char)summa;
			} // of column
	} // of row
}