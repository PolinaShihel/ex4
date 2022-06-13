#include "Pitfall.h"

Pitfall* Pitfall::Clone() const 
{
	return new Pitfall(*this);
}

void Pitfall::applyEncounter(Player& player) const
{
	Rogue* isRogue = dynamic_cast<Rogue*>(&player);
	if (!isRogue) {
		player.damage(PITFALL_DAMAGE);
	}
	printPitfallMessage(isRogue);
}