#include "Fighter.h"

int Fighter::getAttackStrength() const
{
    return FORCE_DOUBLED* Player::getForce() + Player::getLevel();
}
void Fighter::printInfo() const
{
    Player::printInfo(FIGHTER);
}



