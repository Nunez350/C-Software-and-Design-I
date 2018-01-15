#include <string>
using namespace std;

const int MAXCOUNTRIES=240; //array sizes in structures MUST be declared constant

struct Country {//declaring struct object Country which will contain variables namely, population number in each year listed, country's name and  population growth rate, respectively
  string name;
  double pop1950;
  double pop1970;
  double pop1990;
  double pop2010;
  double pop2015;
  string countryName;
  double growth;

};


struct World {//this struct object will store the number of countries computed and set our max parameters when computing variables e.g. the struct Country
  int     numCountries;
  Country countries[MAXCOUNTRIES];
};

