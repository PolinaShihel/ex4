#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "BattleCard.h"

const int FORCE_POINTS_LOST = 1;
const int VAMPIRE_FORCE = 10;
const int VAMPIRE_LOOT = 2;
const int VAMPIRE_DAMAGE = 10;

class Vampire : public BattleCard {
public:
	/*
	 * C'tor of Vampire class
	 *
	 * @param name - the name of the card ("Vampire").
	 * @return
	 *      A new instance of Vampire.
	*/
	Vampire() : BattleCard(VAMPIRE_CARD_NAME) {}
	
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

protected:
	/*
	 * Decrease player's force after a lost
	 *
	 * @return
	 *      void
	*/
	void afterLost(Player& player) const override;
	
	/*
	* Prints additional details of card
	*
	* @param os - reference to the stream the card will be printed to.
	* @return
	*      void
	*/
	virtual void printAdditionalDetails(std::ostream& os) const override;
	
	virtual int getMonsterForce() const override;
	virtual int getMonsterLoot() const override;
	virtual int getMonsterDamage() const override;
};


#endif //VAMPIRE_H