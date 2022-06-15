#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "BattleCard.h"

const int FORCE_POINTS_DECREASED_ON_LOST = 1;

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
	 * Decrease player's health & force
	 *
	 * @return
	 *      void
	*/
	void onLost(Player& player) const override;
	
	/*
	 * Returns Vampire's force
	 */
	virtual int getMonsterForce() const override;

	/*
	 * Returns Vampire's loot
	 */
	virtual int getMonsterLoot() const override;

	/*
	 * Returns Vampire's damage
	 */
	virtual int getMonsterDamage() const override;

    virtual std::string getMonsterName() const override;

private:
	const int VAMPIRE_FORCE = 10;
	const int VAMPIRE_LOOT = 2;
	const int VAMPIRE_DAMAGE = 10;
};


#endif //VAMPIRE_H