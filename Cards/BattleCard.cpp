#include "BattleCard.h"

using std::ostream;

void BattleCard::applyEncounter(Player& player) const
{
	if (player.getAttackStrength() >= getMonsterForce()) {
		player.levelUp();
		player.addCoins(getMonsterLoot());
	}
	else {
		player.damage(getMonsterDamage());
		afterLost(player);
	}
}