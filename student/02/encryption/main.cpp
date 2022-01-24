#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    bool tarkista_pienet (string teksti);
    string salausavain = " ";
    cout << "Enter the encryption key: ";
    cin>>salausavain;
    string::size_type pituus = 0;
    pituus = salausavain.length();
    if (pituus != 26)
    {
        cout<< "Error! The encryption key must contain 26 characters."<<endl;
        return 0;
    }
    bool totuusarvo;
    totuusarvo = tarkista_pienet(salausavain);
    if (totuusarvo == false)
    {
        cout<<"Error! The encryption key must contain only lower case characters."<<endl;
        return 0;
    }

   return 0;
}

bool tarkista_pienet (string teksti)
{
    char merkki = ' ';
    for (int i = 0; i != 26; ++i)
    {
        merkki = teksti.at(i);
        bool testi;
        testi = islower(merkki);
        if (testi == false)
        {
            return false;
            break;
        }

        }
    return true;

    }


