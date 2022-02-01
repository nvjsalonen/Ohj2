#ifndef BOOK_HH
#define BOOK_HH
#include<string>
#include "date.hh"
using namespace std;
class Book
{
public:
    Book(const string &kirjoittaja, const string &kirja);
    void print() const;
    void loan(const Date &lainattu);
    void renew();
    void give_back();

private:
    string kirjoittaja_;
    string kirja_;
    Date lainattu_;
    bool available_;
};

#endif // BOOK_HH
