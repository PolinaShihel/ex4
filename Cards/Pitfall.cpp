#include "Pitfall.h"

Pitfall* Pitfall::Clone() const 
{
	return new Pitfall(*this);
}

void Pitfall::applyEncounter(Player& player) const
{
	bool isRogue = dynamic_cast<Rogue*>(&player) != nullptr;
	if (!isRogue) {
		player.damage(PITFALL_DAMAGE);
	}
	printPitfallMessage(isRogue);
}