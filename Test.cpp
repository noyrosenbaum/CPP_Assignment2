#include "doctest.h"
#include "./sources/game.hpp"
#include "./sources/player.hpp"
#include "./sources/card.hpp"
#include <iostream>
using namespace ariel;

TEST_CASE("Test Player Class")
{
    Player p1("Alice");
    Player p2("Bob");
    REQUIRE(p1.cardesTaken() >= 0);
    REQUIRE(p2.cardesTaken() >= 0);

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
}

TEST_CASE("Test Game Class")
{
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
