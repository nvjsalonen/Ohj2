#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <set>
#include <sstream>
using namespace std;
using DATA_STRUCT = std::map<std::string, std::set<int>>;
int avaaTiedosto(string tiedoston_nimi, DATA_STRUCT &rivit);
void muunnaData(DATA_STRUCT::const_iterator iter);
void tulostaData(DATA_STRUCT const &rivit);

int main()
{
    DATA_STRUCT rivi_data = {};
    string luettavan_tiedoston_nimi;
    cout<<"Input file: ";
    cin>>luettavan_tiedoston_nimi;
    int status = avaaTiedosto(luettavan_tiedoston_nimi, rivi_data);

    tulostaData(rivi_data);
    return status;
}
int avaaTiedosto(string tiedoston_nimi, DATA_STRUCT &rivi_data)
{
    ifstream tiedosto(tiedoston_nimi);
    if(!tiedosto)
    {
          cout<<"Error! The file "<<tiedoston_nimi<<" cannot be opened."<<endl;
          return EXIT_FAILURE;
    }

    string apusana = "";
    string jono = "";
    if(tiedosto){
        int n = 1;
        ifstream tiedosto(tiedoston_nimi);
        string apusana = "";
        string jono = "";
            while(getline(tiedosto,jono))
            {
               istringstream sanat(jono);
               while(sanat >> apusana)
               {
                   if(rivi_data.find(apusana) == rivi_data.end())
                   {
                       rivi_data.insert({apusana, {}});
                   }
                     rivi_data.at(apusana).insert(n);

               }
            n++;

            }
tiedosto.close();
return EXIT_SUCCESS;
        }
        {

    }
}
void muunnaData(DATA_STRUCT::const_iterator iter)
{
      string avain = iter->first;
      set<int> rivi_data = iter->second;

      cout<< avain << " "<< rivi_data.size()<<": ";
      for(set<int>::iterator iter = rivi_data.begin(); iter != rivi_data.end();iter++)
        {
            cout<< *iter;
            if((++iter) != rivi_data.end())
            {
                cout<<", ";
            }
            else{
                cout <<std::endl;
            }
            iter--;
        }


}
void tulostaData(DATA_STRUCT const &rivi_data)
{
    for(DATA_STRUCT::const_iterator iter = rivi_data.begin();iter != rivi_data.end();iter++)
    {
        muunnaData(iter);
    }
}







