/*
  Author: Roy Nunez
  Course: {135,136}
  Instructor: Professor Samantha
  Assignment: Lab 5
*/
#include <iostream>
#include <math.h>
using namespace std;


int numDigits(int num); //Prototype of function to get of number of digits contained in the number
int getDigit(int num,int index);//Prototype of function to get index of number from right
int replaceDigit(int num, int olddigit, int newdigit);//Protoype of function that replaces a specified digit with desired digit
void replaceDigNew(int & num, int d, int dp);

int main()  {
  int num;
  int d;
  int dp;
  int index = 0;
  
  //int num, olddigit, newdigit;
   cout << "Enter an integer greater than 0"<< endl;
   cin >> num;
   if (num > 0){
   cout<< "Enter d"<<endl;
   cin >> d;
   }else { 
     while (num<=0) {
       cout <<"Invalid input please enter an integer greater than 0"<<endl; //prompt user for valid input
        cin >> num;
     } 
   }
   cout<< "Enter dp'"<<endl;
   cin>> dp;
   cout<<"Old Number - "<< num<<endl;
   replaceDigNew(num,d,dp);
   cout<<"New Number - "<<num<<endl;
   return 0;
}
   
int numDigits(int num) {  //Prototype of function to get length of number integer
  int length = 0;
  if (num == 0)
    length = 1;
     while (num != 0) { 
       num = num/10;
       length = length+1;
     }
     return length;
}


//generates number with index
int getDigit(int num, int index) { //Passing num and index arguments
  int index_spot = 1, place = 0;
  if (index <= numDigits(num)) {
    index_spot=pow(10,index);//recording position value
    place=num/index_spot;
    return place % 10;
  }else {
    cout<<"not working"<<endl;
    return -1;
  }
}



void replaceDigNew(int & num, int d, int dp) {//Function replaces a specified digit within valid input with a desired digit and generates a new number. Uses pass by reference changing old number.
  int placecounter = 0;
  int newNum = 0, digit;
   int nomatch=0; 
    for (int i=0; i < numDigits(num); i++) {
	 if (d!=getDigit(num, i)) {
	   nomatch++;
	 }
    }	 
    if (nomatch==numDigits(num)) {
      cout<<"Illegal input. d entered cannot be found in num. Please try again and enter a valid d!"<<endl;
    }
    for (int i = 0; i < numDigits(num); i++) {//iterates through each element as long as it is smaller than length
      if (getDigit(num, i) == d) {//if the iterative element equals to d
	digit = dp;//will replace digit with dprime
      } else {
	digit = getDigit(num,i); //otherwise it will return the orginal digit
      }
      newNum+=digit*pow(10,i);    //generates that digits index
    }
  num = newNum;
}







/*
//generates number with index
int getDigit(int num, int index) //Passing num and index arguments
{
  int temp = 0; //counter, being used to serve as a reference
  int len = numDigits(num); //storing length
  int neworder = len - index + 1;//reverse position and store 
  while( num != 0 )// while number is not equal to 0
    {
      int digit = num % 10;//returns the number
      temp++;//taking stock of each iteration
      if( int  == temp )//while under this while loops condition met, each iteration in this if loop equals previous order(neworder)
	return digit;
      num = num/10;
    }
  return -1;
}
*/


/*
int replaceDigit(int num, int d, int dp) {//Protoype of function that replaces a specified digit with desired digit
  int placecounter = 0;
  int newNum = 0, digit;
  for (int i = 0; i < numDigits(num); i++) {
    if (getDigit(num, i) == d) {
      digit = dp;
    } else {
      digit = getDigit(num,i);
    }
      newNum+=digit*pow(10,i);    
  }
  return newNum;
}
*/

/*
int getDigit(int num, int i) {  
  int index_spot;
  int place;
  for (int j; j <= numDigits(num); j++) {
  if (num == 6) {
    index_spot=pow(10,i);
    place=num/index_spot;
    //    cout<<place<<endl; 
    return (num/(int)pow(10,i)%10);
//  }else {
    // return -1;  
   }
 }
   return 0;
}
  

//int spot = 0;
//int numa;
  
  
//  if (numa==num) {
//    index=i;
    // }
//}
// 
      //    return place % 10;
//}



*/



