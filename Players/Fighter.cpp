#include "Fighter.h"

int Fighter::getAttackStrength() const
{
    return FORCE_DOUBLED* Player::getForce() + Player::getLevel();
}
string Fighter::getPlayerJob() const {
    return jobs[FIGHTER];
}

Player* Fighter::clone() const
{
    return new Fighter(*this);
}

