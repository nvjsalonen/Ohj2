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
    is_green_ = true;
    print();
    string ajoneuvo;
    int maara = cycle_;
    for(int i = 0;i < maara;i++)
    {
    dequeue();
    }
    is_green_ = false;
}

void Queue::reset_cycle(unsigned int cycle)
{
    cycle_ = cycle;
}

void Queue::print() const
{
    Vehicle* tulostettava_auto = first_;

    if(!is_green_)
    {
        cout<<"Red: Vehicle(s) ";
        while ( tulostettava_auto != nullptr ) {
            cout << tulostettava_auto->reg_num <<" ";
            tulostettava_auto = tulostettava_auto->next;
        }
        cout<<" waiting in traffic lights"<<endl;
    }
    else{
        cout<<"Green: Vehicle(s) ";
        for (unsigned int i= 0;i < 3;i++) {
            cout << tulostettava_auto->reg_num <<" ";
            tulostettava_auto = tulostettava_auto->next;
        }
        cout<<" can go on"<<endl;
    }

}

