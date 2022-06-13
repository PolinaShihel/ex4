#include "Fairy.h"

Fairy* Fairy::Clone() const
{
	return new Fairy(*this);
}

void Fairy::applyEncounter(Player& player) const
{
	bool isWizard = dynamic_cast<Wizard*>(&player) != nullptr;
	if (isWizard) {
		player.heal(HEALTH_POINTS_TO_INCREASE);
	}
	printFairyMessage(isWizard);
}