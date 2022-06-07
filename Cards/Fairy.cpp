#include "Fairy.h"

void Fairy::applyEncounter(Player& player) const override
{
	Wizard* isWizard = dynamic_cast<Wizard*>(player);
	if (isWizard) {
		player.heal(POINTS_TO_INCREASE);
	}
	printFairyMessage(isWizard);
}