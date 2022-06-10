#ifndef DRAGON_H
#define DRAGON_H

#include "BattleCard.h"

const int DRAGON_FORCE = 25;
const int DRAGON_LOOT = 1000;
const int DRAGON_DAMAGE = INFINITY;

class Dragon : public BattleCard {
public:
	/*
	 * C'tor of Dragon class
	 *
	 * @param name - the name of the card ("Dragon").
	 * @return
	 *      A new instance of Dragon.
	*/
	Dragon() : BattleCard(DRAGON_CARD_NAME) {}
	
	/*
	* D'tor of Dragon class.
	*/
	~Dragon() override = default;
	
	/*
	* Copy C'tor of Dragon class
	*/
	Dragon(const Dragon& name) = default;
	
	/*
	 * Clones a Dragon object (alternative virtual Copy C'tor of Card)
	 *
	 * @return
	 *      Pointer to a new instance of Dragon.
	*/
	Dragon* Clone() const override;

protected:
	/*
	 * "Burns" the player
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
	void printAdditionalDetails(std::ostream& os) const override;

	virtual int getMonsterForce() const override;
	virtual int getMonsterLoot() const override;
	virtual int getMonsterDamage() const override;
};


#endif //DRAGON_H