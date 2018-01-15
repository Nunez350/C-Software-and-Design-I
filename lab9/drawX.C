#include <iostream>
#include <cmath> 
#include "lab9.h"
using namespace std;

void drawX(int length) {  
  int l=1;
  int h=1;
  int height; 
  int s1=1,s2;
  s2=length;   
  height = length;
  while (h<=height) 
    {    

      for(l=1; l<=length; l++)
	{
	  if (l==s1 or l==s2)  
	    {cout<<"*";
	    } 
	  else 
	    {cout<<" ";
	    }  
	}
      cout<<endl;
      s1=s1+1;
      s2=s2-1;
      l=1; // does this reset l to 1?

      h=h+1;  
    }

}
