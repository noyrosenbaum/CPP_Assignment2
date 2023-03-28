#include <string>
#include "player.hpp"
using namespace std;

namespace ariel
{
    Player::Player(string name)
    {
        this->name = name;
    }

    string Player::getName()
    {
        return name;
    }

    int Player::stacksize()
    {
        return pile;
    }

    int Player::cardesTaken()
    {
        return 0;
    }
}