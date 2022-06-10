#include "Barfight.h"

Barfight* Barfight::Clone() const 
{
	return new Barfight(*this);
}

void Barfight::applyEncounter(Player& player) const 
{
	Fighter* isFighter = dynamic_cast<Fighter*>(isFighter);
	if (!isFighter) {
		player.damage(DAMAGE);
	}
	printBarfightMessage(isFighter);
}