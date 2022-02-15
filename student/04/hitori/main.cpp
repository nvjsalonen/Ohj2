#include <iostream>
/* Hitori
 *
 * Kuvaus:
 *   Ohjelma toteuttaa Hitori-pelin. Pelissä on peliruudukko kooltaan
 * 5 x 5. Kukin ruutu sisältää jonkin numeroista 1-5. Vaaka- ja
 * pystyriveillä voi aluksi olla useita samoja numeroita, mutta
 * tarkoituksena on poistaa numeroita niin, että kullakin vaaka- ja
 * pystyrivillä on kutakin numeroa vain yksi tai ei yhtään. Kuitenkaan
 * vierekkäisten ruutujen numeroita ei saa poistaa, eikä mikään jäljelle
 * jäävä numero (ruutu) saa jäädä irralleen muista, eli sen ympäriltä
 * (yläpuolelta, alapuolelta, vasemmalta, oikealta) ei saa poistaa
 * kaikkia numeroita.
 *   Aluksi käyttäjältä kysytään, täytetäänkö peliruudukko satunnaisesti
 * arvottavilla luvuilla 1-5 vai käyttäjän valitsemilla 25 luvulla.
 * Ensimmäisessä vaihtoehdossa käyttäjältä kysytään satunnaisluku-
 * generaattorin siemenlukua ja jälkimmäisessä häntä pyydetään syöttämään
 * 25 lukua.
 *   Joka kierroksella käyttäjältä kysytään poistettavan numeron
 * koordinaatteja eli kahta lukua. Peli päättyy pelaajan voittoon,
 * jos peliruudukon kaikilla vaaka- ja pystyriveillä esiintyy kukin
 * numero 1-5 korkeintaan kerran. Peli päättyy pelaajan häviöön,
 * jos hän poistaa jo poistetun numeron viereisen numeron tai jos
 * jokin numero jää irralleen muista.
 *   Ohjelma tarkistaa annetut koordinaatit. Koordinaattien pitää olla
 * peliruudukon sisällä, ja niiden osoittaman ruudun pitää sisältää
 * numero, eli jo poistettua numeroa ei voi poistaa toiseen kertaan.
 *   Pelin päättyessä kerrotaan, voittiko vai hävisikö pelaaja.
 *
 * Ohjelman kirjoittaja ( Täytä omilla tiedoillasi )
 * Nimi: Nikolas Salonen
 * Opiskelijanumero: 050158931
 * Käyttäjätunnus: chnisa ( Git-repositorion hakemistonimi. )
 * E-Mail: nikolas.salonen@tuni.fi
 *
 * Huomioita ohjelmasta ja sen toteutuksesta:
 * Ohjelma toimii, mutta ei ole erityisen kaunis.
 * */


#include <vector>
#include <string>
#include <random>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;
const unsigned int BOARD_SIDE_IN_VECTOR = 9;
const unsigned int BOARD_SIDE = 10;
const unsigned char EMPTY = ' ';

unsigned int stoi_with_check(const string& str);
vector<vector<string>> syotaKentta();
void print(const vector<vector<string>>& gameboard);

