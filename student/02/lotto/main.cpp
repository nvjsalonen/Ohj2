#include <iostream>

using namespace std;

int main()
{

    int pallojen_maara;
    int nostetut_pallot;
    unsigned long int erotusten_faktori (int n, int p);
    unsigned long int maaran_faktori (int n);
    unsigned long int nostettujen_faktori (int n);
    unsigned long int todennakoisyys (int n, int p);

    cout<<"Enter the total number of lottery balls: ";
    cin >>pallojen_maara;
    cout<<"Enter the number of drawn balls: ";
    cin >>nostetut_pallot;
    if (pallojen_maara <= 0)
    {
        cout << "The number of balls must be a positive number."<<endl;
        return 0;
    }
    if (nostetut_pallot > pallojen_maara)
    {
        cout << "The maximum number of drawn balls is the total amount of balls."<<endl;
        return 0;
    }
    cout<< "The probability of guessing all "<< nostetut_pallot<<" balls correctly is 1/"<< todennakoisyys(pallojen_maara, nostetut_pallot)<<endl;


}
unsigned long int maaran_faktori (int n)
{
    unsigned long int luku = 1;
   for (int i = 1; i < n;++i)
       {
       luku *= i+1;
        }
return luku;
}

unsigned long int nostettujen_faktori (int n)
{
    unsigned long int faktori= 1;
   for (int i = 1; i < n;++i)
       {
       faktori *= i+1;
}
return faktori;

}

unsigned long int erotusten_faktori (int n, int p)
{
    unsigned long  int erotus = n-p;
   unsigned long int faktori = 1;
    for (int i = 1; i < erotus;++i)
        {
        faktori *= i+1;
}
    return faktori;

}
unsigned long int todennakoisyys (int n, int p)

{
   unsigned long int ylakerta = maaran_faktori(n);
   unsigned long int erotus_faktori = erotusten_faktori(n, p);
   unsigned long int nostettu_faktori = nostettujen_faktori(p);
   unsigned long int tulos = ylakerta/(erotus_faktori * nostettu_faktori);
   return tulos;
}



