
#include <iostream>
using namespace std;

int power (int a, int b)
{
    int p = 1;
    if  (b == 0)
    {
        p = 1;
    }
        else
        {
            for (int i = 1; i <=b; i++)
            {
                p = p * a;
            }
        }
    return p;
}

int replaceDig (int num, int oldDigit, int newDigit)
{
    int rem, newnum = 0, i = 0;
    
    while (num != 0)
    {
        rem = num % 10;
        cout <<" rem " << rem <<endl;
        
    if (rem==oldDigit)
    {
        rem = newDigit;
    }
        cout << " power = "<<power (10,i)<<endl;
        
    newnum = rem * power(10, i)+newnum;
        cout<< " num = " <<num<<endl;
        
    num = num/10;
        cout << "num "<< num << endl;
            i= i+1;
    }
    cout << i << " end " <<endl;
    return newnum;
}

//Task 1:
int main ()
{
    
    int num, oldDigit, newDigit;
    
    cout << "Please enter a number: ";
    cin >> num;
    
    cout << "Please enter any single digit you would like to replace: ";
    cin >> oldDigit;
        while ((oldDigit<0) || (10<=oldDigit)) {
            cout<< "Please enter a positive single digit: ";
            cin >>oldDigit;
        }
    
    cout<< "Please enter any single digit with the number you'd to replace the old digit with: ";
    cin>> newDigit;
        while ((newDigit<0) || (10<=newDigit)) {
            cout<< "Please enter a positive single digit: ";
            cin >>newDigit;
        }
    
    cout << "The new replaced digit number is: " << replaceDig(num, oldDigit, newDigit)<<endl;
    return  0;

}
