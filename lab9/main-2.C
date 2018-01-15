/*Author: Roy Nunez
Course: {135,136}
Assignment: Header, Makefiles
Lab 8
This program prompts the user for a choice in shape and takes parameters if there is any needed and prints out corresponding shape using separate files for each shape printing function.
*/


#include <iostream>
#include "lab9.h"
using namespace std;


int main() 
{
  string input;
  //prompts user for choice
  do {
    cout <<"Please enter rec, x, or pix to pick the corresponding shape or enter q to quit" <<endl;
    cout <<"(rec = Rectangle)"<<endl;
    cout <<"(x = X Shape)"<<endl;
    cout <<"(pix = Pixel)"<<endl;
    cout<<endl;
    cin>>input;
    //if the input is rec then the user is prompted for width and height parameters and passes those as arguments and calls the drawRect function with them which is housed in another file
  if (input == "rec") {
    int width, height;
    cout<<"Please Enter a Width for Rectangular Frame (Must be 2 or Greater)"<<endl;
    cin  >> width;
    cout << "Please Enter a Height for Rectangular Frame (Must be 2 or Greater)"<<endl;
    cin  >> height;
    drawRect(width, height);
    //if the input is xc then the user is prompted for length parameters and passes that as an arguments and calls the drawX function with them which is housed in another file
  } else if (input =="x") {
    int length;
    cout << "Please Enter an Integer for a Length for your X-Shape (Must Greater than 0)"<<endl;
    cin  >> length;
    while (length<=0)
      { cout << "Please Enter an Integer for a Length for your X-Shape (Must Greater than 0)"<<endl;
	cin  >> length;
      }
    drawX(length);
  } else if (input == "pix") {//if the input is pix then the program calls the drawPix function which is housed in another file
    char c = '*';
    drawPix(c);
  } else {
    if (input != "q") { //if the input is not q or any of the aforementioned parameters, the program prints the follwing to the command line
    cout<<"This is not valid input!!!"<<endl<<endl;
    }
  }
  }while (input != "q");//if the input is q then the program exits
  return 0;
}


//  while(input != "rec" || input != "x" || input != "lowt" || input != "pix") {
//  cin>>input;
//}

