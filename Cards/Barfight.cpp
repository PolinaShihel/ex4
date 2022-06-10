#include "Barfight.h"

BarFight* BarFight::Clone() const 
{
	return new BarFight(*this);
}

void BarFight::applyEncounter(Player& player) const 
{
	Fighter* isFighter = dynamic_cast<Fighter*>(isFighter);
	if (!isFighter) {
		player.damage(DAMAGE);
	}
	printBarfightMessage(isFighter);
}