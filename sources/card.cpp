#include "card.hpp"
#include <string>
#include <iostream>
using namespace std;
using namespace ariel;

Card::Card(sign Sign, values Value)
{
    this->Sign = Sign;
    this->Value = Value;
}
string Card::getValue()
{
    switch (this->Value)
    {
    case Ace:
        return "Ace";
        break;
    case Two:
        return "Two";
        break;
    case Three:
        return "Three";
        break;
    case Four:
        return "Four";
        break;
    case Five:
        return "Five";
        break;
    case Six:
        return "Six";
        break;
    case Seven:
        return "Seven";
        break;
    case Eight:
        return "Eight";
        break;
    case Nine:
        return "Nine";
        break;
    case Ten:
        return "Ten";
        break;
    case Jack:
        return "Jack";
        break;
    case Queen:
        return "Queen";
        break;
    case King:
        return "King";
        break;
    default:
        return "Ace";
        break;
    }
}
string Card::getSign()
{
    switch (this->Sign)
    {
    case Hearts:
        return "Hearts";
        break;
    case Spades:
        return "Spades";
        break;
    case Clubs:
        return "Clubs";
        break;
    case Diamonds:
        return "Diamonds";
        break;
    default:
        return "Hearts";
    }
};
