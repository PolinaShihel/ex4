#include "Fighter.h"
using std::string;

int Fighter::getAttackStrength() const
{
    return FORCE_DOUBLED* Player::getForce() + Player::getLevel();
}
string Fighter::getPlayerJob() const {
    return FIGHTER;
}

Player* Fighter::clone() const
{
    return new Fighter(*this);
}

