/*  COMP.CS.100 Project 2: GAME STATISTICS
 * ===============================
 * EXAMPLE SOLUTION
 * ===============================
 *
 *  Acts as a game statistics with n commands:
 * ALL_GAMES - Prints all known game names
 * GAME <game name> - Prints all players playing the given game
 * ALL_PLAYERS - Prints all known player names
 * PLAYER <player name> - Prints all games the given player plays
 * ADD_GAME <game name> - Adds a new game
 * ADD_PLAYER <game name> <player name> <score> - Adds a new player with the
 * given score for the given game, or updates the player's score if the player
 * already playes the game
 * REMOVE_PLAYER <player name> - Removes the player from all games
 *
 *  The data file's lines should be in format game_name;player_name;score
 * Otherwise the program execution terminates instantly (but still gracefully).
 *
 * */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
struct pisteet{
    std::string nimi;
    unsigned int pisteet;
};
std::vector<std::string> split( const std::string& str, char delim = ';' );
using STAT = std::map<std::string, std::map<std::string, unsigned int>>;
STAT tilastot;
void lisaaPelaaja(std::vector<std::string> pelaajat, STAT& tilastot);

unsigned int stoi_with_check(const std::string& str)
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

void kaikkiPelit(STAT tilastot)
{
    std::map<std::string,std::map<std::string, unsigned int>>::iterator iter;
    iter = tilastot.begin();
    while(iter != tilastot.end())
    {
        std::cout<<iter->first<<std::endl;
        ++iter;
    }
}
void kaikkiPelaajat(STAT tilastot)
{
std::vector<std::string> apuvektori;
for(auto& peli : tilastot)
    for(auto& pelaaja : peli.second)
   {
       apuvektori.push_back(pelaaja.first);
    }
       sort(apuvektori.begin(), apuvektori.end());
       std::string sana;
       for(std::vector<std::string>::iterator it = apuvektori.begin(); it != apuvektori.end();it++)
       {
           if(*it == sana)
           {
               continue;
           }
           else{
               std::cout<<*it<<std::endl;
               sana = *it;
           }
       }
    }


void pelaaja(std::string henkilo, STAT tilastot)
{
    for(auto& peli : tilastot)
        for(auto& pelaaja : peli.second)
        {
            if(pelaaja.first == henkilo)
            {
                std::cout<<peli.first<<std::endl;
            }
        }
}
void lisaaPeli(std::string peli, STAT& tilastot)
{
    std::vector<std::string> uusi_peli = {peli," "," "};
    lisaaPelaaja(uusi_peli, tilastot);
    std::cout<<"Game was added."<<std::endl;
}
void lisaaPelaaja(std::vector<std::string> pelaajat, STAT& tilastot)
{
    if(tilastot.find(pelaajat.at(0)) != tilastot.end())
    {
        std::string pelaaja = pelaajat.at(1);
        unsigned int pisteet = stoi_with_check(pelaajat.at(2));
        tilastot[pelaajat.at(0)].insert({pelaaja, pisteet});

    }
    else
    {
        std::string pelaaja = pelaajat.at(1);
        unsigned int pisteet = stoi_with_check(pelaajat.at(2));
        std::map<std::string, unsigned int> sisempi = {{pelaaja, pisteet}};
        tilastot.insert({pelaajat.at(0), sisempi});
    }






    }
std::pair<unsigned int, std::string> kaannaMap(std::string pelaaja, unsigned int pisteet)
{
    std::pair<unsigned int, std::string> kaannetty (pisteet, pelaaja);
    return kaannetty;
}


