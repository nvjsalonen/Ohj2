/*  COMP.CS.100 Projekti 2: Pelitilastot
 * ===============================
 *  Ohjelma on pelitilastoja ylläpitävä tietokanta.
 *  Peliin syotetaan pelitilastot tiedostosta ja loput komennot
 *  suoritetaan valitun tietorakenteen sisalla.
 *  Komennot ja niiden kuvaus:
 * ALL_GAMES - Tulostaa kaikki tietorakenteen pelit.
 * GAME <Pelin nimi> - Tulostaa kaikki pelaajat, jotka pelaavat pelia.
 * ALL_PLAYERS - Tulostaa kaikki pelaajat, jotka pelaavat jotakin pelia.
 * PLAYER <pelaajan nimi> - Tulostaa kaikki pelit, joita pelaaja pelaa.
 * ADD_GAME <pelin nimi> - Lisaa uuden pelin.
 * ADD_PLAYER <pelin nimi> <pelaajan nimi> <pisteet> - Lisaa tietorakenteeseen
 * pelaajan, pelin, jota pelaaja pelaa ja pelin pistetilanteen. Jos pelaaja pelaa
 * jo pelia, paivittaa pisteet.
 * REMOVE_PLAYER <pelaajan nimi> - Poistaa pelaajan kaikista peleista.
 * Komennot eivat toimi, jos parametreja ei ole riittavasti. Ylimaaraiset
 * parametrit eivat vaikuta pelin toimintaan,
 *
 *  Tiedoston rivit tulee olla muodossa pelin_nimi;pelaajan_nimi;pisteet
 *  Muussa tapauksessa ohjelman suoritus paattyy.
 *
 * Ohjelman kirjoittaja
 * Nimi: Nikolas Salonen
 * Opiskelijanumero: 050158931
 * Käyttäjätunnus: chnisa ( Git-repositorion hakemistonimi. )
 * E-Mail: nikolas.salonen@tuni.fi
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
const unsigned int PELAAJAN_KOKO = 4;
const unsigned int PELIN_PARAMETRIT = 2;
const unsigned int TIEDOSTON_RIVIN_KOKO = 3;
using namespace std;
using STAT = std::map<std::string, std::map<std::string, unsigned int>>;
STAT tilastot;
void lisaaPelaaja(std::vector<std::string> pelaajat, STAT& tilastot);


/**
 * @brief split
 * Pohjassa valmiina oleva funktio, joka pilkkoo jonon osiin ja
 * tallettaa vektoriin.
 * @param str
 * string-tyyppinen, jono joka pilkotaan.
 * @param delim
 * Merkki, joka nayttaa mista kohtaa pilkotaa. 
 * Oletuksena ';'.
 * @return
 * Palauttaa vektorin, jossa jono pilkottuna.
 */
std::vector<std::string> split( const std::string& str, char delim = ';')
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

/**
 * @brief stoi_with_check
 * Hitori-projektista suoraan kopioitu funktio, joka tarkistaa onko
 * merkkijono numero ja palauttaa numeron jos on.
 * @param str
 * String-tyyppinen merkkijono, josta halutaan tarkistaa numerot.
 * @return 
 * Palauttaa int-tyyppisen luvun jos merkkijono on luku. 
 * Muussa tapauksessa palauttaa nollan.
 */
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

/**
 * @brief kaikkiPelit
 * Tulostaa kaikki pelit ASCII-aakkosjärjestyksessa.
 * @param tilastot
 * Map mapissa, josta pelit tulostetaan.
 */
void kaikkiPelit(STAT tilastot)
{
    cout<<"All games in alphabetical order:"<<endl;
    std::map<std::string,std::map<std::string, unsigned int>>::iterator iter;
    iter = tilastot.begin();
    while(iter != tilastot.end())
    {
        std::cout<<iter->first<<std::endl;
        ++iter;
    }
}
/**
 * @brief kaikkiPelaajat
 * Tulostaa kaikki pelaajat, jotka pelaavat jotain pelia.
 * @param tilastot
 * Map mapissa, josta pelaajia etsitaan.
 */
