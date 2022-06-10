#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H
#include "Player.h"

static const int FORCE_DOUBLED = 2;

class Fighter : public Player{
public:
    /*
     * C'tor of Fighter class
     *
     * @param name - The Fighter's name.
     * @return
     *      A new instance of Fighter.
    */
    Fighter(string name) : Player(name)
    {}

    /*
    * Copy C'tor for Wizard class
    */
    Fighter(const Fighter& current) = default;
    /*
    * Returns Fighter's attack strength, determined by the sum of double his force & level
    */
    int getAttackStrength() const override;

    /*
     * returns the type of the current player:
     *
     * @return
     *      string correlating to the type pf player
    */
    string getPlayerJob () const override;

    /*
     * An abstract type of Copy C'tor for creating a Fighter player
     * Allows to create the specific type of current player dynamically -  In this case a
     * a Fighter player
     */
    Player* clone() const override;
};


#endif //EX4_FIGHTER_H
