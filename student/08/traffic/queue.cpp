#include "queue.hh"
#include <string>
#include <iostream>
using namespace std;
// Implement the member functions of Queue here



Queue::Queue(unsigned int cycle)
{
    cycle_ = cycle;
}

Queue::~Queue()
{
    
}

void Queue::enqueue(const string &reg)
{
    Vehicle* uusi_auto = new Vehicle{reg, nullptr};

    if ( first_ == nullptr) {
       first_ = uusi_auto;
       last_ = uusi_auto;
       if(is_green_)
       {
       delete uusi_auto;
           cout<<"GREEN: The vehicle "<< reg << " need not stop to wait"<<endl;
       }
    } else {
       last_->next = uusi_auto;
       last_ = uusi_auto;
    }
}

bool Queue::dequeue()
{
    if(first_ == nullptr)
    {
        return false;

    }
    else{

    {
    Vehicle* poistettava_auto = first_;
    if ( first_ == last_ ) {
       first_ = nullptr;
       last_ = nullptr;
    } else {
       first_ = first_->next;
    }

    delete poistettava_auto;
    return true;
}
}
}

void Queue::switch_light()
{
if(is_green_)
{
    is_green_ = false;
    print();
}
else{
    is_green_ = true;
    unsigned int maara = 0;
    if(cycle_ > count())
    {
        maara = count();
        print();
        for(unsigned int i = 0;i < maara;i++)
        {
        dequeue();
        }
        if(maara != 0)
        {
        is_green_ = false;
        }
    }
    else if(count() != 0){
    maara = cycle_;
    print();
    string ajoneuvo;
    for(unsigned int i = 0;i < maara;i++)
    {
    dequeue();
    }
    is_green_ = false;
}
}
}


void Queue::reset_cycle(unsigned int cycle)
{
    cycle_ = cycle;
}

void Queue::print()
{
    if(first_== nullptr)
    {
        if(!is_green_)
        {
                        cout<<"RED: No vehicles waiting in traffic lights"<<endl;
        }
        if(is_green_)
        {
            cout<<"GREEN: No vehicles waiting in traffic lights"<<endl;
        }
    }
    else{
    Vehicle* tulostettava_auto = first_;

    if(!is_green_)
    {

        cout<<"RED: Vehicle(s) ";
        while ( tulostettava_auto != nullptr ) {
            cout << tulostettava_auto->reg_num <<" ";
            tulostettava_auto = tulostettava_auto->next;
        }
        cout<<"waiting in traffic lights"<<endl;
    }
    else{

        unsigned int maara = 0;
        if(cycle_ > count())
        {
            maara = count();
        }
        else{
            maara = cycle_;
        }
        cout<<"GREEN: Vehicle(s) ";
        for (unsigned int i= 0;i < maara;i++) {
            cout << tulostettava_auto->reg_num <<" ";
            tulostettava_auto = tulostettava_auto->next;
        }
        cout<<"can go on"<<endl;
    }

}
}

unsigned int Queue::count()
{
    Vehicle* laskettava_auto = first_;
    unsigned int laskuri = 0;
    while ( laskettava_auto != nullptr ) {
        laskettava_auto = laskettava_auto->next;
    laskuri++;
}
    return laskuri;
}

