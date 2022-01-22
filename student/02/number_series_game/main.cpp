#include <iostream>
using namespace std;


int main()
{
    int pelien_maara = 0;
    cout << "How many numbers would you like to have? ";
    cin >> pelien_maara;
    for (int luku = 1; luku <= pelien_maara; ++luku)
        {
        cout << luku << endl;
        }

    return 0;
}
