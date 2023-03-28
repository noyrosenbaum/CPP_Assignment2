#include <string>
#include <iostream>
#pragma once
#define CARD_HPP
using namespace std;

namespace ariel
{
    class card
    {
    public:
        enum Sign
        {
            HEARTS,
            CLUBS,
            DIAMONDS,
            SPADES
        };
    // we have 13 values - check 
        card(string sign, int value);
        int getValue();
        string getSign();
    private:
        Sign sign;
        int value;
    };
}
