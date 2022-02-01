#ifndef BOOK_HH
#define BOOK_HH
#include<string>
#include "date.hh"
using namespace std;
class Book
{
public:
    Book(string const &kirjoittaja, string const &kirja);
    void print() const;
    void loan(Date lainattu);
    void renew();
    void give_back();

private:
    string kirjoittaja_;
    string kirja_;
    Date lainattu_;
};

#endif // BOOK_HH
