#include <string>
#include <iostream>
#include "player.hpp"
#include "card.hpp"
#define GAME_HPP
#pragma once
using namespace std;

namespace ariel
{
    class Game
    {
    private:
        Player p1;
        Player p2;
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