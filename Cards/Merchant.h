#ifndef MERCHANT_H
#define MERCHANT_H

#include "Card.h"
#include <string>

const int DO_NOTHING_ID = 0;
const int HEAL_ID = 1;
const int INCREASE_FORCE_ID = 0;

const int DO_NOTHING_PAYMENT = 0;
const int HEALTH_POINTS_TO_INCREASE = 1;
const int HEALING_PAYMENT = 5;
const int FORCE_UNITS_TO_INCREASE = 1;
const int BUFF_PAYMENT = 10;

using std::stoi;
using std::getline;

class Merchant : public Card {
public:
	Merchant(const string& name) : Card(name) {}
	~Merchant() override = default;
	Merchant(const Merchant& name) = default;
	Merchant* Clone() const override;
	void Merchant::applyEncounter(Player& player) const override;
};


#endif //MERCHANT_H