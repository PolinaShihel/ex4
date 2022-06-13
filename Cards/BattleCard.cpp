#include "BattleCard.h"
#include "BattleCard.h"

using std::ostream;

void BattleCard::applyEncounter(Player& player) const
{
	if (player.getAttackStrength() >= getMonsterForce()) {
		player.levelUp();
		player.addCoins(getMonsterLoot());
	}
	else {
		onLost(player);
	}
}

void BattleCard::printAdditionalDetails(std::ostream& os) const
{
	printMonsterDetails(os, getMonsterForce(), getMonsterDamage(), getMonsterLoot());
}
