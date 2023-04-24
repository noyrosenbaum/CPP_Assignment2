#include <string>
#include <iostream>
#include <algorithm>
#include "game.hpp"
#include "player.hpp"
using namespace std;
using namespace ariel;

// takes two parameters, which are references to objects of a Player, and it initializes two member variables of the Game 
Game::Game(Player &p1, Player &p2) : first_player(p1), second_player(p2)
{
    turnCounter = 0;
    cardCounter1 = 0;
    cardCounter2 = 0;
    winCounter1 = 0;
    winCounter2 = 0;
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

    // ----------------- Start a normal turn ------------------ //
    this->turnCounter++;
    Card card1 = this->first_player.removeTopCard();
    Card card2 = this->second_player.removeTopCard();
    // Push cards into winner's card pile per turn
    winCards.push_back(card1);
    winCards.push_back(card2);
    string log = this->first_player.getName() + "played " + card1.getValue() + "of " + card1.getSign() + this->second_player.getName() + "played " + card2.getValue() + "of " + card2.getSign();
    turn.push_back(log);
    // Regular comparison - 1 for player 1, 0 for tie, -1 for player 2 per turn
    int result = compareTo(card1, card2);
    // ----------------- Start a tie ------------------ //
    if (result == 0)
    {
        cout << "Draw! Each player puts one card face down and draws another." << endl;
        turn.push_back("draw. ");
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
        // Compare tie's turn
        int tieResult = compareTo(openCard1, openCard2);
        // Tie results
        while (tieResult == 0)
        {
            // gets out of this loop when there are no cards left
            while (this->first_player.stacksize() > 0 && this->second_player.stacksize() > 0)
            {
                cout << "Draw! Continuing with another draw round..." << endl;
                this->drawCounter++;
                Card newCard1 = this->first_player.removeTopCard();
                Card newCard2 = this->second_player.removeTopCard();
                this->winCards.push_back(newCard1);
                this->winCards.push_back(newCard2);
                // gets out of these conditions if one of the players takes the whole pile
                if (compareTo(newCard1, newCard2) == 1)
                {
                    for (Card win : winCards)
                    {
                        this->first_player.setPile(win);
                    }
                    cardCounter1 += winCards.size();
                    winCounter1++;
                    winCards.clear();
                    turn.push_back(this->first_player.getName() + "wins.");
                    return;
                }
                else if (compareTo(newCard1, newCard2) == -1)
                {
                    for (Card win : winCards)
                    {
                        this->second_player.setPile(win);
                    }
                    cardCounter2 += winCards.size();
                    winCounter2++;
                    winCards.clear();
                    turn.push_back(this->second_player.getName() + "wins.");
                    return;
                }
            }
            // No more cards when tie break
            devide(winCards);
            return;
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
            cardCounter1 += winCards.size();
            winCounter1++;
            winCards.clear();
            turn.push_back(this->first_player.getName() + "wins.");
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
            cardCounter2 += winCards.size();
            winCounter2++;
            winCards.clear();
            turn.push_back(this->second_player.getName() + "wins.");
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
        cardCounter1 += winCards.size();
        winCounter1++;
        winCards.clear();
        turn.push_back(this->first_player.getName() + "wins.");
    }
    // Second player wins normal turn
    else if (result == -1)
    {
        cout << this->second_player.getName() << " won the turn!" << endl;
        for (Card win : winCards)
        {
            this->second_player.setPile(win);
        }
        cardCounter2 += winCards.size();
        winCounter2++;
        winCards.clear();
        turn.push_back(this->second_player.getName() + "wins.");
    }
    else
    {
        throw "Unexpected result from compareTo function";
    }
    // Amount of cards that each one of the players has won.
    this->first_player.setCardIsTaken(cardCounter1);
    this->second_player.setCardIsTaken(cardCounter2);
}

void Game::printLastTurn()
{
    if (!turn.empty())
    {
        string lastTurn = turn.back();
        cout << lastTurn << endl;
    }
    throw "No move was made";
};
void Game::playAll()
{
    while (this->first_player.stacksize() != 0 || this->second_player.stacksize() != 0)
    {
        playTurn();
    }
};
void Game::printWiner()
{

    if (first_player.cardesTaken() > second_player.cardesTaken())
    {
        cout << "Winner is " << first_player.getName() << endl;
    }
    else if (first_player.cardesTaken() < second_player.cardesTaken())
    {
        cout << "Winner is " << second_player.getName() << endl;
    }
    else
        cout << "Game has ended" << endl;

    throw "Unable to print winner";
};
void Game::printLog()
{
    if (!turn.empty())
    {
        for (auto &log : turn)
        {
            cout << log << endl;
        }
    }
    else
        throw "There are no logs to print";
};
void Game::printStats()
{
    if (this->turnCounter != 0)
    {
        cout << "First player: " << first_player.getName() << "stats: " << endl;
        cout << "Win rate: " << (double)winCounter1 / turnCounter << endl;
        cout << "cards won: " << first_player.cardesTaken() << endl;
        cout << "draw rate: " << (double)drawCounter / turnCounter << endl;
        cout << "Amount of draws: " << drawCounter << endl;

        cout << "Second player stats: " << second_player.getName() << endl;
        cout << "Win rate: " << (double)winCounter2 / turnCounter << endl;
        cout << "cards won: " << second_player.cardesTaken() << endl;
        cout << "draw rate: " << (double)drawCounter / turnCounter << endl;
        cout << "Amount of draws: " << drawCounter << endl;
    }
    else
        throw "No stats to print";
};
void Game::shuffle(vector<Card> deck)
{
    random_shuffle(deck.begin(), deck.end());
};
void Game::initializeDeck(vector<Card> deck)
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
void Game::devide(vector<Card> deck)
{
    for (size_t cardValue = 0; cardValue < deck.size(); cardValue++)
    {
        if (cardValue % 2)
        {
            this->first_player.setPile(deck[cardValue]);
        }
        else
        {
            this->second_player.setPile(deck[cardValue]);
        }
    }
}
int Game::compareTo(Card &card1, Card &card2)
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
    else
        throw "Comparison error";
}