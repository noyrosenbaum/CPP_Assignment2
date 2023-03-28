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
        int pile;
    public:
        Player(string name);
        int stacksize(); // player's current pile
        int cardesTaken();
        string getName();
    };
};