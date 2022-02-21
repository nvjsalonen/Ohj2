#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
bool avaaTiedosto(string tiedoston_nimi);
void tulostaPisteet(string tiedoston_nimi);
unsigned int stoi_with_check(const string& str);

int main()
{
        string luettavan_tiedoston_nimi;
        cout<<"Input file: ";
        cin>>luettavan_tiedoston_nimi;
        if(avaaTiedosto(luettavan_tiedoston_nimi))
        {
            tulostaPisteet(luettavan_tiedoston_nimi);
            EXIT_SUCCESS;
        }
        else{
            cout<<"Error! The file "<<luettavan_tiedoston_nimi<<" cannot be opened."<<endl;
            EXIT_FAILURE;
        }
}

bool avaaTiedosto(string tiedoston_nimi)
{
    ifstream pisteet(tiedoston_nimi);
    if(pisteet){
        return true;
    }
    else{
        return false;
    }
}

void tulostaPisteet(string input_tiedosto)
{
    string parit;
    map<string, int> taulukko;
    ifstream pisteet(input_tiedosto);
    while(getline(pisteet, parit))
    {
        string::size_type kohta = parit.find(":");
        string kilpailija = parit.substr(0, kohta);
        int kilpailijan_pisteet = stoi_with_check(( parit.substr(kohta+1)));
        if(taulukko.find(kilpailija) != taulukko.end())
        {
            taulukko.at(kilpailija) += kilpailijan_pisteet;
        }
        else{
        taulukko.insert({kilpailija, kilpailijan_pisteet} );
    }
    }
      for (auto& kilpailija : taulukko)
      {
          cout<<kilpailija.first<<": "<<kilpailija.second<<endl;
      }
}


unsigned int stoi_with_check(const string& str)
{
    bool is_numeric = true;
    for(unsigned int i = 0; i < str.length(); ++i)
    {
        if(not isdigit(str.at(i)))
        {
            is_numeric = false;
            break;
        }
    }
    if(is_numeric)
    {
        return stoi(str);
    }
    else
    {
        return 0;
    }
}
