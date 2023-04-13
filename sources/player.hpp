#pragma once
#include <vector>

#include <string>
#include "card.hpp"

using namespace std;
namespace ariel
{
    class Player
    {
    private:
        string name;
        int cardisTaken;
        int winCard;
        vector<Card> pile;

    public:
        Player(string name);
        int stacksize(); // player's current pile
        int cardesTaken();
        string getName();
        Card removeTopCard();
        void setPile(Card card);
        void setCardIsTaken(int counter);
    };
};