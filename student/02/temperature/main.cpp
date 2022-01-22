#include <iostream>

using namespace std;

int main()
{
    double temperature = 0;
    cout << "Enter a temperature: ";
    cin >> temperature;
    cout << temperature << " degrees Celsius is " << temperature * 1.8 + 32 << " degrees Fahrenheit" << endl;

    return temperature;
}
