#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAXWIDTH = 512;
const int MAXHEIGHT = 512;

int inImage[MAXWIDTH][MAXHEIGHT];
int outImage[MAXWIDTH][MAXHEIGHT];

int imageWidth, imageHeight;

// reads a PPM file.
// Notice that: width and height are passed by reference!

void readImage(int image[MAXWIDTH][MAXHEIGHT], int &width, int &height) {
  // cout << " 2"<<endl;
  char c;
  int x;
  ifstream instr;
  // cout << " 2"<<endl;
  instr.open("city.pgm");
  // cout << " 3"<<endl;

  // read the header P3
  instr >> c; assert(c == 'P');
  instr >> c; assert(c == '2');

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
void interpolate(int i, int j)
{
  //int i,j;
  int sum=0,counti=0,avg;

  sum += inImage[i][j];
  counti++;

  if(j+1 < imageHeight-1)
    {
      sum += inImage[i][j+1];
      counti++;
    }
  if(j>0)
    {
      sum += inImage[i][j-1];
      counti++;
    }

  if(i-1 > 0)
    {
      sum += inImage[i-1][j];
      counti++;
      if(j+1 < imageHeight-1)
	{
	  sum += inImage[i-1][j+1];
	  counti++;
	}
      if(j>0)
	{
	  sum += inImage[i-1][j-1];
	  counti++;
	}

    }
  if(i+1 < imageWidth-1)
    {
      sum += inImage[i-1][j];
      counti++;
      if(j+1 < imageHeight-1)
	{
	  sum += inImage[i+1][j+1];
	  counti++;
	}
      if(j>0)
	{
	  sum += inImage[i+1][j-1];
	  counti++;
	}
    }

  avg = sum/counti;
  outImage[i][j] = avg;
  return;

}

int main() {

  readImage(inImage, imageWidth, imageHeight);

  /* for(int i = 0; i<imageWidth; i++)
for(int j = 0; j<imageHeight; j++) {
cout << inImage[i][j] << " ";}*/

  //int n;
  cout << "Hurray...No input needed this time.... :P"<<endl;
  //cin >> n;
  for(int i = 0; i<imageWidth; i++)
    for(int j = 0; j<imageHeight; j++) {
      interpolate(i,j);

    }

  writeImage(outImage, imageWidth, imageHeight);
  return 0;

}
