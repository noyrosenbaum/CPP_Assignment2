#pragma once

#include <string>
#include "card.hpp"

using namespace std;
namespace ariel
{
    class Player
    {
    private:
        string name;
        int pile;
    public:
        Player(string name);
        int stacksize(); // player's current pile
        int cardesTaken();
        string getName();
    };
};