void kaikkiPelaajat(STAT tilastot)
{
    cout<<"All players in alphabetical order:"<<endl;
    std::vector<std::string> apuvektori = {};
    for(auto& peli : tilastot)
        for(auto& pelaaja : peli.second)
        {
            apuvektori.push_back(pelaaja.first);
        }
    sort(apuvektori.begin(), apuvektori.end());
    std::string sana;
    for(vector<string>::iterator it = apuvektori.begin();
        it != apuvektori.end();it++)
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


/**
 * @brief loytyykoPelaaja
 * Tarkistetaan onko pelaajaa ylipaataan mapissa.
 * @param henkilo
 * Henkilo, jota etsitaan
 * @param tilastot
 * Map mapissa, josta pelaajaa etsitaan
 * @return 
 * Palauttaa joko totuusarvon true tai false.
 */
bool loytyykoPelaaja(std::string henkilo, STAT tilastot)
{
    for(auto& peli : tilastot)
        for(auto& pelaaja : peli.second)
        {
            if(pelaaja.first == henkilo)
            {
                return true;
                break;
            }
        }
    return false;
}


/**
 * @brief pelaaja
 * Tulostaa pelit, joita pelaaja pelaa.
 * @param henkilo
 * Merkkijono pelaajasta, jonka pelit halutaan tulostaa.
 * @param tilastot
 * Map mapissa, josta pelaajan peleja etsitaan.
 */
void pelaaja(std::string henkilo, STAT tilastot)
{
    if(loytyykoPelaaja(henkilo, tilastot))
    {
        cout<<"Player "<<henkilo<<" playes the following games:"<<endl;
        for(auto& peli : tilastot)
            for(auto& pelaaja : peli.second)
            {
                if(pelaaja.first == henkilo)
                {
                    std::cout<<peli.first<<std::endl;
                }
            }
    }
    else{
        {
            std::cout<<"Error: Player could not be found."<<std::endl;
        }
    }
}


/**
 * @brief uusiPelaaja
 * Lisaa uuden pelaajan tilastoon. Tarkistaa myos, onko pelaajan
 * pelaamaa pelia olemassa.
 * @param peli
 * Merkkijono, jossa peli jota pelaaja pelaa.
 * @param pelaaja
 * Merkkijono, jossa tallennettuna pelaaja, joka halutaan
 * lisata.
 * @param pisteet
 * Merkkijono, johon talletettu pelaajan pisteet.
 * @param tilastot
 * Map mapissa, johon talletetaan uusi pelaaja.
 */
void uusiPelaaja(string peli, string pelaaja, string pisteet, STAT& tilastot)
{
    if(tilastot.find(peli) == tilastot.end())
    {
        std::cout<<"Error: Game could not be found."<<std::endl;
    }
    else{
        std::vector<std::string> uusi_pelaaja = {};
        bool loytyyko_pelaaja = false;
        for(auto& peli : tilastot)
            for(auto& henkilo : peli.second)
            {
                if(henkilo.first == pelaaja)
                {
                    henkilo.second = stoi_with_check(pisteet);
                    loytyyko_pelaaja = true;
                }
            }
        if(!loytyyko_pelaaja)
        {
            uusi_pelaaja = {peli,pelaaja,pisteet};
            lisaaPelaaja(uusi_pelaaja,tilastot);
        }
        std::cout<<"Player was added."<<std::endl;
    }
}


/**
 * @brief lisaaPeli
 * Lisaa pelin tilastoon  ja tarkistaa, onko peli jo olemassa.
 * Tulostaa virheilmoituksen jos on.
 * @param peli
 * Merkkijono, jossa peli joka halutaan lisata.
 * @param tilastot
 * Map-tyyppinen sailio, johon peli lisataan
 */
void lisaaPeli(std::string peli, STAT& tilastot)
{
    if(tilastot.find(peli) == tilastot.end())
    {
        std::vector<std::string> uusi_peli = {peli," "," "};
        lisaaPelaaja(uusi_peli, tilastot);
        std::cout<<"Game was added."<<std::endl;
    }
    else{
        std::cout<<"Error: Already exists."<<std::endl;
    }
}


/**
 * @brief lisaaPelaaja
 * Lisaa pelaajan, pelin ja pisteet tilasto-sailioon.
 * @param pelaajat
 * Vektori, joka sisaltaa pelin, pelaajan ja pisteet.
 * @param tilastot
 * Map-tyyppinen sailio, johon pelaajat talletetaan.
 */
void lisaaPelaaja(std::vector<std::string> pelaajat, STAT& tilastot)
{
    if(tilastot.find(pelaajat.at(0)) != tilastot.end())
    {
        std::string pelaaja = pelaajat.at(1);
        unsigned int pisteet = stoi_with_check(pelaajat.at(2));
        tilastot.at(pelaajat.at(0)).insert({pelaaja, pisteet});

    }
    else
    {
        std::string pelaaja = pelaajat.at(1);
        unsigned int pisteet = stoi_with_check(pelaajat.at(2));
        std::map<std::string, unsigned int> sisempi = {{pelaaja, pisteet}};
        tilastot.insert({pelaajat.at(0), sisempi});
    }
}


/**
 * @brief flip
 * Luo parametreina annetuista merkkijonoista ja pisteista parin.
 * Voidaan kayttaa, kun halutaan kaantaa pari toisinpain.
 * @param pelaaja
 * Merkkijono, jossa on talletettuna pelaaja, joka halutaan
 * parin hyotyarvoksi.
 * @param pisteet
 * Pisteet, jotka halutaan talletaa uuden parin avaimeksi.
 * @return
 * Palauttaa parin, jossa on talletettuna pisteet ja pelaaja.
 */
std::pair<unsigned int, std::string> flip(string pelaaja, unsigned int pisteet)
{
    std::pair<unsigned int, std::string> kaannetty (pisteet, pelaaja);
    return kaannetty;
}

/**
 * @brief poistaPelaaja
 * Funktio tarkistaa, onko pelaajaa olemassa ja
 * jos on niin poistaa pelaajan sailiosta.
 * @param pelaaja
 * Merkkijono, johon on talletettu pelaaja, joka halutaan poistaa.
 * @param tilastot
 * Sailio, josta pelaaja poistetaan.
 */
void poistaPelaaja(std::string pelaaja, STAT& tilastot)
{
    if(loytyykoPelaaja(pelaaja, tilastot))
    {
        for(auto& peli : tilastot)
            for(auto& henkilo : peli.second)
            {
                if(henkilo.first == pelaaja)
                {
                    peli.second.erase(pelaaja);
                    continue;
                }
            }
        std::cout<<"Player was removed from all games."<<std::endl;
    }
    else{
        cout<<"Error: Player could not be found."<<endl;
    }
}


/**
 * @brief tulostaPisteet
 * Tulostaa tietyn pelin pelaajien pisteet
 * pisteiden mukaisesti nousevassa jarjestyksessa.
 * @param peli_tilanne
 * Set-sailio, jossa parit jotka halutaan tulostaa.
 */
void tulostaPisteet(set<std::pair<unsigned int, string>> peli_tilanne )
{
    unsigned int pisteet = ' ';
    for(auto& pelaaja : peli_tilanne)
    {
        if(pelaaja.first == 0)
        {
            break;
        }
        if(pelaaja.first != pisteet)
        {
            if(pisteet != ' ')
            {
                std::cout<<std::endl;
            }
            pisteet = pelaaja.first;
            std::cout<<pisteet<<" : "<<pelaaja.second;
            continue;
        }
        if(pelaaja.first == pisteet)
        {
            std::cout<<", "<<pelaaja.second;
        }
    }
    std::cout<<std::endl;
}


/**
 * @brief naytaPeli
 * Tarkistaa, onko pelia olemassa ja tulostaa virheilmoituksen
 * jos ei ole. Tulostaa otsikkotekstin ja kutsuu flip-funktiota
 * ja sen jalkeen tulostaPisteet-funktiota.
 * @param haettava_peli
 * Merkkijono pelista, jonka tilanne halutaan tulostaa.
 * @param tilastot
 * Map-sailio, josta peli haetaan ja tulostetaan.
 */
void naytaPeli(std::string haettava_peli, STAT tilastot)
{
    if(tilastot.find(haettava_peli) == tilastot.end())
    {
        std::cout<<"Error: Game could not be found."<<std::endl;
    }
    else
    {
        std::cout<<"Game "<<haettava_peli<< " has these scores and players, "
        "listed in ascending order:"<<std::endl;
        std::set<std::pair<unsigned int, std::string>> parit = {};
        for(auto& peli : tilastot)
            if(peli.first == haettava_peli)
            {
                for(auto& henkilo : peli.second)
                {
                    if(henkilo.second != 0)
                    {
                        parit.insert((flip(henkilo.first, henkilo.second)));
                    }
                }
            }
        if(not parit.empty())
        {
            tulostaPisteet(parit);
        }
    }
}


/**
 * @brief tarkistaTyhjat
 * Tarkistaa, onko vektorissa tyhjia arvoja.
 * @param syote
 * Vektori, jonka sisalla merkkijono.
 * @return
 * Palauttaa totuusarvon false jos tyhjia loytyy.
 * True jos ei loydy.
 */
bool tarkistaTyhjat(vector<string> syote)
{
    for(auto& c : syote)
    {
        if(c.empty() || c == " ")
        {
            return false;
        }
                {

        }

    }
    return true;
}


/**
 * @brief avaa_tiedosto
 * Avaa tiedoston, tulostaa virheilmoituksen jos sita ei saada auki.
 * Tulostaa virheilmoituksen jos tiedosto ei ole sallitussa muodossa.
 * Kutsuu lisaaPelaaja_funktiota.
 * @param tiedoston_nimi
 * Tiedoston nimi, jota aukaistaan.
 * @param tilastot
 * Map-sailio, jonne tiedot halutaan tallettaa.
 * @return
 * Palauttaa totuusarvon true jos tiedosto saadaan onnistuneesti auki ja se on
 * oikeanmuotoinen. Muussa tapauksessa palauttaa totuusarvon false.
 */
bool avaa_tiedosto(std::string tiedoston_nimi, STAT& tilastot)
{
    std::vector<std::string> syote = {};
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
            if(syote.size() != TIEDOSTON_RIVIN_KOKO||(!tarkistaTyhjat(syote)))
            {
                std::cout<<"Error: Invalid format in file."<<std::endl;
                return false;
                break;
            }
            lisaaPelaaja(syote, tilastot);
        }
        input.close();
        return true;
    }
}


