#include <string>
#include <iostream>
#include "player.hpp"
#include "card.hpp"
using namespace std;

namespace ariel
{
    class game
    {
    private:
        player &p1;
        player &p2;

    public:
        game(player 1, player 2);
        int getValue()
        {
            return value;
        }
        string getSign()
        {
            return sign;
        }
    };
}