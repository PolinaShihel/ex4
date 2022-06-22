#ifndef PITFALL_H
#define PITFALL_H

#include "Card.h"
#include "../Players/Rogue.h"

static const std::string PITFALL_CARD_NAME = "Pitfall";
static const int PITFALL_DAMAGE = 10;

class Pitfall : public Card {
public:
	/*
	 * C'tor of Pitfall class
	 *
	 * @return
	 *      A new instance of Pitfall.
	*/
	Pitfall() : Card(PITFALL_CARD_NAME) 
	{
	}

	/*
	* D'tor of Pitfall class.
	*/
	~Pitfall() override = default;

	/*
	* Copy C'tor of Pitfall class
	*/
	Pitfall(const Pitfall& other) = default;

	/*
	 * Clones a Pitfall object (alternative virtual Copy C'tor of Card)
	 *
	 * @return
	 *      Pointer to a new instance of Pitfall.
	*/
	Pitfall* Clone() const override;

	/*
	 * Handling the player's applyEncounter with the card:
	 *
	 * @param player - The player.
	 * @return
	 *      void
	*/
	void applyEncounter(Player& player) const override;
};


#endif //PITFALL_H