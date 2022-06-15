#include "Goblin.h"

using std::string;

Goblin* Goblin::Clone() const
{
	return new Goblin(*this);
}

void Goblin::onLost(Player& player) const
{
	player.damage(getMonsterDamage());
}

int Goblin::getMonsterForce() const
{
	return GOBLIN_FORCE;
}

int Goblin::getMonsterLoot() const
{
	return GOBLIN_LOOT;
}

int Goblin::getMonsterDamage() const
{
	return GOBLIN_DAMAGE;
}

string Goblin::getMonsterName() const
{
    return GOBLIN_CARD_NAME;
}