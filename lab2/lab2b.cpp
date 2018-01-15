/*
Name Roy Nunez
lab2
*/

/*Verhulst Formula*
p(n+1) = (1+g-h)*p(n) - g*p(n)*p(n)/M
p(n) = population at a particular year n 
g[p(n)] = additional animals in population
k=years of data 
g=population growth rate 
h=loss rate 
M=carrying capacity of animals
*/
#include <iostream>
using namespace std;

int main()
{
  double g;
  cout<<"Enter the population growth rate\n";
  cin>>g;
  g = g/100.00;
  double h;
  cout<<"Enter the population loss rate\n";
  cin>>h;
  h=h/100.00;
  double k;
  cout<<"Enter the years of data you wish to calculate for\n";
  cin>>k;
  double M =100;
  double pn=120;
  //  cout<<"Enter maximum capacity\n";
  //cin>>M;
  //  while(h > 21.00 || h > 99.00){
    double pop;
    //    int pn;
    int i;
    for (i=1; i<=k;i++)
      {    
	pop =(((1+(g-h))*pn)-g*(pn*pn)/M);        
	pn=pop;
	cout<<"Years: "<<i<<" Population: "<<(int)pop<<endl;
      }
   return 0;
    
   //}
}