/**
 * @brief syoteIsoksi
 * Ottaa parametrina vektorin, jonka ensimmaisen merkkijonon
 * merkit muuttaa isoiksi.
 * @param syote
 * Vektori, jonka sisalla on merkkijono, jota halutaan
 * muokata.
 * @return
 * Palauttaa vektorin, jossa ensimmainen merkkijono on korvattu
 * samalla sanalla isona.
 */
vector<string> syoteIsoksi(vector<string> syote)
{
    string sana_isona = "";
    string sana = syote.at(0);
    for(unsigned int i = 0; i < sana.size();i++)
    {
        sana_isona.push_back(toupper(sana.at(i)));
    }
    syote.at(0) = sana_isona;
    return syote;
}


/**
 * @brief komentoLuvuksi
 * Tulkitsee annetut komennot ja muuttaa ne
 * numeeriseksi.
 * @param komento
 * Vektori, jonka sisalla olevan merkkijonon sisalto
 * halutaan tulkita.
 * @return
 * Palauttaa int-muuttujan, joka riippuu komennosta.
 */
int komentoLuvuksi(std::vector<std::string> komento)
{
    if(komento.at(0) == "ALL_GAMES")
    {
        return 1;
    }
    if(komento.at(0) == "ALL_PLAYERS")
    {
        return 2;
    }
    if(komento.at(0)== "PLAYER")
    {
       return 3;
    }
    if(komento.at(0)== "ADD_GAME")
    {
        return 4;
    }
    if(komento.at(0)== "ADD_PLAYER" && komento.size() >= PELAAJAN_KOKO)
    {
        return 5;
    }
    if(komento.at(0)== "REMOVE")
    {
        return 6;
    }
    if(komento.at(0)== "GAME" && komento.size() >= PELIN_PARAMETRIT)
    {
        return 7;
    }
    if(komento.at(0)== "QUIT")
    {
        return 8;
    }
    else return 9;
}


