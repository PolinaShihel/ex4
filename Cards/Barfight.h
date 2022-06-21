#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"
#include "../Players/Fighter.h"

const std::string BARFIGHT_CARD_NAME = "Barfight";
const int BARFIGHT_DAMAGE = 10;

class Barfight : public Card {
public:
	/*
	 * C'tor of Barfight class
	 *
	 * @return
	 *      A new instance of Barfight.
	*/
	Barfight() : Card(BARFIGHT_CARD_NAME) {}

	/*
	* D'tor of Barfight class.
	*/
	~Barfight() override = default;

	/*
	* Copy C'tor of Barfight class
	*/
	Barfight(const Barfight& other) = default;

	/*
	 * Clones a Barfight object (alternative virtual Copy C'tor of Card)
	 *
	 * @return
	 *      Pointer to a new instance of Barfight.
	*/
	Barfight* Clone() const override;

	/*
	 * Handling the player's applyEncounter with the card:
	 *
	 * @param player - The player.
	 * @return
	 *      void
	*/
	void applyEncounter(Player& player) const override;
};


#endif //BARFIGHT_H