#include <iostream>
#include <vector>

using namespace std;

const unsigned int BOARD_SIDE = 5;
const unsigned char EMPTY = ' ';
unsigned int stoi_with_check(const string& str);
vector<vector<int>> syotaKentta();
vector<vector<int>> satunnainenKentta()
{
vector<vector<int>> kentta;
return kentta;
}


// Lukee vasta syötteen, haluaako käyttäjä luoda kentän itse vai tehdä satunnaisesti.
vector<vector<int>> lueSyote()
{
string syote;
cin>>syote;
vector<vector<int>> kentta;

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
vector<vector<int>> syotaKentta()
{
    string syote;
    string luku;
    string numero;
    int lisattava;
    int i = 0;
    vector<int> jono;
    vector<vector<int>> kentta;
    cout<<"Input: ";
    cin>>syote;
    for (const char c : syote)
    {
        if(luku.size()< BOARD_SIDE)
        {
            luku.push_back(c);
            numero = luku.at(i);
            lisattava = stoi_with_check(numero);
            jono.push_back(lisattava);
            numero.clear();
            i++;

            continue;
        }
     else{
            kentta.push_back(jono);
            luku.clear();
            jono.clear();
            jono.push_back(c);
            i=0;
        }

    }
    jono.push_back(lisattava);
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
void print(const vector<vector<int>>& gameboard)
{
    cout << "=================" << endl;
    cout << "|   | 1 2 3 4 5 |" << endl;
    cout << "-----------------" << endl;
    for(unsigned int i = 0; i < BOARD_SIDE; ++i)
    {
        cout << "| " << i + 1 << " | ";
        for(unsigned int j = 0; j < BOARD_SIDE; ++j)
        {
            if((gameboard.at(i).at(j)) == 0)
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
    vector <int> joku = {1,2,4,5};
    vector<vector<int>> pelilauta;
    //pelilauta.push_back(joku);
    cout<<"Select start (R for random, I for input): ";
    pelilauta = lueSyote();
    print(pelilauta);

}
