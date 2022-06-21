#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H
#include <utility>

#include "Player.h"

static const std::string NAME_OF_ROGUE = "Rogue";
static const int COINS_DOUBLED = 2;

class Rogue : public Player {
public:

    /*
     * C'tor of Rogue class
     *
     * @param name - The Rogue's name.
     * @return
     *      A new instance of Rogue.
    */
    Rogue(std::string name) : Player(name)
    {}

    /*
    * Copy C'tor for Wizard class
    */
    Rogue(const Rogue& current) = default;

    /*
     * Increases number of coins a Rogue player has by a double the given amount.
     *
     * @param addedCoins - The number of coins to be added to the player
     * @return
     *      void.
     */
    void addCoins(int addedCoins) override;

    /*
     * returns the type of the current player:
     *
     * @return
     *      string correlating to the type pf player
    */
    std::string getPlayerJob () const override;

    /*
    * An abstract type of Copy C'tor for creating a Rogue player
    *  Allows to create the specific type of current player dynamically
    */
    Player* clone() const override;
};

#endif //EX4_ROGUE_H
