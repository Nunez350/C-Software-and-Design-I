/*Author: Roy Nunez
Course: {135,136}
Instructor: 
Assignment: Shapes, Shpaes, Shapes, "Lab 3"
*/
#include <iostream>
#include <cmath> 
using namespace std;

int main() 
{  
  int w=0;  
  int h=0;  
  int width;
  int height; 
  int line_for_height=1; 
  cout<<"Please Enter a Width for Rectangular Frame (Must be 2 or Greater)"<<endl;
  cin  >> width;      
  cout << "Please Enter a Height for Rectangular Frame (Must be 2 or Greater)"<<endl;
  cin  >> height;
  if (width>2 && height>2)
    {      
      for (w = 0; w < width; ++w)    
    	{
	  cout<<"*";
	}
	  cout<<endl;

      for (int line_for_height =0; line_for_height < height -2; ++line_for_height)
	{
	  cout<<"*";
	}
      for (int i = 0; i< width -2; ++i)
	  {
	    cout<<" ";
	  }
	  cout<<"*";
	  cout<<endl;
	  for (w = 0; w < width; w++)
	    {
	      cout<<"*";
	    }
	  cout<<endl;
	  return 0;
    }
}
