#include "Treasure.h"

Treasure* Treasure::Clone() const 
{
	return new Treasure(*this);
}

void Treasure::applyEncounter(Player& player) const
{
	player.addCoins(TREASURE_VALUE);
	printTreasureMessage();
}