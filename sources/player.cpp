#include <string>
#include "player.hpp"
using namespace std;

namespace ariel
{
    Player::Player(string name)
    {
        this->name = name;
        this->pile.clear();
    }

    string Player::getName()
    {
        return name;
    }

    int Player::stacksize()
    {
        return pile.size();
    }

    int Player::cardesTaken()
    {
        return 0;
    }
    Card Player::removeTopCard()
    {
        if(!this->pile.empty())
        {
            Card &top = this->pile.back();
            this->pile.pop_back();
            return top;
        }
        throw "Empty pile";
    }
    void Player::setPile(Card card)
    {
        this->pile.push_back(card);
    }
}