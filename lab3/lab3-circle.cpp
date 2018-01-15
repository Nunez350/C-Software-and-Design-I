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
  int rad; 
  int h; 
  int x; 
  int index;
  int d;    
  cout << "Please Enter an Integer for a rad of the circle (Must Greater than 0)"<<endl;
  cin  >> rad;
  while (rad<=0)
    { cout << "Please Enter an Integer for a rad of the circle (Must Greater than 0)"<<endl;
      cin  >> rad;
    }
  d=2*rad; 
  h=rad;
  while (h>0) 
    {
      x=sqrt(rad*rad-h*h);
      index = rad - x;
      for (int w=0; w<=2*rad; w++)    
	{
	  if (w==index or w==(d-index))
	    {
	      cout<<"*";
	    }
	  {
	    cout<<"  ";
	  }
	}
      cout<<endl;
      h=h-1;
    }
  h=1;
  while (h<=rad) 
    {
      x=sqrt(rad*rad-h*h);
      index = rad - x;
      for (int w=0; w<=2*rad; w++)   
	{
	  if (w==index or w==(d-index))
	    {
	      cout<<"*";
	    }
	  {
	    cout<<"  ";
	  }
	}
      cout<<endl;
      h=h+1;
    }
}

