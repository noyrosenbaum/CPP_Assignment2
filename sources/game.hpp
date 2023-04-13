#pragma once

#include "player.hpp"
#include "card.hpp"
#include <vector>

using namespace std;

namespace ariel
{
    class Game
    {
    private:
        Player first_player;
        Player second_player;
        vector<string> turn;
        vector<Card> deck;
        vector<Card> winCards;
        int turnCounter;
        int drawCounter;
        int cardCounter1;
        int cardCounter2;

    public:
        Game(Player &p1, Player &p2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void shuffle(vector<Card> &deck);
        void devide(vector<Card> &deck);
        void initializeDeck(vector<Card> &deck);
        int compareTo(Card &card1, Card &card2);
    };
}