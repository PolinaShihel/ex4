#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "BattleCard.h"

static const int VAMPIRE_FORCE = 10;
static const int VAMPIRE_LOOT = 2;
static const int VAMPIRE_DAMAGE = 10;

static const int FORCE_POINTS_DECREASED_ON_LOST = 1;

class Vampire : public BattleCard {
public:
	/*
	 * C'tor of Vampire class
	 *
	 * @param name - the name of the card ("Vampire").
	 * @return
	 *      A new instance of Vampire.
	*/
	Vampire();
	
	/*
	* D'tor of Vampire class.
	*/
	~Vampire() override = default;
	
	/*
	* Copy C'tor of Vampire class
	*/
	Vampire(const Vampire& name) = default;
	
	/*
	 * Clones a Vampire object (alternative virtual Copy C'tor of Card)
	 *
	 * @return
	 *      Pointer to a new instance of Vampire.
	*/
	Vampire* Clone() const override;

private:
	/*
	 * Decrease player's health & force
	 *
	 * @return
	 *      void
	*/
	void onLost(Player& player) const override;
};


#endif //VAMPIRE_H