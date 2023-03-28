#include <string>
#include <iostream>
#include "game.hpp"
#include "player.hpp"
using namespace std;

namespace ariel
{
    Game::Game(Player &p1, Player &p2) : first_player(p1), second_player(p2){};
    void Game::playTurn(){};
    void Game::printLastTurn(){};
    void Game::playAll(){};
    void Game::printWiner(){};
    void Game::printLog(){};
    void Game::printStats(){};
}