#include <string>
#define PLAYER_HPP
#include "card.hpp"
#pragma once
using namespace std;
namespace ariel
{
    class Player
    {
    public:
        string name;
        Player(string name);
        int stacksize();
        int cardsTaken();
    };
};