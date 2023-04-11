#pragma once
#include <string>
using namespace std;
namespace ariel
{
    enum values
    {
        Ace = 1,
        Two = 2,
        Three = 3,
        Four = 4,
        Five = 5,
        Six = 6,
        Seven = 7,
        Eight = 8,
        Nine = 9,
        Ten = 10,
        Jack = 11,
        Queen = 12,
        King = 13
    };
    enum sign
    {
        Hearts,
        Spades,
        Diamonds,
        Clubs
    };
    class Card
    {
    private:
        sign Sign;
        values Value;

    public:
        Card(sign Sign, values Value);
        string getValue();
        string getSign();
    };

}
