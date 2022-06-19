#include "Dragon.h"

using std::string;

Dragon::Dragon() : BattleCard(DRAGON_CARD_NAME, DRAGON_FORCE, DRAGON_LOOT, DRAGON_DAMAGE)
{
}

Dragon* Dragon::Clone() const
{
	return new Dragon(*this);
}

void Dragon::onLost(Player& player) const
{
	player.knockOut();
}

void Dragon::printAdditionalDetails(std::ostream& os) const
{
	printMonsterDetails(os, DRAGON_FORCE, DRAGON_DAMAGE, DRAGON_LOOT, true);
}

string Dragon::getMonsterName() const
{
    return DRAGON_CARD_NAME;
}