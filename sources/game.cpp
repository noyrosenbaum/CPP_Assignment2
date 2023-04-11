#include <string>
#include <iostream>
#include <algorithm>
#include "game.hpp"
#include "player.hpp"
using namespace std;

using namespace ariel;

Game::Game(Player &p1, Player &p2) : first_player(p1), second_player(p2){};
void Game::playTurn()
{
    if (&first_player == &second_player)
        throw "A game must contains 2 individuals";

    if (this->first_player.stacksize() == 0 || this->second_player.stacksize() == 0)
        throw "Game has ended\n";
    printWiner();
};
void Game::printLastTurn(){};
void Game::playAll()
{
    while (this->first_player.stacksize() > 0 || this->second_player.stacksize() > 0)
    {
        playTurn();
    }
};
void Game::printWiner()
{
    if (first_player.stacksize() > second_player.stacksize())
    {
        cout << "Winner is first player" << endl;
    }
    else if (first_player.stacksize() < second_player.stacksize())
    {
        cout << "Winner is second player" << endl;
    }
    else
        cout << "No one wins" << endl;
};
void Game::printLog(){};
void Game::printStats(){};
void Game::shuffle(vector<Card> &deck)
{
    random_shuffle(deck.begin(), deck.end());
};
void initializeDeck(vector<Card> &deck)
{
    if (!deck.empty())
    {
        deck.clear();
    }
    for (int value = 1; value <= 13; value++)
    {
        deck.push_back((Card(Hearts, values(value))));
        deck.push_back((Card(Clubs, values(value))));
        deck.push_back((Card(Diamonds, values(value))));
        deck.push_back((Card(Spades, values(value))));
    }
}
void Game::devide(vector<Card> &deck)
{
    for (int cardValue = 0; cardValue < deck.size(); cardValue++)
    {
        if(cardValue % 2){
            this->first_player.setPile(deck[cardValue]);
        }
        this->second_player.setPile(deck[cardValue]);
    }
}
