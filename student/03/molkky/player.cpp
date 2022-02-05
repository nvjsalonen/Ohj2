#include "player.hh"
#include <iostream>
#include <string>


Player::Player(string name):
    pisteet_(0), nimi_(name)
{

}



void Player::add_points(int pisteet)
{
    pisteet_ +=pisteet;
    if(pisteet_ > 50)
    {
        pisteet_=PENALTY_POINTS;
        cout<<nimi_<<" gets penalty points!"<<endl;
    }
}

bool Player::has_won()
{
    if(pisteet_ == WINNING_POINTS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Player::get_name()
{
    return nimi_;
}

int Player::get_points()
{
    return pisteet_;
}
