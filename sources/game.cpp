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
    winCards.empty();
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
    // Start a normal turn
    this->turnCounter++;
    Card card1 = this->first_player.removeTopCard();
    Card card2 = this->second_player.removeTopCard();
    // Push cards into winner's card pile per turn
    winCards.push_back(card1);
    winCards.push_back(card2);
    string log = this->first_player.getName() + "played " + card1.getSign() + this->second_player.getName() + "played " + card2.getSign();
    turn.push_back(log);
    int result = compareTo(card1, card2);
    // Tie
    if (result == 0)
    {
        cout << "Draw! Each player puts one card face down and draws another." << endl;
        this->drawCounter++;
        if (this->first_player.stacksize() == 0 || this->second_player.stacksize() == 0)
            return;

        Card hiddenCard1 = this->first_player.removeTopCard();
        Card hiddenCard2 = this->second_player.removeTopCard();
        Card openCard1 = this->first_player.removeTopCard();
        Card openCard2 = this->second_player.removeTopCard();
        // Push cards into winner's card pile when there's a tie
        winCards.push_back(hiddenCard1);
        winCards.push_back(hiddenCard2);
        winCards.push_back(openCard1);
        winCards.push_back(openCard2);
        int tieResult = compareTo(openCard1, openCard2);
        // Tie results
        if (tieResult == 0)
        {
            // gets out of this condition if one of the players takes the whole pile
            if (!winCards.empty())
            {
                // gets out of this loop when there are no cards left
                while (this->first_player.stacksize() > 0 && this->second_player.stacksize() > 0)
                {
                    cout << "Draw! Continuing with another draw round..." << endl;
                    this->drawCounter++;
                    if (this->first_player.stacksize() > 0)
                    {
                        Card newCard1 = this->first_player.removeTopCard();
                        this->first_player.setPile(newCard1);
                    }
                    if (this->second_player.stacksize() > 0)
                    {
                        Card newCard2 = this->second_player.removeTopCard();
                        this->second_player.setPile(newCard2);
                    }
                    return;
                }
            }
        }
        // First player wins the tie
        if (tieResult == 1)
        {
            // Wins 6 cards
            cout << this->first_player.getName() << " won the turn!" << endl;
            for (Card win : winCards)
            {
                this->first_player.setPile(win);
            }
            winCards.clear();
        }
        // Second player wins the tie
        else if (tieResult == -1)
        {
            // Wins 6 cards
            cout << this->second_player.getName() << " won the turn!" << endl;
            for (Card win : winCards)
            {
                this->second_player.setPile(win);
            }
            winCards.clear();
        }
        else
        {
            throw "Unexpected result from compareTo function";
        }

        log += "Draw: " + this->first_player.getName() + " put " + hiddenCard1.getSign() + " face down and drew " + newCard1.getSign() + ", " + this->second_player.getName() + " put " + hiddenCard2.getSign() + " face down and drew " + newCard2.getSign() + ". ";
        int result2 = compareTo(newCard1, newCard2);
        if (result2 == 1)
        {
            cout << this->first_player.getName() << " won the draw!" << endl;
            this->first_player.setPile(card1);
            this->first_player.setPile(card2);
            this->first_player.setPile(hiddenCard1);
            this->first_player.setPile(hiddenCard2);
            this->first_player.setPile(newCard1);
            this->first_player.setPile(newCard2);
        }
        else if (result2 == -1)
        {
            cout << this->second_player.getName() << " won the draw!" << endl;
            this->second_player.setPile(card1);
            this->second_player.setPile(card2);
            this->second_player.setPile(hiddenCard1);
            this->second_player.setPile(hiddenCard2);
            this->second_player.setPile(newCard1);
            this->second_player.setPile(newCard2);
        }
        else
        {
            throw "Unexpected result from compareTo function";
        }
    }
    // First player wins normal turn
    else if (result == 1)
    {
        cout << this->first_player.getName() << " won the turn!" << endl;
        for (Card win : winCards)
        {
            this->first_player.setPile(win);
        }
        winCards.clear();
    }
    // Second player wins normal turn
    else if (result == -1)
    {
        cout << this->second_player.getName() << " won the turn!" << endl;
        for (Card win : winCards)
        {
            this->second_player.setPile(win);
        }
        winCards.clear();
    }
    else
    {
        throw "Unexpected result from compareTo function";
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
