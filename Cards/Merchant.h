#ifndef MERCHANT_H
#define MERCHANT_H

#include "Card.h"

const int DO_NOTHING_ID = 0;
const int HEAL_ID = 1;
const int INCREASE_FORCE_ID = 2;

const int DO_NOTHING_PAYMENT = 0;
const int HEALING_PAYMENT = 5;
const int FORCE_UNITS_TO_INCREASE = 1;
const int BUFF_PAYMENT = 10;

class Merchant : public Card {
public:
	/*
	 * C'tor of Merchant class
	 *
	 * @param name - the name of the card ("Merchant").
	 * @return
	 *      A new instance of Merchant.
	*/
	Merchant(const std::string& name) : Card(name) {}
	
	/*
	* D'tor of Merchant class.
	*/
	~Merchant() override = default;
	
	/*
	* Copy C'tor of Merchant class
	*/
	Merchant(const Merchant& name) = default;
	
	/*
	 * Clones a Merchant object (alternative virtual Copy C'tor of Card)
	 *
	 * @return
	 *      Pointer to a new instance of Merchant.
	*/
	Merchant* Clone() const override;

	/*
	 * Handling the player's applyEncounter with the card:
	 *
	 * @param player - The player.
	 * @return
	 *      void
	*/
	void Merchant::applyEncounter(Player& player) const override;
};


#endif //MERCHANT_H