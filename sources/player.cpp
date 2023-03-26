#include <string>
#include "player.hpp"
using namespace std;
namespace ariel
{
    Player::Player(string name)
    {
        this->name = name;
    }
    int Player::stacksize()
    {
        return 0;
    }
    int Player::cardsTaken()
    {
        return 0;
    }
}