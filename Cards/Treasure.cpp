#include "Treasure.h"

void Treasure::applyEncounter(Player& player) const override
{
	player.addCoins(TREASURE_VALUE);
	printTreasureMessage();
}