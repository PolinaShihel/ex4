#include "Dragon.h"

using std::string;

Dragon* Dragon::Clone() const
{
	return new Dragon(*this);
}

void Dragon::afterLost(Player& player) const
{
	player.damage(player.getHealthPoints());
	player.loseForce(player.getForce());
}

void Dragon::printAdditionalDetails(std::ostream& os) const
{
	printMonsterDetails(os, DRAGON_FORCE, DRAGON_DAMAGE, DRAGON_LOOT, true);
}

int Dragon::getMonsterForce() const
{
	return DRAGON_FORCE;
}

int Dragon::getMonsterLoot() const
{
	return DRAGON_LOOT;
}

int Dragon::getMonsterDamage() const
{
	return DRAGON_DAMAGE;
}