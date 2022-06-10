//
// Created by pshih on 08/06/2022.
//

#include "Rogue.h"

void Rogue::addCoins(int addedCoins)
{
    Player::addCoins(COINS_DOUBLED * addedCoins);
}

string Rogue::getPlayerJob() const {
    return jobs[ROGUE];
}

Player* Rogue::clone() const
{
    return new Rogue(*this);
}
