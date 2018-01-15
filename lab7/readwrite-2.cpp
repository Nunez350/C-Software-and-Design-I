/*
  Author: Alexey Nikolaev, 2015.
          Modified by Subash Shankar on Oct 29, 2016.

  Description:
    The program read a PPM file from the standard input,
    and outputs a modified PPM file through the standard output.
  
*/


#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAXWIDTH = 512;
const int MAXHEIGHT = 512;
//task 1 - Write a main program that inputs t1 and t2 from the user, highlights the image, and then writes the image
void highlight(int image[MAXWIDTH][MAXHEIGHT],int width, int height, int t1, int t2) {
  for(int i = 0; i<width; i++)
    for(int j = 0; j<height; j++) {
      if (image[i][j] < t1) image[i][j] = 0;
      else if (image[i][j] > t2) image[i][j] = 255;
    }
}

//task3
void vedgeDet (int inputImage[MAXWIDTH][MAXHEIGHT], int outputImage[MAXWIDTH][MAXHEIGHT], int width, int height) {
  for (int i = 0; i < width; i++)
    for (int j = 0; j < height; j++) {
      outputImage[i][j] = (inputImage[i+1][j-1] + 2*inputImage[i+1][j] + inputImage[i+1][j+1]) - (inputImage[i-1][j-1] + inputImage[i-1][j] + inputImage[i-1][j+1]);
      if (outputImage[i][j] < 0) outputImage[i][j] = 0;
      else if (outputImage[i][j] > 255) outputImage[i][j] = 255;
    }
}

// reads a PPM file.
// Notice that: width and height are passed by reference!
void readImage(int image[MAXWIDTH][MAXHEIGHT], int &width, int &height) {
  char c;
  int x;
  ifstream instr;
  instr.open("city.pgm");
  
  // read the header P3
  instr >> c;  assert(c == 'P');
  instr >> c;  assert(c == '2');

  // skip the comments (if any)
  while ((instr>>ws).peek() == '#') { instr.ignore(4096, '\n'); }

  instr >> width; 
  instr >> height;

  assert(width <= MAXWIDTH);
  assert(height <= MAXHEIGHT);
  int max;
  instr >> max;
  assert(max == 255);

  for (int row = 0; row < height; row++) 
    for (int col = 0; col < width; col++) 
      instr >> image[col][row];
  instr.close();
  return;
}

void writeImage(int image[MAXWIDTH][MAXHEIGHT], int width, int height) {
  ofstream ostr;
  ostr.open("outImage.pgm");
  if (ostr.fail()) {
    cout << "Unable to write file\n";
    exit(1);
  };
  
  // print the header
  ostr << "P2" << endl;
  // width, height
  ostr << width << ' '; 
  ostr << height << endl;
  ostr << 255 << endl;

  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      assert(image[col][row] < 256);
      assert(image[col][row] >= 0);
      ostr << image[col][row] << ' ';
      // lines should be no longer than 70 characters
      if ((col+1)%16 == 0) ostr << endl;
    }
    ostr << endl;
  }
  ostr.close();
  return;
}

int main() {

  int inImage[MAXWIDTH][MAXHEIGHT];
  int outImage[MAXWIDTH][MAXHEIGHT];
    int imageWidth, imageHeight, threshold1, threshold2;
    cin >> threshold1 >> threshold2;
    void highlight(int image[MAXWIDTH][MAXHEIGHT],int width, int height, int t1, int t2) {


  readImage(inImage, imageWidth, imageHeight);
  highlight(inImage, imageWidth, imageHeight, threshold1, threshold2);
 /* for(int i = 0; i<imageWidth; i++)
    for(int j = 0; j<imageHeight; j++) {
	cout << inImage[i][j] << " ";} */
  
  // filter
  for(int i = 0; i<imageWidth; i++)
    for(int j = 0; j<imageHeight; j++) {
      outImage[i][j] = inImage[i][j];
    };
  writeImage(outImage, imageWidth, imageHeight);

}
