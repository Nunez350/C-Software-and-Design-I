
/*


Input a character from the user, and then additional parameters depending on the shape (e.g., the width and height). If the user inputs an illegal character, output an error message and retry.

3    Call the appropriate functon
  4    Goto 1. Of course, you're not allowed to use the goto construct, so you should formulate this as a loop.
  Do not include prototypes for called functions in this file (see next step). 
need to specify prototypes for the draw functions in main; however, in general you may need to specify the prototype for some function in multiple other functions/files. Rather than typing the prototype of a function in each of the function's callers, it is better to specify prototypes common to your project in a header (.h) file. To do this, create a file called lab9.h containing prototypes for all common functions. You will need to specify an extern storage class since these are defined in other files. For example, one line might be:
extern void drawRectFrame(int width, int height);
Note that the "extern" is not needed strictly speaking, since that is the default storage class for function prototypes. However,  most consider it good style to explicitly mention. 

Since main uses the prototypes in this file, you will also need to have the following at the top of each source file that uses one of these:
#include "lab9.h"



*/


#include <iostream>
#include <cmath> 
#include <string>
#include "lab9.h"
using namespace std;


int main() 
{
  //  char quit = 'q';
  string user_input;
  string rec,x,lowt,uppt,cir;
  do {
  cout <<" Please pick a shape " <<endl;
  cout <<"(rec = Rectangle)"<<endl;
  cout <<"(x = X Shape)"<<endl;
  cout <<"(lowt = Lower Triangular Part of Square)"<<endl;
  cout <<"(uppt = Upper Triangular Part of Square)"<<endl;
  cout <<"(cir = Circle)"<<endl;
  cin>>user_input;
  } while(user_input =="rec" or user_input=="x"); 
  //  }while(user_input != "q"); 
  



  if (user_input == "rec") {
    cout<<user_input<<"1"<<endl;
  } else if (user_input =="x") {
    cout<<user_input<<"2"<<endl;
  } else if (user_input == "lowt") {
    cout<<user_input<<"3"<<endl;
  } else if (user_input == "uppt") {
    cout<<user_input<<endl;
  } else if (user_input == "cir") {
    cout<<user_input<<endl;
  } else {
    cout<<"no way"<<endl;
  }
  return 0;
}



