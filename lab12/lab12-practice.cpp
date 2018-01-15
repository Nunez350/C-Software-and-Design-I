#include <iostream>
#include <iomanip>  //used for delimited cout statements

using namespace std;

const int MAXSIZE = 16;
static int values[MAXSIZE];
static int i; // bad idea too call a global variable i!
void initArray(int[], int);
void printArray(int[]);

// This initializes element arr[i] to val for each array element 
void initArray(int arr[], int val) {
  for (i=MAXSIZE; i >= 0; i--)
    arr[i] = val;
  return;
}





// This prints the contents of the argument array, with each element printed as "index: value" on its own line
// For example, a 4-element array containing {10,11,12,13} would print as:
//   0: 10
//   1: 11
//   2: 12
//   3: 13     

void printArray(int arr[]) { 
  for(int i=0; i<MAXSIZE; i++)
    cout << setw(2) <<i << ":" << setw(4) <<arr[i] <<endl;
};





int main() {
  int dummy;
  initArray(values,5);
  int *arr2 = values;
  values[0]=9;

  printArray(values);
  arr2[1]=8;
  printArray(arr2);

  return 0;
};
