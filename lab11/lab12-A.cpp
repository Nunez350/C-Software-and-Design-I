/*
Roy Nunez

Task 1:

You wish to create an array of all countries with a population between m and n (as of 2015), where m and n are numbers input from the user. Since you don't know how many countries this will result in, you will need to make this a dynamic array (lists or vectors would work too, but thats not the point of this lab).

Write a function that has as arguments m, n, and the list, and returns the array. The function should traverse the list to create an array of all countries that have 2015 populations between m and n inclusive. A 2-pass algorithm might be the simplest solution (1 pass to find the size, and 1 to populate the array). Finally, the function should print the resulting list of countries.

Also write a driver main program that prompts the user for m and n and then calls the function. Make sure your code is written to avoid memory leaks (i.e., delete any heap data).
*/




#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct CountryData {
  string name;
  double pop1950;
  double pop1970;
  double pop1990;
  double pop2010;
  double pop2015;
};

struct Node {
  CountryData country;
  Node *      next;
};

void print(Node* headp) {
    Node* temp = headp;
   while(temp != NULL) {
       cout<<temp->country.name<<"\n";
       temp=temp->next;
    }
}

int count1(Node* headp,int m, int n) {
  Node* temp = headp;
    int ct=0;
    while(temp != NULL) {
       if (temp->country.pop2015 >=m && temp->country.pop2015 <=n) {
          ct++; }
       temp=temp->next;
    }
    return ct;
}

//CountryData*
CountryData* function1(Node* headp ,int m, int n) {
  int ct = count1(headp,m,n);
  CountryData* arr = new CountryData[ct];
  Node * temp = headp;
  int i=0;

    while(temp != NULL) {
      //cout << temp -> country.pop2015 << endl;
       if(temp->country.pop2015 >=m && temp->country.pop2015 <=n) {
            //cout<<temp->country.name;
            arr[i].name = temp->country.name;
            arr[i].pop1950 = temp->country.pop1950;
            arr[i].pop1970 = temp->country.pop1970;
            arr[i].pop1990 = temp->country.pop1990;
            arr[i].pop2010 = temp->country.pop2010;
            arr[i].pop2015 = temp->country.pop2015;
            i++;
        }
       temp=temp->next;
    }
    cout<<"\nResulting countries with pop2015 between "<<m<<" and "<<n<<" are : \n";
    for(int i=0;i<ct;i++) {
       cout<<arr[i].name<<"\n";
    }

    return arr;
}

int main() {
  Node * headp = NULL ;
  Node * tailp = NULL;

  ifstream fin("population.csv");
  double p1, p2, p3, p4, p5;
  string tempCountryName;
  string countryName="";
  int countryCount=0;
  int i=0;

  while(!fin.eof()) {
      fin>>p1>>p2>>p3>>p4>>p5;
      getline(fin, tempCountryName);

        for(int d=1; d<tempCountryName.length();d++) {
          countryName=countryName+tempCountryName[d];
         }

      if(headp == NULL) {
	  tailp = new Node;
	  headp = tailp;
	  tailp->country.name = countryName; //name of country
	  tailp->country.pop1950 = p1;
      tailp->country.pop1970 = p2;
      tailp->country.pop1990 = p3;
      tailp->country.pop2010 = p4;
      tailp->country.pop2015 = p5; //current population i.e. 2005
	  tailp->next = NULL;
	}
      else
	{
	  tailp = new Node;
	  tailp->country.name = countryName; //name of country
	  tailp->country.pop1950 = p1;
      tailp->country.pop1970 = p2;
      tailp->country.pop1990 = p3;
      tailp->country.pop2010 = p4;
      tailp->country.pop2015 = p5; //current population i.e. 2005
	  tailp->next = headp;
	  headp = tailp;
	}
	countryName="";
  }
   //print(headp);
  int m,n;
  cout<<"Enter m : "; cin>>m;
  cout<<"Enter n : "; cin>>n;
  int ct = count1(headp,m,n);
  CountryData* array1 = function1(headp,m,n);

}
