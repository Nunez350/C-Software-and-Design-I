/*
Author: Roy Nunez
Course: \{135,136}
Instructor: Priyanka Samanta
Assignment: Lab 1
*/

#include <ctime>
#include <iostream>
using namespace std;

int main() {
    time_t t;
    struct tm *now;
    t = time(0);             // get current time
    now = localtime(&t);     // adjust for local timezone
    int hour_input=-1;         // retrieve hour input from user
    int minute_input=-1;     // retrieve minute input from user
    int hour = now->tm_hour; // retrieve current hour
    int min = now->tm_min;   // retrieve current min

    while(hour_input<1 or hour_input>24)
        {
            cout<<"Enter the hours part of today's sunset time (1-24)"<<endl;
            cin >>hour_input;
        }

    while(minute_input<1 or minute_input>59)
        {
            cout<<"Enter the minutes part of today's sunset time (1-59)"<<endl;
            cin >>minute_input;
        }

    if (hour>=1 and hour<12)
        {
            cout<<"Good Morning Professor Samanta"<<endl;
                            }

  if (12<=hour and hour<18)
    {
        cout<<"Good Afternoon Professor Samanta"<<endl;
    }

  if (hour>=18 and hour<24)
    {cout<<"Good Evening Professor Samanta"<<endl;}

    return 0;
  int home_minutes=-1;
    int how_long=home_minutes+hour;
    while(minute_input>1 or minute_input<60)
      {
        cout<<"How many minutes from now do you expect to be home?"<<endl;
        cin>>home_minutes;
        cout<<"You will get home at: " << hour_input << ":" << home_minutes+minute_input<<endl; //how_long<<endl;
        cout<<"You will get home at: " << hour<<end; //<< ":" << minutes<<endl;
how_long<<endl;

        return 0;
}
}
}