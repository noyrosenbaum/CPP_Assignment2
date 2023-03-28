#include "doctest.h"
#include "./sources/game.hpp"
#include "./sources/player.hpp"
#include "./sources/card.hpp"

// Tests using Demo's functionality only

/**
 * Player - tests
 * constructor:
 * name - enter/initiale name, when it is NULL, another type like integer
 * stack/pile - check it we have for each player 26 cards - stack size
 * Demo's functions:
 * stacksize - should be 21 at the end of a game or less so after we run playTurn we should get <=21
 * cardsTaken - cant be less than 0
 *
 * Game - tests
 * constructor:
 * check if we entered 2 players by the rules of players
 * Demo's functions:
 * playLastTurn - ckeck if there is no errors
 * playTurn -
 * playAll - check if we do 5 rounds and each round has a winner
 * printWiner -
 * printLog - prints detail of the card in every turn by order
 * printStats -
 **/

// Game - tests

// if 2 cards are equal we have a war
// add cards to war pile
// if both players have at least another card
// if any of the players is out of cards - game is over
// if any player win - give them the cards in the pile
#include <iostream>
using namespace ariel;

TEST_CASE("Test Player Class")
{
    Player p1("Alice");
    Player p2("Bob");
    REQUIRE(p1.cardesTaken() >= 0);
    REQUIRE(p2.cardesTaken() >= 0);
    /**
     * Player - tests
     * constructor:
     * name - enter/initiale name, when it is NULL, another type like integer
     * stack/pile - check it we have for each player 26 cards - stack size
     * Demo's functions:
     * stacksize - should be 21 at the end of a game or less so after we run playTurn we should get <=21
     * cardsTaken - cant be less than 0
     */
    SUBCASE("Test player name")
    {
        CHECK_EQ(p1.getName(), "Alice");
        CHECK_EQ(p2.getName(), "Bob");
    }

    SUBCASE("Test player initial stack size")
    {
        CHECK_EQ(p1.stacksize(), 26);
        CHECK_EQ(p2.stacksize(), 26);
    }
    SUBCASE("Test player final number of cards when there was no change")
    {
        CHECK_EQ(p1.cardesTaken(), 0);
        CHECK_EQ(p2.cardesTaken(), 0);
    }
    SUBCASE("Test player total cards combining 2 players")
    {
        CHECK_EQ(p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken(), 52);
    }

    // SUBCASE("Test player play card")
    // {
    //     Player p("Dave");
    //     card c1(card::DIAMONDS, 9);
    //     p.addcardToStack(c1);
    //     CHECK_EQ(p.playcard(), c1);
    //     CHECK_EQ(p.stacksize(), 25);
    // }
}

TEST_CASE("Test Game Class")
{
    /**
     * Game - tests
     * constructor:
     * check if we entered 2 players by the rules of players
     * Demo's functions:
     * playLastTurn - ckeck if there is no errors
     * playTurn -
     * playAll - check if we do 5 rounds and each round has a winner
     * printWiner -
     * printLog - prints detail of the card in every turn by order
     * printStats -
     */
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    int i;

    SUBCASE("Test game initialization")
    {
        CHECK_THROWS_WITH(Game(p1, p1), "A game contains 2 individuals");
    }

    SUBCASE("Test game play turn")
    {
        SUBCASE("Test no war")
        {
            while (i++ < 5)
            {
                game.playTurn();
                CHECK_EQ(p1.cardesTaken() + p2.cardesTaken(), 0);
                CHECK_EQ(p1.stacksize() + p2.stacksize(), 42);
            }
        }
        SUBCASE("Test player has 0 cards after a war")
        {
            while (i++ < 5)
            {
                game.playTurn();
                CHECK_EQ(p1.cardesTaken() + p2.cardesTaken(), 26);
                CHECK_EQ(p1.stacksize() + p2.stacksize(), 52);
            }
        }
    }

    SUBCASE("Test game play all")
    {
        game.playAll();
        CHECK_EQ(p1.cardesTaken() || p2.cardesTaken(), 26);
        CHECK_EQ(p1.stacksize() || p2.stacksize(), 0);
    }

    SUBCASE("Test game winner")
    {
        game.playAll();
        CHECK_THROWS(game.printWiner());
    }

    SUBCASE("Test game stats")
    {
        game.playAll();
        CHECK_THROWS(game.printStats());
    }

    SUBCASE("Test game log")
    {
        game.playAll();
        CHECK_THROWS(game.printLog());
    }

    SUBCASE("Test game last turn stats")
    {
        game.playAll();
        CHECK_THROWS(game.printLastTurn());
    }
}
