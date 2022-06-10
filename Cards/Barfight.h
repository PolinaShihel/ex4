#ifndef Barfight_H
#define Barfight_H

#include "Card.h"
#include "Players/Fighter.h"

class Barfight : public Card {
public:
	/*
	 * C'tor of Barfight class
	 *
	 * @param name - the name of the card ("Barfight").
	 * @return
	 *      A new instance of Barfight.
	*/
	Barfight(const string& name) : Card(name) {}
	
	/*
	* D'tor of Barfight class.
	*/
	~Barfight() override = default;
	
	/*
	* Copy C'tor of Barfight class
	*/
	Barfight(const Barfight& name) = default;
	
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


#endif //Barfight_H