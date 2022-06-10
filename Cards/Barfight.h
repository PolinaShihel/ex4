#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"
#include "Players/Fighter.h"

const int DAMAGE = 10;

class BarFight : public Card {
public:
	BarFight(const string& name) : Card(name) {}
	~BarFight() override = default;
	BarFight(const BarFight& name) = default;
	BarFight* Clone() const override;
	void applyEncounter(Player& player) const override;
};


#endif //BARFIGHT_H