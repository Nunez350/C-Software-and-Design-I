
/*
Author: Roy Nunez
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>  //used for delimited cout statements
using namespace std;




//atoi(argv[1])

const int MAXSIZE = 16;
static int values[MAXSIZE];
static int i; // bad idea too call a global variable i!
static int arr3[MAXSIZE];
void initArray(int[], int);
void printArray(int[]);
void copyArray(int []); //this function copies an array that's passed and assigns the number 8 to the second element in that array and iteratively prints out content in a column 

// This initializes element arr[i] to val for each array element 
void initArray(int arr[], int val){
  for (i=MAXSIZE; i >= 0; i--)
    arr[i] = val;
  return;
}

void printArray(int arr[]) {
  for(int i=0; i<MAXSIZE; i++)
    cout << setw(2) <<i << ":" << setw(4) <<arr[i] <<endl;
 };


int main() {
  
  initArray(values,5);
  int *arr2 = values;
  int dummy = *arr2;
  //  dummy=arr2;
  values[0]=9;    
  arr2[1] = 8;
  //  copyArray(arr2);//copies arr2 into arr3
  printArray(values);
  cout<< sizeof(values)/sizeof(values[0]) <<endl;
  cout<<"first out\n"<<endl;    
  //printArray(dummy);
  //cout<< sizeof(dummy)/sizeof(dummy[0]) <<endl;
  cout<<"second out\n"<<endl;    
  printArray(arr2);
  cout<< sizeof(arr2)/sizeof(arr2[0]) <<endl;
  cout<<"third out\n"<<endl;    
;

  //  printArray(arr2);

  //  printArray(arr3);
  cout<<"please"<<endl;

  return 0;
};

















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
