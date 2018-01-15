/*
Author: Roy Nunez

*/

#include <iostream>
#include <iomanip>  //used for delimited cout statements
#include <stdlib.h>
using namespace std;

const int MAXSIZE = 16;
static int values =MAXSIZE;
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


void copyArray(int arr[]) {
  int temp[MAXSIZE];
  int count = 0;
  for (int i=0; i < MAXSIZE; i++) {
    arr3[i]=arr[i];//iteratively copies passed array
    arr3[1]=8;//assigns/updates first element in new array with the number 8
    //      cout << setw(2) <<i << ":" << setw(4) <<arr[i] <<endl;
  }
}

//int main() {
  int main(int argc, char * argv[]) {
    int  arg1 = atoi(argv[1]);
    int  arg2 = atoi(argv[2]);

  int dummy;
  initArray(values,arg2);
  int *arr2 = values;
  copyArray(arr2);//copies arr2 into arr3
  values[0]=9;  
  printArray(values);
  cout<<"first out\n"<<endl;    

  //  arr2[1] = 8;
  //  printArray(arr2);

  printArray(arr3);
  cout<<"please"<<endl;
  cout<< "size of values"<<sizeof(values)/sizeof(values[0]) <<endl;
  cout<< "size of arr2"<<sizeof(arr2)/sizeof(arr2[0]) <<endl;
  cout<< "size of arr3"<<sizeof(arr3)/sizeof(arr3[0]) <<endl;
  cout<< "first arg "<<typeid(arg1)<<endl;
  cout<< "TWO arg "<<arg2<<endl;


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
