#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"

int const TREASURE_VALUE = 10;

class Treasure : public Card {
public:
	Treasure(const string& name) : Card(name) {}
	~Treasure() override = default;
	Treasure(const Treasure& name) = default;
	Treasure* Clone() const override;
	void applyEncounter(Player& player) const override;
};


#endif //BARFIGHT_H