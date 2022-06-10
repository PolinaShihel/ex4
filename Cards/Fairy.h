#ifndef FAIRY_H
#define FAIRY_H

#include "Card.h"
#include "Players/Wizard.h"

class Fairy : public Card {
public:
	Fairy(const string& name) : Card(name) {}
	~Fairy() override = default;
	Fairy(const Fairy& name) = default;
	Fairy* Clone() const override;
	void applyEncounter(Player& player) const override;
};


#endif //FAIRY_H