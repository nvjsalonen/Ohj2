#include "book.hh"
#include <iostream>
#include <string>

Book::Book(const string &kirjoittaja, const string &kirja):
    kirjoittaja_(kirjoittaja),
    kirja_(kirja),
    lainattu_(Date()),
    available_(true),
    palautuspaiva_(Date())

{  
}

void Book::print() const
{
    std::cout<<kirjoittaja_<< " : "<<kirja_<<std::endl;
    if(available_)
    {
        cout<<"- available"<<endl;
        return;
    }
    cout<<"- loaned: ";
    lainattu_.print();
    cout<<"- to be returned: ";
    palautuspaiva_.print();



}

void Book::loan(const Date &lainattu)
{
    if(!available_)
    {
        cout<<"Already loaned: cannot be loaned"<<endl;
        return;
    }
    lainattu_ = lainattu;
    available_= false;
    palautuspaiva_= lainattu_;
    palautuspaiva_.advance(28);

}

void Book::renew()
{
    if(available_)
    {
        cout <<"Not loaned: cannot be renewed"<<endl;
        return;
    }
    palautuspaiva_.advance(28);
}

void Book::give_back()
{
     available_ = true;
}

