#include "Wizard.h"

void Wizard::printInfo() const
{
    Player::printInfo(WIZARD);
}

void Wizard::heal(int points)
{
    Player::heal(points * HEALTH_DOUBLED);
}


