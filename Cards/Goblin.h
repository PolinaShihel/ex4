#ifndef GOBLIN_H
#define GOBLIN_H

#include "BattleCard.h"

const int GOBLIN_FORCE = 6;
const int GOBLIN_LOOT = 2;
const int GOBLIN_DAMAGE = 10;

class Goblin : public BattleCard {
public:
	/*
	 * C'tor of Goblin class
	 *
	 * @param name - the name of the card ("Goblin").
	 * @return
	 *      A new instance of Goblin.
	*/
	Goblin() : BattleCard(GOBLIN_CARD_NAME) {}
	
	/*
	* D'tor of Goblin class.
	*/
	~Goblin() override = default;
	
	/*
	* Copy C'tor of Goblin class
	*/
	Goblin(const Goblin& name) = default;
	
	/*
	 * Clones a Goblin object (alternative virtual Copy C'tor of Card)
	 *
	 * @return
	 *      Pointer to a new instance of Goblin.
	*/
	Goblin* Clone() const override;

protected:
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


#endif //GOBLIN_H