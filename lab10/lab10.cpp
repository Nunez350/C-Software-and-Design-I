/* Author: Roy Nunez
 

This program keeps track of population information about the countries of the world. The program reads a file in and stores each element on each line into a Struct. The top three global populations with the larget population growth rates are computed and stored using for loops and then printed out. In task 2 the growth rate is computed for each one, and the negative populated growth rates from years 1950 to 2015 are printed out.
*/


#include <iostream>
#include <fstream>
#include "lab10.h"

using namespace std;

int main() {
//task 0   

  World myWorld;
  ifstream fin("population.csv");  //created an ifstream called fin and also used fin to open csv
  double p1, p2, p3, p4, p5;  //fin stream will store in these objects
  string tempCountryName;   //getline to extract these objects/arguments
  string countryName="";   //used as the final countryName object without the preceding blank space
  int countryCount=0;         //counts number of rows/ countries
  int i=0;                    //iterator for max number 

  while(!fin.eof()) {    //this while loop will go through data from file and assign data to variable i.e. p1 (aka column 1) to element countries pop 1950 in myWorld structure object
    fin>>p1>>p2>>p3>>p4>>p5;
    getline(fin, tempCountryName);
    tempCountryName=tempCountryName.substr(1);
    Country country;
    country.pop1950=p1; 
    country.pop1970=p2; //..
    country.pop1990=p3;
    country.pop2010=p4;
    country.pop2015=p5;
    country.name=tempCountryName;  
    myWorld.countries[i] = country;
    i++;
    countryCount++;  //counts number of countries
  }

  //task 1
  double max1 = 0;//intializing variables that will be used to compute max growth rates and the respective index positions
  double max2 = 0;
  double max3 = 0;
  int maxCountryIndex;
  int maxCountryIndex2;
  int maxCountryIndex3;
  for ( int m =0 ; m< i; m++) {//this for loop computes the growth rate for each population and stores the largest as max1
    double currRatio = (double)((myWorld.countries[m].pop2015-myWorld.countries[m].pop1950)/myWorld.countries[m].pop1950)*100;
      if (currRatio > max1) {
	  max1= currRatio;
	  maxCountryIndex = m;
	}
    }

  for ( int m2 =0 ; m2< i; m2++) {//this for loop computes the growth rate for each population and stores the second largest as max2
      double currRatio2 = (double)((myWorld.countries[m2].pop2015-myWorld.countries[m2].pop1950)/myWorld.countries[m2].pop1950)*100;
      if ((m2 != maxCountryIndex) && (currRatio2 >max2)) {
	  max2= currRatio2;
	  maxCountryIndex2 = m2;
	}
    }

  for ( int m3 =0 ; m3< i; m3++) {//this for loop computes the growth rate for each population and stores the third largest as max1
    double currRatio3 = (double)((myWorld.countries[m3].pop2015-myWorld.countries[m3].pop1950)/myWorld.countries[m3].pop1950)*100;
      if ((m3 != maxCountryIndex) && (m3 != maxCountryIndex2) && (currRatio3 >max3)) {
	  max3= currRatio3;
	  maxCountryIndex3 = m3;
	}
    }


  cout<< "The fastest growing country is "<< myWorld.countries[maxCountryIndex].name<<", which grew by " <<max1<<"% between 1950 and 2015."<<  endl;
  cout<< "The second fastest growing country is "<< myWorld.countries[maxCountryIndex2].name<<", which grew by " <<max2<<"% between 1950 and 2015."<<  endl;
  cout<< "The third fastest growing country is "<< myWorld.countries[maxCountryIndex3].name<<", which grew by " <<max3<<"% between 1950 and 2015."<<  endl;
  
  cout<<endl;
  cout<<"The following countries shrunk between 1950 and 2015:"<<endl;


  //task 2
  //this for loop calculates the growth rate for each country and stores it in object structure Country under variable growth
  for (int g =0; g<i; g++) {
    Country growth;
    myWorld.countries[g].growth=(double)((myWorld.countries[g].pop2015-myWorld.countries[g].pop1950)/myWorld.countries[g].pop1950)*100;
    //    cout<<myWorld.countries[g].growth<<"\t"<<myWorld.countries[g].name<<endl;
  }
  //using the population growth any value below 1 is identified as a decrease in population rate and printed out  
  int count =1;
  for (int s =0; s<i;s++) {
    double currRatios = myWorld.countries[s].growth;
    if ((currRatios <1)) {
      cout<<"country "<< count<<" "<<myWorld.countries[s].name<<endl;
      count++;
    }
  }
return 0;
}

