#ifndef DRAGON_H
#define DRAGON_H

#include "BattleCard.h"

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
	void onLost(Player& player) const override;

	/*
	* Prints additional details of card
	*
	* @param os - reference to the stream the card will be printed to.
	* @return
	*      void
	*/
	void printAdditionalDetails(std::ostream& os) const override;

	/*
	 * Returns Dragon's force
	 */
	virtual int getMonsterForce() const override;
	
	/*
	 * Returns Dragon's loot
	 */
	virtual int getMonsterLoot() const override;
	
	/*
	 * Returns Dragon's damage
	 */
	virtual int getMonsterDamage() const override;

protected:
	const int DRAGON_FORCE = 25;
	const int DRAGON_LOOT = 1000;
	const int DRAGON_DAMAGE = INFINITY;
};


#endif //DRAGON_H