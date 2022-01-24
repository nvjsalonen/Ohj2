#include <iostream>
#include <cctype>

using namespace std;
const int ASCII_MIN = 97;
const int ASCII_MAX = 122;

int main()
{
    string kryptaus (string avain, string teksti);
    bool tarkista_aakkoset (string teksti);
    bool tarkista_pienet (string teksti);
    string salausavain = " ";
    cout << "Enter the encryption key: ";
    cin>>salausavain;
    string::size_type pituus = 0;
    pituus = salausavain.length();
    // Tarkistetaan tässä pituus.
    if (pituus != 26)
    {
        cout<< "Error! The encryption key must contain 26 characters."<<endl;
        return 1;
    }
    bool totuusarvo = tarkista_pienet(salausavain);
    if (totuusarvo == false)
    {
        cout<<"Error! The encryption key must contain only lower case characters."<<endl;
        return 1;
    }
    bool anglikaaniset = tarkista_aakkoset(salausavain);
        if(anglikaaniset == false)
        {
            cout <<"Error! The encryption key must contain all alphabets a-z."<< endl;
            return 1;
        }
    string salattava_teksti;
    cout<<"Enter the text to be encrypted: ";
    cin >> salattava_teksti;
    bool salattavan_totuus = tarkista_pienet(salattava_teksti);
            if (salattavan_totuus == false)
    {
            cout<<"Error! The text to be encrypted must contain only lower case characters."<<endl;
            return 1;
    }
    cout<<kryptaus(salausavain, salattava_teksti)<<endl;


   return 0;
}

bool tarkista_pienet (string teksti)
{
    string::size_type pituus = 0;
    pituus = teksti.length();
    char merkki = ' ';
    for (unsigned long i = 0; i != pituus; ++i)
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
bool tarkista_aakkoset (string teksti)
{

    for( uint c = ASCII_MIN; c <= ASCII_MAX; c++)
    {
        if(teksti.find(c) == std::string::npos)
        {
            return false;
        }
    }
    return true;

}
string kryptaus (string avain, string teksti)
{
    for (uint i=0; i < teksti.length();i++)
    {
        char merkki_tekstissä = teksti.at(i);
        teksti.at(i) = avain.at(merkki_tekstissä - ASCII_MIN);
    }
    return teksti;
}
