#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H
#include "Player.h"

static const int HEALTH_DOUBLED = 2;
static const std::string NAME_OF_WIZARD = "Wizard";

class Wizard : public Player {
public:
    /*
     * C'tor of Wizard class
     *
     * @param name - The Wizard's name.
     * @return
     *      A new instance of Wizard.
    */
    Wizard(std::string name): Player(name)
    {
    }

    /*
     * Copy C'tor for Wizard class
     */
    Wizard(const Wizard& current) = default;

    /*
     * Increases the Wizard's health points by a double the given value.
     *
     * @param points - the value that the health points are to be increased by.
     * @return
     *      void.
     */        
    void heal(int points) override;
    
    /*
     * returns the type of the current player:
     *
     * @return
     *      string correlating to the type pf player
    */
    std::string getPlayerJob () const override;

    /*
    * An abstract type of Copy C'tor for creating a Wizard player
    *  Allows to create the specific type of current player dynamically
    */
    Player* clone() const override;
};
#endif //EX4_WIZARD_H
