/*
Author: Roy Nunez
Course: {135/136}
Assignment: Lab 12

This program creates two arrays with 16 elements each or MAXSIZE. The values in each array are updated 
using the first and second command line argument respectivetively, and updates the first element in the 
first array with the value 9 and the second element in the array with the value 8.
There was a problem with the second array print out because it was not truly copied, only the address was at arr2.
As a result the first element at 0 index had a value of 9, which is representative of the first array print out, since in essence it was the same array. To circumvent this 
problem I passed the array to the initArray function which copied the array. 
*/

#include <iostream>
#include <iomanip>  //used for delimited cout statements
#include <stdlib.h>
#include <typeinfo>
using namespace std;

const int MAXSIZE = 16;
static int values[MAXSIZE];
static int i; // bad idea too call a global variable i!
static int arr2[MAXSIZE];//declared my second array globally
void initArray(int[], int);
void printArray(int[]);

// This initializes element arr[i] to val for each array element 
void initArray(int arr[], int val){
  for (i=MAXSIZE; i >= 0; i--)
    arr[i] = val;
  return;
}
// This prints the contents of the argument array, with each element printed as "index: value" on its own line
// For example, a 4-element array containing {10,11,12,13} would print as:
//  0: 10
//   1: 11
//   2: 12
 // ``3: 13     

void printArray(int arr[]) {
  for(int i=0; i<MAXSIZE; i++)
    cout << setw(2) <<i << ":" << setw(4) <<arr[i] <<endl;
 };


  int main(int argc, char * argv[]) {
    int  arg1 = atoi(argv[1]); //saved first command line argument
    int  arg2 = atoi(argv[2]);//saved second command line argument
    int dummy;//still a dummy
  initArray(values,arg1);
  initArray(arr2,arg2);//passed arr2 to initArray and updated each element in it to arg2, which comes from the command line
  arr2[1]=8;//assigns/updates first element in new array with the number 8  
  values[0]=9;  //assigns/updates zero element in new array with the number 9
  cout<<"The first array:"<<endl;    
  printArray(values);
  cout<<"\n";
  cout<<"The second array:"<<endl;
  printArray(arr2);
  cout<<"\n";
  cout<< "The size of values the first array is "<<sizeof(values)/sizeof(values[0]) <<endl; //printed out array sizes to ensure quality
  cout<< "The size of arr2 the second array is "<<sizeof(arr2)/sizeof(arr2[0]) <<endl;

  return 0;
};


//one
















  //  arr2[1]=88;
  //values[0] =4   ;
  //copyArray(values);

  ///  copyArray(fun);
  /*
  for (int i = 0; i <MAXSIZE; i++) {
    cout<< "original_values_main  "<<values[i]<<endl;
  }

  
  for (int i = 0; i <MAXSIZE; i++) {
    cout<< "pointer *arr2   "<<*arr2<<endl;
  }

  copyArray(values);


    //    temp[count]=arr[MAXSIZE];// as we loop through each iteration we assign it to element in an array
    //    arr3[count]=values[count];


  */
