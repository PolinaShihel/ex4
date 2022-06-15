#include "Vampire.h"

using std::string;

Vampire* Vampire::Clone() const
{
	return new Vampire(*this);
}

void Vampire::onLost(Player& player) const
{
	player.damage(getMonsterDamage());
	player.decreaseForce(FORCE_POINTS_DECREASED_ON_LOST);
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