#ifndef GOBLIN_H
#define GOBLIN_H

#include "BattleCard.h"

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
	 * Decrease player's health 
	 *
	 * @return
	 *      void
	*/
	void Goblin::onLost(Player& player) const override;

	/*
	 * Returns Goblin's force
	 */
	virtual int getMonsterForce() const override;

	/*
	 * Returns Goblin's loot
	 */
	virtual int getMonsterLoot() const override;

	/*
	 * Returns Goblin's damage
	 */
	virtual int getMonsterDamage() const override;

private:
	const int GOBLIN_FORCE = 6;
	const int GOBLIN_LOOT = 2;
	const int GOBLIN_DAMAGE = 10;
};


#endif //GOBLIN_H