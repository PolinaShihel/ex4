#include "Fairy.h"

Fairy* Fairy::Clone() const
{
	return new Fairy(*this);
}

void Fairy::applyEncounter(Player& player) const 
{
	Wizard* isWizard = dynamic_cast<Wizard*>(&player);
	if (isWizard) {
		player.heal(HEALTH_POINTS_TO_INCREASE);
	}
	printFairyMessage(isWizard);
}