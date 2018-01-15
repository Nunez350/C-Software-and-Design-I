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
  int l=1;
  int h=1;
  int length;
  int height;
  int s1=1;  

        
  cout << "Please Enter an Integer for a Length for the Upper Triangular Part of Square (Must Greater than 0)"<<endl;
  cin  >> length;
        
  while (length<=0)
    { cout << "Please Enter an Integer for a Length for the Upper Triangular Part of Square (Must Greater than 0)"<<endl;
      cin  >> length;
    }

  height = length;

  while (h<=height) 
    {    

      for(l=1; l<=length; l++)   
	{
	  if (l<s1)      
	    {cout<<" ";
	    } 
	  else 
	    {cout<<"*";
	    }  
	}
      cout<<endl;
      s1=s1+1;
      l=1;

      h=h+1;
    }

}


