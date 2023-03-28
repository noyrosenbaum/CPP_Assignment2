#include <string>
#include "player.hpp"
using namespace std;
namespace ariel
{
    string name;
    Player::Player(string name)
    {
        this->name = name;
    }
    string getName()
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