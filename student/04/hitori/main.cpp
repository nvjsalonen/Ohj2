#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cstdlib>

using namespace std;
const unsigned int BOARD_SIZE = 25;
const unsigned int BOARD_SIDE = 5;
const unsigned char EMPTY = ' ';
unsigned int stoi_with_check(const string& str);
vector<vector<string>> syotaKentta();
vector<vector<string>> satunnainenKentta()
{
    default_random_engine rand_gen;
    string numero;
    vector<vector<string>> kentta;
    vector<string> jono;
    int seed_value = 0;

    cout<<"Enter seed value: ";
    cin>>seed_value;
    rand_gen.seed(seed_value);
    uniform_int_distribution<int> distribution(1, 9);
    for(unsigned int i =0; i < BOARD_SIZE;i++)
    {
        if(jono.size()< BOARD_SIDE)
        {
           numero = distribution(rand_gen);
           jono.push_back(numero);
           continue;
        }

        kentta.push_back(jono);
        jono.clear();

    }
return kentta;
}


// Lukee vasta syötteen, haluaako käyttäjä luoda kentän itse vai tehdä satunnaisesti.
vector<vector<string>> lueSyote()
{
string syote;
cin>>syote;
vector<vector<string>> kentta;

//while(syote != "r" || "i")
//{
//continue;
//}
if(syote == "r")
{
    kentta = satunnainenKentta();
}
if(syote == "i")
{
   kentta = syotaKentta();
}
return kentta;
}


// Funktio luo vektorin vektorn käyttäjän syötteen perusteella
vector<vector<string>> syotaKentta()
{
    string syote;
    string sana;
    vector<string> jono;
    vector<vector<string>> kentta;
    cout <<"Input: ";
    cin.ignore();
    getline(cin, syote);

    for (const char c : syote)
    {
        if(c == EMPTY)
        {
            continue;
        }
        if(jono.size() < BOARD_SIDE)
        {
                sana = c;
                jono.push_back(sana);
                continue;
            }

     else{
            kentta.push_back(jono);
            jono.clear();
            sana = c;
            jono.push_back(sana);

        }

}
    kentta.push_back(jono);
    return kentta;
}


void print(const vector<vector<char>>& gameboard);
// Muuttaa annetun numeerisen merkkijonon vastaavaksi kokonaisluvuksi
// (kutsumalla stoi-funktiota).
// Jos annettu merkkijono ei ole numeerinen, palauttaa nollan.
//
// Converts the given numeric string to the corresponding integer
// (by calling stoi).
// If the given string is not numeric, returns zero.
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

// Tulostaa pelilaudan rivi- ja sarakenumeroineen.
//
// Prints the game board with row and column numbers.
void print(const vector<vector<string>>& gameboard)
{
    cout << "=================" << endl;
    cout << "|   | 1 2 3 4 5 |" << endl;
    cout << "-----------------" << endl;
    for(unsigned int i = 0; i < BOARD_SIDE; ++i)
    {
        cout << "| " << i + 1 << " | ";
        for(unsigned int j = 0; j < BOARD_SIDE; ++j)
        {
            if((stoi_with_check( gameboard.at(i).at(j))) == 0)
            {
                cout << EMPTY << " ";
            }
            else
            {
                cout << gameboard.at(i).at(j) << " ";
            }
        }
        cout << "|" << endl;
    }
    cout << "=================" << endl;
}

int main()
{
    vector<vector<string>> pelilauta;
    cout<<"Select start (R for random, I for input): ";
    pelilauta = lueSyote();
    print(pelilauta);

}
