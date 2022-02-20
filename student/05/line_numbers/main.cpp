#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool lueTiedosto(string luettava_tiedosto, string tallennettava_tiedosto);


int main()
{

    string tallennettavan_tiedoston_nimi = "";
    string luettavan_tiedoston_nimi = "";
    cout<<"Input file: ";
    cin>>luettavan_tiedoston_nimi;
    cout<<"Output file: ";
    cin>>tallennettavan_tiedoston_nimi;


    if(lueTiedosto(luettavan_tiedoston_nimi, tallennettavan_tiedoston_nimi))
    {
            return EXIT_SUCCESS;
     }
    else
    {
            return EXIT_FAILURE;
}
}




bool lueTiedosto(string luettava_tiedosto, string tallennettava_tiedosto)
{

    ifstream input(luettava_tiedosto);
        if(not input)
        {
            cout<<"Error! The file "<<luettava_tiedosto<<" cannot be opened."<<endl;
            return false;
        }
        else{
            int n = 1;
            string jono;
            ofstream output(tallennettava_tiedosto);

            while(getline(input,jono))
            {

                output<<n<<" "<<jono<<endl;
                n += 1;


            }
         input.close();
         output.close();
        return true;
        }


}