void poistaPelaaja(std::string pelaaja, STAT& tilastot)
{
    for(auto& peli : tilastot)
        for(auto& henkilo : peli.second)
        {
            if(henkilo.first == pelaaja)
            {
                peli.second.erase(pelaaja);
                break;
            }
        }
    std::cout<<"Player was removed from all games."<<std::endl;
}
void naytaPeli(std::string haettava_peli, STAT tilastot)
{
    std::vector<std::string> sama_nimiset;
    unsigned int pisteet;
    std::cout<<"Game "<<haettava_peli<< " has these scores and players, listed in ascending order:"<<std::endl;
    std::vector<std::pair<unsigned int, std::string>> parit;
    std::pair<unsigned int, std::string> kaannetty_pari;
    for(auto& peli : tilastot)
        if(peli.first == haettava_peli)
        {
            for(auto& henkilo : peli.second)
            {
                parit.push_back((kaannaMap(henkilo.first, henkilo.second)));
            }

            for(unsigned int i = 0;i < parit.size();i++)
            {
                if(parit.at(i).first != parit.at(i+1).first)
                {
                    if(!sama_nimiset.empty())
                    {
                        std::cout<<pisteet<<" : "<<sama_nimiset.at(0);
                        for(unsigned int j = 1; j < sama_nimiset.size();j++)
                        {
                            std::cout<<", "<<sama_nimiset.at(j);
                        }
                    }
                    std::cout<<std::endl;
                    std::cout<<parit.at(i).first<<" : "<<parit.at(i).second<<std::endl;
                }
                if(parit.at(i).first == parit.at(i+1).first)
                {
                    pisteet = parit.at(i).first;
                    sama_nimiset.push_back(parit.at(i).second);
                }



            }


            }
        }







bool avaa_tiedosto(std::string tiedoston_nimi, STAT& tilastot)
{
    std::vector<std::string> syote;
    std::ifstream input(tiedoston_nimi);
        if(not input)
        {
            std::cout<<"Error: File could not be read."<<std::endl;
            return false;
        }
        else
        {
            std::string jono;
            while(getline(input,jono))
            {

                syote = split(jono);
                if(syote.size() != 3)
                {
                    std::cout<<"Error: Invalid format in file."<<std::endl;
                    break;
                }
                lisaaPelaaja(syote, tilastot);
            }
            input.close();
            return true;
}
}

// Casual split func, if delim char is between "'s, ignores it.
std::vector<std::string> split( const std::string& str, char delim)
{
    std::vector<std::string> result = {""};
    bool inside_quatation = false;
    for ( auto current_char : str )
    {
        if ( current_char == '"' )
        {
            inside_quatation = not inside_quatation;
        }
        else if ( current_char == delim  and not inside_quatation )
        {
            result.push_back("");
        }
        else
        {
            result.back().push_back(current_char);
        }
    }
    if ( result.back() == "" )
    {
        result.pop_back();
    }
    return result;
}


int main()
{
    STAT tilastot;
    std::string jono = "";
    std::cout <<"Give a name for input file: ";
    std::getline(std::cin,jono);
    if(!avaa_tiedosto(jono, tilastot))
    {
        return EXIT_FAILURE;

    };
    std::string komento = " ";
    while(komento != "QUIT")
    {
        std::cout<<"game>";
        std::getline(std::cin, komento);

        if(komento == "ALL_GAMES")
        {
            kaikkiPelit(tilastot);
            continue;
        }
        if(komento == "ALL_PLAYERS")
        {
            kaikkiPelaajat(tilastot);
            continue;
        }
        if(komento.find(" ") != std::string::npos)
        {
            std::vector<std::string> komento_erotetltuna  = split(komento, ' ');
            if(komento_erotetltuna.at(0)== "PLAYER")
            {
                pelaaja(komento_erotetltuna.at(1), tilastot);
                continue;
            }
            if(komento_erotetltuna.at(0)== "ADD_GAME")
            {
                lisaaPeli(komento_erotetltuna.at(1), tilastot);
                continue;
            }
            if(komento_erotetltuna.at(0)== "ADD_PLAYER")
            {
                lisaaPelaaja(komento_erotetltuna, tilastot);
                continue;
            }
            if(komento_erotetltuna.at(0)== "REMOVE")
            {
                poistaPelaaja(komento_erotetltuna.at(1), tilastot);
                continue;
            }
            if(komento_erotetltuna.at(0)== "GAME" && komento_erotetltuna.size() >= 2)
            {

                naytaPeli(komento_erotetltuna.at(1),tilastot);
                continue;
            }
        }

        else
        {
            std::cout<<"Error: Invalid input."<<std::endl;
            continue;
        }

    }
    return EXIT_SUCCESS;




}
