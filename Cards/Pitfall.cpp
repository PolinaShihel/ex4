#include "Pitfall.h"

void Pitfall::applyEncounter(Player& player) const override
{
	Rogue* isRogue = dynamic_cast<Rogue*>(player);
	if (!isRogue) {
		player.damage(DAMAGE_VALUE);
	}
	printPitfallMessage(isRogue);
}