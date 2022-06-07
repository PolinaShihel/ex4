#include "Barfight.h"

void Barfight::applyEncounter(Player& player) const override
{
	Fighter* isFighter = dynamic_cast<Fighter*>(isFighter);
	if (!isFighter) {
		player.damage(DAMAGE_VALUE);
	}
	printBarfightMessage(isFighter);
}