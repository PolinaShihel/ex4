#include "Rogue.h"

using std::string;
void Rogue::addCoins(int addedCoins)
{
    Player::addCoins(COINS_DOUBLED * addedCoins);
}

string Rogue::getPlayerJob() const {
    return NAME_OF_ROGUE;
}

Player* Rogue::clone() const
{
    return new Rogue(*this);
}
