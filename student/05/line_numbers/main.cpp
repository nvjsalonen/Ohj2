#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void lueTiedosto(string luettava_tiedosto, string tallennettava_tiedosto);


int main()
{

    string tallennettavan_tiedoston_nimi = "";
    string luettavan_tiedoston_nimi = "";
    cout<<"Input file: ";
    cin>>luettavan_tiedoston_nimi;
    cout<<"Output file: ";
    cin>>tallennettavan_tiedoston_nimi;


    lueTiedosto(luettavan_tiedoston_nimi, tallennettavan_tiedoston_nimi);
}

void lueTiedosto(string luettava_tiedosto, string tallennettava_tiedosto)
{
    int n = 1;
    ofstream output(tallennettava_tiedosto);
    string syote_ulos = "";
    string jono = "";
    ifstream input(luettava_tiedosto);
        if(not input)
        {
            cout<<"Error! The file "<<luettava_tiedosto<<" cannot be opened."<<endl;
            EXIT_FAILURE;
        }
        if(input)
        {


            while(getline(input,jono))
            {

                output<<n<<" ";
                output<<jono;
                output<<endl;
                n += 1;


            }
         input.close();
         output.close();

        }


}




