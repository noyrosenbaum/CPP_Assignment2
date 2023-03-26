#include <string>
#define PLAYER_HPP
#include "card.hpp"
#pragma once
using namespace std;
namespace ariel
{
    class Player
    {
    private:
        string name;
        int pile = 26;
    public:
        Player(string name);
        int stacksize(); // player's current pile
        int cardsTaken();
        string getName();
    };
};