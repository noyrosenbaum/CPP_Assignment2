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
 * playTurn - 
 * 
 **/ 


// Game - tests


// if 2 cards are equal we have a war
// add cards to war pile
// if both players have at least another card
// if any of the players is out of cards - game is over
// if any player win - give them the cards in the pile
#include <iostream>
using namespace ariel;


TEST_CASE("Test Player Class") {
    SUBCASE("Test player name") {
        Player p("Alice");
        CHECK_EQ(p.getName(), "Alice");
    }

    SUBCASE("Test player initial stack size") {
        Player p("Bob");
        CHECK_EQ(p.stacksize(), 26);
    }

    SUBCASE("Test player play card") {
        Player p("Dave");
        card c1(card::DIAMONDS, 9);
        p.addcardToStack(c1);
        CHECK_EQ(p.playcard(), c1);
        CHECK_EQ(p.stacksize(), 25);
    }
}

TEST_CASE("Test Game Class") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    SUBCASE("Test game initialization") {
        CHECK_EQ(game.getTurnNumber(), 0);
    }

    SUBCASE("Test game play turn") {
        game.playTurn();
        CHECK_GT(p1.cardesTaken() + p2.cardesTaken(), 0);
        CHECK_EQ(game.getTurnNumber(), 1);
    }

    SUBCASE("Test game play all") {
        game.playAll();
        CHECK_GT(p1.cardesTaken() + p2.cardesTaken(), 0);
        CHECK_EQ(game.getTurnNumber(), 26);
    }

    SUBCASE("Test game winner") {
        game.playAll();
        CHECK_NE(game.getWinner(), nullptr);
    }

    SUBCASE("Test game stats") {
        game.playAll();
        game.printStats();
    }

    SUBCASE("Test game log") {
        game.playAll();
        CHECK_GT(game.getLog().size(), 0);
    }

    SUBCASE("Test game last turn stats") {
        game.playAll();
        CHECK(game.getLastTurn().size() > 0);
    }

    SUBCASE("Test player stack size after playing") {
        game.playAll();
        CHECK_EQ(p1.stacksize() + p2.stacksize(), 0);
    }
}

