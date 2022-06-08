#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H
#include "Player.h"

static const int HEALTH_DOUBLED = 2;

class Wizard : public Player {
public:
    /*
     * C'tor of Wizard class
     *
     * @param name - The Wizard's name.
     * @return
     *      A new instance of Wizard.
    */
    Wizard(string& name):
            Player(name){}

    /*
     * Increases the Wizard's health points by a double the given value.
     *
     * @param points - the value that the health points are to be increased by.
     * @return
     *      void.
     */        
    void heal(int points) override;
    
    /*
     * Prints info of Wizard:
     *
     * @return
     *      void
    */
    void printInfo() const;
};
#endif //EX4_WIZARD_H
