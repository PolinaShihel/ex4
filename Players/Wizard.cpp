#include "Wizard.h"

string Wizard::getPlayerJob() const {
    return jobs[WIZARD];
}

void Wizard::heal(int points)
{
    Player::heal(points * HEALTH_DOUBLED);
}

Player* Wizard::clone() const
{
    return new Wizard(*this);
}

