#include "Wizard.h"
using std::string;

string Wizard::getPlayerJob() const
{
    return NAME_OF_WIZARD;
}

void Wizard::heal(int points)
{
    Player::heal(points * HEALTH_DOUBLED);
}

Player* Wizard::clone() const
{
    return new Wizard(*this);
}

