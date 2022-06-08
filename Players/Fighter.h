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
    Fighter(string& name) :
            Player(name) {}

    /*
    * Returns Fighter's attack strength, determined by the sum of double his force & level
    */
    int getAttackStrength() const override;

    /*
     * Prints info of Fighter:
     *
     * @return
     *      void
    */
    void printInfo() const;
};


#endif //EX4_FIGHTER_H
