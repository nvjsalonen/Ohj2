#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <set>
#include <sstream>
using namespace std;
using DATA_STRUCT = std::map<std::string, std::set<int>>;
bool avaaTiedosto(string tiedoston_nimi, DATA_STRUCT &rivit);


void tulostaData(DATA_STRUCT &rivit);

int main()
{
    DATA_STRUCT rivi_data;
    string luettavan_tiedoston_nimi;
    cout<<"Input file: ";
    cin>>luettavan_tiedoston_nimi;
    if(avaaTiedosto(luettavan_tiedoston_nimi, rivi_data))
    {

        return EXIT_SUCCESS;
    }
    else{
        cout<<"Error! The file "<<luettavan_tiedoston_nimi<<" cannot be opened."<<endl;
        return EXIT_FAILURE;
    }
}
bool avaaTiedosto(string tiedoston_nimi, DATA_STRUCT &rivit)
{
    int n = 1;
    ifstream tiedosto(tiedoston_nimi);
    string apusana = "";
    string jono = "";
    if(!tiedosto){
        {
            return false;
           }

        int n = 1;
        ifstream tiedosto(tiedoston_nimi);
        string apusana = "";
        string jono = "";
            while(getline(tiedosto,jono))
            {
               istringstream sanat(jono);
               while(sanat >> apusana)
               {
                   if(rivit.find(apusana) == rivit.end())
                   {
                       rivit.insert({apusana, {}});
                   }
                     rivit.at(apusana).insert(n);

               }

            }
        }
            return true;
        }






