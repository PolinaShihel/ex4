#ifndef MERCHANT_H
#define MERCHANT_H

#include "Card.h"

static const std::string MERCHANT_CARD_NAME = "Merchant";
 
static const int DO_NOTHING_ID = 0;
static const int HEAL_ID = 1;
static const int BUFF_ID = 2;

static const int DO_NOTHING_PAYMENT = 0;
static const int HEALING_PAYMENT = 5;
static const int FORCE_UNITS_TO_INCREASE = 1;
static const int BUFF_PAYMENT = 10;
static const int HEALING_POTION = 1;

class Merchant : public Card {
public:
	/*
	 * C'tor of Merchant class
	 *
	 * @return
	 *      A new instance of Merchant.
	*/
	Merchant() : Card(MERCHANT_CARD_NAME) 
	{
	}

	/*
	* D'tor of Merchant class.
	*/
	~Merchant() override = default;

	/*
	* Copy C'tor of Merchant class
	*/
	Merchant(const Merchant& other) = default;

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
	void applyEncounter(Player& player) const override;
};


#endif //MERCHANT_H