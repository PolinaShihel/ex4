#include "Barfight.h"

Barfight* Barfight::Clone() const 
{
	return new Barfight(*this);
}

void Barfight::applyEncounter(Player& player) const 
{
	Fighter* isFighter = dynamic_cast<Fighter*>(&player);
	if (!isFighter) {
		player.damage(DAMAGE);
	}
	printBarfightMessage(isFighter);
}