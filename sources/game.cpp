#include <string>
#include <iostream>
#include <algorithm>
#include "game.hpp"
#include "player.hpp"
using namespace std;
using namespace ariel;

Game::Game(Player &p1, Player &p2) : first_player(p1), second_player(p2)
{
    turnCounter = 0;
    this->drawCounter = 0;
    this->first_player = p1;
    this->second_player = p2;
    initializeDeck(deck);
    shuffle(deck);
    devide(deck);
};
void Game::playTurn()
{
    if (&first_player == &second_player)
        throw "A game must contains 2 individuals";

    if (this->first_player.stacksize() == 0 || this->second_player.stacksize() == 0)
        throw "Game has ended\n";
    printWiner();

    this->turnCounter++;
    Card card1 = this->first_player.removeTopCard();
    Card card2 = this->second_player.removeTopCard();
    string log = this->first_player.getName() + "played " + card1.getSign() + this->second_player.getName() + "played " + card2.getSign();
    turn.push_back(log);
    int result = compareTo(card1, card2);
    if (result == 0)
    {
        this->drawCounter++;
    }
};
void Game::printLastTurn()
{
    if (!turn.empty())
    {
        string lastTurn = turn.back();
        cout << lastTurn << endl;
    }
    cout << "No move was made" << endl;
};
void Game::playAll()
{
    while (!(this->first_player.stacksize() == 0) || !(this->second_player.stacksize() == 0))
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
void Game::printLog()
{
    for (auto log : turn)
    {
        cout << log;
    }
};
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
        if (cardValue % 2)
        {
            this->first_player.setPile(deck[cardValue]);
        }
        this->second_player.setPile(deck[cardValue]);
    }
}
int compareTo(Card &card1, Card &card2)
// ace wins everyone besides 2, 2 wins ace but loses everyone else
// 1 - win
// 0 - tie
// -1 - lose
{
    if (card1.getValue() == card2.getValue())
        return 0;
    if (card1.getValue() > "2" && card2.getValue() > "2")
    {
        if (card1.getValue() > card2.getValue())
            return 1;
        else
            return -1;
    }
    else if (card1.getValue() == "2")
    {
        if (card2.getValue() == "1")
            return 1;
        else
            return -1;
    }
    else if (card1.getValue() == "1")
    {
        if (card2.getValue() == "2")
            return -1;
        else
            return 1;
    }
}
