#include "Goblin.h"

using std::string;

Goblin* Goblin::Clone() const
{
	return new Goblin(*this);
}

void Goblin::printAdditionalDetails(std::ostream& os) const
{
	printMonsterDetails(os, getMonsterForce(), getMonsterDamage(), getMonsterLoot());
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
