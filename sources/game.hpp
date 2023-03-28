#pragma once

#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel
{
    class Game
    {
    private:
        Player first_player;
        Player second_player;

    public:
        Game(Player &p1, Player &p2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
}