#include "Goblin.h"
#include "Goblin.h"

using std::string;

Goblin::Goblin() : BattleCard(GOBLIN_CARD_NAME, GOBLIN_FORCE, GOBLIN_LOOT, GOBLIN_DAMAGE)
{
}

Goblin* Goblin::Clone() const
{
	return new Goblin(*this);
}

void Goblin::onLost(Player& player) const
{
	player.damage(m_damage);
}

string Goblin::getMonsterName() const
{
    return GOBLIN_CARD_NAME;
}