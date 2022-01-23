#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int number = 0;
    cout << "Enter a number: ";
    cin >>number;
    int check = 0;
    int cubed = pow (number, 3) ;
    check = cbrt(cubed);
    if (check != number)
       {
        cout << "Error! The cube of "<< number<< " is not "<<cubed<<  endl;
        return 0;
    }
    cout << "The cube of "<< number << " is "<< cubed<< endl;

    }


