#ifndef Barfight_H
#define Barfight_H

#include "Card.h"

int const TREASURE_VALUE = 10;

class Treasure : public Card {
public:
	/*
	 * C'tor of Treasure class
	 *
	 * @param name - the name of the card ("Treasure").
	 * @return
	 *      A new instance of Treasure.
	*/
	Treasure(const string& name) : Card(name) {}
	
	/*
	* D'tor of Treasure class.
	*/
	~Treasure() override = default;

	/*
	* Copy C'tor of Treasure class
	*/
	Treasure(const Treasure& name) = default;
	
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


#endif //Barfight_H