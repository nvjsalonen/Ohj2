#ifndef PLAYER_HH
#define PLAYER_HH
#include <string>
using namespace std;

const int WINNING_POINTS = 50;
const int PENALTY_POINTS = 25;

class Player
{
public:
    Player(string name);
    void add_points(int pisteet);
    bool has_won();
    string get_name();
    int get_points();
private:
    int pisteet_;
    string nimi_;

};

#endif // PLAYER_HH
