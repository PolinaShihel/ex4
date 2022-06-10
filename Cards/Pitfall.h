#ifndef PITFALL_H
#define PITFALL_H

#include "Card.h"
#include "Players/Rogue.h"

class Pitfall : public Card {
public:
	Pitfall(const string& name) : Card(name) {}
	~Pitfall() override = default;
	Pitfall(const Pitfall& name) = default;
	Pitfall* Clone() const override;
	void applyEncounter(Player& player) const override;
};


#endif //PITFALL_H