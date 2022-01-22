#include <iostream>
using namespace std;


int main()
{
    int pelien_maara = 0;
    int luku = 1;
    string jaolliset = "zip";
    cout << "How many numbers would you like to have? ";
    cin >> pelien_maara;
    while(luku <= pelien_maara)
        {
        cout << luku << endl;
        ++luku;
        if ((luku % 3) == 0)
        {
            cout << "zip"<< endl;
            ++luku;
        }

    }
    return 0;
}