// Ei todellisuudessa ole satunnainen. Palauttaa käyttäjälle valmiin kentän
// seed valuen perusteella hyödyntäen switch-rakennetta. Palauttaa kentän
// vektorin vektorina.
vector<vector<string>> satunnainenKentta()
{
    string syote;
    string sana;
    vector<string> jono;
    vector<vector<string>> kentta;
    int seed_value;
    cout<<"Enter seed value: ";
    cin>>seed_value;
    while (seed_value <= 0 || seed_value > 10)
    {
        cout<<"Seed value has to be between 1 and 10"<<endl;
        cout<<"Enter seed value: ";
        cin>>seed_value;
    }
    switch (seed_value){
        case 1 :
            syote = "5 1 4 5 3 5 3 4 5 4 3 4 5 1 2 4 1 1 4 5 3 5 3 4 4";
            break;
        case 2 :
            syote = "5 3 5 2 4 3 2 4 4 5 5 3 2 3 2 4 1 4 5 2 5 5 4 2 4";
            break;
        case 3 :
            syote = "5 1 4 5 3 5 3 4 5 4 3 4 5 1 2 4 1 1 4 5 3 5 3 4 4";
            break;
        case 4 :
            syote = "5 3 3 1 4 4 3 1 5 1 1 3 5 3 3 2 5 1 3 4 5 1 4 1 5";
            break;
        case 5 :
            syote = "3 3 4 4 2 3 2 5 3 4 2 5 5 2 1 2 1 4 5 1 2 4 5 3 5";
            break;
        case 6 :
            syote = "2 3 4 1 4 3 4 4 5 3 5 2 1 2 4 4 2 3 2 1 3 1 1 4 3";
            break;
        case 7 :
            syote = "5 5 2 3 1 1 2 1 4 2 2 1 4 1 5 3 5 1 3 4 1 1 2 5 2";
            break;
        case 8 :
            syote = "3 1 5 2 3 1 4 1 5 4 1 5 1 5 4 3 2 5 1 5 4 3 2 4 3";
            break;
        case 9 :
            syote = "4 5 1 5 2 4 3 5 4 1 5 1 2 2 1 3 4 2 1 5 1 3 3 4 4";
            break;
        case 10 :
            syote = "3 5 3 4 5 2 4 2 1 3 3 3 1 5 3 5 1 2 3 5 5 3 3 2 5";
            break;
        default:
            syote = "5 1 4 5 3 5 3 4 5 4 3 4 5 1 2 4 1 1 4 5 3 5 3 4 4";
    }

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




// Lukee vasta syötteen, haluaako käyttäjä luoda kentän itse vai tehdä satunnaisesti.
// Kutsuu kentän luovaa aliohjelmaa ja palauttaa luodun kentän.
vector<vector<string>> lueSyote()
{
string syote;
vector<vector<string>> kentta;
bool jatketaanko = true;

while(jatketaanko)
{
cout<<"Select start (R for random, I for input): ";
getline(cin,syote);
    if(syote != "r" && syote != "i" && syote != "I" )
    {
        jatketaanko = true;
    }
    else
    {
        jatketaanko = false;

    }
}
if(syote == "r")
{
   kentta = satunnainenKentta();
}
if(syote == "i")
{
   kentta = syotaKentta();
}
if(syote == "I")
{
    kentta = syotaKentta();
}
return kentta;
}


// Tarkistaa onko tyhjiä ruutuja tyhjien  vieressä ja onko mikään ruutu yksin.
// Ottaa parametreikseen string tyyppisen vektorin vektorin "lauta". Nurkkien tarkistus on tehty erikseen alkuun.
// Reunojen ja keskialueiden toteutus on tehty silmukoilla. Funktio palauttaa totuusarvon true tai false sen mukaan onko
// peli hävitty.
bool onkoHavio (vector<vector<string>>& lauta)
{
    bool onko_havio = false;

    //Nurkkien tarkistus
    if(lauta.at(BOARD_SIDE_IN_VECTOR).at(BOARD_SIDE_IN_VECTOR) != "0" && lauta.at(BOARD_SIDE_IN_VECTOR -1).at(BOARD_SIDE_IN_VECTOR) == "0")
        if(lauta.at(BOARD_SIDE_IN_VECTOR).at(BOARD_SIDE_IN_VECTOR -1) == "0")
           {
        onko_havio = true;
           }
    if(lauta.at(BOARD_SIDE_IN_VECTOR).at(0) != "0" && lauta.at(BOARD_SIDE_IN_VECTOR).at(1) == "0" && lauta.at(BOARD_SIDE_IN_VECTOR -1).at(0) == "0")
           {
        onko_havio = true;
           }
    if(lauta.at(0).at(BOARD_SIDE_IN_VECTOR) != "0" && lauta.at(1).at(BOARD_SIDE_IN_VECTOR) == "0" && lauta.at(0).at(BOARD_SIDE_IN_VECTOR-1) == "0")
           {
        onko_havio = true;
           }
    if(lauta.at(0).at(0) != "0" && lauta.at(1).at(0) == "0" && lauta.at(0).at(1) == "0")
           {
        onko_havio = true;
           }
    // Yläreunan tarkistus
    for(int x = 0; x < 1;++x)
        for(unsigned int y = 1; y < BOARD_SIDE_IN_VECTOR;y++)
        {
            if(lauta.at(x).at(y) != "0")
            {
                continue;
            }
            if(lauta.at(x).at(y+1) == "0")
            {
                onko_havio = true;
            }
            if(lauta.at(x).at(y-1) == "0")
            {
                onko_havio = true;
            }


        }

    //Alareunan tarkistus
    for(int x = 4; x < 5;++x)
         for(unsigned int y = 1; y < BOARD_SIDE_IN_VECTOR;y++)
         {
             if(lauta.at(x).at(y) != "0")
             {
                 continue;
             }
             if(lauta.at(x).at(y+1) == "0")
             {
                 onko_havio = true;
             }
             if(lauta.at(x).at(y-1) == "0")
             {
                 onko_havio = true;
             }


    }

    //Vasemman sivun tarkistus
    for(int y = 0; y < 1;++y)
         for(unsigned int x = 1; x < BOARD_SIDE_IN_VECTOR;x++)
         {
             if(lauta.at(x).at(y) != "0")
             {
                 continue;
             }

             if(lauta.at(x+1).at(y) == "0")
             {
                 onko_havio = true;
             }
             if(lauta.at(x-1).at(y) == "0")
             {
                 onko_havio = true;
             }
         }

    //Oikean sivun tarkistus
    for(int y = 4; y < 5;++y)
         for(unsigned int x = 1; x < BOARD_SIDE_IN_VECTOR;x++)
         {
             if(lauta.at(x).at(y) != "0")
             {
                 continue;
             }

             if(lauta.at(x+1).at(y) == "0")
             {
                 onko_havio = true;
             }
             if(lauta.at(x-1).at(y) == "0")
             {
                 onko_havio = true;
             }
         }


    // Muiden alueiden tarkistus
    for(unsigned int x = 1; x < BOARD_SIDE_IN_VECTOR;x++)
        for(unsigned int y = 1; y < BOARD_SIDE_IN_VECTOR;y++)
        {
            if(lauta.at(y).at(x) != "0")
            {
                if(lauta.at(y-1).at(x) == "0")
                    if(lauta.at(y+1).at(x) == "0")
                        if(lauta.at(y).at(x+1) == "0")
                            if(lauta.at(y).at(x-1) == "0")
                            {
                                onko_havio = true;
                            }


                continue;
              }

                if(lauta.at(x-1).at(y)== "0")
                {
                    onko_havio = true;
                }

                        if(lauta.at(y+1).at(x)== "0")
                        {
                            onko_havio = true;
                        }
                            if(lauta.at(y).at(x-1)== "0")
                            {
                                onko_havio = true;
                            }
                                if(lauta.at(y).at(x+1)== "0")
                                {
                                    onko_havio = true;
                                }

                }

    return onko_havio;
}

//Funktio tarkastaa onko riveillä tai sarakkeilla samoja lukuja tallentamalla
//tallentamalla luvut vektoriin ja sen jälkeen järjestää ne suuruusjärjestykseen
//ja tarkistaa duplikaatit. Ottaa parametrinä string-tyyppisen vektorin vektorin
//ja palauttaa true tai falsen riippuen onko voittoa vai ei.
bool onkoVoitto(vector<vector<string>>& lauta)
{
    bool onko_voitto = false;
    vector<unsigned int> luvut;
    //Tarkastaa rivit
    for(unsigned int x = 0; x < BOARD_SIDE;x++)
    {
        for(unsigned int y = 0; y < BOARD_SIDE;y++)
        {

            luvut.push_back(stoi_with_check(lauta.at(y).at(x)));
         }
    sort(luvut.begin(), luvut.end());
    for(unsigned int i = 0; i < luvut.size()-1;i++)
    {
        if(luvut.at(i)==0 || luvut.at(i+1)==0)
        {
            continue;
        }
        if(luvut.at(i)== luvut.at(i+1))
        {
            onko_voitto = false;
            break;
        }
        else
        {
            onko_voitto = true;
        }
    }
    luvut.clear();
 }

    // Tarkistaa sarakkeet
    for(unsigned int y = 0; y < BOARD_SIDE;y++)
    {
        for(unsigned int x = 0; x < BOARD_SIDE;x++)
        {

            luvut.push_back(stoi_with_check(lauta.at(y).at(x)));
         }
    sort(luvut.begin(), luvut.end());
    for(unsigned int i = 0; i < luvut.size()-1;i++)
    {
        if(luvut.at(i)==0 || luvut.at(i+1)==0)
        {
            continue;
        }
        if(luvut.at(i)== luvut.at(i+1))
        {
            onko_voitto = false;
            break;
        }
        else
        {
            onko_voitto = true;
        }
    }
    luvut.clear();
 }
    return onko_voitto;
}


//Lukee käyttäjältä koordinaatit tai käskyn lopettaa.
//Poistaa halutun kohdan, kutsuu print-funktiota sekä voiton ja häviön
// tarkistavia funktioita. Ottaa parametrina string-tyyppisen vektorin vektorin.
void poistaKohta(vector<vector<string>>& lauta)
{
    vector<vector<string>> uusi_lauta = lauta;
    string a;
    string b;
    int x;
    int y;
    bool jatkuuko_peli = true;
    while(jatkuuko_peli)
    {
        cout<<"Enter removable element (x, y): ";
        cin>>a;
         if(a == "q")
         {
             cout<<"Quitting"<<endl;
             break;
         }
         cin>>b;
     if(b == "q")
     {
         cout<<"Quitting"<<endl;
         break;
     }

     x = stoi_with_check(b);
     y = stoi_with_check(a);



    if((x) <= 0 || (x) >= 6 || (y) <= 0 || (y) >= 6 )
    {
        cout<<"Out of board"<<endl;
        continue;
    }
    if(lauta.at(x-1).at(y-1) == "0")
    {
        cout<<"Already removed"<<endl;
        continue;
    }
        lauta.at(x-1).at(y-1) = "0";
        print(lauta);
     if(onkoHavio(lauta))
        {
            jatkuuko_peli = false;
            cout<<"You lost"<<endl;
        }
     if(onkoVoitto(lauta))
     {
        jatkuuko_peli = false;
        cout<<"You won"<<endl;
     }

    }
    EXIT_SUCCESS;


}


// Funktio luo vektorin vektorn käyttäjän syötteen perusteella.
// Paluuarvona palauttaa vektorin vektorin käyttäjän haluamilla luvuilla
vector<vector<string>> syotaKentta()
{
    string syote;
    string sana;
    vector<string> jono;
    vector<vector<string>> kentta;
    cout <<"Input: ";
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
    vector<vector<string>> pelilauta = lueSyote();
    print(pelilauta);
    poistaKohta(pelilauta);

}
