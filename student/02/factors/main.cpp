#include <iostream>

using namespace std;

int main()
{
    int annettu_luku = 0;
    cout << "Enter a positive number: ";
    cin >>annettu_luku;
    if (annettu_luku <= 0)
    {
        cout << "Only positive numbers accepted" << endl;
        return 0;
    }
    int lyhin_matka = annettu_luku;
    int a = 1, b = 1;
    for (int i = 1; i < annettu_luku; i++)
    {
        int n = annettu_luku/i;
        if (i*n == annettu_luku)
        {
            int valimatka = n-i;
            if (valimatka < 0)
            {
                valimatka = -valimatka;
            }
            if (valimatka < lyhin_matka)
            {
                lyhin_matka = valimatka;
                a = i;
                b = n;
            }

            }

        }
    cout << annettu_luku << " = "<< a << " * "<< b << endl;
}




