#include "book.hh"
#include <iostream>

Book::Book(const string &kirjoittaja, const string &kirja): kirjoittaja_(" "), kirja_(" "), lainattu_(0,0, 0)

{  
}

void Book::print() const
{
    std::cout<<kirjoittaja_<<kirja_<<std::endl;
}

void Book::loan(Date lainattu)
{

}

void Book::renew()
{

}

void Book::give_back()
{

}
