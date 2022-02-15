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
void print(const vector<vector<string>>& gameboard);
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
// Tarkistaa onko tyhjiä kohtia tyhjien vieressä. Silmukat käyvät erikseen reunat läpi ja yksi silmukka käy muut alueet.
bool onkoHavio (vector<vector<string>>& lauta)
{
    // Yläreunan tarkistus
    bool onko = false;
    for(int x = 0; x < 1;++x)
        for(unsigned int y = 1; y < BOARD_SIDE-1;y++)
        {
            if(lauta.at(x).at(y) != "0")
            {
                continue;
            }
            if(lauta.at(x).at(y+1) == "0")
            {
                onko = true;
            }
            if(lauta.at(x).at(y-1) == "0")
            {
                onko = true;
            }


        }
    //Alareunan tarkistus
    for(int x = 4; x < 5;++x)
         for(unsigned int y = 1; y < BOARD_SIDE-1;y++)
         {
             if(lauta.at(x).at(y) != "0")
             {
                 continue;
             }
             if(lauta.at(x).at(y+1) == "0")
             {
                 onko = true;
             }
             if(lauta.at(x).at(y-1) == "0")
             {
                 onko = true;
             }


    }
    //Vasemman sivun tarkistus
    for(int y = 0; y < 1;++y)
         for(unsigned int x = 1; x < BOARD_SIDE-1;x++)
         {
             if(lauta.at(x).at(y) != "0")
             {
                 continue;
             }

             if(lauta.at(x+1).at(y) == "0")
             {
                 onko = true;
             }
             if(lauta.at(x-1).at(y) == "0")
             {
                 onko = true;
             }
         }
    //Oikean sivun tarkistus
    for(int y = 4; y < 5;++y)
         for(unsigned int x = 1; x < BOARD_SIDE-1;x++)
         {
             if(lauta.at(x).at(y) != "0")
             {
                 continue;
             }

             if(lauta.at(x+1).at(y) == "0")
             {
                 onko = true;
             }
             if(lauta.at(x-1).at(y) == "0")
             {
                 onko = true;
             }
         }

    // Muiden alueiden tarkistus
    for(int x = 1; x < BOARD_SIDE-1;x++)
        for(unsigned int y = 1; y < BOARD_SIDE-1;y++)
        {
            if(lauta.at(y).at(x) != "0")
            {
                continue;
              }

                if(lauta.at(x-1).at(y)== "0")
                {
                    onko = true;
                }

                        if(lauta.at(y+1).at(x)== "0")
                        {
                            onko = true;
                        }
                            if(lauta.at(y).at(x-1)== "0")
                            {
                                onko = true;
                            }
                                if(lauta.at(y).at(x+1)== "0")
                                {
                                    onko = true;
                                }

                }

    return onko;
}

bool onkoVoitto(vector<vector<string>>& lauta)
{
    int ykkosia = 0;
    int kakkosia = 0;
    int kolmosia = 0;
    int nelosia = 0;
    int vitosia = 0;
    int sykkosia = 0;
    int skakkosia = 0;
    int skolmosia = 0;
    int snelosia = 0;
    int svitosia = 0;
    bool onkoriveilla = false;
    bool onkosarakkeilla = false;
    bool paluuarvo = false;
    for(int x = 0; x < BOARD_SIDE;x++)
        for(unsigned int y = 0; y < BOARD_SIDE;y++)
        {

            if(lauta.at(y).at(x) == "1")
            {
                ykkosia += 1;
                if(ykkosia > 1)
                {
                    onkoriveilla = false;
                    break;
                }
            }
            if(lauta.at(y).at(x) == "2")
            {
                kakkosia += 1;
                if(kakkosia > 1)
                {
                    onkoriveilla = false;
                    break;
                }
            }
            if(lauta.at(y).at(x) == "3")
            {
                kolmosia += 1;
                if(kolmosia > 1)
                {
                    onkoriveilla = false;
                    break;
                }
            }
            if(lauta.at(y).at(x) == "4")
            {
                nelosia += 1;
                if(nelosia > 1)
                {
                    onkoriveilla = false;
                    break;
                }
            }
            if(lauta.at(y).at(x) == "5")
            {
                vitosia += 1;
                if(vitosia > 1)
                {
                    onkoriveilla = false;
                    break;
                }
            }
            else
              {
                onkoriveilla = true;
            }
        }
    for(unsigned int y = 0; y < BOARD_SIDE;y++)
        for(unsigned int x = 0; x < BOARD_SIDE;x++)
        {

            if(lauta.at(y).at(x) == "1")
            {
                sykkosia += 1;
                if(sykkosia > 1)
                {
                    onkosarakkeilla = false;
                    break;
                }
            }
            if(lauta.at(y).at(x) == "2")
            {
                skakkosia += 1;
                if(skakkosia > 1)
                {
                    onkosarakkeilla = false;
                    break;
                }
            }
            if(lauta.at(y).at(x) == "3")
            {
                skolmosia += 1;
                if(skolmosia > 1)
                {
                    onkosarakkeilla = false;
                    break;
                }
            }
            if(lauta.at(y).at(x) == "4")
            {
                snelosia += 1;
                if(snelosia > 1)
                {
                    onkosarakkeilla = false;
                    break;
                }
            }
            if(lauta.at(y).at(x) == "5")
            {
                svitosia += 1;
                if(svitosia > 1)
                {
                    onkosarakkeilla = false;
                    break;
                }
            }
            else
              {
                onkosarakkeilla = true;
            }
        }
    if(onkoriveilla == true && onkosarakkeilla == true)
    {
        paluuarvo =true;
    }
    return paluuarvo;
}


void poistaKohta(vector<vector<string>>& lauta)
{
    vector<vector<string>> uusi_lauta = lauta;

    int x;
    int y;
    bool jatkuuko = true;
    while(jatkuuko)
    {
        cout<<"Enter removable element (x, y): ";
        cin>>x;
        cin>>y;
        lauta.at(x-1).at(y-1) = "0";
        print(lauta);
     if(onkoHavio(lauta))
        {
            jatkuuko = false;
            cout<<"Luuseri";
        }
     if(onkoVoitto(lauta))
     {
        jatkuuko = false;
        cout<<"Yeah boi";
     }

    }


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
    cout<<"Select start (R for random, I for input): ";
    vector<vector<string>> pelilauta = lueSyote();
    print(pelilauta);
    poistaKohta(pelilauta);

}