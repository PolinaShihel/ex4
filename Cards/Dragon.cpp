#include "Dragon.h"
#include "Dragon.h"

using std::string;

Dragon::Dragon() : BattleCard(DRAGON_CARD_NAME, DRAGON_LOOT, DRAGON_FORCE, DRAGON_DAMAGE)
{
}

Dragon* Dragon::Clone() const
{
	return new Dragon(*this);
}

void Dragon::onLost(Player& player) const
{
	player.damage(player.getHealthPoints());
	player.decreaseForce(player.getForce());
}

void Dragon::printAdditionalDetails(std::ostream& os) const
{
	printMonsterDetails(os, DRAGON_FORCE, DRAGON_DAMAGE, DRAGON_LOOT, true);
}