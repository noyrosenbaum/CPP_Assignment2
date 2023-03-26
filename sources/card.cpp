#include <string>
#include <iostream>
#include "card.hpp"
using namespace std;

namespace ariel
{
    card::card(string sign, int value)
    {
        this->sign = sign;
        this->value = value;
    }
    string card::getSign()
    {
        return sign;
    }
    int card::getValue()
    {
        return value;
    }
}
