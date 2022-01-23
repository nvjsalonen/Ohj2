#include <iostream>

using namespace std;

int main()
{

    long int pallojen_maara;
    long int nostetut_pallot;
    long int erotusten_faktori (int n, int p);
    long int maaran_faktori (int n);
    long int nostettujen_faktori (int n);
    long int todennakoisyys (int n, int p);

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
long int maaran_faktori (int n)
{
   long int luku = 1;
   for (int i = 1; i < n;++i)
       {
       luku *= i+1;
        }
return luku;
}

long int nostettujen_faktori (int n)
{
   long int faktori= 1;
   for (int i = 1; i < n;++i)
       {
       faktori *= i+1;
}
return faktori;

}

long int erotusten_faktori (int n, int p)
{
    long  int erotus = n-p;
    long int faktori = 1;
    for (int i = 1; i < erotus;++i)
        {
        faktori *= i+1;
}
    return faktori;

}
 long int todennakoisyys (int n, int p)

{
  long int ylakerta = maaran_faktori(n);
  long int erotus_faktori = erotusten_faktori(n, p);
  long int nostettu_faktori = nostettujen_faktori(p);
  long int tulos = ylakerta/(erotus_faktori * nostettu_faktori);
   return tulos;
}



