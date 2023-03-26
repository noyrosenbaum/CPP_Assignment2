#include <string>
#include <iostream>
#include "player.hpp"
#include "card.hpp"
#define GAME_HPP
#pragma once
using namespace std;

namespace ariel
{
    class game
    {
    private:
        Player *p1;
        Player *p2;
    public:
        game(Player &p1, Player &p2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };

}