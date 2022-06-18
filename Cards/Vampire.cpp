#include "Vampire.h"
#include "Vampire.h"

using std::string;

Vampire::Vampire() : BattleCard(VAMPIRE_CARD_NAME, VAMPIRE_FORCE, VAMPIRE_LOOT, VAMPIRE_DAMAGE)
{
}

Vampire* Vampire::Clone() const
{
	return new Vampire(*this);
}

void Vampire::onLost(Player& player) const
{
	player.damage(m_damage);
	player.decreaseForce(FORCE_POINTS_DECREASED_ON_LOST);
}

string Vampire::getMonsterName() const
{
    return VAMPIRE_CARD_NAME;
}