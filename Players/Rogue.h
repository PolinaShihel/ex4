#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H
#include <utility>

#include "Player.h"

static const int COINS_DOUBLED = 2;

class Rogue : public Player{
public:

    /*
     * C'tor of Rogue class
     *
     * @param name - The Rogue's name.
     * @return
     *      A new instance of Rogue.
    */
    Rogue(string& name) :
            Player(name) {}

    /*
     * Increases number of coins a Rogue player has by a double the given amount.
     *
     * @param addedCoins - The number of coins to be added to the player
     * @return
     *      void.
     */
    void addCoins(int addedCoins) override;

    /*
     * Prints info of Rogue:
     *
     * @return
     *      void
    */
    void printInfo() const;
};

#endif //EX4_ROGUE_H