/**
 * @brief syotaKomentoja
 * Kutsuu halutun komennon suorittavaa funktiota.
 * Ohjelman kayttoliittyma.
 * @param tilastot
 * Map-sailio, jota halutaan kasitella.
 */
void syotaKomentoja(STAT tilastot)
{
    bool jatketaanko = true;
    while(jatketaanko)
    {
        string komento = "";
        std::cout<<"games> ";
        std::getline(std::cin, komento);
        std::vector<std::string> syote  = split(komento, ' ');
        syote = syoteIsoksi(syote);
        int komento_lukuna = komentoLuvuksi(syote);
        switch(komento_lukuna){
        case 1:
            kaikkiPelit(tilastot);
            break;
        case 2:
            kaikkiPelaajat(tilastot);
            break;
        case 3:
            pelaaja(syote.at(1), tilastot);
            break;
        case 4:
            lisaaPeli(syote.at(1), tilastot);
            break;
        case 5:
            uusiPelaaja(syote.at(1), syote.at(2),syote.at(3), tilastot);
            break;
        case 6:
            poistaPelaaja(syote.at(1), tilastot);
            break;
        case 7:
            naytaPeli(syote.at(1),tilastot);
            break;
        case 8:
            jatketaanko = false;
            break;
        default:
            std::cout<<"Error: Invalid input."<<std::endl;
        }
    }

}


/**
 * @brief main
 * Kutsutaan ainoastaan funktiota, joissa sitten suoritetaan ohjelman
 * toimintoja.
 * @return
 * Palauttaa EXIT_FAILURE tai EXIT_SUCCESS.
 */
int main()
{
    STAT tilastot;
    std::string jono = "";
    std::cout <<"Give a name for input file: ";
    std::getline(std::cin,jono);
    if(!avaa_tiedosto(jono, tilastot))
    {
        return EXIT_FAILURE;
    }
    syotaKomentoja(tilastot);
    return EXIT_SUCCESS;
}





