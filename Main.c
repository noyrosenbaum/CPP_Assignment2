#include "./sources/game.hpp"
#include "./sources/player.hpp"
#include "./sources/card.hpp"
#include <iostream>
#include <assert.h>
#include <vector>
#include <string>

using namespace ariel;

int main()
{
    // Init player class
    Player p1("Alice");
    Player p2("Bob");
    assert((p1.getName(), "Alice") == TRUE);
    assert((p2.getName(), "Bob") == TRUE);
    // Initial pile
    assert((p1.stacksize(), 26) == TRUE);
    assert((p2.stacksize(), 26) == TRUE);
    // player final number of cards when there was no change
    assert((p1.cardesTaken(), 0) == TRUE);
    assert((p1.cardesTaken(), 0) == TRUE);
    // player total cards combining 2 players
    assert((p1.stacksize() + p1.cardesTaken() + p2.stacksize() + p2.cardesTaken(), 52) == TRUE);
    // init Game class
    Game game(p1, p2);
    int i;
    // Game initialization eith no war
    while (i++ < 5)
    {
        game.playTurn();
        assert((p1.cardesTaken() + p2.cardesTaken(), 0) == TRUE);
        assert((p1.stacksize() + p2.stacksize(), 42) == TRUE);
    }
    while (i++ < 5)
    {
        game.playTurn();
        assert((p1.cardesTaken() + p2.cardesTaken(), 26) == TRUE);
        assert((p1.stacksize() + p2.stacksize(), 52) == TRUE);
    }
    // game play all
    game.playAll();
    assert((p1.cardesTaken() || p2.cardesTaken(), 26) == TRUE);
    assert((p1.stacksize() || p2.stacksize(), 0) == TRUE);

    return 0;
}
