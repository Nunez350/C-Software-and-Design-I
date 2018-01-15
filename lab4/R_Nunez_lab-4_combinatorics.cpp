/*
  Author: Roy Nunez
  Course: {135,136}
  Instructor: Professor Samantha
  Assignment: Lab 4 
  */
#include <iostream>
using namespace std;

int main() {
  int nfac = 1;
  int kfac = 1;
  int n = 0;
  int k = 0;
  int zfac = 1;

  do{
    cout << "Enter a number for n greater than 0: " << endl;
    cin >> n;
  } while(n<0);


  do{
    cout << "Enter a number for k that is smaller than n: " << endl;
    cin >> k;
  } while( (k > n) && (k < 0) );

  //using method 1 to calculate C(n,k)

  for(int i = 1; i <= n; i++)
    {
      nfac = nfac*i;
    }

  for(int i = 1; i <= k; i++)
    {
      kfac = kfac*i;
    }

  for(int i = 1; i <= (n-k); i++)
    {
      zfac = zfac*i;
    }

  cout << "Method 1 : " << endl;
  cout << "n! = " << nfac << " k! =  " << kfac   << "  (n-k)! = " << zfac << endl;
  cout << "C(n,k) is = " << ((nfac)/((zfac)*(kfac))) << endl;

  //using method 2 to calculate C(n,k)
  //2.    C(n,k) can be rewritten as n(n-1)(n-2)...(n-k+1)/k!.

  int n_kfac = 1;
  kfac = 1;
  for(int i = n; i >= n-k+1; i--)
    {
      n_kfac = n_kfac*i;
    }

  for(int i = 1; i <= k; i++)
    {
      kfac = kfac*i;
    }
  //  cout << "n! = " << nfac << endl;

  cout << "Method 2 : " << endl;
  cout  << "k! =  " << kfac   << "  (n-k + 1)! = " << n_kfac << endl;
  cout << "C(n,k) is = " << ((n_kfac)/(kfac)) << endl;

  double ans = 1.0;
  double diff = n-k;

  for(int i = 1; i <=k ; i++)
    {
      double t = 1.0 + (diff/(double)i );
      ans = ans * t;
    }

  cout << "Method 3 : " << endl;
  cout << "C(n,k) is = " << (ans) << endl;

  int ans1 = 1;
  int counter = 1;

  while( counter <= k )
    {
      ans1 = ans1 * n;
      while(  counter <= k && ans1 % counter == 0 )
	{
	  ans1 = ans1/counter;
	  counter++;
	}
      n--;
    }

  ans1 = ans1 * n;
  cout << "Method 4 : " << endl;
  cout << "C(n,k) is = " << (ans) << endl;
}
// TASK 1.
// Computes C(n,k) directly by computing the 3 factorials (representing variables as LONG).
// Largest value of n for which C(n,n-1) returns a correct result is n=20. n=21 CRASHES
//NOT ENOUGH BITS TO REPRESENT for C(21,20)
//The code will loop through all the values, however once there is overflow, my
// program will produce a -1 as output and cause my program to crash
// that is why I am commenting this out, because I want the rest of my program to compile.

/*C(n,k) can be rewritten as n(n-1)(n-2)...(n-k+1)/k!. Implement program that computes
C(n,k) based on this formula. Repeat the questions from above. This program is
better than #1 since it works on more input values. More efficient than #1 because
iterations are FROM n-k+1 to n , rather than FULL iterations
The appropriate measure of efficiency here would be the number of multiplies. */

// Iterate from n-k+1 to n
// First calculate numerator for Task 2  n(n-1)(n-2)..(n-k+1)

//TASK 2.
/*C(n,k) can be rewritten as n(n-1)(n-2)...(n-k+1)/k!. Implement program that computes
C(n,k) based on this formula. Repeat the questions from above. This program is
better than #1 since it works on more input values. More efficient than #1 because
iterations are FROM n-k+1 to n , rather than FULL iterations
The appropriate measure of efficiency here would be the number of multiplies. */

// Iterate from n-k+1 to n
// First calculate numerator for Task 2  n(n-1)(n-2)..(n-k+1)

//TASK 3
//(P2)  C(n,k) = C(n,n-k)
//Use property (P2) to make your solution to 2 more efficient.
//e.g.  C(5,3) = C(5,2)
// this property is only worth it if k is less than half n

//TASK 4
// C(n,k) can be expressed as the product (1+(n-k)/1) (1+(n-k)/2) (1+(n-k)/3) ... (1+(n-k)/k).
// This program will handle much larger values of n and k now.
// Warning: a naive implementation that ignores the type casting needed to convert
// between ints and intermediate data types will result in incorrect results -
// you can compare the results from programs 1-3 and this.


