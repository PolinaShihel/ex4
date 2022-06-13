#include "Barfight.h"

Barfight* Barfight::Clone() const 
{
	return new Barfight(*this);
}

void Barfight::applyEncounter(Player& player) const 
{
	bool isFighter = dynamic_cast<Fighter*>(&player) != nullptr;
	if (!isFighter) {
		player.damage(BARFIGHT_DAMAGE);
	}
	printBarfightMessage(isFighter);
}