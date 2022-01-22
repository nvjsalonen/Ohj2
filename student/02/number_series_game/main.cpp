#include <iostream>
using namespace std;


int main()
{
    int pelien_maara = 0;
    int luku = 1;
    cout << "How many numbers would you like to have? ";
    cin >> pelien_maara;
    while(luku <= pelien_maara)
        {
        if ((luku % 3 == 0) && (luku % 7 == 0))
        {
            cout << "zip"<< endl;
            cout <<"boing"<< endl;
            ++luku;
        }
        else if (luku % 7 == 0)
        {
            cout <<"boing"<< endl;
            ++luku;
        }
        else if(luku % 3 == 0)
        {
            cout <<"zip"<< endl;
            ++ luku;
        }
        else
        {
            cout << luku << endl;
            ++luku;
        }


    }
    return 0;
}
