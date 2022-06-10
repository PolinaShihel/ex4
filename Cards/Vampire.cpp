#include "Vampire.h"

using std::string;

Vampire* Vampire::Clone() const
{
	return new Vampire(*this);
}

void Vampire::afterLost(Player& player) const
{
	player.loseForce(FORCE_POINTS_LOST);
}

void Vampire::printAdditionalDetails(std::ostream& os) const
{
	printMonsterDetails(os, getMonsterForce(), getMonsterDamage(), getMonsterLoot());
}

int Vampire::getMonsterForce() const 
{
	return VAMPIRE_FORCE;
}

int Vampire::getMonsterLoot() const
{
	return VAMPIRE_LOOT;
}

int Vampire::getMonsterDamage() const
{
	return VAMPIRE_DAMAGE;
}