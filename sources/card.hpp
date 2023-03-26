#include <string>
#include <iostream>
#pragma once
#define CARD_HPP
using namespace std;

namespace ariel
{
    class card
    {
    private:
        string sign;
        int value;

    public:
        card(string sign, int value);
        int getValue();
        string getSign();
    };
}
