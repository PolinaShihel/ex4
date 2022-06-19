#ifndef FAIRY_H
#define FAIRY_H

#include "Card.h"
#include "../Players/Wizard.h"

class Fairy : public Card {
public:

    /*
     * C'tor of Fairy class
     *
     * @return
     *      A new instance of Fairy.
    */
    Fairy() : Card(FAIRY_CARD_NAME)
    {}

	/*
	* D'tor of Fairy class.
	*/
	~Fairy() override = default;

	/*
	* Copy C'tor of Fairy class
	*/
	Fairy(const Fairy& name) = default;

	/*
	 * Clones a Fairy object (alternative virtual Copy C'tor of Card)
	 *
	 * @return
	 *      Pointer to a new instance of Fairy.
	*/
	Fairy* Clone() const override;

	/*
	 * Handling the player's applyEncounter with the card:
	 *
	 * @param player - The player.
	 * @return
	 *      void
	*/
	void applyEncounter(Player& player) const override;
};


#endif //FAIRY_H