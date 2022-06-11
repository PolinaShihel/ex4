#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

int const TREASURE_VALUE = 10;

class Treasure : public Card {
public:
	/*
	 * C'tor of Treasure class
	 *
	 * @return
	 *      A new instance of Treasure.
	*/
	Treasure() : Card(TREASURE_CARD_NAME) {}
	
	/*
	* D'tor of Treasure class.
	*/
	~Treasure() override = default;
	
	/*
	 * Clones a Treasure object (alternative virtual Copy C'tor of Card)
	 *
	 * @return
	 *      Pointer to a new instance of Treasure.
	*/
	Treasure* Clone() const override;

	/*
	 * Handling the player's applyEncounter with the card:
	 *
	 * @param player - The player.
	 * @return
	 *      void
	*/
	void applyEncounter(Player& player) const override;
};


#endif //TREASURE_H