#include <iostream>
#include <cmath>
#include "lab9.h"
using namespace std;
void drawRect(int width, int height) {  
  int w=0;  
  int h=0;  
  int line_for_height=1; 

  if (width>2 && height>2)
    {      
      for (w = 0; w < width; ++w)    
    	{
	  cout<<'*';
	}
      cout<<endl;
      
      for (int line_for_height =0; line_for_height < height -2; ++line_for_height)
	{
	  cout<<"*";
	  for (int i = 0; i< width -2; ++i)
	    {
	      cout<<" ";
	    }
	  cout<<"*";
	  cout<<endl;
	}
      
	  for (w = 0; w < width; w++)
	    {
	      cout<<"*";
	    }
	  cout<<endl;
    }
}
