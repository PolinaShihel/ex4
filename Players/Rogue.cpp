//
// Created by pshih on 08/06/2022.
//

#include "Rogue.h"

void Rogue::addCoins(int addedCoins)
{
    Player::addCoins(COINS_DOUBLED * addedCoins);
}

void Rogue::printInfo() const
{
    Player::printInfo(ROGUE);
}

