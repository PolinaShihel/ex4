#include "Fighter.h"
using std::string;

int Fighter::getAttackStrength() const
{
    return FORCE_DOUBLED* Player::getForce() + Player::getLevel();
}
string Fighter::getPlayerJob() const {
    return NAME_OF_FIGHTER;
}

Player* Fighter::clone() const
{
    return new Fighter(*this);
}

